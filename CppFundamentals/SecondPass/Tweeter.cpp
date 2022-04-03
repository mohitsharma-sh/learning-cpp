#include "Tweeter.h"
#include "Person.h"
#include<string>
#include<iostream>

Tweeter::Tweeter(std::string first, std::string last, int arbitrarynumber, std::string handle):
    Person(first, last, arbitrarynumber), twitterhandle(handle)
{
    std::cout << "constructing tweeter " << twitterhandle << std::endl;
}

Tweeter::~Tweeter()
{
    std::cout << "destructing tweeter " << twitterhandle << std::endl; 
}
