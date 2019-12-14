/*
 * overhead.cpp
 *
 *  Created on: 11.12.2019
 *      Author: Jens Schröder
 */

#include <iostream>
#include "stopwatch.hpp"

#define MEASURETIME(description, repetitions, instructions2test)sw.start(); \
	for(int i = 0; i < repetitions; i++) { instructions2test;} \
	std::cout << "My computer requires " << sw.stop() << " seconds to execute " << description << " "  << repetitions << " times" << std::endl;

class StaticBase {

public:
	static int sb_int;
	static void myFunc() {
		++sb_int;
#ifdef VERBOSE
		std::cout << "Called " << "StaticBase" << "::" << __func__ << std::endl;
#endif
	}
};

int StaticBase::sb_int = 0;

class PureBase {

private:
	int pb_int;

public:
	PureBase() {
	}
	void myFunc() {
		++this->pb_int;
#ifdef VERBOSE
std::cout << "Called " << typeid(*this).name() << "::"
<< __func__ << std::endl;
#endif
	}

};

class VirtBase {

	int vb_int;

public:
	VirtBase() {
	}

	void nvFunc() {
		++this->vb_int;
#ifdef VERBOSE
std::cout << "Called " << typeid(*this).name() << "::"
<< __func__ << std::endl;
#endif
	}

	virtual void virtFunc() {
		++this->vb_int;
#ifdef VERBOSE
std::cout << "Called " << typeid(*this).name() << "::"
<< __func__ << std::endl;
#endif
	}
};

class VirtDer: public VirtBase {

	int vd_int;

public:
	void myFunc() {
		++this->vd_int;
#ifdef VERBOSE
std::cout << "Called " << typeid(*this).name() << "::"
<< __func__ << std::endl;
#endif
	}
	void virtFunc() {
		++this->vd_int;
#ifdef VERBOSE
std::cout << "Called " << typeid(*this).name() << "::"
<< __func__ << std::endl;
#endif
	}
};

int main(void) {
	PureBase pure;
	VirtBase vbase;
	VirtDer vder;
	PureBase *ppure = new PureBase();
	VirtBase *pvbase = new VirtBase();
	VirtDer *pvder = new VirtDer();
	VirtBase *pvbaseder = pvder;

	// 1.Static member functions
	StaticBase::myFunc();

	pure.myFunc();

	vbase.nvFunc();
	vbase.virtFunc();

	vder.myFunc();
	vder.nvFunc();
	vder.virtFunc();

	ppure->myFunc();

	pvbase->nvFunc();
	pvbase->virtFunc();

	pvder->nvFunc();
	pvder->myFunc();
	pvder->virtFunc();

	pvbaseder->nvFunc();
	pvbaseder->virtFunc();

	StopWatch sw;

#ifdef TASK02
	int t = 50000000;

	MEASURETIME("StaticBse::myFunc()",t, StaticBase::myFunc())

	MEASURETIME("pure.myFunc()", t, pure.myFunc())
	MEASURETIME("ppure->myFunc()", t, ppure->myFunc())
	MEASURETIME("vder.myFunc()", t, vder.myFunc())
	MEASURETIME("pvder->myFunc()", t, pvder->myFunc())

	MEASURETIME("vbase.nvFunc()", t, vbase.nvFunc())
	MEASURETIME("pvbase->nvFunc()", t, pvbase->nvFunc())
	MEASURETIME("vder.nvFunc()", t, vder.nvFunc())
	MEASURETIME("pvder->nvFunc()", t, pvder->nvFunc())
	MEASURETIME("pvbaseder->nvFunc()", t, pvbaseder->nvFunc())

	MEASURETIME("vbase.virtFunc()", t, vbase.virtFunc())
	MEASURETIME("pvbase->virtFunc()", t, pvbase->virtFunc())
	MEASURETIME("vder.virtFunc()", t, vder.virtFunc())
	MEASURETIME("pvder->virtFunc()", t, pvder->virtFunc())
	MEASURETIME("pvbaseder->virtFunc()", t, pvbaseder->virtFunc())


#endif

#ifdef TASK03
	// ziel ist es mit pvbaseder die nicht-virtuelle methode von VirtDer
	// aufzurufen mit Casts. Dynamic & static cast.
	// pvbaseder ist vom Typ VirtBase
	// pvder ist vom Typ VirtDer

	//  dynamic cast
	VirtDer *dynamicCast = dynamic_cast<VirtDer*>(pvbaseder);
	if (dynamicCast == NULL) {
		std::cout << "FICKEN" << std::endl;
	} else {
		MEASURETIME("dynamic", 50000000, dynamicCast->myFunc());
	}

	// static cast
	VirtDer *staticCast = static_cast<VirtDer*>(pvbaseder);
	if (staticCast == NULL) {
		std::cout << "FICKEN" << std::endl;
	} else {
		MEASURETIME("static", 50000000, staticCast->myFunc());
	}

#endif

}

