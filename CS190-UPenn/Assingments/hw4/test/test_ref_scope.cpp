#include<iostream>
#include<string>

int main()
{
    std::string name = "Mohit";
    {
        std::string& another_name = name;
    }

    std::cout << another_name << std::endl;
    return 0;
}
