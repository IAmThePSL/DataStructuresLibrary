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
