//
//  ViewController.m
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/18/12.
//
//

#import "ViewController.h"

ViewController      *_g_Controller = nil;

@interface ViewController ()

@end

@implementation ViewController

+ (ViewController *)instance {
    if (!_g_Controller) {
        _g_Controller = [[ViewController alloc] init];
    }
    return _g_Controller;
}

- (void)loadView {
    UIScreen *screen = [UIScreen mainScreen];
    
    self.view = [[GLSurface alloc] initWithFrame:screen.bounds andDepthFormat:_depthFormat andPixelFormat:_pixelFormat];
}

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)shouldAutorotate
{
    return YES;
}

- (NSUInteger)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskLandscape;
}

@end
