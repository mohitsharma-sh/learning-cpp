# learning-cpp
Notes from different sources I am using to learn cpp.

## 1. C++ Fundamentals Including C++ 17 (Kate Gregory)
## 2. [UPenn CIS 190, C++ Programming](https://www.seas.upenn.edu/~cis190/fall2019/)

1. Homework 1  
    - Overloading of `>>` and `<<` operator (return types, `const`ness).
    - Return types of overloaded operators (why `+=` should return a self reference)
    - `iostream`, `fstream`

2. Homework 2
    - Core Concepts: Abstract Classes, Polymorphism, Inheritence
    - C++: `virtual`, `pure virtual`, `protected`, `std::initializer_list`

3. Homework 3
    - Core concepts: Rule of five, move semantics, valgrind
    - C++: `lvalue`, `rvalue`, `lvalue reference`, `rvalue reference`, `std::move`

4. Homework 4
    - [Copy-and-Swap Idiom](https://cpppatterns.com/patterns/copy-and-swap.html)

## 3. [Caltech CS11 -- Advanced C++ 11](http://courses.cms.caltech.edu/cs11/material/advcpp/)

1. Lab 1: Regular Expressions
    - Lesson: If you intend a base class to declare a function (with NO implementation) and expect the derived class to provide the implementation, you have to define that function as **pure virtual** function, virtual alone will throw linking errors.
    - There's also a few things about virtual destructors that I don't fully understand yet. Go read it up.
    - As a general note, read up more about OOP in general, and in context of C++.
