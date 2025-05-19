#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> vec = {14, 15, 16, 17};
    vec.push_back(18);
    cout << "Added element: " << vec[4] << endl;
}