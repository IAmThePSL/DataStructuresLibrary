/**
 * Key variable meanings:
 * - temp: Temporary node used during traversal or operations
 * - head: Pointer to the first node in the list
 * - next: Pointer to the subsequent node in the sequence
 */
 #include "LinkedList.hpp"
 #include <stdexcept>
 
 LinkedList::LinkedList() : head(nullptr) {}
 
 LinkedList::~LinkedList() {
     clear();
 }
 
 /**
  * Inserts new node at the beginning of the list.
  */
 void LinkedList::push_front(int value) {
     Node* new_node = new Node(value);
     new_node->next = head;
     head = new_node;
 }
 
 /**
  * Appends new node to the end of the list.
  */
 void LinkedList::push_back(int value) {
     Node* new_node = new Node(value);
     if(!head) {
         head = new_node;
         return;
     }
     Node* temp = head;
     while(temp->next) {
         temp = temp->next;
     }
     temp->next = new_node;
 }
 
 /**
  * Inserts node at specified position. Throws if invalid index.
  */
 void LinkedList::insert_at(int index, int value) {
     if(index < 0) throw std::out_of_range("Index out of range");
 
     if(index == 0) {
         push_front(value);
         return;
     }
 
     Node* temp = head;
     for(int i = 0; i < index - 1 && temp; ++i) {
         temp = temp->next;
     }
 
     if(!temp) throw std::out_of_range("Index out of range");
 
     Node* new_node = new Node(value);
     new_node->next = temp->next;
     temp->next = new_node;
 }
 
 //removes first element
 void LinkedList::pop_front() {
     if(!head) return;
     Node* temp = head;
     head = head->next;
     delete temp;
 }
 
 /**
  * Removes last element from the list.
  * Handles empty and single-element cases.
  */
 void LinkedList::pop_back() {
     if(!head) return;
     if(!head->next) {
         delete head;
         head = nullptr;
         return;
     }
 
     Node* temp = head;
     while(temp->next->next) {
         temp = temp->next;
     }
 
     delete temp->next;
     temp->next = nullptr;
 }
 
 /**
  * Removes node at specified index. Throws if invalid.
  */
 void LinkedList::remove_at(int index) {
     if(index < 0) throw std::out_of_range("Index out of range");
     if(!head) throw std::runtime_error("List is empty");
 
     if(index == 0) {
         pop_front();
         return;
     }
 
     Node* temp = head;
     for(int i = 0; i < index - 1 && temp; ++i) {
         temp = temp->next;
     }
 
     if(!temp || !temp->next) throw std::out_of_range("Index out of range");
 
     Node* node_to_remove = temp->next;
     temp->next = node_to_remove->next;
     delete node_to_remove;
 }
 
 /**
  * Returns value at specified index. Throws if out of bounds.
  */
 int LinkedList::at(int index) const {
     if(index < 0) throw std::out_of_range("Index out of range");
 
     Node* temp = head;
     for(int i = 0; i < index && temp; ++i) {
         temp = temp->next;
     }
 
     if(!temp) throw std::out_of_range("Index out of range");
     return temp->data;
 }
 
/**
 * Reverses list by modifying node pointers.
 * No memory allocations/deallocations occur.
 */
void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* current = head;

    while(current) {
        Node* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    head = prev;
}
 
//counts number of nodes
int LinkedList::size() const {
    int count = 0;
    Node* temp = head;
    while(temp) {
        ++count;
        temp = temp->next;
    }
    return count;
}
 
//checks if list has no nodes
bool LinkedList::is_empty() const {
    return head == nullptr;
}
 
/**
 * Deletes all nodes and resets head to nullptr.
 */
void LinkedList::clear() {
    Node* temp = head;
    while(temp) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
}
 
/**
 * Outputs list contents to standard output.
 */
void LinkedList::print() const {
    Node* temp = head;
    while(temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr\n";
}
 
//removes first node and returns its value
int LinkedList::pop_front() {
    if(is_empty()) throw std::underflow_error("List is empty");
    
    int value = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    length--;

    return value;
}
 
//removes last node and returns its value
int LinkedList::pop_back() {
    if(is_empty()) throw std::underflow_error("List is empty");
    
    if(length == 1) {
        int value = head->data;
        delete head;
        head = nullptr;
        length--;
        
        return value;
    }

    Node* current = head;
    while(current->next->next) current = current->next;

    int value = current->next->data;
    delete current->next;
    current->next = nullptr;
    length--;
    
    return value;
}
 
//finds first occurrence of value, returns index
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
 
//deletes first node containing specified value
void LinkedList::remove_value(int value) {
    if(!head) return;
    if(head->data == value){
        Node* to_delete = head;
        head = head->next;
        delete to_delete;
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
    }
}
 
//updates value at specified index
void LinkedList::set_at(int index, int value) {
    Node* temp = head;
    for(int i = 0; i < index && temp; ++i){
        temp = temp->next;
    }
    if(temp){
        temp->data = value;
    }
}
 
//checks if value exists in list
bool LinkedList::contains(int value) const {
    Node* temp = head;
    while(temp){
        if(temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}
 
//compares two lists for equality
bool LinkedList::equals(const LinkedList& other) const { 
    Node* a = head;
    Node* b = other.head;
    while(a && b){
        if(a->data != b->data) return false;
        a = a->next;
        b = b->next;
    }
    return a == nullptr && b == nullptr;
}
 
//creates deep copy of list
LinkedList LinkedList::clone() const {
    LinkedList copy;
    Node* temp = head;
    while(temp){
        copy.push_back(temp->data);
        temp = temp->next;
    }
    return copy;
}
