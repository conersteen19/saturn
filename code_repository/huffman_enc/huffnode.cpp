/*
 * Conner Steenrod
 * cts4cv
 * 4/14/20
 * huffnode.cpp
 */

#include "huffnode.h"
using namespace std;

huffnode::huffnode(){
	left = 0;
	right = 0;
	freq = 0;
	val = 0;
}

huffnode::huffnode(char v, int f){
	left = 0;
	right = 0;
	freq = f;
	val = v;
}

huffnode::~huffnode(){
}
