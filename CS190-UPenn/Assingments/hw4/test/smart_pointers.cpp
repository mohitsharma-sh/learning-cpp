#include<iostream>
#include<string>
#include<memory>

void remove_lastname(std::unique_ptr<std::string> sp)
{
    std::cout << "Say goodbye to your first name" << std::endl;
    *sp = "Mohit";
    std::cout << "First name removed" << std::endl;
}

int main()
{
    std::string name = "Mohit Sharma";
    std::unique_ptr<std::string> up_name = std::make_unique<std::string>(name);

    std::cout << "Hello: " << *up_name << std::endl;
    remove_lastname(std::move(up_name));
    std::cout << "Hello Again: " << *up_name << std::endl;
    return 0;
}
