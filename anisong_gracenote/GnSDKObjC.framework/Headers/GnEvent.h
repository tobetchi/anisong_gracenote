/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnEvent_h_
#define _GnEvent_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"




/**
* Data object for event data
*
* Object containing metadata about a GNSDK generated event.
*
*/ 

@interface GnEvent : GnDataObject

NS_ASSUME_NONNULL_BEGIN

/**
* GnEvent
*/
-(nullable INSTANCE_RETURN_TYPE) init;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnEvent_h_ */

