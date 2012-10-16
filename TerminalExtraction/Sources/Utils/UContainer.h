//
//  UContainer.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/16/12.
//
//

#ifndef __TerminalExtraction__UContainer__
#define __TerminalExtraction__UContainer__

#include <iostream>

namespace Utils {
    
    class UContainer {
        
        void        *_array;
        
        int         _baseSize;
        int         _count;
        int         _currentSize;
    
    public:
        
        UContainer(int baseSize);
        
        void remove(int index);
        void removeObject(void * object);
        void addObject(void * object);
        int indexOf(void * object);
        void clear();
        void * objectAtIndex(int index);
        void sortWithSize(void * pointer, size_t size);
    };
}


#endif /* defined(__TerminalExtraction__UContainer__) */
