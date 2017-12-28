/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMusicIdBatch_h_
#define _GnMusicIdBatch_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnLocale.h"
#import "GnMusicIdBatchOptions.h"
#import "GnResponseAlbums.h"
#import "GnResponseDataMatches.h"
#import "GnEnums.h"
#import "GnStatusEventsDelegate.h"
#import "GnUser.h"




/**
*  \class GnMusicIdBatch
*  Provides services for audio recognition using CD TOC-based search,
*  text-based search, fingerprint, and identifier lookup functionality.
*
*  <p><b>SDK Documentation</b></p>
*  <b>Topic:</b> Implementing Applications (All Platforms) > Identifying Music > Identifying Music Using a CD-TOC, Text, or Fingerprints (MusicID)
*
*  For more information on using MusicID, see the above topic which covers:
*    <ul>
*   <li>MusicID queries</li>
*   <li>Options for MusicID queries</li>
*   <li>Identifying music using a CD TOC<ul>
*   <li>Code samples for identifying music using a CD TOC</li></ul></li>
*   <li>Identifying music using text<ul>
*   <li>Code samples for identifying music using text</li></ul></li>
*   <li>Identifying music using fingerprints</li>
*   <li>MusicID fingerprinting<ul>
*   <li>Code samples for identifying music using MusicID fingerprinting</li></ul></li>
*   </ul>
*
*  <p><b>Overiew</b></p>
*  <b>Topic:</b> Concepts > Music Modules > Music Module Overview > MusicID Overview
*
*  <p><b>Sample Apps</b></p>
*  <ul>
*     <li>.../samples/musicid_gdo_navigation</li>
*     <li>.../samples/musicid_lookup_album_id</li>
*     <li>.../samples/musicid_lookup_album_local_online</li>
*     <li>.../samples/musicid_lookup_album_toc</li>
*     <li>.../samples/musicid_lookup_matches_text</li>
*     <li>.../samples/musicid_persist_and_manage</li>
*     <li>.../samples/musicid_persist_results</li>
*   </ul>
*
*/ 

@interface GnMusicIdBatch : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
*  Defualt constructs a batch music identification query object
*/ 

-(nullable INSTANCE_RETURN_TYPE) init;

/**
*  Constructs a batch music identification query object with a Gracenote user and event delegate
*  @param user          [in] Set GnUser object representing the user making the GnMusicId request
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed.
*/ 

-(nullable INSTANCE_RETURN_TYPE) init: (nonnull GnUser*)user statusEventsDelegate: (nullable id <GnStatusEventsDelegate>)pEventHandler error: (NSError**)error;

/**
*  Constructs a batch music identification query object with a Gracenote user, locale and event delegate
*  @param user          [in] Set GnUser object representing the user making the GnMusicIdBatch request
*  @param locale		 [in] GnLocale object representing region and language preferred for MusicID-Stream responses
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed.
*/ 

-(nullable INSTANCE_RETURN_TYPE) init: (nonnull GnUser*)user locale: (nonnull GnLocale*)locale statusEventsDelegate: (nullable id <GnStatusEventsDelegate>)pEventHandler error: (NSError**)error;

/**
*  Clear all queries from batch music identification
*/ 

-(void) clear: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Perform album find for all individual queries in the batch
*/ 

-(void) findAlbums: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Perform match find for all individual queries in the batch
*/ 

-(void) findMatches: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Retrieve album query from batch music identification
*/ 

-(nullable GnResponseAlbums*) getAlbums: (nullable NSString*)unique_id error: (NSError**)error;

/**
*  Retrieve match query from batch music identification
*/ 

-(nullable GnResponseDataMatches*) getMatches: (nullable NSString*)unique_id error: (NSError**)error;

/**
*  Retrieves the MusicID library version string.
*  @return gnsdk_cstr_t Version string, if successful
*  <p><b>Remarks:</b></p>
*  You can call this API after successfully instantiating a GnManager instance.
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
*
*  Major: New functionality
*
*  Minor: New or changed features
*
*  Improvement: Improvements and fixes
*
*  Build: Internal build number
*/ 

+(nonnull NSString*) version;

/**
*  Retrieves the MusicID SDK's build date string.
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  You can call this API after successfully instantiating a GnManager instance.
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example build date string: 2008-02-12 00:41 UTC
*/ 

+(nonnull NSString*) buildDate;

/**
* Set cancel state
* @param bCancel 	[in] Cancel state
*/ 

-(void) setCancel: (BOOL)bCancel;

/**
* Get cancel state.
* @return Cancel state
*/ 

-(BOOL) isCancelled;

/**
* Get GnMusicIdBatchOption options object. Use to configure your GnMusicIdBatch instance.
* @return Options objects
*/ 

-(nonnull GnMusicIdBatchOptions*) options;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnMusicIdBatch_h_ */

