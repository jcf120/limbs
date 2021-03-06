//
//  AppDelegate.h
//  Limbs
//
//  Created by Jocelyn Clifford-Frith on 01/06/2013.
//  Copyright (c) 2013 Jocelyn Clifford-Frith. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "OpenGLView.h"

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet OpenGLView *openGLView;
- (IBAction)buttonPush:(id)sender;

@end
