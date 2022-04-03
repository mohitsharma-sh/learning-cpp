#pragma once
#include "person.hpp"
#include <string>

class Tweeter : public Person
{
    private:
        std::string handle;
    public:
        Tweeter(std::string first,
                std::string last,
                int arbitrary,
                std::string handle);
        ~Tweeter();
        std::string get_name() const;
};
