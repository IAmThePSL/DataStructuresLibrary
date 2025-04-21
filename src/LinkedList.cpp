#include "LinkedList.hpp"
#include <stdexcept>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::push_front(int value) {
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}

void LinkedList::push_back(int value) {
    Node* new_node = new Node(value);
    if (!head) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void LinkedList::insert_at(int index, int value) {
    if (index < 0) throw std::out_of_range("Index out of range");

    if (index == 0) {
        push_front(value);
        return;
    }

    Node* temp = head;
    for (int i = 0; i < index - 1 && temp; ++i) {
        temp = temp->next;
    }

    if (!temp) throw std::out_of_range("Index out of range");

    Node* new_node = new Node(value);
    new_node->next = temp->next;
    temp->next = new_node;
}

void LinkedList::pop_front() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

/**
 * Removes the last element from the list.
 * If the list is empty or has one node, handles those cases appropriately.
 */
void LinkedList::pop_back() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void LinkedList::remove_at(int index) {
    if (index < 0) throw std::out_of_range("Index out of range");
    if (!head) throw std::runtime_error("List is empty");

    if (index == 0) {
        pop_front();
        return;
    }

    Node* temp = head;
    for (int i = 0; i < index - 1 && temp; ++i) {
        temp = temp->next;
    }

    if (!temp || !temp->next) throw std::out_of_range("Index out of range");

    Node* node_to_remove = temp->next;
    temp->next = node_to_remove->next;
    delete node_to_remove;
}

int LinkedList::at(int index) const {
    if (index < 0) throw std::out_of_range("Index out of range");

    Node* temp = head;
    for (int i = 0; i < index && temp; ++i) {
        temp = temp->next;
    }

    if (!temp) throw std::out_of_range("Index out of range");
    return temp->data;
}

/**
 * Reverses the linked list by changing next pointers.
 * Does not allocate or deallocate any nodes.
 */
void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* current = head;

    while (current) {
        Node* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    head = prev;
}

int LinkedList::size() const {
    int count = 0;
    Node* temp = head;
    while (temp) {
        ++count;
        temp = temp->next;
    }
    return count;
}

bool LinkedList::is_empty() const {
    return head == nullptr;
}

/**
 * Deletes all nodes from the list and resets head to nullptr.
 */
void LinkedList::clear() {
    Node* temp = head;
    while (temp) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
}

void LinkedList::print() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr\n";
}

int LinkedList::pop_front() {
    if (is_empty()) throw std::underflow_error("List is empty");
    
    int value = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    length--;

    return value;
}

int LinkedList::pop_back() {
    if (is_empty()) throw std::underflow_error("List is empty");
    
    if(length == 1) {
        int value = head->data;
        delete head;
        head = nullptr;
        length--;
        
        return value;
    }

    Node* current = head;
    while (current->next->next) current = current->next;

    int value = current->next->data;
    delete current->next;
    current->next = nullptr;
    length--;
    
    return value;
}

int LinekdList::find(int value) const {
    Node* current = head;
    int index = 0;
    
    while(current) {
        if (current->data == value){ 
            return index;
        }

        current = current->next;
        index++;
    }
    return -1;
}