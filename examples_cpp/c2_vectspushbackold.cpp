#include <vector>
#include <iostream>
using namespace std;

int main() {
    int arr[] = {14, 15, 16, 17};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    vec.push_back(18);
    cout << "Added element: " << vec[4] << endl;
    return 0;
}