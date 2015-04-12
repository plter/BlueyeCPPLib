//
//  autoptr.h
//  BlueyeCPPLib
//
//  Created by plter on 4/12/15.
//  Copyright (c) 2015 plter. All rights reserved.
//

#ifndef BlueyeCPPLib_autoptr_h
#define BlueyeCPPLib_autoptr_h

#include "AutoptrObject.hpp"

namespace blueye {
    template<class T>
    class autoptr final{
    public:
        autoptr(T * ptr){
            internalConstructor(ptr);
        }
        
        autoptr(blueye::autoptr<T> & source){
            internalConstructor(source._thePtr);
        }
        
        virtual ~autoptr(){
            if (_thePtr) {
                _thePtr->release();
            }
        }
        
        T* operator->(){
            return _thePtr;
        }
        
    private:
        T * _thePtr;
        
    private:
        void internalConstructor(T * ptr){
            _thePtr = ptr;
            _thePtr->retain();
        }
    };
}

#endif
