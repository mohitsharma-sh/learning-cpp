#include <string>
#include <iostream>

template <class T>
class Accum
{
    private:
        T total;

    public:
        Accum(T start): total(start) {}; 

        T operator+=(T const& t)
        {
            total += t;

            return total;
        };

        T get_total(){return total;};
};

int main()
{

    int start = 1;
    auto a = Accum<int>(start);

    for(int i=2; i <= 10; i++){
        a += i;
    }
    std::cout << "Starting from " << start << " accumulated value is " << a.get_total() << std::endl;

    std::string start2 = "My ";
    auto a2 = Accum<std::string>(start2);
    std::string s1 = "name ";
    std::string s2 = "is ";
    std::string s3 = "Mohit ";
    std::string s4 = "Sharma ";
    a2 += s1;
    a2 += s2;
    a2 += s3;
    a2 += s4;
    
    std::cout << "Starting from " << start2 << " accumulated value is " << a2.get_total() << std::endl;
    return 0;
}
