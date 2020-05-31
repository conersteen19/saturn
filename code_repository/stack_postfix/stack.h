/*
 * Conner Steenrod
 * cts4cv
 * 2/6/20
 * stack.h (Modified from List.h)
 */
#ifndef STACK_H
#define STACK_H

#include "ListNode.h"
#include <iostream>
using namespace std;

class stack {
	public:
    		stack();
    		~stack();
    		bool empty() const;
		void push(int x);
		void pop();
		int top();
    
	private:
		ListNode *head, *tail; 
};
#endif
