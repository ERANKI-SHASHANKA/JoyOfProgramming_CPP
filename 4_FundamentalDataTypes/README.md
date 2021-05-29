## README file for Chapter 4 : Fundamental Data Types

#### 4_A) Object sizes and sizeof operator :

    - The sizeof operator is a unary operator that takes either a type or a variable, and returns its size in bytes. 
    - Using the sizeof operator on the void type will cause compile error as void has no size.

#### 4_B) Signed integers :

    - There are 4 fundamental integer types : short, int, long, long long
    - "short a;" = "short int a;" = "signed short a;" = "signed short int a;" // Same is the case with other integer types also.
    - Integer overflow (often called overflow for short) occurs when we try to store a value that is outside the range of the type. In such a case, data is lost because the object doesn’t have enough memory to store everything.

#### 4_C) Unsigned integers :

    - If an unsigned value is out of range, usually it is divided by one greater than the largest number of the type, and only the remainder kept/stored.
    - Many developers (and some large development houses, such as Google) believe that developers should generally avoid unsigned integers. This is because :
        a) If two unsigned integers (a,b such that a<b) are subtracted, their result if it's negative leads to wrapping around to a number close to the top of the range. Eg. 3-5 = -2 shall be stored as 4294967294 and this may result in unexpected behaviour.
        b) Unexpected behavior can result when you mix signed and unsigned integers.

#### 4_D) Fixed width integers and std::size_t :

    - We know that C++ only guarantees that integer variables will have a minimum size -- but they could be larger, depending on the target system. But this may result in issues in cross-platform potability.
    - To help with cross-platform portability, C99 defined a set of fixed-width integers (in the stdint.h header which is cstdint in C++11) that are guaranteed to have the same size on any architecture. Eg. std::int8_t, std::uint8_t etc.
    - One of the downsides of using fixed-width integers is : it may be slower than a wider type on some architectures. If you need an integer to hold values from -10 to 20, you might be tempted to use std::int8_t. But your CPU might be better at processing 32 bit wide integers, so you just lost speed by making a restriction that wasn’t necessary.
    - To address the above downside, C++ provides 2 alternatives :
        a) The fast type (std::int_fast#_t) : It provides the fastest signed integer type with a width of at least # bits (where # = 8, 16, 32, or 64)
        b) The least type (std::int_least#_t): It provides the smallest signed integer type with a width of at least # bits (where # = 8, 16, 32, or 64).
    - sizeof(std::int_fast16_t) ==> 4 bytes (32 bits)
    - sizeof(std::int_least16_t) ==> 2 bytes (16 bits)
    
    - sizeof (and many functions that return a size or length value) return a value of type std::size_t. std::size_t is defined as an unsigned integral type, and it is typically used to represent the size or length of objects.
    - std::size_t also varies in size depending on the system. std::size_t is guaranteed to be unsigned and at least 16 bits.
    - size_t is defined to be big enough to hold the size of the largest object creatable on your system (in bytes).

### 4_E) Floating point numbers :

    - There are three different floating point data types: float, double, and long double.
    - Floating point data types are ALWAYS signed.
    - By default, floating point literals default to type double. An f suffix is used to denote a literal of type float.
    - When outputting floating point numbers, std::cout has a default precision of 6 i.e, it assumes all floating point variables are only significant to 6 digits.
    - We can override the default precision that std::cout shows by using an output manipulator function named std::setprecision() defined in iomanip header.
    - Rounding errors occur when a number can’t be stored precisely. Eg. say size of float is 8 bytes, 
        then say,
        float f { 123456789.0f }; // f has 10 significant digits
        std::cout << std::setprecision(9); // to show 9 digits in f 
        OUTPUT : 123456792 // This is because the float had to truncate the approximation due to its limited memory. So it printed correctly till 7

### 4_F) Boolean Values :

    - If you want std::cout to print “true” or “false” instead of 0 or 1, you can use std::boolalpha. You can use std::noboolalpha to turn it back off.
        Eg. std::cout<<std::boolalpha;
            std::cout<<true<<'\n'; // Prints true
            std::cout<<std::noboolalpha;
            std::cout<<true<<'\n'; // Prints 1

    - You can’t initialize a Boolean with an integer using uniform initialization(error: narrowing conversions disallowed) whereas copy initialization allows implicit conversion from int to bool.
    - std::cin only accepts two inputs for boolean variables: 0 and 1 (not true or false). Any other inputs will cause std::cin to silently fail.

### 4_G) Chars :

    - The fixed width integer int8_t is usually treated the same as a signed char in C++, so it will generally print as a char instead of an integer.
    - char16_t and char32_t were added to C++11 to provide explicit support for 16-bit and 32-bit Unicode characters. char8_t has been added in C++20.

### 4_H) std::string :

    - To read a full line of input into a string, you’re better off using the std::getline() function. std::getline() takes two parameters: the first is std::cin, and the second is your string variable.
    - std::getline(std::cin>>std::ws,variable) : The std::ws input manipulator tells std::cin to ignore any leading whitespace. Note that std::ws is not a function.
    - Using the extraction operator (>>) with std::cin ignores leading whitespace. But std::getline does not ignore leading whitespace unless you use input manipulator std::ws.

### 4_I) Literals :

    - C++ has two kinds of constants: literal constants, and symbolic constants.
    - Literal constants (usually just called literals) are values inserted directly into the code. Eg. 5(integer literal), true(boolean literal), 3.4(double literal)
    - If an integer number is preceded by the 0 digit, it will be treated as an octal value.
    - If an integer number is preceded by 0x or 0X, it will be treated as an hexadecimal value. 
    - In C++14, we can assign binary literals by using the 0b prefix. Eg. int bin = 0b1010;
    - Because long literals can be hard to read, C++14 also adds the ability to use a quotation mark (') as a digit separator. Eg. long value = 2'132'673'462;
    - Printing decimal, octal, hexadecimal, and binary numbers:
        int x { 12 };
        std::cout << x;                 //Decimal (by default)                                              o/p = 12
        std::cout << std::hex << x;     //Hexadecimal                                                       o/p = c
        std::cout << x;                 //Hexadecimal output until it's explicitly changed to decimal.
        std::cout << std::oct << x;     //Octal                                                             o/p = 14
        std::cout << std::dec << x;     //Decimal                                                           o/p = 12
        std::cout << std::bitset<4>{x}; //Binary (std::bitset is part of <bitset> header)                   o/p = 1100
    
    - A magic number is a literal (usually a number) in the middle of the code that does not have any context.

### 4_J) const, constexpr and symbolic constants :

    - const variables :
        a) Const variables must be initialized when you define them.
        b) const variables can be initialized from other variables (including non-const ones)
        c) Const is often used with function parameters

    - Runtime vs Compile time constants :
        a) Runtime constants are those whose initialization values can only be resolved at runtime.
           Eg. std::cin>>age;
               const int userAge{age};
        b) Compile-time constants are those whose initialization values can be resolved at compile-time.
           Eg. const int gravity{9.8};
        c) Compile-time constants enable the compiler to perform optimizations that aren’t available with runtime constants. 

    - constexpr :
        a) C++11 introduced the keyword constexpr, which ensures that a constant must be a compile-time constant

    - symbolic constants :
        a) Using object-like macros with a substitution parameter ---> BAD
            REASON :
            Problem #1 - One of the evils of macros is that they don't know about or respect scope (or namespaces). Its a primitive and dumb textual "find and replace all". They leak out from one scope into another. From one library header into another. From a library header into client code and the other way. Causing havoc.
        b) Instead use constexpr to create the symbolic constants.
        c) in C++17 or newer, prefer "inline constexpr".
            

### GOOD PRACTICE :
```
1) Prefer the shorthand types that do not use the int suffix or signed prefix. (Ref. 4_B)
2) Avoid using unsigned numbers, except in specific cases or when unavoidable. (Ref. 4_C)
3) The fixed-width integers should be avoided, as they may not be defined on all target architectures. (Ref. 4_D)
4) Favor the std::int_fast#_t and std::int_least#_t integers when you need an integer guaranteed to be at least a certain minimum size. (Ref. 4_D)
5) Avoid the 8-bit fixed-width integer types. If you do use them, note that they are often treated like chars. (Ref. 4_D)
6) int should be preferred when the size of the integer doesn’t matter.
7) If you need a variable guaranteed to be a particular size and want to favor performance, use std::int_fast#_t.
8) If you need a variable guaranteed to be a particular size and want to favor memory conservation over performance, use std::int_least#_t. This is used most often when allocating lots of variables.
9) If using std::getline to read strings, use the std::ws input manipulator to ignore leading whitespace.
10) Don’t use magic numbers in your code.
11) Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr.
12) Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as const.
13) Avoid using #define to create symbolic constants macros.