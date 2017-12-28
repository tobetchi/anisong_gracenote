//
//  ViewController.m
//  anisong_gracenote
//
//  Created by tobetchi on 2017/05/24.
//  Copyright © 2017年 tobetchi. All rights reserved.
//

#import "ViewController.h"
#import <AVFoundation/AVFoundation.h>
#import <GnSDKObjC/Gn.h>
#import "WebViewController.h"

#define CLIENTID @""
#define CLIENTIDTAG @""

@interface ViewController () <GnMusicIdStreamEventsDelegate>

@property (strong) GnMusicIdStream *gnMusicIDStream;
@property (strong) GnMic *gnMic;
@property (strong) GnManager *gnManager;
@property (strong) GnUser *gnUser;
@property (strong) GnUserStore *gnUserStore;
@property (strong) GnLocale *locale;

@property dispatch_queue_t internalQueue;
@property (nonatomic) NSString *trackTitle;

@property (nonatomic) UIButton *idNowButton;
@property (nonatomic) UILabel *statusLabel;
@property (nonatomic) UILabel *artistLabel;
@property (nonatomic) UILabel *trackLabel;
@property (nonatomic) UIButton *searchButton;
@end

@implementation ViewController
- (void)viewDidLoad {
    [super viewDidLoad];

    // Instantiating a GNSDK Manager Object
    NSError* error = nil;
    NSString* resourcePath = [[NSBundle mainBundle] pathForResource:@"license.txt"
                                                             ofType:nil];
    NSString* licenseString = [NSString stringWithContentsOfFile:resourcePath
                                                        encoding:NSUTF8StringEncoding
                                                           error:&error];

    self.gnManager = [[GnManager alloc] initWithLicense:licenseString
                                       licenseInputMode:kLicenseInputModeString
                                                  error:nil];


    // Instantiating a GN User Object
    self.gnUserStore = [GnUserStore new];
    self.gnUser = [[GnUser alloc] initWithUserStoreDelegate:self.gnUserStore
                                                   clientId:CLIENTID
                                                  clientTag:CLIENTIDTAG
                                         applicationVersion:@"1.0.0.0"
                                                      error:&error];


    NSError *localeError = nil;
    self.locale = [[GnLocale alloc] initWithLocaleGroup:kLocaleGroupMusic
                                               language:kLanguageJapanese
                                                 region:kRegionGlobal
                                             descriptor:kDescriptorSimplified
                                                   user:self.gnUser
                                   statusEventsDelegate:nil
                                                  error:&localeError];
    [self.locale setGroupDefault:&localeError];
    
    AVAudioSession *session = [AVAudioSession sharedInstance];
    [session setPreferredSampleRate:44100 error:nil];
    [session setInputGain:0.5 error:nil];
    [session setActive:YES error:nil];

    if ([session respondsToSelector:@selector(requestRecordPermission:)]) {
        [session requestRecordPermission:^(BOOL granted) {
                if (granted) {
                    [self microphoneInitialize];
                } else {
                    [self updateStatus: @"Microphone access denied"];
                }
            }];
    } else { //(pre iOS7)
        [self microphoneInitialize];
    }

    [self setupInterface];
}
    
- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    [self layoutInterface];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)setupInterface {
    self.idNowButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [self.idNowButton setTitle:@"ID Now" forState:UIControlStateNormal];
    self.idNowButton.enabled = YES;
    [self.idNowButton addTarget:self action:@selector(idNow:) forControlEvents:UIControlEventTouchDown];
    [self.view addSubview:self.idNowButton];

    self.statusLabel = [[UILabel alloc] init];
    [self.view addSubview:self.statusLabel];

    self.artistLabel = [[UILabel alloc] init];
    [self.view addSubview:self.artistLabel];

    self.trackLabel = [[UILabel alloc] init];
    [self.view addSubview:self.trackLabel];

    self.searchButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [self.searchButton setTitle:@"Search Anisong" forState:UIControlStateNormal];
    self.searchButton.enabled = NO;
    [self.searchButton addTarget:self action:@selector(showWebView:) forControlEvents:UIControlEventTouchDown];
    [self.view addSubview:self.searchButton];
}

- (void)layoutInterface {
    CGFloat margin = 20.0;
    CGFloat width = self.view.bounds.size.width - 2.0 * margin;

    self.idNowButton.frame = CGRectMake(margin, margin + self.topLayoutGuide.length,
                                        200, 31);

    self.statusLabel.frame = CGRectMake(margin, [self posY:self.idNowButton.frame], width, 31);
    self.artistLabel.frame = CGRectMake(margin, [self posY:self.statusLabel.frame], width, 31);
    self.trackLabel.frame = CGRectMake(margin, [self posY:self.artistLabel.frame], width, 31);
    self.searchButton.frame = CGRectMake(margin, [self posY:self.trackLabel.frame], 200, 31);
}

- (CGFloat)posY:(CGRect)frame {
    return frame.origin.y + frame.size.height + 10.0;
}

- (void)microphoneInitialize {
    self.gnMic = [[GnMic alloc] initWithSampleRate: 44100 bitsPerChannel:16 numberOfChannels: 1];
    self.internalQueue = dispatch_queue_create("gnsdk.TaskQueue", DISPATCH_QUEUE_CONCURRENT);
    if (self.gnMic) {
        [self setupMusicIDStream];
    }
}


#pragma mark - Id Now

- (void)idNow:(id)sender {
    if (!self.gnMusicIDStream) return;

    NSError *error = nil;
    [self.gnMusicIDStream identifyAlbumAsync:&error];

    [self updateStatus: @"Identifying"];
    self.artistLabel.text = @"";
    self.trackLabel.text = @"";
    self.searchButton.enabled = NO;
    
    if (error) {
        NSLog(@"Identify Error = %@", [error localizedDescription]);
    }
}


#pragma mark - Music ID Stream Setup

-(void) setupMusicIDStream {
    if (!self.gnUser) return;
    
    __block NSError *musicIDStreamError = nil;
    @try {
        self.gnMusicIDStream = [[GnMusicIdStream alloc] initWithUser:self.gnUser preset:kPresetMicrophone locale:self.locale musicIdStreamEventsDelegate: self error:&musicIDStreamError];
        
        musicIDStreamError = nil;
        GnMusicIdStreamOptions *options = [self.gnMusicIDStream options];
        [options resultSingle:YES error:&musicIDStreamError];
        [options lookupData:kLookupDataSonicData enable:YES error:&musicIDStreamError];
        [options lookupData:kLookupDataContent enable:YES error:&musicIDStreamError];
        [options preferResultCoverart:YES error:&musicIDStreamError];
        
        musicIDStreamError = nil;
        dispatch_async(self.internalQueue, ^{
                self.idNowButton.enabled = NO; //disable stream-ID until audio-processing-started callback is received
                           
                [self.gnMusicIDStream audioProcessStart:self.gnMic error:&musicIDStreamError];
                
                if (musicIDStreamError) {
                    dispatch_async(dispatch_get_main_queue(), ^{
                            NSLog(@"Error while starting Audio Process With AudioSource - %@", [musicIDStreamError localizedDescription]);
                        });
                }
            });
    }
    @catch (NSException *exception) {
        NSLog( @"Error: %@ - %@ - %@", [exception name], [exception reason], [exception userInfo] );
    }
}

#pragma mark - GnMusicIdStreamEventsDelegate Methods

- (void)musicIdStreamIdentifyingStatusEvent:(GnMusicIdStreamIdentifyingStatus)status cancellableDelegate:(id <GnCancellableDelegate>)canceller {
    NSString *statusString = nil;
    switch (status) {
    case kStatusIdentifyingInvalid:
        statusString = @"Error";
        break;
    case kStatusIdentifyingStarted:
        statusString = @"Identifying";
        break;
    case kStatusIdentifyingFpGenerated:
        statusString = @"Fingerprint Generated";
        break;
    case kStatusIdentifyingLocalQueryStarted:
        statusString = @"Local Query Started";
        break;
    case kStatusIdentifyingLocalQueryEnded:
        statusString = @"Local Query Ended";
        break;
    case kStatusIdentifyingOnlineQueryStarted:
        statusString = @"Online Query Started";
        break;
    case kStatusIdentifyingOnlineQueryEnded:
        statusString = @"Online Query Ended";
        break;
    case kStatusIdentifyingEnded:
        statusString = @"Identification Ended";
        break;
    }
    
    if (statusString) {
        [self updateStatus:[@"Status: " stringByAppendingString:statusString]];
    }
}

- (void)musicIdStreamProcessingStatusEvent:(GnMusicIdStreamProcessingStatus)status cancellableDelegate:(id <GnCancellableDelegate>)canceller {
    switch (status) {
    case kStatusProcessingAudioStarted:
        {
            dispatch_async(dispatch_get_main_queue(), ^{
                    self.idNowButton.enabled = YES;
                });
            break;
        }
    case kStatusProcessingInvalid:
        break;
    case  kStatusProcessingAudioNone:
        break;
    case  kStatusProcessingAudioEnded:
        break;
    case kStatusProcessingAudioSilence:
        break;
    case kStatusProcessingAudioNoise:
        break;
    case kStatusProcessingAudioSpeech:
        break;
    case kStatusProcessingAudioMusic:
        break;
    case kStatusProcessingTransitionNone:
        break;
    case kStatusProcessingTransitionChannelChange:
        break;
    case kStatusProcessingTransitionContentToContent:
        break;
    case kStatusProcessingErrorNoClassifier:
        break;

    }
}

- (void)statusEvent: (GnStatus)status
    percentComplete: (NSUInteger)percentComplete
     bytesTotalSent: (NSUInteger)bytesTotalSent
 bytesTotalReceived: (NSUInteger)bytesTotalReceived
cancellableDelegate: (id <GnCancellableDelegate>)canceller
{
    NSString *statusString = nil;
    
    switch (status) {
    case kStatusUnknown:
        statusString = @"Status Unknown";
        break;
    case kStatusBegin:
        statusString = @"Status Begin";
        break;
    case kStatusProgress:
        break;
    case kStatusComplete:
        statusString = @"Status Complete";
        break;
    case kStatusErrorInfo:
        statusString = @"No Match";
        //[self stopBusyIndicator];
        break;
    case kStatusConnecting:
        statusString = @"Status Connecting";
        break;
    case kStatusSending:
        statusString = @"Status Sending";
        break;
    case kStatusReceiving:
        statusString = @"Status Receiving";
        break;
    case kStatusDisconnected:
        statusString = @"Status Disconnected";
        break;
    case kStatusReading:
        statusString = @"Status Reading";
        break;
    case kStatusWriting:
        statusString = @"Status Writing";
        break;
    case kStatusCancelled:
        statusString = @"Status Cancelled";
        break;
    case kStatusCancelCheck:
        statusString = @"Status Cancel Check";
    }
    
    if (statusString) {
        [self updateStatus: [NSString stringWithFormat:@"%@ [%zu%%]", statusString?statusString:@"", percentComplete]];
    }
}

- (void)musicIdStreamAlbumResult:(GnResponseAlbums *)result cancellableDelegate:(id <GnCancellableDelegate>)canceller {
    [self processAlbumResponseAndUpdateResultsTable:result];
}

-(void)musicIdStreamIdentifyCompletedWithError:(NSError *)completeError {
    NSString *statusString = [NSString stringWithFormat:@"%@ - [%zx]", [completeError localizedDescription], [completeError code]];
    [self updateStatus:[@"[Error] " stringByAppendingString:statusString]];
}

#pragma mark - Process Album Response

- (void)processAlbumResponseAndUpdateResultsTable:(id)responseAlbums {
    id albums = nil;
    
    if ([responseAlbums isKindOfClass:[GnResponseAlbums class]])
        albums = [responseAlbums albums];
    else
        albums = responseAlbums;

    NSString *albumArtist = @"";
    NSString *albumTitle = @"";
    NSString *trackTitle = @"";
    
    for (GnAlbum* album in albums) {
        GnTrackEnumerator *tracksMatched  = [album tracksMatched];
        albumArtist = [[[album artist] name] display];
        albumTitle = [[album title] display];
        
        for (GnTrack *track in tracksMatched) {
            trackTitle = [[track title] display];
        }

        self.trackTitle = trackTitle;
        NSLog(@"Artist %@, Album %@, Track %@", albumArtist, albumTitle, trackTitle);
    }

    dispatch_async(dispatch_get_main_queue(), ^{
            self.artistLabel.text = [@"Artist: " stringByAppendingString:albumArtist];
            self.trackLabel.text = [@"Track: " stringByAppendingString:trackTitle];;
            self.searchButton.enabled = YES;
    });
}

- (void)updateStatus:(NSString *)status {
    dispatch_async(dispatch_get_main_queue(), ^{
        self.statusLabel.text = [NSString stringWithFormat: @"%@\n", status];
    });
}

- (void)showWebView:(UIButton *)btn {
    WebViewController *webView = [[WebViewController alloc] init];
    webView.modalTransitionStyle = UIModalPresentationFullScreen;

    webView.keyword = self.trackTitle;

    [self presentViewController:webView animated:YES completion:nil];
}
@end
