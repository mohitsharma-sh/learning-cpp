#include "node.h"
#include<iostream>

node create_node()
{
    node some_node {1};

    return some_node;
}

int main()
{
    node root1 {10};
    std::cout << "Finding " << 10 << " Result=" << root1.search(10) << std::endl;
    
    std::cout << "Finding " << 11 << " Result=" << root1.search(11) << std::endl;

    // all ways to call copy constructor
    node root2 = root1;

    //// Let's call move constructor

    //node root5 = std::move(root4);
    //node root6 = create_node();
    //
    //// Let's call copy assignment operator
    //node root7 {2};
    //root7 = root6;

    //// Move assignment
    //root7 = create_node();

    return 0;
}
