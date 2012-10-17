//
//  GLSurface.m
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/18/12.
//
//

#import "GLSurface.h"
#import <OpenGLES/EAGL.h>
#import <OpenGLES/EAGLDrawable.h>
#import <QuartzCore/QuartzCore.h>

@implementation GLSurface

+ (Class)layerClass {
    return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        NSLog(@"Initializing iOS GL Surface");
        CAEAGLLayer *eaglLayer = (CAEAGLLayer *)self.layer;
        
        eaglLayer.opaque = YES;
        eaglLayer.drawableProperties = [NSDictionary dictionaryWithObjectsAndKeys:
                                        [NSNumber numberWithBool:YES], kEAGLDrawablePropertyRetainedBacking,
                                        kEAGLColorFormatRGB565, kEAGLDrawablePropertyColorFormat, nil];

        
        _glContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
        
        NSAssert(_glContext, @" OpenGL ES 2.0 API Support required ");
        
        [EAGLContext setCurrentContext:_glContext];
        
    }
    return self;
}

- (void)dealloc {
    
    [EAGLContext setCurrentContext:nil];
    [_glContext release];
    _glContext = nil;
    
    [super dealloc];
}

@end
