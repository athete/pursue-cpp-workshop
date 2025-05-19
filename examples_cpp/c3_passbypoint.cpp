#include <iostream>
using namespace std;

void passByValue(int* ptr_val) {
    cout << "Pointer passed to func: " << ptr_val << endl;
    *ptr_val =  4 * (*ptr_val); // Dereference ptr_val to modify the value it points to
}

int main() {
    int a = 10;
    int* ptr_a = &a; // Pointer to a
    cout << "Value: " << a << endl; // Output: 10
    cout << "Pointer: " << ptr_a << endl; // Output: Address of a in hexadecimal
    passByValue(ptr_a);
    cout << "Value after func: " << a << endl; // Output: 40
    cout << "Pointer after func: " << ptr_a << endl; // Output: Same address as before
    return 0;
}