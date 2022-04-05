#include "triangle.h"
#include "square.h"
#include "shape.h"
#include<iostream>

int main()
{
    shape* some_shape = new triangle(1); 
    shape* some_other_shape = new square(2);

    std::cout << "some_shape.getArea()=" << some_shape->getArea() << std::endl;
    std::cout << "some_other_shape.getArea()=" << some_other_shape->getArea() << std::endl;

    return 0;
}
