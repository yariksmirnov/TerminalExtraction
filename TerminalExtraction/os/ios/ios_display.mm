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

iosDisplay::iosDisplay() {
    m_obScreenSize.width = m_obDesignResolutionSize.width = [UIScreen mainScreen].bounds.size.width;
    m_obScreenSize.height = m_obDesignResolutionSize.height = [UIScreen mainScreen].bounds.size.height;
}

void iosDisplay::InitGLSurface(unsigned int depthFormat, unsigned int pixelFormat) {
    
    UIScreen *iphoneScreen = [UIScreen mainScreen];
    
    UIWindow *window = [[UIWindow alloc] initWithFrame:iphoneScreen.bounds];
    
    [ViewController instance].pixelFormat = pixelFormat;
    [ViewController instance].depthFormat = depthFormat;
    
    window.rootViewController = [ViewController instance];
    [window makeKeyAndVisible];
    
}

GLfloat iosDisplay::GetDisplayHeight() {
    return [[ViewController instance] view].layer.bounds.size.height * [UIScreen mainScreen].scale;
}

GLfloat iosDisplay::GetDisplayWidth() {
    return [[ViewController instance] view].layer.bounds.size.width * [UIScreen mainScreen].scale;
}

void iosDisplay::SwapBuffers() {
    EAGLContext* context = [EAGLContext currentContext];
    
    [context presentRenderbuffer:GL_RENDERBUFFER];
}

void iosDisplay::swapBuffers() {
    //SwapBuffers();
}

bool iosDisplay::isOpenGLReady() {
    return [ViewController instance].view != nil;
}

bool iosDisplay::setContentScaleFactor(float contentScaleFactor) {
    //[[ViewController instance].view setNeedsLayout];
    
    return true;
}

void iosDisplay::end() {
    // do nothing;
}

void iosDisplay::setIMEKeyboardState(bool bOpen) {
    if (bOpen) {
        [[ViewController instance].view becomeFirstResponder];
    } else
        [[ViewController instance].view resignFirstResponder];
}