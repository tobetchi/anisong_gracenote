/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMusicIdBatchOptions_h_
#define _GnMusicIdBatchOptions_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"




/**
* \class GnMusicIdBatchOptions
* Configures options for GnMusicIdBatch
*/ 

@interface GnMusicIdBatchOptions : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
*  Indicate whether the MusicID query should be performed against local embedded databases or online.
*  @param lookupMode  [in] One of the GnLookupMode values
*  @ingroup MusicId_Options
*/ 

-(void) lookupMode: (GnLookupMode)lookupMode error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Return current lookup mode for MusicID query
*  @ingroup MusicId_Options
*/ 

-(GnLookupMode) lookupMode: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Set the lookup data value for the MusicID query.
*  @param lookupData [in] One of the GnLookupData values
*  @param bEnable    [in] Set lookup data
*  @ingroup MusicId_Options
*/ 

-(void) lookupData: (GnLookupData)lookupData bEnable: (BOOL)bEnable error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Set the preferred language for the returned results.
*  @param preferredLanguage [in] One of the GNSDK language values
*  @ingroup MusicId_Options
*/ 

-(void) preferResultLanguage: (GnLanguage)preferredLanguage error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Set the preferred external ID of the returned results.
*  Only available where single result is also requested.
*  @param strExternalId [in] Gracenote external ID source name
*  @ingroup MusicId_Options
*/ 

-(void) preferResultExternalId: (nullable NSString*)strExternalId error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Set that you would like cover art (if availble) in the returned results.
*  @param bEnable [in] Set prefer cover art
*  @ingroup MusicId_Options
*/ 

-(void) preferResultCoverart: (BOOL)bEnable error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Indicates whether the query should attempt to lookup & include the requested image size in the response.
*  @param GnImageSize  [in] One of the GnImageSize values
*  @ingroup MusicId_Options
*/ 

-(void) inlineImage: (GnImageSize)imageSize error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Enable you have a full album object and you want to see if GN has updated data for it.
*  @param bEnable [in] Set revision check
*
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*  @ingroup MusicId_Options
*/ 

-(void) revisionCheck: (BOOL)bEnable error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Set a specific network interface to use with this object's connections. This can be useful for
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
*  @param intfName [in] Local IP address or system name for the desired network interface
*  @ingroup MusicId_Options
*/ 

-(void) networkInterface: (nullable NSString*)intfName error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Return the network interface being used with this object's connections if one has been set.
* If no specific network interface has been set, this option returns an empty string.
*  @ingroup MusicId_Options
*/ 

-(nullable NSString*) networkInterface: (NSError**)error;

/**
*  Set option using option name
*  @param option   [in] Option name
*  @param value	[in] Option value
*  @ingroup MusicId_Options
*/ 

-(void) custom: (nullable NSString*)option value: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Set option using option name
*  @param option   [in] Option name
*  @param bEnable	[in] Option enable true/false
*  @ingroup MusicId_Options
*/ 

-(void) custom: (nullable NSString*)option bEnable: (BOOL)bEnable error: (NSError**)error NS_REFINED_FOR_SWIFT;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnMusicIdBatchOptions_h_ */

