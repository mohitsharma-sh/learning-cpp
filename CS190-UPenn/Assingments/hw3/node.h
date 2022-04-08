#pragma once

class node
{
private:
    int val;
    node* left = nullptr;
    node* right = nullptr;
public:
    node(int);
    ~node();                            // Destructor
    node(node const& rhs);              // Copy Constructor
    node(node&& rhs);                   // Move Constructor
    node& operator=(node const& rhs);   // Copy Assignment Operator
    node& operator=(node&& rhs);        // Move Assignment Operator 

    bool search(int) const;
    void insert(int);
};
