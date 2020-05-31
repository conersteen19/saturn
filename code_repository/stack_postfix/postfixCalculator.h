/*
 * Conner Steenrod
 * cts4cv
 * 2/3/20
 * postfixCalculator.h
 */

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H


#include <iostream>
#include "stack.h"
using namespace std;

class postfixCalculator {
	public:
		postfixCalculator();
		~postfixCalculator();
		void pushNum(int x);
		void add();
		void subtract();
		void multiply();
		void divide();
		void negate();
		int getTopVal();
	private:
		stack s;

};

#endif
