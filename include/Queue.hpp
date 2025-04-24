#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "LinkedList.hpp"

class Queue {
private:
	LinkedList list;

public:
	Queue();

	void enqueue(int value);		//add to back
	void dequeue();					//remove from front
	int front() const;				//peek front
	bool is_empty() const;
	int size() const;
	void print() const;
};

#endif
