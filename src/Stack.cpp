#include "Stack.hpp"
#include <stdexcept>
#include <vector>

/**
 * Initializes an empty stack.
 */
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

/**
 * Returns a deep copy of the stack with the same element order.
 */
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
