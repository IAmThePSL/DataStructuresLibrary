#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "LinkedList.hpp"

class Queue {
private:
	LinkedList list;

public:
	Queue();

	void enqueue(int value);			//add to back
	void dequeue();					//remove from front
	int front() const;				//peek front
	bool is_empty() const;
	int size() const;
	void print() const;

	void clear();					//reset the queue
	bool contains(int value) const;			//check if value exists
	bool equals(const Queue& other) const; 		//compare two queues
	Queue clone() const;				//return a copy
	std::vector<int> to_vector() const; 		//convert to vector
	void enqueue_front(int value);			//add to front (deque style)
	void reverse();					//reverse the queue
};

#endif
