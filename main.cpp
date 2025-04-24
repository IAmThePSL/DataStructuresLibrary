#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include <iostream>
#include <vector>

int main() {
    std::cout << "===== LinkedList Demo =====\n";
    LinkedList list;
    list.push_back(10);
    list.push_front(5);
    list.push_back(20);
    list.insert_at(1, 7);
    list.print(); //expected: 5 -> 7 -> 10 -> 20 -> nullptr

    list.remove_at(2);
    list.print(); //expected: 5 -> 7 -> 20 -> nullptr

    std::cout << "Value at index 1: " << list.at(1) << "\n"; //expected: 7
    std::cout << "Size: " << list.size() << "\n"; //expected: 3

    list.reverse();
    list.print(); //expected: 20 -> 7 -> 5 -> nullptr

    list.clear();
    std::cout << "Cleared. Is empty? " << (list.is_empty() ? "Yes" : "No") << "\n"; //expected: Yes

    // ===== Stack Demo =====
    std::cout << "\n===== Stack Demo =====\n";
    Stack stack;
    stack.push(100);
    stack.push(200);
    stack.push(300);
    stack.print(); //expected: top -> 300 -> 200 -> 100 -> nullptr

    std::cout << "Top element: " << stack.top() << "\n"; //expected: 300

    stack.pop();
    stack.print(); //expected: top -> 200 -> 100 -> nullptr

    std::cout << "Is empty? " << (stack.is_empty() ? "Yes" : "No") << "\n"; //expected: No
    std::cout << "Size: " << stack.size() << "\n"; //expected: 2

    stack.pop();
    stack.pop();
    std::cout << "After popping all: Is empty? " << (stack.is_empty() ? "Yes" : "No") << "\n"; //expected: Yes

    // stack.pop(); //uncomment to test error: should throw std::runtime_error

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Contains 20? " << (stack.contains(20) ? "Yes" : "No") << "\n"; //expected: Yes
    std::cout << "Contains 50? " << (stack.contains(50) ? "Yes" : "No") << "\n"; //expected: No

    Stack copy;
    copy.push(10);
    copy.push(20);
    copy.push(30);
    std::cout << "Stacks equal? " << (stack.equals(copy) ? "Yes" : "No") << "\n"; //expected: Yes

    copy.pop();
    std::cout << "After modifying copy, equal? " << (stack.equals(copy) ? "Yes" : "No") << "\n"; //expected: No

    stack.clear();
    std::cout << "After clear: Is empty? " << (stack.is_empty() ? "Yes" : "No") << "\n"; //expected: Yes

    stack.push(1);
    stack.push(2);
    stack.push(3);

    Stack cloned = stack.clone();
    std::cout << "Cloned stack: ";
    cloned.print(); //expected: top -> 3 -> 2 -> 1 -> nullptr

    stack.reverse();
    std::cout << "Reversed original: ";
    stack.print(); //expected: top -> 1 -> 2 -> 3 -> nullptr

    std::vector<int> vec = stack.to_vector();
    std::cout << "Stack as vector: ";
    for (int v : vec) std::cout << v << " "; //expected: 1 2 3
    std::cout << "\n";

    // Future stack features:
    // stack.set_at(1, 42);  // To be implemented
    // stack.remove_value(2);  // To be implemented

    // ===== Queue Demo =====
    std::cout << "\n===== Queue Demo =====\n";
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print(); //expected: front -> 10 -> 20 -> 30 -> nullptr

    std::cout << "Front: " << q.front() << "\n"; //expected: 10

    q.dequeue();
    q.print(); //expected: front -> 20 -> 30 -> nullptr

    std::cout << "Is empty? " << (q.is_empty() ? "Yes" : "No") << "\n"; //expected: No
    std::cout << "Size: " << q.size() << "\n"; //expected: 2

    q.dequeue();
    q.dequeue();
    std::cout << "After dequeuing all: Is empty? " << (q.is_empty() ? "Yes" : "No") << "\n"; //expected: Yes

    return 0;
}
