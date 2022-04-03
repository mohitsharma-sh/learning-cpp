#include<iostream>

template <class T>
T max(T const& t1, T const& t2)
{
    return t1 < t2 ? t2 : t1;
}
int main()
{
    std::cout << max(0, 1) << std::endl;
    std::string s1 = "abc";
    std::string s2 = "abcd";
    std::cout << max(s1, s2) << std::endl;
    return 0;
}
