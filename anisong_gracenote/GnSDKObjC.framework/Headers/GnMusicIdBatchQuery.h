/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMusicIdBatchQuery_h_
#define _GnMusicIdBatchQuery_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnEnums.h"
#import "GnMusicIdBatch.h"




/**
* \class GnMusicIdBatchQuery
* Configures query for GnMusicIdBatch
*/ 

@interface GnMusicIdBatchQuery : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
*  Constructs a batch music identification query object with a unique identifier
*  @param batch		[in] GnMusicIdBatch object to use with query
*  @param unique_id	[in] Unique identifier for batch query
*/ 

-(nullable INSTANCE_RETURN_TYPE) init: (nonnull GnMusicIdBatch*)batch uniqueId: (nullable NSString*)uniqueId error: (NSError**)error;

/**
*  Sets externally- and internally-generated Gracenote fingerprint
*  fingerprint Extraction (GNFPX) or Cantametrix (CMX) fingerprint data.
*	Use with GnMusicIdBatch::GetAlbums
*  @param strFingerprintData	[in] Audio source to fingerprint
*  @param fpType				[in] One of the GnFingerprintType fingerprint data types,
*/ 

-(void) setFingerprint: (nullable NSString*)strFingerprintData fpType: (GnFingerprintType)fpType error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Sets metadata::GnDataObject, use with GnMusicIdBatch::GetAlbums
*  @param gnObj				[in] An metadata::GnDataObject object
*/ 

-(void) setGDO: (nonnull GnDataObject*)gnObj error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Sets text string, use with GnMusicIdBatch::GetAlbums and GnMusicIdBatch::GetMatches
*  @param albumTitle			[in] Album title string
*  @param trackTitle			[in] Track title string
*  @param albumArtistName		[in] Album artist string
*  @param trackArtistName		[in] Track artist string
*  @param composerName			[in] Composer string
*/ 

-(void) setText: (nullable NSString*)albumTitle trackTitle: (nullable NSString*)trackTitle albumArtistName: (nullable NSString*)albumArtistName trackArtistName: (nullable NSString*)trackArtistName composerName: (nullable NSString*)composerName error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Sets TOC Offset
*  @param strCDTOC				[in] CD TOC string
*/ 

-(void) setTOCOffset: (NSUInteger)tocOffset error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Sets CDTOC string, use with GnMusicIdBatch::GetAlbums
*  @param strCDTOC				[in] CD TOC string
*/ 

-(void) setTOC: (nullable NSString*)strTOC error: (NSError**)error NS_REFINED_FOR_SWIFT;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnMusicIdBatchQuery_h_ */

