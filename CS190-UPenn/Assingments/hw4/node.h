#pragma once
#include<iostream>
#include<memory>

class node
{
private:
    int val = 0;
    std::unique_ptr<node> left;
    std::unique_ptr<node> right;
public:
    node();                             // Default Constructor
    node(int);                          // Constructor
    ~node();                            // Destructor
    node(node const& rhs);              // Copy Constructor
    node(node&& rhs);                   // Move Constructor
    node& operator=(node const& rhs);   // Copy Assignment Operator
    node& operator=(node&& rhs);        // Move Assignment Operator 

    void swap(node& other);             // member swap function

    bool search(int) const;
    void insert(int);

    node operator+(int i) const;
    node& operator+=(int i);

    friend std::ostream& operator<<(std::ostream& os, node const& tree);
    friend std::istream& operator>>(std::istream& in, node& tree);
};

std::ostream& operator<<(std::ostream& os, node const& tree);
std::istream& operator>>(std::istream& in, node& tree);
