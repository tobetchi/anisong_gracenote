/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnSubscriptionEventsDelegate_h_
#define _GnSubscriptionEventsDelegate_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEventData.h"


@class GnEventData;


NS_ASSUME_NONNULL_BEGIN

@protocol GnSubscriptionEventsDelegate <NSObject>

@required

/**
* Provides event data can retrieve published information
* @param GnEventData		Event data
*/ 

-(void) recievedEvents: (nonnull GnEventData*)receivedEventData;


@end

NS_ASSUME_NONNULL_END



#endif /* _GnSubscriptionEventsDelegate_h_ */

