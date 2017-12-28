/*
 * Copyright (c) 2000-2017 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

#import <Foundation/Foundation.h>

@interface NSMutableArray (NSQueue)

-(void) enqueueObj:(NSData*) object;
-(id) dequeue;
-(NSArray*) dequeueObjects:(NSInteger) count;
-(void) enqueueObjects:(NSArray*) objects;

@end
