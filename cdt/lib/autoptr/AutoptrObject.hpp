//
//  AutoptrObject.hpp
//  BlueyeCPPLib
//
//  Created by plter on 4/12/15.
//  Copyright (c) 2015 plter. All rights reserved.
//

#ifndef BlueyeCPPLib_AutoptrObject_hpp
#define BlueyeCPPLib_AutoptrObject_hpp

namespace blueye {
    class AutoptrObject{
    public:
        AutoptrObject(){
            _retainCount = 0;
        }
        
        virtual ~AutoptrObject(){
        }
        
        inline int getRetainCount() {
            return _retainCount;
        }
        
        inline void retain(){
            _retainCount++;
        }
        
        inline void release(){
            _retainCount--;
            
            if (_retainCount<=0) {
                delete this;
            }
        }
        
    private:
        int _retainCount;
    };
}

#endif
