
// Exampler Usage: before doing this dont forget to remove main() from GDSL.cpp

#include <iostream>
#include "GDSL.cpp" 

using namespace std;

int main()
{
    cout << "--------------------------------------------------\n";
    cout << "      Generic Data Structure Library (GDSL)       \n";
    cout << "             Author: Soham Sonar                  \n";
    cout << "--------------------------------------------------\n";

    // ==========================================
    // 1. Testing Singly Linear Linked List
    // ==========================================
    cout << "\n[Testing Singly Linear Linked List]...\n";
    SinglyLLL<int> *iObj = new SinglyLLL<int>();
    
    iObj->InsertFirst(51);
    iObj->InsertFirst(21);
    iObj->InsertFirst(11);
    iObj->InsertLast(101);
    
    cout << "Data: ";
    iObj->Display();
    cout << "Count: " << iObj->Count() << "\n";
    
    delete iObj; // Clean up memory

    // ==========================================
    // 2. Testing Stack (With Error Handling)
    // ==========================================
    cout << "\n[Testing Stack with Exception Handling]...\n";
    Stack<char> *sObj = new Stack<char>();

    sObj->Push('A');
    sObj->Push('B');

    try 
    {
        cout << "Popped: " << sObj->Pop() << "\n"; // Outputs B
        cout << "Popped: " << sObj->Pop() << "\n"; // Outputs A
        
        cout << "Attempting to Pop empty stack...\n";
        cout << "Popped: " << sObj->Pop() << "\n"; // This triggers the ERROR
    }
    catch(const char* msg)
    {
        cout << ">>> Exception Caught: " << msg << "\n";
    }

    delete sObj;

    // ==========================================
    // 3. Testing Queue
    // ==========================================
    cout << "\n[Testing Queue]...\n";
    Queue<float> *qObj = new Queue<float>();

    qObj->enqueue(10.5f);
    qObj->enqueue(20.5f);

    cout << "Queue Elements: ";
    qObj->Display();

    try
    {
        cout << "Dequeued: " << qObj->dequeue() << "\n";
        cout << "Dequeued: " << qObj->dequeue() << "\n";
    }
    catch(const char* msg)
    {
        cout << ">>> Exception Caught: " << msg << "\n";
    }

    delete qObj;

    cout << "\n--------------------------------------------------\n";
    cout << "All tests completed successfully.\n";
    cout << "--------------------------------------------------\n";

    return 0;
}