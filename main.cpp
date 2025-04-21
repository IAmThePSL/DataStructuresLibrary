#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include <iostream>

int main() {
    std::cout << "===== LinkedList Demo =====\n";
    LinkedList list;
    list.push_back(10);
    list.push_front(5);
    list.push_back(20);
    list.insert_at(1, 7);
    list.print();  // expected: 5 -> 7 -> 10 -> 20 -> nullptr

    list.remove_at(2);
    list.print();  // expected: 5 -> 7 -> 20 -> nullptr

    std::cout << "Value at index 1: " << list.at(1) << "\n"; // expected: 7
    std::cout << "Size: " << list.size() << "\n";            // expected: 3

    list.reverse();
    list.print();  // expected: 20 -> 7 -> 5 -> nullptr

    list.clear();
    std::cout << "Cleared. Is empty? " << (list.is_empty() ? "Yes" : "No") << "\n"; // expected: Yes



    
    std::cout << "\n===== Stack Demo =====\n";
    Stack stack;
    stack.push(100);
    stack.push(200);
    stack.push(300);
    stack.print(); // expected: Top -> 300 -> 200 -> 100 -> nullptr

    std::cout << "Top element: " << stack.top() << "\n"; // expected: 300

    stack.pop();
    stack.print(); // expected: Top -> 200 -> 100 -> nullptr

    std::cout << "Is empty? " << (stack.is_empty() ? "Yes" : "No") << "\n"; // expected: No
    std::cout << "Size: " << stack.size() << "\n"; // expected: 2

    stack.pop();
    stack.pop();

    std::cout << "After popping all: Is empty? " << (stack.is_empty() ? "Yes" : "No") << "\n"; // expected: Yes

    // !!!!! UNCOMMENT TO TEST ERROR CASE !!!!!
    // stack.pop(); // Should throw runtime_error




    std::cout << "\n===== Queue Demo =====\n";
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();

    std::cout << "Front: " << q.front() << "\n";
    q.dequeue();
    q.print();

    std::cout << "Is empty? " << (q.is_empty() ? "Yes" : "No") << "\n";
    std::cout << "Size: " << q.size() << "\n";

    q.dequeue();
    q.dequeue();
    std::cout << "After dequeuing all: Is empty? " << (q.is_empty() ? "Yes" : "No") << "\n";
    
    return 0;
}