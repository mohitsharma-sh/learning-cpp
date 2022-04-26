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

    // Can't I recursively invoke the copy constructor like this?
    if (source.left)
    {
        *left = *source.left;
    }
    if (source.right) 
    {
        *right = *source.right;
    }
}

node::node(node&& source) // Move Constructor
{

    std::cout << "Move Constructor" << std::endl;
    val = source.val;
    left = std::move(source.left);
    right = std::move(source.right);

    // These two are critical for move constructor
    source.left = nullptr;
    source.right = nullptr;
}

void node::swap(node& other)
{
    // Q: Isn't this the default behavior of std::swap
    std::swap(val, other.val);
    std::swap(left, other.left); 
    std::swap(right, other.right);
}

node& node::operator=(node const& rhs) // Copy Assignment Operator
{
    // Use copy and swap idiom
    std::cout << "Copy Assignment" << std::endl;

    node copy = rhs; // copy is made
    copy.swap(*this);

    return *this;

}

node& node::operator=(node&& rhs) // Move Assignment Operator
{
    
    std::cout << "Move Assignment" << std::endl;

    node copy = std::move(rhs); // copy is made
    copy.swap(*this);

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
            left = std::make_unique<node>(i);
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
            right = std::make_unique<node>(i);
        }
    }
}

node::~node() // Destructor
{
    std::cout << "Deleting node " << val << std::endl;
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
    node new_tree {val + i};
    
    if (left)
    {
        node temp_left {*left + i}; // standard constructor
        *new_tree.left = std::move(temp_left); // Move assignment operator
    }

    if (right)
    {
        node temp_right {*right + i};
        *new_tree.right = std::move(temp_right);
    }

    return new_tree;
}

node& node::operator+=(int i)
{
    val += i;

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
