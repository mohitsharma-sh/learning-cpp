#include<iostream>
#include<string>

#include "complex.h"

ComplexNumber ComplexNumber::operator+(ComplexNumber const& other) const
{
    return ComplexNumber(re + other.re, im + other.im);
}

ComplexNumber& ComplexNumber::operator+=(ComplexNumber const& other)
{
    re += other.re;
    im += other.im;
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, ComplexNumber const& number) 
{
    os << "{r " << number.re << "i: " << number.im << "}";

    return os; 
}

std::istream& operator>>(std::istream& is, ComplexNumber& number)
{
    std::string sink_;
    is >> sink_ >> number.re >> sink_ >> number.im >> sink_;

    return is;
}
