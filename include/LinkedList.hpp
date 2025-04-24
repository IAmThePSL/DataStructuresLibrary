#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int length;

public:
    LinkedList();
    ~LinkedList();

    void push_front(int value);            //insert at beginning
    void push_back(int value);             //insert at end
    int pop_and_return_front();            //remove first node and return
    int pop_and_return_back();             //remove last node and return
    bool search(int value);                //check if value exists
    void print() const;                    //print values
    void clear();                          //delete all nodes
    int size() const;                      //get current size
    bool is_empty() const;                 //check if empty
    int at(int index) const;               //get value at index
    void remove_at(int index);             //remove node at index
    void insert_at(int index, int value);  //insert node at index
    void reverse();                        //reverse list in-palce
    int find(int value) const;              //find first value index
    void remove_value(int value);          //delete first occurrence
    void set_at(int index, int value);     //update value at index
    bool contains(int value) const;        //check value existence
    bool equals(const LinkedList& other) const;//compare lists
    LinkedList clone() const;              //create deep copy
    std::vector<int> to_vector() const;
};

#endif
