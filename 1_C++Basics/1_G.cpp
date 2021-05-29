/*
 * @author: Eranki Shashanka
 * @Date  : 23-May-2021
 * @brief : Understanding Pre-increment and Post-increment operators
 */

#include <iostream>

int main()
{
    int i = 4;
    int j{0};

    //POST-INCREMENT --- j = 4 and i = 5 
    //j = i++;

    //PRE-INCREMENT ---  j = 5 and i = 5
    //j = ++i;

    /*
        1) The i variable is assigned the value of 4;
        2) We take the original value of i (4), multiply it by 2, assign the result (8) to j and eventually (post-)increment the i variable (it equals 5 now);
        3) We (pre-)decrement the value of j (it equals 7 now); this reduced value is taken and multiplied by 2 and the result (14) is assigned to the variable i.
    */
    j = 2 * i++; 
    i = 2 * --j;
    
    // i = 14 and j = 7
    std::cout<<"i = "<<i<<"; j = "<<j<<'\n';

    return 0;
}