//
//  Sys.c
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/15/12.
//
//

#include <stdio.h>
#include "stdarg.h"
#include <strings.h>
#include "Sys.h"
#include "memory.h"

void SysLog(const char * args, ...) {
    va_list list;
    va_start(list, args);
    size_t sz = strlen(args) + 20;
    char *string = (char *)malloc(sz);
    sprintf(string, "TEEngine: %s\n", args);
    printf(string, list);
    free(string);
}

void SysLog(int interval , const char *args, ...) {
    static int _interval = -1;
    if (_interval < 0) {
        _interval = interval;
    }
    
    if (_interval > 0) {
        va_list list;
        va_start(list, args);
        SysLog(args, list);
        _interval--;
    } else
        _interval = interval;
}