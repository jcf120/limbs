//
//  OpenGLView.m
//  Limbs
//
//  Created by Jocelyn Clifford-Frith on 01/06/2013.
//  Copyright (c) 2013 Jocelyn Clifford-Frith. All rights reserved.
//

#import "OpenGLView.h"

@implementation OpenGLView

- (void)prepareOpenGL
{
    // this sets swap interval for double buffering
    GLint swapInt = 1;
    [[self openGLContext] setValues:&swapInt forParameter:NSOpenGLCPSwapInterval];
    
    // this enables alpha in the frame buffer
    GLint opaque = 0;
    [[self openGLContext] setValues:&opaque forParameter:NSOpenGLCPSurfaceOpacity];
}

- (void)drawRect:(NSRect)dirtyRect {
    
    [[self openGLContext] flushBuffer];
    
    int err;
    if ((err = glGetError()) != 0)
        NSLog(@"glGetError(): %d", err);
}

@end
