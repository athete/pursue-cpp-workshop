#include <iostream>
using namespace std;


int main () {
    int x = 10;
    if (x > 5) {
        cout << "x is greater than 5 \n";
    } else if ((x <= 5) && (x >= 0)) {
        cout << "x is in between 5 and 0 (inclusive) \n";
    } else {
        cout << "x is negative \n";
    }
}