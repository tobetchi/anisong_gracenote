/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnEventSubscription_h_
#define _GnEventSubscription_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEventData.h"
#import "GnEnums.h"
#import "GnEventSubscriber.h"
#import "GnSubscriptionEventsDelegate.h"




/**
* <b>This class is experimental and may be change or removed in future releases</b>
* Event subscriber
*/ 

@interface GnEventSubscription : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* <b>This API is experimental and may be change or removed in future releases</b>
* Subscribe to specific GNSDK event group
* @param subscriber		[in] The subscriber 
* @param eventGroup		[in] GNSDK event group to subscribe to 
* @param pEventDelegate	[in] Delegate instance to receive subscription events. 
*							The application must ensure this delegate instance remains valid for the duration of the subscription.
*/ 

-(nullable INSTANCE_RETURN_TYPE) init: (nonnull GnEventSubscriber*)subscriber eventGroup: (nullable NSString*)eventGroup subscriptionEventsDelegate: (nullable id <GnSubscriptionEventsDelegate>)pEventDelegate error: (NSError**)error;

/**
* <b>This API is experimental and may be change or removed in future releases</b>
* Do not use.
*/ 

-(void) notify: (nullable NSString*)eventGroup data: (nullable NSString*)data dataSize: (NSUInteger)dataSize dataType: (GnEventDataType)dataType error: (NSError**)error NS_REFINED_FOR_SWIFT;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnEventSubscription_h_ */

