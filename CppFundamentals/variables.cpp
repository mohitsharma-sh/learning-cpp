#include <iostream>

int main(){
    int i1 = 1;
    int i2; i2 = 2;
    int i3(3);
    int i4{ 4 }; // Used for collection initialization

    double d1 = 2.2;
    double d2 = i1;
    int i5 = d1;
    
    char c1 = 'a';
    bool flag = false; // If you do bool flag = d1 (conversion happens and it's essentially non-zero check)
    
    auto a1 = 1;
    auto a2 = 2.2;
    auto a3 = 'a';
    auto a4 = "a"; // char* c style string
    auto a5 = 3L; // Long literal
    auto a6 = 1'000'000'000'000; // Long Long (apostrophe separators got introduced in cpp 14)
    auto a7 = 0xFF; // Hexdecimal literal
    auto a8 = 0b111; // binary literal

    std::cout << "i1=" << i1 << std::endl;
    std::cout << "i2=" << i2 << std::endl;
    std::cout << "i3=" << i3 << std::endl;
    std::cout << "i4=" << i4 << std::endl;
    std::cout << "i5=" << i5 << std::endl;
    std::cout << "d1=" << d1 << std::endl;
    std::cout << "d2=" << d2 << std::endl;

    std::cout << "c1=" << c1 << std::endl;
    std::cout << "flag=" << flag << std::endl;

}

