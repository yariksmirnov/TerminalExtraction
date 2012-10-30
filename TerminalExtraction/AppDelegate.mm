//
//  AppDelegate.m
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/16/12.
//
//

#import "AppDelegate.h"
#include "TEEngine.h"
#include "Utils.h"

#import <QuartzCore/QuartzCore.h>

@interface AppDelegate ()

- (void)frameCallback:(CADisplayLink *)link;

@end


@implementation AppDelegate

- (void)initEnviroment {
    
    CADisplayLink *link = [CADisplayLink displayLinkWithTarget:self selector:@selector(frameCallback:)];
    [link addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
    
    engine->Init();
}

- (void)frameCallback:(CADisplayLink *)link {
    
    engine->RunLoop(link.timestamp);
    
}


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    [self initEnviroment];
    
    return YES;
}

int main(int argc, char *argv[])
{
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}



@end
