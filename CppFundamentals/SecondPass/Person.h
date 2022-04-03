#pragma once
#include<string>

class Person
{
    private:
        std::string firstname;
        std::string lastname;
        int arbitrarynumber;
        friend bool operator<(int number, Person const& person);

    public:
        Person(std::string first, std::string last, int arbitrarynumber);
        Person();
        ~Person();
        std::string getName() const;
        int getNumber() const;
        void setNumber(int newNumber);
        bool operator<(Person const& otherPerson) const;
        bool operator<(int number) const;
        bool operator==(Person const& otherPerson) const;
};

bool operator<(int number, Person const& person);
