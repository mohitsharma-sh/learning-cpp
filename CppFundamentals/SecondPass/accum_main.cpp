#include<iostream>
#include<string>
#include "accum.h"

int main(){
    Accum<int> intAccum(0);
    intAccum += 2;
    intAccum += 3;
    std::cout << intAccum.getTotal() << std::endl;

    Accum<std::string> stringAccum("");
    stringAccum += "Mohit";
    stringAccum += " ";
    stringAccum += "Sharma";

    std::cout << stringAccum.getTotal() << std::endl;
}
