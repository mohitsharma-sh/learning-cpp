#include <string>
#include <iostream>

template <class T>
T my_max(T const& t1, T const& t2)
{
    return t1 < t2? t2: t1;
}

class Item
{
    private:
        int priority;

    public:
        Item(int priority): priority(priority){};
        int get_priority(){return priority;};
        bool operator<(Item const& other_item) const {return priority < other_item.priority;};
};

int main()
{
    std::cout << "Max of 1, 2 is " << my_max(1, 2) << std::endl; 
    std::string s1 = "a";
    std::string s2 = "b";

    std::cout << "Max of 'a' and 'b' is" << my_max(s1, s2) << std::endl;

    Item item1 = Item(1);
    Item item2 = Item(2);
    
    std::cout << "Max of item1 and item2 is " << my_max(item1, item2).get_priority() << std::endl;
    
    return 0;
}
