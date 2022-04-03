#include "person.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int a = 3;

    cout << "a is " << a << endl;

    int& rA = a;
    rA = 5;

    // int const & cSA = a; This will not work!
    int& csA = a;
    csA = 7;


    cout  << "a is " << a << endl;

    Person p = Person("Mohit", "Sharma", 190);

    Person& rP = p;

    rP.set_number(380);

    cout << "Person's number is " << p.get_number() << endl;

    int* pA = &a;

    cout << "pA is pointint to a memory with value " << (*pA) << endl;
    
    *pA = 100;

    cout << "pA is pointing to a memory of variable with value " << a << endl;

    Person* pP = nullptr;
    
    pP = & p;

    cout << "Getting person's number using a pointer " << pP->get_number() << endl;


}
