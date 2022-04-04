#include "complex.h"
#include<iostream>
#include<string>
#include<fstream>
ComplexNumber fixed_additive(1, 1);

ComplexNumber handle_stdin()
{
    
    ComplexNumber latest, cumulative;
    while (std::cin >> latest)
    {
        cumulative += latest;
        std::cout << latest + fixed_additive << std::endl;
    }

    return cumulative;
}

ComplexNumber handle_file(std::string fname)
{
    ComplexNumber cumulative, latest;
    std::ifstream infile(fname);

    std::string line;
    while (true)
    {
        infile >> latest;
        if (!infile) break;
        std::cout << latest + fixed_additive << std::endl;
        cumulative += latest;
    }

    return cumulative;    
}
int main()
{
    
    int user_input;
    while (true)
    {
        std::cout << "Please enter 0 for stdin, 1 for file input" << std::endl;
        std::cin >> user_input;

        if (user_input == 0 || user_input == 1) break;
    }

    ComplexNumber cumulative;

    if (user_input == 0)
    {
        std::cout << handle_stdin() << std::endl;
    } else
    {
        std::string fname;
        std::cin >> fname;
        std::cout << handle_file(fname) << std::endl;
    }
    return 0;
}
