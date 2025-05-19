# Chapter 3: Functions and Memory

In this chapter, we will explore functions in C++. We will start by building on what we covered in Chapter 2 and then expand to cover concepts unique to C++. We'll also discuss memory allocation, pointers, and the differences between passing by reference and passing by value.

## What We Saw Before

In Chapter 2, we introduced the basics of functions in C++. We saw that the definition of a function has two components: 
* Function declaration: Tells the compiler about a function's name, return type, and parameters.
* Definition: Provides the actual body of the function.

Example in Python:
```python
def add(a, b):
    return a + b

result = add(3, 4)
print(result)
```

Equivalent in C++:
```cpp
#include <iostream>
using namespace std;

// Function declaration
int add(int a, int b);

// Function definition
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(3, 4);
    cout << result << endl;
    return 0;
}
```

```{admonition} Exercise 3.1
To review your understanding, make a function which implements powers.
```

## Default Arguments and Function Overloading

In C++, just like in Python, you can have arguments in your functions which have a default value. The syntax is nearly identical. For instance, we can have the following:

```cpp
#include <iostream>
#include <string>
using namespace std;

void greet(string name = "User") {
    cout << "Hello, " << name << "!" << end;
}

int main () {
    greet();
    greet("Alice");
    return 0;
}
```

Additionally, we can have define multiple distinct functions with the same name. In order for C++ to distinguish them, we must use different parameters for each of these functions. This is called function overloading and it is a form of polymorphism (more on that in later chapters). Here is an example:

```cpp
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    cout << add(3, 4) << endl;
    cout << add(3.5, 4.5) << endl;
    return 0;
}
```

In this exmaple, C++ is able to understand which `add` function we are referring to because when we do `add(3, 4)`, we are passing `int` values, so it corresponds to the first function definition, whereas when we do `add(3.5, 4.5)` we are passing `double` typed values, corresponding to the second function definition.


```{admonition} Exercise 3.2
Make two print functions. One of them should take in a `string` as an argument, the other one should take in an `int` value as an argument. If no value is passed to these function, they should print `"Nothing to print..."` and `0` respectively. You can have it `return 0;`.
```

## Ways of Passing to a Function

### Pointers

Whenever you create a variable in C++, you are doing a couple of things:

1. Allocating Memory:
   * You are allocating a space in memory of the size appropriate for the type of the variable. This space in memory is reserved to store the value of the variable.
   * For instance, creating an `int` variable allocates 4 bytes of memory on most systems.
2. Creating a Variable:
   * You are creating a variable that contains the value stored in the allocated memory space.
   * Each variable has a particular memory address, which is the location in memory where the value is stored. You can access this memory address using the address-of operator `&`. For instance, if I declare `int x = 4`, and I then do `&x`, I will get the address in memory of `x`, which is usually represented as a hexadecimal number such as `0x16b671738`.

A pointer is a variables that store memory addresses. They are powerful, but you need to be careful when you handle them. This is the power of C++: it trusts you with direct access to the memory. Use that that level of control carefully! Otherwise, you might end up having errors such as memory leaks and segmentation fauls.

### Passing by Value vs. Passing by Reference

So far, we have seen that we can pass arguments to a function and that function can perform some operations with that data. However, this "standard" way of passing values to a function is such that any change to the information you pass to the function is lost once you are outside the scope of the function unless you return this information. If you run the following code, you will see this in effect.

```{literalinclude} ../examples_cpp/c3_passbyval.cpp
:language: cpp
:lineno-match:
```

Passing a parameter to a function in this way is called passing by value because, as the name suggests, you are passing the value or contents of the variable, but not the memory address itself which would allow the function to access the data you passed to it.

If we wish to provide the function access to the data in memory instead of giving it a copy of the data, we would need to pass by reference. This can be achieved by changing the header of the function to `void passByValue(int& val)`. `int&` denotes a reference to an integer, which means that `val` will be an alias of the original variable instead of just a copy of it. The code and output would look as such:

```{literalinclude} ../examples_cpp/c3_passbyref.cpp
:language: cpp
:lineno-match:
```

Another way to achieve this effect is to pass the address in memory of the variable, i.e. the pointer. The following example shows how to do this.

```{literalinclude} ../examples_cpp/c3_passbypoint.cpp
:language: cpp
:lineno-match:
```

Through this example, we can see that the pointer printed inside of the function is the same than the one outside. However, it is worth pausing and taking a look at two new things seen here which have to do with memory and pointers:
* `int* ptr_a`: This declares a *pointer to* an `int`. It is different than `int a` because this just declares the variable `a` with type `int`.
* `&a`: Here we use the "pointer to" operator, `&` which gives us the address in memory of the variable `a` in this case.
*`*ptr_val`: Here we use the "dereference" operator which acts on a pointer (`ptr_val`) and returns the value pointed to by the pointer. 

```{admonition} Exercise 3.3
Make another add function which sums two integers. It should take in integer values *by reference* and add them. Don't put a `return` statement at the end of the function and change the return type of the function accordingly (what would the return value be if the function doesn't return anything? 🤔)
```

With this, we have the basic building blocks neccesary for most programs. However, there is one last component that is at the core of the most popular programming paradigm, object oriented programming (OOP): classes.