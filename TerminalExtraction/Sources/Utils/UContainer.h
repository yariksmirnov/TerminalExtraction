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
        
        UContainer();
        UContainer(int baseSize);
        ~UContainer();
        
        void remove(int index);
        bool removeObject(shared_ptr<T> object);
        void addObject(shared_ptr<T> object);
        int indexOf(shared_ptr<T> object);
        void clear();
        shared_ptr<T> objectAtIndex(int index);
        void sort(int (* pointer)(const void *, const void *), size_t size);
        int GetCount() { return _count; }
    };

    template <class T>
    UContainer<T>::UContainer():UContainer(100) {
    }
    
    template<class T>
    UContainer<T>::UContainer(int baseSize):_count(0) {
        _baseSize = baseSize;
        _array = (shared_ptr<T>*)malloc(sizeof(shared_ptr<T>)*_baseSize);// new shared_ptr<T>[_baseSize];
        _currentSize = _baseSize;
    }
    
    template <class T>
    UContainer<T>::~UContainer<T>() {
        clear();
        free(_array);
        //delete [] _array;
    }
    
    template <class T>
    void UContainer<T>::remove(int index) {
        if (index < _count) {
            shared_ptr<T> obj  = _array[index];
            obj.reset();
            
            _array[index] = _array[_count - 1];
            _array[_count - 1] = nullptr;
            _count--;
        }
    }
    
    template <class T>
    void UContainer<T>::clear() {
        for (int i = 0; i < _count; i++) {
            _array[i].reset();
        }
        _count = 0;
    }
    
    template <class T>
    bool UContainer<T>::removeObject(shared_ptr<T> object) {
        for (int i = 0; i < _count; i++) {
            if (_array[i] == object) {
                remove(i);
                return true;
            }
        }
        return false;
    }
    
    template <class T>
    void UContainer<T>::addObject(shared_ptr<T> object) {
        if (_count == _currentSize) {
            shared_ptr<T> *tmp = _array;
            
            _array = (shared_ptr<T>*)malloc(sizeof(shared_ptr<T>)*(_currentSize + _baseSize));// new shared_ptr<T>[_currentSize + _baseSize];
            memcpy(_array, tmp, sizeof(shared_ptr<T>)*_currentSize);
            _currentSize += _baseSize;
            free(tmp);
        }
        _array[_count] = object;
        _count ++;
    }
    
    template <class T>
    shared_ptr<T> UContainer<T>::objectAtIndex(int index) {
        return _array[index];
    }
    
    template <class T>
    void UContainer<T>::sort(int (*pointer)(const void *, const void *), size_t size) {
        qsort(_array, _count, size, pointer);
    }
    
}

#endif /* defined(__TerminalExtraction__UContainer__) */
