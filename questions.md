1. Inline initialization vs Constructor Initialization

```cpp

// foo.h
#include<string>
class foo
{
    private:
        int i = 0;
        std::string name = "foo";
}

// foo.h
#include<string>
class foo
{
    private:
        int i;
        std::string name;

    public:
        foo(): i{0}, name{"foo"} {};
}
```
So the [C.45](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines.html#c45-dont-define-a-default-constructor-that-only-initializes-data-members-use-in-class-member-initializers-instead) core guidlines suggest the first one. It reads as follows:  
`Don’t define a default constructor that only initializes data members; use in-class member initializers instead`
The rationale behind this is that with in-class member initialization, the compiler can generate the constructor for you, which can be more efficient.

2. Can reference to a type bind to the type itself?

```c++
#include<iostream>
void f(int i)
{
    std::cout << i << std::endl;
}

int main()
{
    int a = 0;
    int& b = a;

    f(b); // Should this work?
}
```
