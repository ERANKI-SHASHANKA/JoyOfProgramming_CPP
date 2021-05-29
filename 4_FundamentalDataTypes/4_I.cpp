/*
 * @author: Eranki Shashanka
 * @Date  : 29-May-2021
 * @brief : Literal constants
 */

#include <iostream>
#include <bitset>   //std::bitset

int main()
{
    // floating point literal constants have a type of double.
    // To make them float literals instead, the f (or F) suffix should be used
    float a{3.4};
    std::cout<<"(double type literal) a = "<<a<<'\n';
    float b{3.4f};
    std::cout<<"(float type literal) b = "<<b<<'\n';

    int c{012}; //Octal literal
    std::cout<< std::oct <<"(octal literal 12) c = "<<c<<'\n';                  //Output : 12
    std::cout<< std::dec <<"(octal literal 12) c in decimal = "<<c<<'\n';       //Output : 10
    
    int d{0xA}; //Hexadecimal literal
    std::cout<< std::hex <<"(Hexadecimal literal A) d = "<<d<<'\n';             //Output : A
    std::cout<< std::dec <<"(Hexadecimal literal A) d in decimal = "<<d<<'\n';  //Output : 10

    unsigned long long e{0b1010}; //Binary literal (since C++14)
    std::cout<<"(Binary literal 1010) e in decimal = "<<e<<'\n';                //Output : 10

    // std::cout doesn’t come with this capability built-in to print binary numbers
    // C++ standard library includes a type called std::bitset
    // we can define a std::bitset variable and tell std::bitset how many bits we want to store.
    // The number of bits must be a compile time constant. 
    // std::bitset can be initialized with an unsigned integral value (in any format, including decimal, octal, hex, or binary).
    std::cout<<"(Binary literal 1010) e = "<<std::bitset<4>{e}<<'\n';           //Output : 1010
    // If the number of bits given as input to std::bitset is 3 then            //Output : 010
    // If the number of bits given as input to std::bitset is 6 then            //Output : 001010

    return 0;
}