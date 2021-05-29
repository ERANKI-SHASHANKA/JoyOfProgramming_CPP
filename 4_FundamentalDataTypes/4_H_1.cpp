/*
 * @author: Eranki Shashanka
 * @Date  : 29-May-2021
 * @brief : Using std::string with std::cin
 */

#include <iostream>

int main()
{
    std::string str;
    // using operator>> to extract a string from cin, 
    // operator>> only returns characters up to the first whitespace it encounters.
    // Any other characters are left inside std::cin, waiting for the next extraction.
    // Eg. Jonh Wright
    std::cout<<"Enter your full name \n";
    std::cin>>str;
    std::cout<<str<<'\n'; // John

    // Won't wait for us to input an age
    // prints default value of int
    int age;
    std::cin>>age;
    std::cout<<age<<'\n'; // 0

    // To read a full line of input into a string, 
    // you’re better off using the std::getline() function instead. 
    // std::getline() takes two parameters: 
    // i)   std::cin, 
    // ii)  string variable.


    return 0;
}