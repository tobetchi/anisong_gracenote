/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnBuffer_h_
#define _GnBuffer_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"





/**
* GnBuffer
*/
@interface GnBuffer : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* Construct an empty GnBuffer object
*/ 

-(nullable INSTANCE_RETURN_TYPE) init;

/**
* GnBuffer
*/
-(nullable INSTANCE_RETURN_TYPE) init:(NSData*)data ;

/**
* size
*/
-(NSUInteger) size;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnBuffer_h_ */

