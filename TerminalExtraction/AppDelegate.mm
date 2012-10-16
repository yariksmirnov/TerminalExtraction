//
//  AppDelegate.m
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/16/12.
//
//

#import "AppDelegate.h"

#include "Utils.h"


@implementation AppDelegate

- (void)initEnviroment {
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor blackColor];
    [self.window makeKeyAndVisible];
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
