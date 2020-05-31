/*
 * Conner Steenrod
 * cts4cv
 * 2/3/20
 * postfixCalculator.cpp
 */

#include "postfixCalculator.h"
using namespace std;

postfixCalculator::postfixCalculator(){
	stack s;
}

postfixCalculator::~postfixCalculator(){
}

void postfixCalculator::pushNum(int x){
	s.push(x);
}

void postfixCalculator::add(){
	int one = s.top();
	s.pop();
	int two = s.top();
	s.pop();
	s.push(one + two);
}

void postfixCalculator::subtract(){
	int one = s.top();
	s.pop();
	int two = s.top();
	s.pop();
	s.push(two - one);
}

void postfixCalculator::multiply(){
	int one = s.top();
	s.pop();
	int two = s.top();
	s.pop();
	s.push(one * two);
}

void postfixCalculator::divide(){
	int one = s.top();
	s.pop();
	int two = s.top();
	s.pop();
	s.push(two / one);
}

int postfixCalculator::getTopVal(){
	return s.top();
}

void postfixCalculator::negate(){
	int neg = s.top();
	s.pop();
	s.push(-1 * neg);
}
