#include <iostream>
#include <string>
using namespace std;

int main(){
    int input;
    cout << "What is your favorite color (input the number):\n";
    cout << "1. Red \n2. Blue\n3. Green\n4. Yellow\n";
    cin >> input;

    switch (input){
        case 1:
            cout << "You must like apples!\n";
            break;
        case 2:
            cout << "You must like looking at the sky!\n";
            break;
        case 3:
            cout << "You must like vegetables!\n";
            break;
        case 4:
            cout << "You must like looking at the Sun! (And you should probably stop...)\n";
            break;
        default:
            cout << "I've never heard of that color... :(\n";
    }
    return 0;
}