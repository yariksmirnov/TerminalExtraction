//
//  UContainer.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/16/12.
//
//

#include "UContainer.h"

using namespace Utils;


template<class T>
UContainer<T>::UContainer(int baseSize) {
    _baseSize = baseSize;
    _array = new shared_ptr<T>[_baseSize];
}

template <class T>
UContainer<T>::~UContainer<T>() {
    delete _array;
}

