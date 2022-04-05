#pragma once

#include "shape.h"
#include<cmath>

class triangle: public shape
{
    public:
        triangle(int side): shape(side){}
        triangle(){}
        
        double getArea() const override {return (std::sqrt(3) / 4) * side_ * side_;}
};
