/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnPlaylistResults_h_
#define _GnPlaylistResults_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnPlaylistIdentifier.h"


@class GnPlaylistIdentifierEnumerator;


/**
* <b>Experimental</b>: GnPlaylistResults
*/ 

@interface GnPlaylistResults : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* GnPlaylistResults
*/
-(nullable INSTANCE_RETURN_TYPE) init;

/**
* Identifiers
*/
-(GnPlaylistIdentifierEnumerator*) identifiers;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnPlaylistResults_h_ */

