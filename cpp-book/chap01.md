# Chapter 1: Compiled and Interpreted Languages

## Machine Code and Assembly Language

A computer's CPU only processes a limited set of instructions written as a sequence of 0s and 1s called **machine code**. For instance, `10110000 01100001` is an
instruction to the CPU to move a value into one of its registers. Naturally, we don't do too well programming in machine code and for this reason, people inventes assembly 
language, where each instruction is defined by short abbreviations, and specialized names and numbers are also used. The aforementioned instruction can be written in assembly language 
as `mov al, 061h`. However, since a CPU only understands a string of bits, we need to use a program called an **assembler** to translate assembly into machine code. However, there is one issue with both machine code and assembly: **each CPU has a different set of instructions and thus neither machine code or assembly is very portable to other CPU architectures.**

## High-level Languages

Portability issues with machine and assembly are eased by using **high-level** languages such as C++, Python, Javascript, etc. These are designed to be human-readable and to be used on any kind of computer, regardless of the CPU's architecture. These types of languages can be divided into two main categories:

* **Interpreted**
    - A program called an interpreter directly executes the instructions in the code without compilation.
    - Highly portable, but normally inefficient
* **Compiled**
    - A program called a compiler translates the source code into another, lower level language (e.g. assembly, machine code).
    - Usually efficient compared to its interpreted counterparts

Remember the cryptic snippet of code in machine code and assembly seen in the previous section? Here is the exact same instruction, but in C++: `a = 97;`. You do not need to be a programmer to understand what that those! As an example of how compilers work, we can visit [godbolt.org](https://godbolt.org) to see the end result of a compilation! Just copy the following piece of code into the cell on the left, choose your favorite compiler, and see the results on the cell to the right. We will discuss more about what code such as this does later on.

```{literalinclude} ../examples_cpp/c1_godbolt.cpp
---
language: cpp
---
```

## Compiling C++ Source Code

```{figure} assets/mermaid-diagram-2024-06-05-001615.svg
---
align: right
---
Building process flow chart
```

Compilation of source code is only the first step in the construction of executable software from source code. The process of running any piece of C++ code can be summarized into the following steps:

- The compiler checks that the input C++ code is well written and does not have any syntactical errors.
- The compiler translates the C++ code into machine language instructions. This produces an object file (.obj or .o) for each input file.
- The linker combines all of the object files, ensuring all cross-file dependencies are resolved properly, and linking library files. This almost always includes the C++ Standard Library which provides some basic libraries such as the iostream library.
- The compiler produces an executable file which you can run.

```{admonition} Exercise 1.1
Let's compile our first C++ code. First open [helloworld.cpp](../examples_cpp/helloworld.cpp) with your favorite text editor (can you guess what it does)? Next, run `g++ helloworld.cpp -o helloworld.o`. This will produce a new file called `helloworld.o`. This is the output of the compilation process. To run it just run `./helloworld.o` in the terminal.
```