# Generic Data Structure Library (GDSL)

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data%20Structures-Linked%20List%20%7C%20Stack%20%7C%20Queue-orange?style=for-the-badge)
![Generic](https://img.shields.io/badge/Template-Generic%20Programming-blueviolet?style=for-the-badge)
![Maintained](https://img.shields.io/badge/Maintained%3F-yes-green.svg?style=for-the-badge)
![Author](https://img.shields.io/badge/Author-Soham%20Sonar-lightgrey?style=for-the-badge)

A comprehensive, efficient, and generic C++ library implementing fundamental linear data structures. 

This project demonstrates the power of **C++ Templates** to create reusable data structures that work with any data type (`int`, `float`, `char`, `std::string`, or custom objects). It includes robust error handling and follows Object-Oriented Programming (OOP) principles.

## 🚀 Features

* **Generic Programming:** Built using C++ Templates (`template <class T>`), allowing a single implementation to handle any data type.
* **6 Core Data Structures:** Implements the complete suite of Linear and Circular Linked Lists, plus Stack and Queue.
* **Exception Handling:** Includes built-in safety mechanisms to prevent operations on empty structures (e.g., `Pop` or `Dequeue` on empty lists) without crashing the program.
* **Modular Design:** Each data structure is encapsulated in its own class with dedicated Node classes.
* **Visual Output:** Custom `Display()` methods to visualize the structure of the lists (e.g., `| 10 |->| 20 |->NULL`).

## 📚 Supported Data Structures

| Data Structure | Class Name | Type | Description |
| :--- | :--- | :--- | :--- |
| **Singly Linear Linked List** | `SinglyLLL` | Linear | Uni-directional navigation. |
| **Singly Circular Linked List** | `SinglyCLL` | Circular | Last node points back to First. |
| **Doubly Linear Linked List** | `DoublyLLL` | Linear | Bi-directional navigation. |
| **Doubly Circular Linked List** | `DoublyCLL` | Circular | Bi-directional with circular linkage. |
| **Stack** | `Stack` | LIFO | Last-In-First-Out principle. |
| **Queue** | `Queue` | FIFO | First-In-First-Out principle. |

## 🛠️ Installation & Usage

1.  **Clone the Repository**
    ```bash
    git clone [https://github.com/soham-exe/GDSL.git](https://github.com/soham-exe/GDSL.git)
    cd GDSL
    ```

2.  **Compile the Code**
    You can use any standard C++ compiler (g++, clang, MSVC).
    ```bash
    g++ GDSL.cpp -o app
    ```

3.  **Run the Executable**
    ```bash
    ./app
    ```

## 💻 Code Example

Here is how to use the library in your own code.

### Check out exampler main.cpp file:
[main.cpp](https://github.com/soham-exe/GDSL/blob/main/main.cpp)

### 1. Creating a Singly Linked List of Integers
```cpp
SinglyLLL<int> *obj = new SinglyLLL<int>();

obj->InsertFirst(51);
obj->InsertFirst(21);
obj->InsertFirst(11);

obj->Display(); // Output: | 11 |->| 21 |->| 51 |->NULL
```
### 2. Using the Stack with Error Handling
The library throws exceptions for invalid operations. It is recommended to use try-catch blocks.

```C++
Stack<char> *stackObj = new Stack<char>();

stackObj->Push('A');
stackObj->Push('B');

try 
{
    cout << "Popped: " << stackObj->Pop() << endl; // Outputs 'B'
    cout << "Popped: " << stackObj->Pop() << endl; // Outputs 'A'
    cout << "Popped: " << stackObj->Pop() << endl; // Throws Exception
}
catch(const char* msg)
{
    cout << "Exception Occurred: " << msg << endl; // Output: Stack is empty. Cannot Pop.
}
```
## 📂 Project Structure
- Node Classes: SinglyLLLnode, DoublyLLLnode, etc. (Define the structure of elements).
- Container Classes: SinglyLLL, Stack, etc. (Define the behavior and algorithms).
- Main Function: Contains driver code to demonstrate and test all functionalities.

## 👤 Author
### Soham Sachin Sonar

- Role: Developer & Maintainer
- Focus: C++, Data Structures, Algorithms

This project is for educational purposes and demonstrates proficiency in C++ memory management and template architecture.
