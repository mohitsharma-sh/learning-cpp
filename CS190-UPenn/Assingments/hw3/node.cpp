#include "node.h"
#include<iostream>

node::node(int val) : val {val} // Constructor
{
    std::cout << "Constructor" << std::endl;
}

node::node(node const& source) // Copy Constructor
{

    std::cout << "Copy Constructor" << std::endl;
    val = source.val;
    if (source.left)
    {
        left = new node(*source.left);
    }
    if (source.right) 
    {
        right = new node(*source.right);
    }
}

node::node(node&& source) // Move Constructor
{

    std::cout << "Move Constructor" << std::endl;
    val = source.val;
    left = source.left;
    right = source.right;

    source.left = nullptr;
    source.right = nullptr;
}

node& node::operator=(node const& rhs) // Copy Assignment Operator
{

    std::cout << "Copy Assignment" << std::endl;
    val = rhs.val;
    if (rhs.left)
    {
        left = new node(*rhs.left);
    }
    if (rhs.right) 
    {
        right = new node(*rhs.right);
    }

    return *this;

}

node& node::operator=(node&& rhs) // Move Assignment Operator
{
    
    std::cout << "Move Assignment" << std::endl;
    val = rhs.val;
    left = rhs.left;
    right = rhs.right;

    rhs.left = nullptr;
    rhs.right = nullptr;

    return *this;
}

bool node::search(int i) const
{
    bool result = false;
    if (i == val)
    {
        result = true;
    }
    else if (i < val)
    {
        // search in left subtree
        result = left ? left->search(i) : false;
    }
    else
    { 
        result = right ? right->search(i) : false;
    }

    return result;
}

void node::insert(int i)
{
    if (i < val)
    {
        if (left)
        {
            left->insert(i);
        }
        else
        {
            left = new node(i);
        }
    }
    else
    {
        if (right)
        {
            right->insert(i);
        }
        else
        {
            right = new node(i);
        }
    }
}

node::~node() // Destructor
{
    std::cout << "Deleting node " << val << std::endl;
    delete left; // Interesing
    delete right;
}
