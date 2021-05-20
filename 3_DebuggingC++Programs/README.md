## README file for Chapter 3 : Debugging C++ programs

#### 3_A) Basic debugging tactics :

    - Commenting out your code in parts.
    - Validating your code flow by adding debug statements.
    - Printing values of variables (including parameters) or expressions to ensure that they are correct.

#### 3_B) More debugging tactics :

    - using printing statements to debug isn’t great for a number of reasons:
        a) Debug statements clutter your code.
        b) Debug statements clutter the output of your program.
        c) Debug statements must be removed after you’re done with them, which makes them non-reusable.
        d) Debug statements require modification of your code to both add and to remove, which can introduce new bugs. 

    - To mitigate some of these above disadvantages, we have some more techniques:
        a) Conditionalizing your debugging code
        Eg.
            #define ENABLE_DEBUG // comment out to disable debugging
 
            int main()
            {
                #ifdef ENABLE_DEBUG
                std::cerr << "main() called\n";
                #endif
                return 0;
            }

        b) Using a logger such as DLT, PLOG etc. 
        c) Using integrated Debuggers available in most of the modern IDEs (using stepping, breakpoints, watches, call stack window etc.).

### GOOD PRACTICE :
```
1) When printing information for debugging purposes, use std::cerr instead of std::cout. 
One reason for this is that std::cout may be buffered, which means there may be a pause between when you ask std::cout to output information and when it actually does. If you output using std::cout and then your program crashes immediately afterward, std::cout may or may not have actually output yet. This can mislead you about where the issue is. On the other hand, std::cerr is unbuffered, which means anything you send to it will output immediately. This helps ensure all debug output appears as soon as possible (at the cost of some performance, which we usually don’t care about when debugging).
