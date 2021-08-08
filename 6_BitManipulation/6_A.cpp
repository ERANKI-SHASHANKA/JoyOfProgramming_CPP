/*
 * @author: Eranki Shashanka
 * @Date  : 09-July-2021
 * @brief : About std::bitset
 */

#include <bitset>
#include <vector>
#include <iostream>
 
int main()
{
    std::bitset<4> num{17}; // 17 = 1'0001 but the size of std::bitset is given as 4, hence only last 4 bits will be considered
    // Compiles but crashes at run time "std::out_of_range" exception
    //num.set(5); 
    num.set(1);  // Set bit position @1 = 0011
    num.flip(); // flip the bits at all positions = 1100
    num.reset();// Set all bits to 0
    num.set();  // Set all bits to 1
    std::cout<< num<< '\n';

    std::bitset<8> bits{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    bits.set(3); // set bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4); // flip bit 4 (now we have 0001 1101)
    bits.reset(4); // set bit 4 back to 0 (now we have 0000 1101)
 
    std::cout << "All the bits: " << bits << '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

    // If we don't know the size at runtime we can use std::vector<bool>
    std::vector<bool> bitsVector;//{1,0,0};
    bitsVector.push_back(1);
    bitsVector.push_back(0);
    // set(), reset(), test() doesn't apply here on std::vector
    for (auto itr : bitsVector)
    {
        std::cout<<"####### "<<itr<<'\n';
    }
    bitsVector.flip();
    for (auto itr : bitsVector)
    {
        std::cout<<"###***#### "<<itr<<'\n';
    }
    return 0;
}