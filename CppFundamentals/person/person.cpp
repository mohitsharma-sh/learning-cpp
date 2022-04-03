#include "person.hpp"
#include <iostream>


Person::Person(std::string first, std::string last, int arbitrary):
first_name(first),
last_name(last),
arbitrary_number(arbitrary)
{
    std::cout << "constructing " << get_name() << std::endl;
}

Person::Person() : arbitrary_number(0)
{
    std::cout << "constructing " << get_name() << std::endl;
}

Person::~Person()
{
    std::cout << "destructing " << get_name() << std::endl;
}

std::string Person::get_name() const
{
    return first_name + " " + last_name;
}

bool Person::operator<(Person const& p) const
{
    return arbitrary_number < p.arbitrary_number;
}

bool Person::operator<(int i) const
{
    return arbitrary_number < i;
}

bool operator<(int i, Person const& p)
{
    return i < p.arbitrary_number;
}
