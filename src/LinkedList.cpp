/**
 * LinkedList Implementation (Singly Linked List)
 * 
 * This file implements a singly linked list with the following:
 * 
 *  DATA MEMBERS:
 *  - Node* head: Points to the first node in the list.
 *  - int length: Tracks the number of elements in the list.
 * 
 *  CONSTRUCTORS & ASSIGNMENT:
 *  - LinkedList(): Default constructor.
 *  - LinkedList(const LinkedList& other): Copy constructor (deep copy).
 *  - operator=(const LinkedList& other): Copy assignment operator (deep copy).
 *  - ~LinkedList(): Destructor that clears the list.
 * 
 *  BASIC OPERATIONS:
 *  - push_front(value): Insert a node at the beginning.
 *  - push_back(value): Insert a node at the end.
 *  - insert_at(index, value): Insert a node at a specific index.
 *  - pop_and_return_front(): Remove and return the first node's value.
 *  - pop_and_return_back(): Remove and return the last node's value.
 *  - remove_at(index): Remove a node at a specific index.
 *  - at(index): Return the value at a given index.
 *  - set_at(index, value): Update value at a specific index.
 *  - remove_value(value): Remove the first occurrence of the given value.
 * 
 *  INSPECTION & INFO:
 *  - find(value): Return the index of first occurrence of value.
 *  - contains(value): Check if value exists in the list.
 *  - size(): Return the current number of elements.
 *  - is_empty(): Check if the list is empty.
 * 
 *  TRANSFORMATIONS:
 *  - reverse(): Reverse the linked list in-place.
 *  - clone(): Return a deep copy of the list.
 *  - equals(other): Check if two lists have identical contents.
 *  - clear(): Delete all nodes and reset list.
 *  - to_vector(): Return the contents of the list as a std::vector.
 *  - print(): Output the list to std::cout.
 */
#include "LinkedList.hpp"
#include <stdexcept>
#include <iostream>

LinkedList::LinkedList(): head(nullptr), length(0) {}

LinkedList::~LinkedList(){
    clear();
}

//copy constructor
LinkedList::LinkedList(const LinkedList& other) : head(nullptr), length(0) {
    Node* curr = other.head;
    while(curr){
        push_back(curr->data);
        curr = curr->next;
    }
}

//copy assignment
LinkedList& LinkedList::operator=(const LinkedList& other){
    if(this == &other) return *this; //self assignment check

    clear(); //clear current list

    Node* curr = other.head;
    while(curr){
        push_back(curr->data);
        curr = curr->next;
    }

    return *this;
}

//inserts at the front
void LinkedList::push_front(int value){
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
    length++;
}

//inserts at the back
void LinkedList::push_back(int value){
    Node* new_node = new Node(value);
    if(!head){
        head = new_node;
    }else{
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    length++;
}

//inserts at index
void LinkedList::insert_at(int index, int value){
    if(index < 0 || index > length){
        throw std::out_of_range("Index out of range");
    }

    if(index == 0){
        push_front(value);
        return;
    }

    Node* temp = head;
    for(int i = 0; i < index - 1; ++i){
        temp = temp->next;
    }

    Node* new_node = new Node(value);
    new_node->next = temp->next;
    temp->next = new_node;
    length++;
}

//removes and returns first element
int LinkedList::pop_and_return_front(){
    if(!head){
        throw std::underflow_error("List is empty");
    }

    int value = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    length--;

    return value;
}

//removes and returns last element
int LinkedList::pop_and_return_back(){
    if(!head){
        throw std::underflow_error("List is empty");
    }

    if(!head->next){
        int value = head->data;
        delete head;
        head = nullptr;
        length--;
        return value;
    }

    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }

    int value = temp->next->data;
    delete temp->next;
    temp->next = nullptr;
    length--;

    return value;
}

//removes at index
void LinkedList::remove_at(int index){
    if(index < 0 || index >= length){
        throw std::out_of_range("Index out of range");
    }

    if(index == 0){
        pop_and_return_front();
        return;
    }

    Node* temp = head;
    for(int i = 0; i < index - 1; ++i){
        temp = temp->next;
    }

    Node* to_delete = temp->next;
    temp->next = to_delete->next;
    delete to_delete;
    length--;
}

//value at index
int LinkedList::at(int index) const {
    if(index < 0 || index >= length){
        throw std::out_of_range("Index out of range");
    }

    Node* temp = head;
    for(int i = 0; i < index; ++i){
        temp = temp->next;
    }

    return temp->data;
}

//reverse list
void LinkedList::reverse(){
    Node* prev = nullptr;
    Node* current = head;

    while(current){
        Node* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    head = prev;
}

//size of list
int LinkedList::size() const {
    return length;
}

//check if empty
bool LinkedList::is_empty() const {
    return head == nullptr;
}

//clear list
void LinkedList::clear(){
    Node* temp = head;
    while(temp){
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
    length = 0;
}

//print list
void LinkedList::print() const {
    Node* temp = head;
    while(temp){
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr\n";
}

//find first occurrence
int LinkedList::find(int value) const {
    Node* current = head;
    int index = 0;

    while(current){
        if(current->data == value){
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

//remove first occurrence of value
void LinkedList::remove_value(int value){
    if(!head){
        return;
    }

    if(head->data == value){
        Node* to_delete = head;
        head = head->next;
        delete to_delete;
        length--;
        return;
    }

    Node* temp = head;
    while(temp->next && temp->next->data != value){
        temp = temp->next;
    }

    if(temp->next){
        Node* to_delete = temp->next;
        temp->next = temp->next->next;
        delete to_delete;
        length--;
    }
}

//set value at index
void LinkedList::set_at(int index, int value){
    if(index < 0 || index >= length){
        throw std::out_of_range("Index out of range");
    }

    Node* temp = head;
    for(int i = 0; i < index; ++i){
        temp = temp->next;
    }

    temp->data = value;
}

//check if contains value
bool LinkedList::contains(int value) const {
    Node* temp = head;
    while(temp){
        if(temp->data == value){
            return true;
        }
        temp = temp->next;
    }

    return false;
}

//compare for equality
bool LinkedList::equals(const LinkedList& other) const {
    Node* a = head;
    Node* b = other.head;

    while(a && b){
       if(a->data != b->data){
           return false;
       }
       a = a->next;
       b = b->next;
    }

   return a == nullptr && b == nullptr;
}

//deep copy
LinkedList LinkedList::clone() const {
    LinkedList copy;
    Node* temp = head;
    while(temp){
        copy.push_back(temp->data);
        temp = temp->next;
    }
    return copy;
}

//convert to vector
std::vector<int> LinkedList::to_vector() const {
    std::vector<int> vec;
    Node* current = head;
    while(current){
        vec.push_back(current->data);
        current = current->next;
    }
    return vec;
}
