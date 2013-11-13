/*
 
    Project : GraniteDS iOS Client
    File    : GDSAsyncResponder.h
    Author  : Franck WOLFF
 
    ------------------------------------------------------------------------------

    GRANITE DATA SERVICES
    Copyright (C) 2011 GRANITE DATA SERVICES S.A.S.

    This file is part of Granite Data Services.

    Granite Data Services is free software; you can redistribute it and/or modify
    it under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    Granite Data Services is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE. See the GNU Library General Public License
    for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; if not, see <http://www.gnu.org/licenses/>.
 
*/

#ifndef __GDSASYNCRESPONDER_H__
#define __GDSASYNCRESPONDER_H__


#import <Foundation/Foundation.h>

@class GDSAbstractEvent;
@class GDSResultEvent;
@class GDSFaultEvent;


/**
 *
 *
 * @author Franck WOLFF
 */
@interface GDSAsyncResponder : NSObject {
    
    id m_target;
    SEL m_result;
    SEL m_fault;
    
    void (^m_resultCallback)(GDSResultEvent*);
    void (^m_faultCallback)(GDSFaultEvent*);
}

#pragma mark -
#pragma mark Properties

@property (readonly) id target;
@property (readonly) SEL result;
@property (readonly) SEL fault;
@property (readwrite, copy) void (^resultCallback)(GDSResultEvent*);
@property (readwrite, copy) void (^faultCallback)(GDSFaultEvent*);

#pragma mark -
#pragma mark Initialization

+ (id)responderWithTarget:(id)target result:(SEL)result fault:(SEL)fault;
+ (id)responderWithResult:(void(^)(GDSResultEvent*)) result fault:(void(^)(GDSFaultEvent*)) fault;
- (id)initWithTarget:(id)target result:(SEL)result fault:(SEL)fault;

#pragma mark -
#pragma mark Responder Selector Call

- (void)callWithEvent:(GDSAbstractEvent *)event;

@end


#endif

