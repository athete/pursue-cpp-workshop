# Chapter 4: Classes

C++ is an object oriented programming language, where classes form a principal role in structuring software in a manageable, efficient, and reusable manner. This programming paradigm is intuitive and its use is widespread[^classparadigm].

In this chapter, we will take a deeper look at classes and what differentiates them from what you have seem in Python.

## What We've Seen Before

We saw that classes can have public and private methods and attributes, each with a different level of accesibility. Their accesibility is re-sumarized in the following list

1. `public`: Members are accessible from outside the class
1. `private`: Members are accesible only inside the class.

In addition, we saw that when we instantiate a class, a method called the "contructor" is called which has the purpose of initializing the object if neccesary. The following example summarizes all of these things.

```{literalinclude} ../examples_cpp/c4_classeg.cpp
:language: cpp
:lineno-match:
```

## Inheritance

Inheritance is a fundamental concept in OOP. It describes the capacity for a class to acquire methods and attributes from another. The base class from which other class(es) derive from is called the parent/base class, while those classes that inherit from the parent class are called the child/derived class. This is very useful because it allows you to define a generalized base class which works for many different sitautions, and then have derived classes which inherit from the base class to work in a more specialized case. For instance, you could define a base class called `vehicle`, and then have children classes such as `car`, `bus` and `motorcycle` which inherit from `vehicle`. This key feature in OOP allows us to structure our code in a logical fashion which is easier to understand.

The following example illustrates the use of inheritance between two classes in C++.

```{literalinclude} ../examples_cpp/c4_inh.cpp
:language: cpp
:lineno-match:
```
```
Particle Constructor Called. Assigning mass, quirkiness, and meanlifetime...
Muon Constructor Called. Assigning charge and spin.
Function of Muon Class. Just printing!
Function of Particle Class. Just printing!
Charge: 1
Spin: 0.5
Mass: 0.1057
Mean Lifetime: 10
```

In this example, `Particle` is a parent class from which `Muon` inherits. As can be observed, in the `main` body of the code we were able to call a public method that belonged to `Particle` as if it belonged to the `Muon` class. In addition, we called the method `PrintLifeTime()` which accessed `Particle`'s protected attribute `meanlifetime`. WHen a method or attribute is `protected`, it can only be accesed in two ways: through the class itself, or through one of its derived classes that inherit from it. This means that if we had tried to do `mu.meanlifetime`, I would have gotten an error. On the other hand, the private attribute `quirkiness` can *only* be accessed in the same class it was defined, which means that `Muon` cannot access it directly. However, it is possible for `Muon` to access it indirectly by calling a protected or public method which in `Particle` which accesses `meanlifetime`.

You might ask yourself: "That's nice, but I can code in Python without having to have any private, public or protected method/attributes and it works perfectly fine. So what's the point!" While its true that its not neccesary for a programming language to have these features, having them does offer some benefits. For instance, it allows us to control access to certain critical methods or attributes, thus enhancing the security of our code. Additionally, it can help with controlling what exactly is inherited to a derived class and with having a stable API for users despite changes to the parent class definition itself.

## Polymorphism

Polymorphism allows methods to do different things based on the object is is acting on. The main idea is that you want to be able to use a function with different types of inputs without having to define a function for every possible type of input. Polymorphism is achieved primarily through the use of virtual function and abstract classes.

```cpp
#include <iostream>
using namespace std;

class Animal 
{
public:
    virtual void speak() 
    {
        cout << "Some animal sound!" << endl;
    }
};

class Dog : public Animal 
{
public:
    void speak() override 
    {
        cout << "Woof!" << endl;
    }
};

void makeAnimalSpeak(Animal& animal) 
{
    animal.speak();
}

int main() 
{
    Animal animal;
    Dog dog;

    makeAnimalSpeak(animal); // Outputs: Some animal sound!
    makeAnimalSpeak(dog); // Outputs: Woof!, thanks to polymorphism
    return 0;
}
```

## Destructor

A destructor is another special function that is automatically called when an object goes out of scope or is deleted. Its purpose is to free sources allocated during the object's lifetime, such as memory and file. These type of class method exists in Python, but it is not as essential as in C++ because Python has a garbage collector that takes care of these things in the background automatically[^pydestruc].

If we forget to include a destructor, one is created for us by default. This is mostly okay, but if your class handles pointers, we should write a destructor ourselves. Not doing this could lead to memory leaks.

Here is a quick example of a destructor in use.

```{literalinclude} ../examples_cpp/c4_destruc.cpp
:language: cpp
:lineno-match:
```

If you’re ever asking yourself whether you need to explicitly define a destructor for your class, ask yourself this: “Does my class manage any resources, such as dynamically allocated memory, file handles, or network connections?” If it does, you should explicitly define a destructor. This is because built-in data types and standard library classes like `std::string` or `std::vector` have destructors that automatically manage their resources. However, if your class directly manages resources like pointers, these resources will not be automatically released when the object goes out of scope, which can lead to memory leaks and resource leaks. Therefore, defining a destructor allows you to ensure proper cleanup of these resources.

```{admonition} Exercise 4.1
Write a program that allows the user to get information about different types of particles (Electron, Muon and Tau in particular) and compute their energy given a fraction of the speed of light they are traveling at. The requirements are the following:

1. I/O
    * Use `cin` to get input from the user.
    * use `cout` to display results to the user.
2. Decision making:
    * Use `if-else` to handle different user inputs.
3. Functions:
    * Create functions to display particle information.
    * Create a function to compute the energy of a particle given a fraction of the speed of light.
4. Classes and inheritance:
    * Implement a base class `Particle` with pure virtual functions.
    Implement derived classes `Electron`, `Muon` and `Tau` that inherit from `Particle`.
5. Access specifiers
    * Use `public`, `protected` and `private` access specifiers wherever neccesary and appropriate.

You can find some of the code already done in `exercises_cpp/c4_1.cpp` to get you started! 
```

[^pydestruc]: If you need it, Python allows you to define a destructor method in your class which is called when all references to it have been deleted. In Python, this method is called `__del__()`.

[^classparadigm]: Keep in mind that it is not the only one and that it might not even be the best one for the particular problem you are trying to solve. However, for many problems, the abstraction provided by the use of classes can be extremely valuable.