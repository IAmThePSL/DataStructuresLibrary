#include "Stack.hpp"
#include <stdexcept>

Stack::Stack() {}

/**
 * Pushes a value onto the top of the stack
 * Internally inserts at the front of a linked list
 */
void Stack::push(int value) {
	list.push_front(value); //stack top is front of list
}

/**
 * Removes the value from the top of the stack
 * Throws an error if the stack is empty
 */
void Stack::pop(){
	if (is_empty()) throw std::runtime_error("Stack is empty");
	list.pop_front();
}

/**
 * Returns the value at the top of the stack
 * Throws an error if the stack is empty
 */
int Stack::top() const {
	if (is_empty()) throw std::runtime_error("Stack is empty");
	return list.at(0); //front is top
}

bool Stack::is_empty() const {
	return list.is_empty();
}

int Stack::size() const {
	return list.size();
}

/**
 * Pritns the stack contents in top-to-bottom order
 */

void Stack::print() const {
	std::cout << "Top -> ";
	list.print();
}