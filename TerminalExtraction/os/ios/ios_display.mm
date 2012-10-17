//
//  ios_display.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/18/12.
//
//

#include "ios_display.h"
#import "AppDelegate.h"
#import "ViewController.h"

void iosDisplay::InitGLSurface() {
    
    UIScreen *iphoneScreen = [UIScreen mainScreen];
    
    UIWindow *window = [[UIWindow alloc] initWithFrame:iphoneScreen.bounds];
    window.rootViewController = [ViewController instance];
    [window makeKeyAndVisible];
    
}