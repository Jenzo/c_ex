/*
 * overhead.cpp
 *
 *  Created on: 11.12.2019
 *  Author: Jens Schr�der
 */

#include <iostream>
#include "stopwatch.hpp"

/**
 * Macro function to measure time for instructions to perform.
 *
 * @param description, a short description of operation to perform. should be a string.
 * @param repetitions, number of iterations 'instructions2test' are performed. should be an integer.
 * @param instructions2test, function calls or else to perform.
 */
#define MEASURETIME(description, repetitions, instructions2test)sw.start(); \
	for(int i = 0; i < repetitions; i++) { instructions2test;} \
	std::cout << "My computer requires " << sw.stop() << " seconds to execute " << description << " "  << repetitions << " times" << std::endl;

/**
 * StaticBase class
 */
class StaticBase {

public:
	StaticBase() {
	}
	static int sb_int;
	static void myFunc() {
		++sb_int;
#ifdef VERBOSE
		std::cout << "Called " << "StaticBase" << "::" << __func__ << std::endl;
#endif
	}
};

/**
 * StaticBase sb_int initialization, because static integer can't be initialized in class.
 */
int StaticBase::sb_int = 0;

/**
 * PureBase class
 */
class PureBase {

private:
	int pb_int;

public:
	PureBase() :
			pb_int(0) {
	}
	void myFunc() {
		++this->pb_int;
#ifdef VERBOSE
std::cout << "Called " << typeid(*this).name() << "::"
<< __func__ << std::endl;
#endif
	}

};

/**
 * VirtBase class
 */
class VirtBase {

	int vb_int;

public:
	VirtBase() :
			vb_int(0) {
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

/**
 * VirtDer class.
 * Inherits from VirtBase publicly.
 */
class VirtDer: public VirtBase {

	int vd_int;

public:

	VirtDer() :
			vd_int(0) {

	}
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

/**
 * @brief Main method to initialize and make all distinct function calls.
 *
 *
 *
 * @return integer as program exit code, but not set.
 */
int main(void) {
	PureBase pure;
	VirtBase vbase;
	VirtDer vder;
	PureBase *ppure = new PureBase();
	VirtBase *pvbase = new VirtBase();
	VirtDer *pvder = new VirtDer();
	VirtBase *pvbaseder = pvder;

	/**
	 * TASK 01
	 */
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

	/**
	 * TASK02
	 */
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

	/**
	 * TASK 03
	 */
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
