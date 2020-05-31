/*
 * Filename: ListNode.h
 * Description: ListNode class definition
 */

#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class ListNode {
public:

    	ListNode();                // Constructor
	~ListNode(); 			//Destructor

private:
    int value;                 // The value of the node!
    ListNode *next, *previous; // For doubly linked lists

    // List needs to be able to access/change ListNode's next and
    // previous pointers
    friend class stack;

};

#endif
