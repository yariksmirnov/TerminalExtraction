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
#include "PivotObject.h"
#include "cocos2d.h"
#import <QuartzCore/QuartzCore.h>

@interface AppDelegate ()

- (void)frameCallback:(CADisplayLink *)link;

@end

class MyClass {
    
    
public:
    int a;
    
    MyClass();
    ~MyClass();
};

MyClass::MyClass()
{
    cout << "I born" << endl;
}

MyClass::~MyClass()
{
    cout << "I die" << endl;
}


@implementation AppDelegate

- (void)initEnviroment {
    
    CADisplayLink *link = [CADisplayLink displayLinkWithTarget:self selector:@selector(frameCallback:)];
    [link addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
    
    engine->Init();
}

- (void)frameCallback:(CADisplayLink *)link {
    engine->RunLoop(link.duration);
}


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
//    {
//        
//        cout << sizeof(shared_ptr<PivotObject>);
//    
//        UContainer<MyClass> container = UContainer<MyClass>(10);
//        {
//            shared_ptr<MyClass> outptr;
//            {
//                shared_ptr<MyClass> ptr(new MyClass());
//                ptr->a = 10;
//                outptr = ptr;
//            }
//            container.addObject(outptr);
//        }
//        
//        
//        shared_ptr<MyClass> outptr = container.objectAtIndex(0);
//        cout <<"count=" <<container.GetCount() <<" item=" << outptr->a <<endl;
//        
//    }
    
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
