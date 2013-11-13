//
//  NSInvocation-AMFExtensions.h
//  Supertrump
//
//  Created by Marc Bauer on 26.02.09.
//  Copyright 2009 nesiumdotcom. All rights reserved.
//

#ifndef __NSINVOCATION_AMFEXTENSIONS_H__
#define __NSINVOCATION_AMFEXTENSIONS_H__


#import <Foundation/Foundation.h>


@interface NSInvocation (AMFExtensions)

- (id)returnValueAsObject;

@end


#endif