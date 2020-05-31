/*
 * Conner Steenrod
 * cts4cv
 * 1/25/20
 * ListNode.cpp
 */


#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode::ListNode(){
	value = 0;
	next = NULL;
	previous = NULL;
}

ListNode::~ListNode(){
	if (next != NULL){
		delete next;
	}
}
