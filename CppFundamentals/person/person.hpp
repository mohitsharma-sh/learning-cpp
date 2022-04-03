#pragma once
#include <string>

class Person {

    private:
        std::string first_name;
        std::string last_name;
        int arbitrary_number;
        friend bool operator<(int i, Person const& p);

    public:
        Person();
        Person(std::string first, std::string second, int arbitrary);
        ~Person();
        std::string get_name() const;
        int get_number() const {return arbitrary_number;};
        void set_number(int number) {arbitrary_number = number;};
        bool operator<(Person const& p) const;
        bool operator<(int i) const;
};

bool operator<(int i, Person const& p);
