#include <iostream>
using namespace std;

int main () {
    int max_num = 10000;
    for (int i = 0; i < max_num; ++i) {
        if (i == 50) {
            break;
        } else if (i % 2 == 0) {
            continue;
        }
        cout << i << endl;
    }
    cout << "End of loop!\n";
}