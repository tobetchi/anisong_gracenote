/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnEventSubscriber_h_
#define _GnEventSubscriber_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"





/**
* <b>This class is experimental and may be change or removed in future releases</b>
* Represents a unique subscriber, allow GNSDK event subscriptions to be tied to
* a single specific subscriber, or multiple subscribers as needed.
*/ 

@interface GnEventSubscriber : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* <b>This API is experimental and may be change or removed in future releases</b>
* Create a subscriber that can then subscribe to various GNSDK events.
* Note a single subscriber is typically used for all events.
*/ 

-(nullable INSTANCE_RETURN_TYPE) init;

/**
* <b>This API is experimental and may be change or removed in future releases</b>
* Get the identifier for this subscriber
*/ 

-(nullable NSString*) id;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnEventSubscriber_h_ */

