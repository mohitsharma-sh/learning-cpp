#include<string>
#include<iostream>
#include "Person.h"

Person::Person(std::string first, std::string last, int arbitrarynumber):
    firstname(first), lastname(last), arbitrarynumber(arbitrarynumber)
{
    std::cout << "Constructing " << firstname << " " << lastname << std::endl;
}

Person::Person(): arbitrarynumber(0)
{
    std::cout << "Constructing " << firstname << " " << lastname << std::endl;
}

Person::~Person()
{
    std::cout << "Destructing " << firstname << " " << lastname << std::endl;
}

std::string Person::getName() const
{
    return firstname + " " + lastname;
}

int Person::getNumber() const
{
    return arbitrarynumber;
}

void Person::setNumber(int newNumber)
{
    arbitrarynumber = newNumber;
} 

bool Person::operator<(Person const& otherPerson) const
{
    return arbitrarynumber < otherPerson.arbitrarynumber;
}

bool Person::operator<(int number) const
{
    return arbitrarynumber < number;
}

bool operator<(int number, Person const& person)
{
    return number < person.arbitrarynumber;
}

bool Person::operator==(Person const& otherPerson) const
}
