/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAsset_h_
#define _GnAsset_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnEnums.h"




/**
* Assets for content (cover art, biography etc)
*
* For additional information about the underlying data model, see
* the "Data Models" topic in the Help system.
*
*/ 

@interface GnAsset : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Asset dimension
*  @return Dimention string
*/ 

-(nullable NSString*) dimension;

/**
*  Asset Type
*  @return asset's mime type string
*/ 

-(nullable NSString*) type;

/**
*  Size of content asset in bytes
*  @return Size in bytes
*/ 

-(NSInteger) bytes;

/**
*  Pixel image size of asset as defined with a GnImageSize enum, such as kImageSize110 (110x110)
*  @return Image size
*/ 

-(GnImageSize) size;

/**
* @deprecated NB: This method has been marked as deprecated and will be removed from the next major release.
*      Use UrlHttp() or UrlHttps() instead.
*/ 

-(nullable NSString*) url;

/**
*  GNSDK url for retrieval of asset from Gracenote
*  @return URL
*/ 

-(nullable NSString*) urlGnsdk;

/**
*  HTTP url for retrieval of asset from Gracenote
*  @return URL
*/ 

-(nullable NSString*) urlHttp;

/**
*  HTTPS url for retrieval of asset from Gracenote
*  @return URL
*/ 

-(nullable NSString*) urlHttps;

/**
* ImageDataBase64
*/
-(nullable NSString*) imageDataBase64;


NS_ASSUME_NONNULL_END

@end


@interface GnAssetEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnAssetBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnAssetBlock)handler;

-(NSUInteger) count;

-(nullable GnAsset*) nextObject;

-(nullable GnAsset*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnAsset_h_ */

