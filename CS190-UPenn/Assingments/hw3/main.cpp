#include "node.h"
#include<iostream>

int main()
{
    node* root = new node(10);
    std::cout << "Finding " << 10 << " Result=" << root->search(10) << std::endl;
    
    std::cout << "Finding " << 11 << " Result=" << root->search(11) << std::endl;
    delete root;
    return 0;
}
