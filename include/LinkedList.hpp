#pragma once
#include <iostream>

struct Node {
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
	Node* head;

public:
	LinkedList();
	~LinkedList();

	//NOTE: 
	// I am not bothered to sort these functions
	// They are just in the way I implemented their functions
	// And not in a special order.
	// might use AI to help me sort them.. :P	
	void push_front(int value);				//insert at the beginning
	void push_back(int value);				//insert at the end
	void pop_front();						//remove the first node
	void pop_back();						//remove the last node
	bool search(int value);					//check if the value exists in the list
	void print() const;						//print values
	void clear();							//delete all nodes
    int size() const;						//get current size
    bool is_empty() const;					//speaks for itself. (returns true or false whether the list is empty or not.)
    int at(int index) const;				//get value at specific index
    void remove_at(int index);				//remove node at index
    void insert_at(int index, int value);	//insert node at index
    void reverse();							//reverse list in-palce
	int pop_front();
	int pop_back();
	int find(int value) const;
};