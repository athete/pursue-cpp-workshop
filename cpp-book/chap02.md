# Chapter 2: From Python to C++

In this chapter, we will introduce fundamental concepts in C++ by seeing how elements from Python such as variables, flow control and functions look like in C++. In the end, we will look at 
more complex comparative examples. It should be stressed that there are fundamental paradigmatic differences between C++ and Python, not just at the syntactic level. While two different programs written in C++ and Python might have the same behaviour or outputs, they operate differently under the hood.

## First Things First...

Before we can jump into programming in C++, we need to cover some fundamental points neccesary for actually running any C++ code. Consider the following, very simple code in Python.

```{literalinclude} ../examples_python/c2_pyeg.py
:language: py
:lineno-match:
```

If we were to translate this into C++, it would look something like the following.

```{literalinclude} ../examples_cpp/c2_cppeg.cpp
:language: cpp
:lineno-match:
```

Let's go line by line to understand the elements introduced by C++ in this example:
* Line 1-2:
  * The `#include <iostream>` is called a preprocessor directive. Think of this as `import` in Python. In this case its "importing" `iostream`, which is part of the standard library and includes tools to read and write text to/from the console such as `cout` and `cin`.
  * In C++, code is organized into namespaces. In practice, this allows us to have functions with the same name. For instance, I could have a namespace called `space1` and another `space2`, both of which have a function defined within them called `func` and I could use them both in my code by specifying which namespace I am referring to when I call the function `func`.
    ```cpp
    space1::func();
    space2::func();
    ```
  * By specifying that we are using the namespace `std`, we avoid having to specifying that `cout`, which is part of the `std` namespace, indeed comes from said namespace. If line 2 was not there, we would need to write `std::cout`.
* Line 4
  * This line is a function header for a function called `main` which we indicate will return a value of type `int`. This function is fundamental because **every C++ program starts by running the `main` function**.
  * Unlike in Python where we indicate that a set of statements are part of a function by indenting them with respect to the function header, in C++ we indicate this by having these statements enclosed by `{}`. 
* Lines 5 to 10
  * These lines define the body of the function `main`.
  * Notice that each statement ends in `;`. This tells the compiler that that is the end of that particular statement. This is neccesary to add because, unlike Python, C++ is a **whitespace-independent language** which means that the following two snippets of code are completely equivalent to the compiler and thus, without `;`, there would be no way for the compiler to know that it had reached the end of a statement[^hard2read].
    ```cpp
    int main() {
      int x = 2;
      int y = 4;
      return 0;
    }
    ```
    ```cpp
    int main(){int x=2;int y=4;return 0;}
    ```
We will discuss the rest of the elements seen in the code snipper as we go along, but take some time to try to deduce what each part is doing.

## Variables and Types

### Basic Types

In Python, if you want to define a variable of type `int` you simply need to write `x = 2`, and the interpreter will infer the type. This is because Python is a **dynamically typed** language, which means that type checking and type assignment of variables happens at runtime and the type of a variable will be based on the value assigned to it. This also means that we can declare a variable to have a value of a particular type, but then assign it a value of a different type. For instance, the following is valid in Python.

```python
x = 2
x = "This is a string!"
```

C++, however, is a statically typed language. This means that type assignment and checking is done at *compile time* and that, when we declare a variable, we must specify its type and that this type is unchanging. Thus the following works

```cpp
int x = 5;
x = 6;
```

but this will cause an error when you attempt to compile

```cpp
int x = 5;
x = 0.45; // Not an integer!
```

Note that, just like in Python has some reserved keywords which you would not want to name your variables (e.g. `print` is a terrible name for a variable!), C++ also has a set of reserved names. For instance, if you try to call a variable `return`, the compiler will complain. You can ready more about these reserved keywords [here](https://en.cppreference.com/w/cpp/keyword). In addition to these restrictions, C++ has other rules for what variable names are valid. In order for an identifier to be valid, it must obey the following conditions:
  * It must be a sequence of one or more letters, digits, or underscore
  * It must NOT include spaces, punctuation marks & symbols
  * It must ALWAYS begin with letter or underscore (though the latter is usually reserved for special purposes)
  * It must NOT be one of the reserved keywords in C++ 

The following table shows some of the data types found in C++ which you might find most familiar having some knowledge of Python. Note that there are more data types than these which we will see later, but these will at least get you started.

```{list-table} Some Fundamental Types in C++
:header-rows: 1
*   - Type
    - Keyword
    - Example value
*   - Boolean
    - bool
    - True
*   - Character
    - char
    - "c"
*   - Integer
    - int
    - 64
*   - Floating point
    - float
    - 3.14
*   - Double floating point
    - double
    - 6.15
*   - Valueless
    - void
    - n/a
*   - String
    - std:string
    - "Hello World!"
```

In C++ we also have arrays. An array is a series of elements of the same type (thus occupying the same amount of memory) in a contiguous memory location. Each of them can be refereced with an index.

### Arrays & Vectors

An array, the C++ equivalent of a tuple in Python, is a series of elements of the same type (and thus each occupying the same amount of memory) in a contiguous memory location. Just like with tuples in Python, each element can be refereced with an index. So, for example, while in Python we might have something like the following

```python
tuple_of_nums = (14, 15, 16, 17)
num1 = list_of_nums[1]
print("The second number in the tuple is: ", num1)
```

In C++, we would have something like this instead

```{literalinclude} ../examples_cpp/c2_cpparr.cpp
:language: cpp
:lineno-match:
```

Here, we are defining an array `arr_of_num` which we tell the computer will have elements of size `int` (usually 4 bytes). In additional, we are initializing the array with some integers. Note that when we assign `arr_of_nums[1]` to `x`, what happens is that the value is *copied* and assigned to x. 

```{warning}
Unlike in Python, in C++ it is possible to use an out of bounds index when fetching an element from an array. This is because when you do `int_arr[n]` all your computer is doing is finding the space space in memory `sizeof(int) * n` away from `int_arr[0]`, which can go beyond the actual space alloted for the array. To see this in action, run the following code. Your compiler might complain, but if it does indeed compile, you see that what is printed to the console is junk because we are accessing some random piece of memory. Do this at your own risk and, in practice, try to never do it! You could break something or cause your program to behave unexpectedly.
```
One limitation with arrays is that the size of the array is unchangeable[^arrsize]. However, C++ offers an alternative called vectors which are dynamic arrays that can change in size, making them the Python equivalent of lists. So, for example, in Python we might have something like the following

```python
lst_nums = [14, 15, 16, 17]
lst_nums.append(18) # Adding an element to the list
print("Added element", lst_nums[4])
```

Whereas, in C++, using vectors we would have:

```{literalinclude} ../examples_cpp/c2_vectspushback.cpp
:language: cpp
:lineno-match:
```

where `push_back` is the C++ equivalent of `append`.

```{warning}
If the above example does not compile for you, it might due to the way we are initializing the vector, which is only compatible with C++11 or later. To fix this, add `-std=c+11` when you go to compile, or use the included extra example, `examples_cpp/c2_vectspushbackold.cpp` which does not use this way of initializing.
```

## Statements & Control Flow

In Python, we have the well known flow control statements `if-else` statements, `while` loops, etc. All of these are used to allow us to repeat operations in our code or to allow it to branch depending on some pre-defined conditions. C++ also has its own control flow statements, many of which will be familiar to you. To get started, in the table below, we present a summary of the main control flow statements in C++. In the subsequent sub-sections, we will cover the most basic and useful of these by starting with a Python example at first, and then seeing the equivalent in C++.

```{list-table} Flow Control Statements in C++
:header-rows: 1

*   - Category
    - Meaning
    - Implemented in C++ by
*   - Conditional statements
    - Set of statements will only be executed if a condition is met.
    - `if`, `else`, `switch`
*   - Jumps
    - Start executing statements at another location
    - `goto`, `break`, `continue`
*   - Function calls
    - Jumps to another location and back
    - functional calls, `return`
*   - Loops
    - Repeatedly execute a set of statements until some condition is met.
    - `while`, `do-while`, `for`, `ranged-for`
*   - Halts
    - Terminate the program
    - `std::exit()`, `std::abort()`
*   - Exceptions
    - Error handling
    - `try`, `throw`, `catch`
```

### `if-else`

In Python, we might have something like the following

```{literalinclude} ../examples_python/c2_ifelse.py
:language: python
:lineno-match:
```

In C++, the equivalent would be:

```{literalinclude} ../examples_cpp/c2_ifelse.cpp
:language: cpp
:lineno-match:
```

### `for`

In Python, we might iterate over a list like this:

```{literalinclude} ../examples_python/c2_for.py
:language: python
:lineno-match:
```

In C++, the equivalent `for` loop woudl be:

```{literalinclude} ../examples_cpp/c2_for.cpp
:language: cpp
:lineno-match:
```
### `while`

A Python `while` loop might look like this:

```{literalinclude} ../examples_python/c2_while.py
:language: python
:lineno-match:
```

In C++, the same logic would be:

```{literalinclude} ../examples_cpp/c2_while.cpp
:language: cpp
:lineno-match:
```

### `do-while`

Python does not a have a direct implementatinon of `do-while` loops. However, we can create the logic. It would be as follows:

```{literalinclude} ../examples_python/c2_dowhile.py
:language: python
:lineno-match:
```

In C++, this same logic would look like 

```{literalinclude} ../examples_cpp/c2_dowhile.cpp
:language: cpp
:lineno-match:
```

### `break` & `continue`

`break` and `continue` work in the exact same way in C++ as they do in Python. For instance, in Python we might have something like this:

```{literalinclude} ../examples_python/c2_breakcont.py
:language: python
:lineno-match:
```

In C++, the same code would look like this:

```{literalinclude} ../examples_cpp/c2_breakcont.cpp
:language: cpp
:lineno-match:
```
### `switch`

If you have a fixed set of possible ramifications that you want your code to go down, the you would use `switch`. They are equivalent to a set of `if-elif-else` statements in Python, but they are not directly implemented. For instance, in Python, we might have the following:

```{literalinclude} ../examples_python/c2_switch.py
:language: python
:lineno-match:
```

In C++, we could implement this rather easily with `if-else` statements, but it can be done more straightforwardly using `switch`. The following snippet is the C++ translation of this.

```{literalinclude} ../examples_cpp/c2_switch.cpp
:language: cpp
:lineno-match:
```
## Functions

Functions in C++ work very similary to how they work in Python. However, there are some additional complications regarding memory and how values are passed to them which will be discussed later on. For now, we can familiarize ourselves with functions by seeing how they are structured in both Python and C++. In Python, we may have a function like the following.

```{code-block} python
---
linenos: True
---
def add(a, b):
  return a + b

result = add(3, 4)
print(result)
```

In C++, the equivalent function would be:

```{code-block} cpp
---
linenos: True
---
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(3, 4);
    cout << result << endl;
    return 0;
}
```
