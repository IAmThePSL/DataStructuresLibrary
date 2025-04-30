/**
 * Queue Implementation (Using Singly Linked List)
 * 
 * This file implements a FIFO queue using a LinkedList internally, with the following:
 * 
 *  DATA MEMBERS:
 *  - LinkedList list: Underlying list that stores queue elements.
 * 
 *  BASIC OPERATIONS:
 *  - enqueue(value): Add an element to the back of the queue.
 *  - dequeue(): Remove the element from the front of the queue.
 *  - front(): Return the element at the front without removing it.
 * 
 *  INSPECTION & INFO:
 *  - is_empty(): Check if the queue is empty.
 *  - size(): Return the number of elements in the queue.
 *  - contains(value): Check if a value exists in the queue.
 * 
 *  TRANSFORMATIONS:
 *  - clear(): Reset the queue to empty.
 *  - reverse(): Reverse the order of elements in the queue.
 *  - equals(other): Check if two queues are identical in content and order.
 *  - clone(): Return a deep copy of the queue.
 *  - to_vector(): Return a std::vector of the queue's elements.
 * 
 *  EXTRAS:
 *  - enqueue_front(value): Add an element to the front (like a deque).
 *  - print(): Print the queue from front to back.
 */

#include "Queue.hpp"
#include <stdexcept>
#include <iostream>

Queue::Queue() {}

void Queue::enqueue(int val){
	list.push_back(val);
}

void Queue::dequeue(){
	if(is_empty()) throw std::runtime_error("Queue is empty");
	list.pop_and_return_front();
}

int Queue::front() const{
	if(is_empty()) throw std::runtime_error("Queue is empty");
	return list.at(0); //front is index 0
}

bool Queue::is_empty() const{
	return list.is_empty();
}

int Queue::size() const{
	return list.size();
}

void Queue::print() const{
	std::cout << "Front -> ";
	list.print();
}

//reset the queue
void Queue::clear(){
	list.clear();
}

//check if value exists
bool Queue::contains(int value) const{
	return list.contains(value);
}

//compare two queues
bool Queue::equals(const Queue& other) const{
	return this->list.equals(other.list);
}

//return a copy
Queue Queue::clone() const{
	Queue copy;
	copy.list = list.clone();
	return copy;
}

//convert to vector
std::vector<int> Queue::to_vector() const{
	return list.to_vector();
}

//add to front (deque style)
void Queue::enqueue_front(int value){
	list.push_front(value);
}

//reverse the queue
void Queue::reverse(){
	list.reverse();
}
