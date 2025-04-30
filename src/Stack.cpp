/**
 * Stack Implementation (Using Singly Linked List)
 * 
 * This file implements a LIFO stack using a LinkedList internally, with the following:
 * 
 *  DATA MEMBERS:
 *  - LinkedList list: Underlying list that stores stack elements.
 * 
 *  BASIC OPERATIONS:
 *  - push(value): Add an element to the top of the stack.
 *  - pop(): Remove the element from the top of the stack.
 *  - top(): Return the element at the top without removing it.
 * 
 *  INSPECTION & INFO:
 *  - is_empty(): Check if the stack is empty.
 *  - size(): Return the number of elements in the stack.
 *  - contains(value): Check if a value exists in the stack.
 * 
 *  TRANSFORMATIONS:
 *  - clear(): Reset the stack to empty.
 *  - reverse(): Reverse the order of elements in the stack.
 *  - equals(other): Check if two stacks are identical in content and order.
 *  - clone(): Return a deep copy of the stack with the same order.
 *  - to_vector(): Return a std::vector of the stack's elements.
 * 
 *  EXTRAS:
 *  - print(): Print the stack from top to bottom.
 */

#include "Stack.hpp"
#include <stdexcept>
#include <vector>

//Initializes an empty stack
Stack::Stack() {}

void Stack::push(int value) {
    list.push_front(value);
}

void Stack::pop() {
    if(is_empty()) throw std::runtime_error("Stack is empty");
    list.pop_and_return_front();
}

int Stack::top() const {
    if(is_empty()) throw std::runtime_error("Stack is empty");
    return list.at(0);
}

bool Stack::is_empty() const {
    return list.is_empty();
}

int Stack::size() const {
    return list.size();
}

void Stack::print() const {
    std::cout << "Top -> ";
    list.print();
}

void Stack::clear() {
    list.clear();
}

bool Stack::contains(int value) const {
    return list.contains(value);
}

bool Stack::equals(const Stack& other) const {
    return list.equals(other.list);
}

//Returns a deep copy of the stack with the same element order
Stack Stack::clone() const {
    Stack cloned;
    std::vector<int> elements = list.to_vector();

    //push in reverse order to preserve stack structure
    for(auto it = elements.rbegin(); it != elements.rend(); ++it){
        cloned.push(*it);
    }

    return cloned;
}

void Stack::reverse() {
    list.reverse();
}

std::vector<int> Stack::to_vector() const {
    return list.to_vector();
}
