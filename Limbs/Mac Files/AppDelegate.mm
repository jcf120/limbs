//
//  AppDelegate.m
//  Limbs
//
//  Created by Jocelyn Clifford-Frith on 01/06/2013.
//  Copyright (c) 2013 Jocelyn Clifford-Frith. All rights reserved.
//

#import "AppDelegate.h"
#include "Renderer.h"

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application
}

- (IBAction)buttonPush:(id)sender {
    Renderer render;
    render.Render();
    [self.openGLView setNeedsDisplay:YES];
}
@end
