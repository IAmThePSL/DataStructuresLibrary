#pragma once
#include "LinkedList.hpp"

class Stack{
private:
	LinkedList list;

public:
	Stack();

	void push(int value);		//add to top
	void pop();					//remove top
	int top() const;			//peek at top
	bool is_empty() const;		//speaks for itself
	int size() const;			//also speaks for itself
	void print() const;
};