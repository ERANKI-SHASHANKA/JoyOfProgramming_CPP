/*
 * @author: Eranki Shashanka
 * @Date  : 29-May-2021
 * @brief : using std::getline() to input text
 */

#include <iostream>

int main()
{
    std::cout<<"Enter age \n";
    int age{};
    std::cin>>age;

    // The below code if uncommented, won't wait for user input after entering the age.
    // This is because :
    /* when you enter a value using operator>>,
     * std::cin not only captures the value, 
     * it also captures the newline character ('\n') that occurs when you hit the enter key.
     * So when we type 27(age) and then hit enter, std::cin receives the string "27\n".
     * It then extracts the 27 to variable age, leaving the newline character behind for later.
     * Then, when std::getline() goes to read the name, it sees "\n" is already in the stream,
     * and figures we must have previously entered an empty string! 
/*
    std::cout<<"Enter full name \n";
    std::string name{};
    std::getline(std::cin,name);
*/

    // std::ws input manipulator, tells std::getline() to IGNORE any leading whitespace characters:
    std::cout<<"Enter full name \n";
    std::string name{};
    std::getline(std::cin>>std::ws,name);

    std::cout<<"Name = "<<name<<"\n age = "<<age<<'\n';
    return 0;
}