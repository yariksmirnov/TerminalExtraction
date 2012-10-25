//
//  ViewController.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/18/12.
//
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "GLSurface.h"

@interface ViewController : UIViewController {
@private
    GLSurface           *_glView;
}

+ (ViewController *)instance;

@end
