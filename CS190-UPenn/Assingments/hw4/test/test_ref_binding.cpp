#include<iostream>

void f(int i)
{
    std::cout << i << std::endl;
}

int main()
{
    int a = 10;
    int& b = a;

    f(b); // Should this work?
    return 0;
}
