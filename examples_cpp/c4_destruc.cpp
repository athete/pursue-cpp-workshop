#include <iostream>
using namespace std;

class DynamicArray 
{
public:
    // Constructor
    DynamicArray(int size) : m_size(size) 
    {
        m_array = new int[m_size];  // Allocate memory for the array
        cout << "Array of size " << m_size << " created." << endl;
        // Initialize the array for the sake of completeness
        for (int i = 0; i < m_size; ++i) {
            m_array[i] = i * i;  // Storing square of the index
        }
    }

    // Destructor
    ~DynamicArray() 
    {
        delete[] m_array;  // Release the allocated memory
        cout << "Array of size " << m_size << " destroyed." << endl;
    }

    // A function to print the array elements
    const void printArray() 
    {
        for (int i = 0; i < m_size; ++i) {
            cout << "Element at index " << i << ": " << m_array[i] << endl;
        }
    }

private:
    int* m_array;  // Pointer to the dynamically allocated array
    int m_size;    // Size of the array
};

int main() 
{
    DynamicArray arr(5);  // Create an object of DynamicArray
    arr.printArray();     // Print the array elements

    // When the function exits, arr goes out of scope, and its destructor is automatically called
    return 0;
}