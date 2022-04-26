#include "node.h"
#include<iostream>

int main()
{
    // Test operator>> overloading
    node root;
    std::cout << "Enter the space separated numbers you want to insert in a single line." << std::endl;
    std::cin >> root;
    
    std::cout << "You entered:" << std::endl;
    std::cout << root << std::endl;

    std::cout << "Adding 5 to the tree." << std::endl;
    std::cout << (root += 5) << std::endl;
    return 0;
}
