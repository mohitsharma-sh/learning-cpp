#pragma once
#include<string>
#include<iostream>

class ComplexNumber{
    private:
        double re; // Real Part
        double im; // Imaginary Part

    public:
        ComplexNumber(double re, double im): re(re), im(im){};
        ComplexNumber(): re(0), im(0){};
        ComplexNumber operator+(ComplexNumber const& other) const;
        ComplexNumber& operator+=(ComplexNumber const& other);
        friend std::ostream& operator<<(std::ostream& os, ComplexNumber const& number); // const or not ?
        friend std::istream& operator>>(std::istream& is, ComplexNumber& number);
};

std::ostream& operator<<(std::ostream& os, ComplexNumber const& number);
std::istream& operator>>(std::istream& is, ComplexNumber& number);
