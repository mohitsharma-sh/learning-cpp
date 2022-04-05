#pragma once

#include "shape.h"

class square: public shape
{
    public:
        square(int side): shape(side) {}
        square(){} // Is default constructor of base class called here?

        double getArea() const override { return side_ * side_;}
};
