/*
 * Conner Steenrod
 * cts4cv
 * 1/25/20
 * ListItr.cpp
 */

#include <iostream>
#include "ListItr.h"
using namespace std;

ListItr::ListItr(){
	current = NULL;
}

ListItr::ListItr(ListNode* theNode){
	current = theNode;
}

bool ListItr::isPastEnd() const{
	if (current->next == NULL){
		return true;
	}
	else {
		return false;
	}
}

bool ListItr::isPastBeginning() const{
	if (current->previous == NULL){
		return true;
	}
	else {
		return false;
	}
}

void ListItr::moveForward(){
	current = current->next;
}

void ListItr::moveBackward(){
	current = current->previous;
}

int ListItr::retrieve() const{
	return current->value;
}
