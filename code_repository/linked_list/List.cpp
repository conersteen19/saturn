/*
 * Conner Steenrod
 * cts4cv
 * 1/25/20
 * List.cpp
 */
#include <iostream>
#include "List.h"
using namespace std;

List::List(){
	head = new ListNode();
	tail = new ListNode();
	head->next = tail;
	tail->previous= head;
	count = 0;
}

List::~List(){
	delete head;
}


List::List(const List& source) {
	head=new ListNode();
	tail=new ListNode();
	head->next=tail;
	tail->previous=head;
	count=0;

	// Make a deep copy of the list
	ListItr iter(source.head->next);
	while (!iter.isPastEnd()) {
		insertAtTail(iter.retrieve());
		iter.moveForward();
	}
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
	if (this == &source) {
		// The two are the same list; no need to do anything
		return *this;
	} else {
		// Clear out anything this list contained
		// before copying over the items from the other list
		makeEmpty();
		// Make a deep copy of the list
		ListItr iter(source.head->next);
		while (!iter.isPastEnd()) {
			insertAtTail(iter.retrieve());
			iter.moveForward();
		}
	}
	return *this;
}


bool List::isEmpty() const {
	if(head->next == tail){
		return true;
	}
	else {
		return false;
	}
}

void List::makeEmpty(){
	ListNode *end = tail->previous;
	end->next = NULL;
	delete head->next;
	head->next = tail;
	tail->previous = head;
}

ListItr List::first(){
	ListItr first = ListItr(head->next);
	return first;
}

ListItr List::last(){
	ListItr last = ListItr(tail->previous);
	return last;
}

void List::insertAfter(int x, ListItr position){
	ListNode *newNode = new ListNode();
	newNode->value = x;
	ListNode *before = position.current;
	ListNode *after = position.current->next;
	before->next = newNode;
	newNode->previous = before;
	newNode->next = after;
	after->previous = newNode;
	count += 1;
}

void List::insertBefore(int x, ListItr position){
	ListNode *newNode = new ListNode();
	newNode->value = x;
	ListNode *before = position.current->previous;
	ListNode *after = position.current;
	before->next = newNode;
	newNode->previous = before;
	newNode->next = after;
	after->previous = newNode;
	count += 1;
}

void List::insertAtTail(int x){
	ListNode *newNode = new ListNode();
	newNode->value = x;
	ListNode *before = tail->previous;
	ListNode *after = tail;
	before->next = newNode;
	newNode->previous = before;
	newNode->next = after;
	after->previous = newNode;
	count += 1;
}

ListItr List::find(int x){
	ListItr itr = ListItr(head->next);
	while(itr.current != tail){
		if (itr.retrieve() == x){
			return itr;
		}
		itr.moveForward();
	}
	return itr;
}

void List::remove(int x){
	ListItr itr = find(x);
	if (itr.retrieve() == x){
		ListNode *before = itr.current->previous;
		ListNode *after = itr.current->next;
		before->next = after;
		after->previous = before;
	}
	itr.current->next = NULL;
	delete itr.current;	
	count -= 1;
}

int List::size() const {
	return count;
}

void printList(List& source, bool forward){
	if (forward){
		ListItr temp = source.first();
		ListItr *itr = &temp;
		while(!itr->isPastEnd()){
			cout << itr->retrieve() << " " << endl;
			itr->moveForward();
		}
	}
	else {
		ListItr temp = source.last();
		ListItr *itr = &temp;
		while(!itr->isPastBeginning()){
			cout << itr->retrieve() << " " << endl;
			itr->moveBackward();
		}
	}
}
