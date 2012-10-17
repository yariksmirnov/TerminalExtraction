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


@implementation AppDelegate

- (void)initEnviroment {
    engine->Init();
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
