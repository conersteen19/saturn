/*
 * Conner Steenrod
 * cts4cv
 * 2/6/20
 * stack.cpp (modified from List.cpp)
 */
#include <iostream>
#include "stack.h"
using namespace std;

stack::stack(){
	head = new ListNode();
	tail = new ListNode();
	head->next = tail;
	tail->previous= head;
}

stack::~stack(){
	delete head;
}
bool stack::empty() const {
	if(head->next == tail){
		return true;
	}
	else {
		return false;
	}
}

void stack::push(int x){
	ListNode *newNode = new ListNode();
	newNode->value = x;
	ListNode *before = head;
	ListNode *after = head->next;
	before->next = newNode;
	newNode->previous = before;
	newNode->next = after;
	after->previous = newNode;
}

void stack::pop(){
	ListNode *toDel = head->next;
	ListNode *before = head;
	ListNode *after = toDel->next;	
	before->next = after;
	after->previous = before;
	toDel->next = NULL;
	delete toDel;
}

int stack::top(){
	return head->next->value;
}


