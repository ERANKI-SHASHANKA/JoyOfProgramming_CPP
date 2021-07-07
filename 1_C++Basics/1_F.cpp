/*
 * @author: Eranki Shashanka
 * @Date  : 12-May-2021
 * @brief : About Whitespaces
 */

#include <iostream>

int main()
{
    std::cout<<"Hello\n"; // Valid

    // Invalid (error: missing terminating " character)
    //  std::cout<<"Hello
    //  World";

    // Valid - Output : HelloWorld
    std::cout<<"Hello"
    "World\n";

    // Valid - Output : Hello   World
    std::cout<<"Hello\
    World\n";

    // Valid - Output : 27 = 
    std::cout<< 3+4
    *6
    <<" = "
    ;

    // No Compilation error. Undefined/Unexpected Output : ;L = 
    std::cout<< 3+4
    + "A"
    <<" = "
    ;

    // No Compilation error. Undefined/unexpected output : �� =
    std::cout<< 3+4
    * 6 + "A"
    <<" = "
    ;
    
    return 0;
}