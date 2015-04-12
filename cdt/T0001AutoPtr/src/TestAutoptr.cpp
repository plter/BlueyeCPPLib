//
//  TestAutoptr.cpp
//  BlueyeCPPLib
//
//  Created by plter on 4/12/15.
//  Copyright (c) 2015 plter. All rights reserved.
//


#include <autoptr/autoptr.hpp>
#include <stdio.h>

class Hello:public blueye::AutoptrObject {

public:
	void sayHello(){
		printf("Hello autoptr\n");
	}

	virtual ~Hello(){
		printf("delete Hello\n");
	}
};


int main(){
	blueye::autoptr<Hello> hi(new Hello());
	hi->sayHello();

	blueye::autoptr<Hello> hi1(hi);
	return 0;
}
