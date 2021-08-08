## README file for Chapter 6 : Bit Manipulation

#### `6_A) Bit flags and bit manipulation via std::bitset` :
 
   - Modifying individual bits within an object is called bit manipulation.
   - Bit manipulation is useful in encryption and compression algorithms.
   - When individual bits of an object are used as Boolean values, the bits are called bit flags.
   - std::bitset provides 4 key functions that are useful for doing bit manipulation:
        | S.No. | function | Description |
        | :------| :------| :------|
        | 1 | test() | allows us to query whether a bit is a 0 or 1 |
        | 2 | set()  | allows us to turn a bit on (this will do nothing if the bit is already on) |
        | 3 | reset() | allows us to turn a bit off (this will do nothing if the bit is already off) | 
        | 4 | flip() | allows us to flip a bit value from a 0 to a 1 or vice versa | 
   - Each of these functions takes the position of the bit we want to operate on as their only argument. If no argument is passed, then the function applies to all the bits.
   - If the size of the bitset is not known at compile time, std::vector<bool> or boost::dynamic_bitset<> (boost library) may be used. 
   - std::bitset doesn't make it easy to get/set multiple bits at once. we then need to use traditional approaches.

#### `6_B) bitwise operators` :

   - Results of applying the bitwise shift operators to a signed integer are compiler dependent prior to C++20. 