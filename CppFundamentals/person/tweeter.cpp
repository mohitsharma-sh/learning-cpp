#include "tweeter.hpp"
#include <iostream>
#include <string>

Tweeter::Tweeter(std::string first,
        std::string last,
        int arbitrary,
        std::string handle)
    :
    Person(first, last, arbitrary),
    handle(handle)
{
    std::cout << "constructing tweeter " << handle << std:: endl;
}

Tweeter::~Tweeter()
{
    std::cout << "destructing tweeter " << handle << std::endl; 
}

std::string Tweeter::get_name() const
{
    return Person::get_name() + handle;
}
