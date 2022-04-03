#include "person.hpp"
#include "status.hpp"
#include "tweeter.hpp"
#include <iostream>
#include <string>

int main(){

    Person p1 = Person("Mohit", "Sharma", 1);

    std::cout << p1.get_number() << std::endl;

    auto name = p1.get_name();
    {
        Tweeter t1("Someone", "Else", 777, "@someoneelse");
        std::string other_name = t1.get_name();
        std::cout << other_name << std::endl;
        
        std::cout << "Is p1 < t1 " << (p1 < t1) << std::endl;
    }


    std::cout << name << std::endl;

    Status s = Approved;

    FileError fe = FileError::ok;
    NetworkError ne = NetworkError::disconnected;
    
    return 0;
}
