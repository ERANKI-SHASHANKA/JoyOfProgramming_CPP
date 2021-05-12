/*
 * @author: Eranki Shashanka
 * @Date  : 09-May-2021
 * @brief : About std::cout, std::cin, std::endl and '\n'
 */

#include <iostream>

int main()
{
    // ===== Part I =====
    int i{15};

    std::cout<<i<<'\n'; // 15
    std::cout<<i<<"\n"; // 15
    std::cout<<"Hi \n"; // Hi

    // warning: multi-character character constant 
    // Output - 1214849034 (Is this a Garbage value??? - NO)
    // Also '\n' below, doesn't move the cursor to the next line 
    std::cout<<'Hi \n'; 

    std::cout<<"Hi /n";  // Hi /n

    // warning: unknown escape sequence: '\/'
    // Output - Hi /n
    std::cout<<"Hi \/n"; 
    
    // warning: multi-character character constant 
    // Output - 12142
    std::cout<<'/n';
    std::cout<<'\n';

    // ===== Part II =====
    std::cout << "Enter a number: ";
    int x{};
    // Try entering integer, non-integer, character values and see the output
    std::cin >> x;

    // For input : 2            ------- Output : 2
    // For input : 2.5          ------- Output : 2  
    // For input : -2.5         ------- Output : -2  
    // For input : A            ------- Output : 0  
    // For input : AbC          ------- Output : 0 
    // For input : 2A3;s        ------- Output : 2 
    // For input : A3;s         ------- Output : 0
    // For input : 345AB.;      ------- Output : 345
    // For input : .;?>         ------- Output : 0
    // For input > 2147483647   ------- Output : 2147483647 (max limit, post this int overflows)
    std::cout << "You entered " << x << '\n';

    std::cout<<"Hello\n"; // Valid

    // Invalid (error: missing terminating " character)
    //  std::cout<<"Hello
    //  World"; */

    // Valid
    std::cout<<"Hello"
    "World\n";

    return 0;
}