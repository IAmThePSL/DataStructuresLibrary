#ifndef STACK_HPP
#define STACK_HPP
#include "LinkedList.hpp"

class Stack {
private:
    LinkedList list;

public:
    Stack();

    void push(int value);            //add to top
    void pop();                      //remove top
    int top() const;                 //peek at top
    bool is_empty() const;           //check if empty
    int size() const;                //get element count
    void print() const;              //print stack contents
    void clear();                    //reset stack
    bool contains(int value) const;  //check value existence
    bool equals(const Stack& other) const;//compare stacks
    Stack clone() const;	     //clone stack
    void reverse();                  //reverse stack
    std::vector<int> to_vector() const;//convert stack to std::vector<T>
};

#endif
