#include "Queue.hpp"
#include <stdexcept>
#include <iostream>

Queue::Queue() {}

void Queue::enqueue(int val) {
    list.push_back(val);
}

void Queue::dequeue() {
    if (is_empty()) throw std::runtime_error("Queue is empty");
    list.pop_and_return_front();
}

int Queue::front() const {
    if (is_empty()) throw std::runtime_error("Queue is empty");
    return list.at(0); //front is index 0
}

bool Queue::is_empty() const {
    return list.is_empty();
}

int Queue::size() const {
    return list.size();
}

void Queue::print() const {
    std::cout << "Front -> ";
    list.print();
}
