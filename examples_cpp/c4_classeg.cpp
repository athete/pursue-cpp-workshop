#include <iostream>
using namespace std;

class MyClass 
{
  public:
    // Constructor, equivalent of __init__ in Python
    MyClass(int val) : value(val) {}

    void display() 
    {
      cout << value << endl;
    }
  private:
    int value;
};

int main() 
{
  MyClass obj(10);
  obj.display();
  return 0;
}