# Custom Data Structures Library Implementation in C++

## Project Introduction

Welcome to the Custom Data Structures Library project! This project provides a comprehensive implementation of two essential data structures—Stack and Queue—using a singly linked list. These data structures are fundamental in computer science and are widely used in various applications, from algorithm design to system programming. This project serves as an educational resource, helping you understand the inner workings of these data structures while providing a clean and intuitive interface for use in your own applications.

## Features

### Stack Features

- **Push**: Add an element to the top of the stack.
- **Pop**: Remove the top element from the stack.
- **Top**: Retrieve the top element without removing it.
- **Is Empty**: Check if the stack is empty.
- **Size**: Get the number of elements in the stack.
- **Clear**: Remove all elements from the stack.
- **Contains**: Check if a specific element exists in the stack.
- **Equals**: Compare two stacks for equality.
- **Reverse**: Reverse the order of elements in the stack.
- **Clone**: Create a copy of the stack.
- **To Vector**: Convert the stack elements to a vector.

### Queue Features

- **Enqueue**: Add an element to the back of the queue.
- **Dequeue**: Remove the front element from the queue.
- **Front**: Retrieve the front element without removing it.
- **Enqueue Front**: Add an element to the front of the queue.

## Public Methods

### Stack Methods

- **void push(T value)**: Adds a value to the top of the stack.
- **T pop()**: Removes and returns the top value of the stack. Throws an exception if the stack is empty.
- **T top()**: Returns the top value without removing it. Throws an exception if the stack is empty.
- **bool is_empty()**: Returns 
  ```
  true
  ```

  if the stack is empty, otherwise 
  ```
  false
  ```

- **size_t size()**: Returns the number of elements in the stack.
- **void clear()**: Removes all elements from the stack.
- **bool contains(T value)**: Returns 
  ```
  true
  ```

  if the stack contains the specified value, otherwise 
  ```
  false
  ```

- **bool equals(const Stack&lt;T&gt;& other)**: Compares this stack with another stack for equality.
- **void reverse()**: Reverses the order of elements in the stack.
- **Stack&lt;T&gt; clone()**: Returns a new stack that is a copy of the current stack.
- **std::vector&lt;T&gt; to_vector()**: Converts the stack elements to a vector.

### Queue Methods

- **void enqueue(T value)**: Adds a value to the back of the queue.
- **T dequeue()**: Removes and returns the front value of the queue. Throws an exception if the queue is empty.
- **T front()**: Returns the front value without removing it. Throws an exception if the queue is empty.
- **void enqueue_front(T value)**: Adds a value to the front of the queue.

## Build Instructions
To build the project, follow these steps:
1. Open your terminal and navigate to the project directory.

2. Run the following command to compile the project using the provided Makefile:
	```bash
	make
	```
3. After a successful build, you can run the application with:
	```bash
	./main
	```
4. To clean up the build files, you can run:
	```
	make clean
	```

## Example Usage

Here are some code snippets demonstrating how to use the Stack and Queue implementations:

### Stack Example

```cpp
#include "Stack.h"
#include <iostream>

int main() {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl; //output: 30

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl; //output: 20

    std::cout << "Stack size: " << stack.size() << std::endl; //output: 2

    return 0;
}

```

### Queue Example

```cpp
#include "Queue.h"
#include <iostream>

int main() {
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front element: " << queue.front() << std::endl; //output: 10

    queue.dequeue();
    std::cout << "Front element after dequeue: " << queue.front() << std::endl; //output: 20

    return 0;
}
```

## License
This project is licensed under the MIT License. See the [LICENSE](https://github.com/IAmThePSL/DataStructuresLibrary/blob/main/LICENSE) file for more details.

