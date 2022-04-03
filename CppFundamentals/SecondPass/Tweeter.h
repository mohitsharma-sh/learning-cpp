#include "Person.h"

class Tweeter: public Person
{
    std::string twitterhandle;
    public:
        Tweeter(std::string first, std::string last, int arbitrarynumber, std::string handle);
        ~Tweeter();
};
