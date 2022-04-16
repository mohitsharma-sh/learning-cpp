#include "node.h"
#include<iostream>
#include<sstream>

node::node() // Default Constructor
{
    std::cout << "Default Constructor" << std::endl;
}

node::node(int val) : val {val} // Constructor
{
    std::cout << "Constructor (with " << val << " argument)" << std::endl;
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

    // These two are critical for move constructor
    source.left = nullptr;
    source.right = nullptr;
}

node& node::operator=(node const& rhs) // Copy Assignment Operator
{

    std::cout << "Copy Assignment" << std::endl;
    val = rhs.val;
    left = nullptr;
    right = nullptr;
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

std::ostream& operator<<(std::ostream& os, node const& tree)
{
    // Print the tree in inorder fashion

    if (tree.left)
    {
        os << *(tree.left);
    }

    os << tree.val << " ";
    if (tree.right)
    {
        os << *(tree.right);
    }

    return os;
} 

std::istream& operator>>(std::istream& is, node& tree)
{
    // Assume all numbers to be inserted to be in a single line
    // separated by spaces
    
    std::cout << "operator>>" << std::endl;
    int num;
    std::string all_numbers;
    std::getline(is, all_numbers);

    std::istringstream iss(all_numbers);

    iss >> num;

    tree = node {num};

    while (iss >> num)
    {
        tree.insert(num);
    }

    return is;
}


// node new_tree = tree + 1;
node node::operator+(int i) const
{
    node new_tree = node {val + i};
    
    if (left)
    {
        new_tree.left = new node {(*left) + i}; // Move constructor + Standard constructor
    }

    if (right)
    {
        new_tree.right = new node {(*right) + i};
    }

    return new_tree;
}

node& node::operator+=(int i)
{
    val += 1;

    if (left)
    {
        (*left) += i;
    }

    if (right)
    {
        (*right) += i;
    }

    return *this;
}
