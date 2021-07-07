/*
 * @author: Eranki Shashanka
 * @Date  : 29-May-2021
 * @brief : About char data type
 */

#include <iostream>

int main()
{
    // The fixed width integer int8_t is usually treated the same as a signed char in C++
    // It will generally print as a char instead of an integer.
    uint8_t a{97};
    int8_t b{98};

    // error: invalid conversion from ‘const char*’ to ‘char’
    // char c{"a"};
    char c{'a'};

    // Since this program is not unicode compatible
    char16_t d{'D'}; // std::cout<<d; ==prints==> 68
    
    std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<'\n';
    return 0;
}