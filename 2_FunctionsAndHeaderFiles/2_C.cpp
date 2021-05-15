/*
 * @author: Eranki Shashanka
 * @Date  : 15-May-2021
 * @brief : About object-like macros (with and without substitution text) and their scope
 */

#include <iostream>

// For general readability, you’ll generally want to #define identifiers at the beginning of the file.
// The scope of PRINT begins from here and lasts till the EOF.
#define PRINT 3

void fn()
{
    // The scope of PRINT begins from here and lasts till the EOF.
    // Don't consider that FUNCTION_PRINT will have local scope.
    #define FUNCTION_PRINT

    // We can #define the object-like macro without substitutuon any number of times as it's a mere flag expression. Doesn't give compilation errors
    #define PRINT

    // Doesn't give any compilation errors. Instead it throws warning.
    // warning: "PRINT" redefined
    #define PRINT 0
}

int main()
{
    #ifdef FUNCTION_PRINT
    std::cout<<"Function Print\n";
    #endif

    #ifdef PRINT
    std::cout<<"Print\n";
    #endif

    // gets excluded from compilation
    #if (PRINT == 3)
    std::cout<<"PRINT = 3\n";
    #endif

    // gets excluded from compilation
    #if PRINT
    std::cout<<"PRINT = 2\n";
    #endif

    // gets included for compilation
    #if PRINT == 0
    std::cout<<"PRINT = 2\n";
    #endif

    return 0;
}