#include<iostream>
#include<string>
#include "Person.h"
#include "Tweeter.h"

int main()
{

    Person p1 = Person("Mohit", "Sharma", 567);
    Person p2 = Person("Rohit", "Sharma", 456); // Default constructor sets the arbitrarynumber to 0
    
    if(p1 < p2)
    {
        std::cout << p1.getName() << " is less than " << p2.getName() << std::endl;
    } else if(p2 < p1){
        std::cout << p2.getName() << " is less than " << p1.getName() << std::endl;
    } else{
        std::cout << p1.getName() << " and " << p2.getName() << " are equal." << std::endl;
    }

    {
        Tweeter t1 = Tweeter("Mohit", "Sharma", 456, "@mohitsharma-sh");
        std::cout << t1.getName() << std::endl;

    }

    std::cout << p1.getName() << std::endl;
    std::cout << p1.getNumber() << std::endl;
    p1.setNumber(456);
    std::cout << p1.getNumber() << std::endl;
    
    return 0;
}
