/*
 * @author: Eranki Shashanka
 * @Date  : 29-May-2021
 * @brief : const, constexpr, symbolic constants
 */

#include <iostream>

// Symbolic constant
#define GRAVITY 9.8 // BAD PRACTICE

namespace A
{
    // Error : below line expands to float 9.8{9.8}
    // This is the problem with MACROS; they don't know about or respect scope (or namespaces)
    // float GRAVITY{9.8};

    float gravity{GRAVITY};
}

int main()
{
    //==== 1. const ====
    // 1.a : Compile time constant
    const double gravity{9.8};

    int age;
    std::cout<<"Enter age \n";
    std::cin>>age;
    // 1.b : Run time constant
    const int userAge{age};
    
    //==== 2. constexpr (since C++11) ====
    // constexpr ensures that a const must be a compile time constant
    constexpr double gravityConst{9.8}; //OK
    constexpr double sumConst{3+7};     //OK
    int weight;
    std::cout<<"Enter Weight \n";
    std::cin>>weight;
    //constexpr int weightConst{weight};   //NOT OK, weight can't be resolved at compile time

    //==== 3. symbolic constants ====
    constexpr double gravity{9.8}; 
    inline constexpr double gravity17{9.8}; // since C++17

    return 0;
}