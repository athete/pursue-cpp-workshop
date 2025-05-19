#include <iostream>
using namespace std;

void passByValue(int& val) {
    val =  4 * val;
}

int main() {
    int a = 10;
    cout << a << endl; // Output: 10
    passByValue(a);
    cout << a << endl; // Output: 40
    return 0;
}