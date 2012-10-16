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

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    
    UContainer container = UContainer(10);
    
    return YES;
}



@end
