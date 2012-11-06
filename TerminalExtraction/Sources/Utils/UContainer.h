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
    
    using namespace std;
    
    template<class T>
    class UContainer {
        
        shared_ptr<T> *_array;
        
        int         _baseSize;
        int         _count;
        int         _currentSize;
    
    public:
        
        UContainer(int baseSize);
        ~UContainer();
        
        void remove(int index);
        void removeObject(shared_ptr<T> object);
        void addObject(shared_ptr<T> object);
        int indexOf(shared_ptr<T> object);
        void clear();
        shared_ptr<T> objectAtIndex(int index);
        void sortWithSize(shared_ptr<T> pointer, size_t size);
    };
}


#endif /* defined(__TerminalExtraction__UContainer__) */
