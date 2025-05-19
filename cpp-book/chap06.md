# Chapter 6: Advanced Topics in C++

In this chapter, we will introduce a set of elements from C++ which do not neatly fit into any of the other, basics-focused chapters and which, in large part, have no direct analogue in Python.

## Dynamic Memory Allocation
Dynamic memory allocation allows you to allocate memory during runtime using the `new` operator and deallocate it using the `delete` operator.

```cpp
#include <iostream>
using namespace std;

int main() {
    int* dynamicInt = new int(5);  // Dynamically allocate memory for an integer
    cout << "Value of dynamicInt: " << *dynamicInt << endl;
    delete dynamicInt;  // Free the allocated memory

    int* dynamicArray = new int[5];  // Dynamically allocate memory for an array
    for (int i = 0; i < 5; ++i) {
        dynamicArray[i] = i * 10;
        cout << "dynamicArray[" << i << "] = " << dynamicArray[i] << endl;
    }
    delete[] dynamicArray;  // Free the allocated memory

    return 0;
}
```