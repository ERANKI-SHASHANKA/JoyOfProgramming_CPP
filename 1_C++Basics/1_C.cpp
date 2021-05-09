/*
 * @author: Eranki Shashanka
 * @Date  : 09-May-2021
 * @brief : Different types of Variable assignment and initialization
 */

#include <iostream>

int main()
{
    //Copy initialization. x and y will have value 4
    int x = 4;
    int y = 4.5;    //NO ERROR 
    
    //Direct initialization. 
    // int x(); //ERROR : int x()’ redeclared as different kind of symbol
    int a();        // std::cout<<a; --> 1 
    int b(4);       // b = 4
    int c(4.5);     // c = 4 NO ERROR
    int d = (3.5);  // d = 3 NO ERROR

    //List initialization. (preferred) and uniform for simple or complex datatypes
    int m{};   // called value initialization. Initlizes the variable with default value.(=0 here)
    int n({}); // warning: list-initializer for non-class type must not be parenthesized (n = 0)
    int o{3};
    //int p{3.5}; // ERROR : narrowing conversion of ‘3.5e+0’ from ‘double’ to ‘int’ inside { }
    
    // Initializing multiple variables
    int q(4.6), r{3}, s = 10;

    return 0;
}
