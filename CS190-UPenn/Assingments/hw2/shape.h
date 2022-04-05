#pragma once

class shape
{
    protected:
        int side_;

    public:
        shape(int side): side_(side) {}
        shape(): side_(0) {}

        ~shape(){}

        void setSideLength(int side) {side_ = side;}
        virtual double getArea() const = 0; // pure virtual function, makes shape an abstract class
};
