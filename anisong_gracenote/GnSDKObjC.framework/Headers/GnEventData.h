/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnEventData_h_
#define _GnEventData_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEvent.h"
#import "GnEnums.h"




/**
* <b>This class is experimental and may be change or removed in future releases</b>
* Event Data can be accessed in GnSubscriptionEventsDelegate 
*/ 

@interface GnEventData : NSObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* <b>This API is experimental and may be change or removed in future releases</b>
*  Event type
*  @return Event type
*/ 

-(nullable NSString*) eventType: (NSError**)error;

/**
* <b>This API is experimental and may be change or removed in future releases</b>
*  Event group
*  @return Event group
*/ 

-(nullable NSString*) eventGroup: (NSError**)error;

/**
* <b>This API is experimental and may be change or removed in future releases</b>
*  Event data type
*  @return Event data type
*/ 

-(GnEventDataType) dataType: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* <b>This API is experimental and may be change or removed in future releases</b>
*  Event data in XML format
*  @return XML format string
*/ 

-(nullable NSString*) dataXml: (NSError**)error;

/**
* <b>This API is experimental and may be change or removed in future releases</b>
*  Event data in JSON format
*  @return JSON format string
*/ 

-(nullable NSString*) dataJson: (NSError**)error;

/**
* <b>This API is experimental and may be change or removed in future releases</b>
*  Event data in default format 
*  @return default format string
*/ 

-(nullable NSString*) dataDefault: (NSError**)error;

/**
* <b>This API is experimental and may be change or removed in future releases</b>
*  Event data in GnDataObject format 
*  @return GnDataObject
*/ 

-(nullable GnEvent*) dataObject: (NSError**)error;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnEventData_h_ */

