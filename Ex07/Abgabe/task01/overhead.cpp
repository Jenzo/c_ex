/*
 * overhead.cpp
 *
 *  Created on: 11.12.2019
 *  Author: Jens Schr�der
 */

#include <iostream>
#include <typeinfo>

/**
 * Only include stopwatch.hpp if preprocessor variable TASK02 or TASK03
 * are defined.
 */
#if defined TASK02 || defined TASK03
	#include "stopwatch.hpp"
#endif


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
	/**
	 * Constructor for StaticBase class
	 */
	StaticBase() {
	}
	/**
	 * static int var
	 */
	static int sb_int;

	/**
	 * static void myFunc() to pre-increment 'sb_int'
	 * If preprocessor variable VERBOSE is defined, then include print
	 */
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
	/**
	 * private int var
	 */
	int pb_int;

public:
	/**
	 * PureBase constructor with initializer list to set pb_int = 0 per default
	 */
	PureBase() :
			pb_int(0) {
	}

	/**
	 * void myFunc() to pre-increment 'pb_int'
	 * If preprocessor variable VERBOSE is defined, then include print
	 */
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

 /**
  * private vb_int
	*/
	int vb_int;

public:
	/**
	 * VirtBase constructor with initializer list to set vb_int = 0 per default
	 */
	VirtBase() :
			vb_int(0) {
	}

/**
 * void myFunc() to pre-increment 'vb_int'
 * If preprocessor variable VERBOSE is defined, then include print
 */
void nvFunc() {
		++this->vb_int;
#ifdef VERBOSE
std::cout << "Called " << typeid(*this).name() << "::"
<< __func__ << std::endl;
#endif
	}

	/**
	 * virtual void myFunc() to pre-increment 'vb_int'
	 * If preprocessor variable VERBOSE is defined, then include print
	 */
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

 /**
  * private int vd_int
	*/
	int vd_int;

public:
 /**
  * VirtDer constructor with initializer list to set vd_int = 0 per default
	*/
	VirtDer() :
			vd_int(0) {

	}

	/**
	* void myFunc() to pre-increment 'vd_int'
	* If preprocessor variable VERBOSE is defined, then include print
	*/
	void myFunc() {
		++this->vd_int;
#ifdef VERBOSE
std::cout << "Called " << typeid(*this).name() << "::"
<< __func__ << std::endl;
#endif
	}

	/*
	 * void myFunc() to pre-increment 'vd_int'.
	 * If preprocessor variable VERBOSE is defined, then include print
	 */
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
 * Predefined preprocessor variable 'TASK02' will include code for
 * task02 to measure processing time for distinct function calls.
 * Variable 'TASK03' will include code for task03 to measure processing time
 * for dynamic and static cast of pointer and function call.
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
	 * 1.group: static function call
	 * 2.group: non-virtual member function
	 * 3.group: virtual-member function
	 */

	// 1.group
	StaticBase::myFunc();

  // 2.group
	pure.myFunc();
	ppure->myFunc();
	vder.myFunc();
	pvder->myFunc();

	vbase.nvFunc();
	vder.nvFunc();
	pvbase->nvFunc();
	pvder->nvFunc();
	pvbaseder->nvFunc();

  // 3.group
	vbase.virtFunc();
	vder.virtFunc();
	pvbase->virtFunc();
	pvder->virtFunc();
	pvbaseder->virtFunc();

	/**
	 * TASK02
	 */
#ifdef TASK02
	StopWatch sw;
	int times = 50000000;

	MEASURETIME("StaticBse::myFunc()",times, StaticBase::myFunc())

	MEASURETIME("pure.myFunc()", times, pure.myFunc())
	MEASURETIME("ppure->myFunc()", times, ppure->myFunc())
	MEASURETIME("vder.myFunc()", times, vder.myFunc())
	MEASURETIME("pvder->myFunc()", times, pvder->myFunc())

	MEASURETIME("vbase.nvFunc()", times, vbase.nvFunc())
	MEASURETIME("vder.nvFunc()", times, vder.nvFunc())
	MEASURETIME("pvbase->nvFunc()", times, pvbase->nvFunc())
	MEASURETIME("pvder->nvFunc()", times, pvder->nvFunc())
	MEASURETIME("pvbaseder->nvFunc()", times, pvbaseder->nvFunc())

	MEASURETIME("vbase.virtFunc()", times, vbase.virtFunc())
	MEASURETIME("vder.virtFunc()", times, vder.virtFunc())
	MEASURETIME("pvbase->virtFunc()", times, pvbase->virtFunc())
	MEASURETIME("pvder->virtFunc()", times, pvder->virtFunc())
	MEASURETIME("pvbaseder->virtFunc()", times, pvbaseder->virtFunc())


#endif

	/**
	 * TASK 03
	 */
#ifdef TASK03
	StopWatch sw;
	int times = 50000000;

  // dynamic cast
	VirtDer *p_cast_virt_der = dynamic_cast<VirtDer*>(pvbaseder);
 	if (p_cast_virt_der == NULL) {
 		std::cout << "warning, dynamic cast must not be NULL!" << std::endl;
 	} else {
 		MEASURETIME("dynamic cast", times, p_cast_virt_der->nvFunc());
 	}

	// static cast
	VirtDer *staticCast = static_cast<VirtDer*>(pvbaseder);
	if (typeid(VirtDer*) != typeid(staticCast)) {
		std::cout << "warning, cast not possible!" << std::endl;
	} else {
		MEASURETIME("static cast", times, staticCast->nvFunc());
	}

#endif

}
