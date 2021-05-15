## README file for Chapter 2 : Functions and Files

All required examples in this section will be named based on the section they are present in this README.

i.e An example program that demonstrates the concept of 2_A section of this README shall be named as "2_A.cpp"

#### `2_A) Introduction to Functions & return values` :

   - The C++ standard only defines the meaning of 3 status codes: 0, EXIT_SUCCESS, and EXIT_FAILURE.
   - C++ disallows calling the main function explicitly.
   - If a function has a non-void return type, it must return a value of that type. Failure to do so will result in undefined behavior.
   - The only exception to this rule is for function main(), which will assume a return value of 0 if one is not explicitly provided.
   - A function can only return a single value back to the caller each time it is called.

#### `2_B) Forward Declarations` :

   - If a forward declaration is made, but the function is never called, the program will compile and run fine.
   - However, if a forward declaration is made and the function is called, but the program never defines the function, the program will compile okay, but the linker will complain that it can’t resolve the function call.

#### `2_C) Translation & the preprocessor` : 

   - Prior to compilation, the code file goes through a phase known as translation. Many things happen in the translation phase (https://en.cppreference.com/w/cpp/language/translation_phases) to get your code ready to be compiled.
   - A code file with translations applied to it is called a translation unit.
   - The most noteworthy of the translation phases involves the preprocessor. The preprocessor is best thought of as a separate program that manipulates the text in each code file.
   - Preprocessor directives start with a # symbol. There are many directives extensively used in C++ such as :
        | S.No. | directive | Description |
        | :------| :------| :------|
        | 1 | #include | includes |
        | 2 | #define  | macro defines (With and without substitution text) |
        | 3 | #ifdef, #ifndef, #endif, #if, #elif, #else | conditional compilation | 
  
   - #define directive is used to create macro. There are two basic types of macros: object-like macros (with and without substitution text), and function-like macros.
        
            #define ONE 1 //Object like macros with substitution text 
            #define FLAG  //Object like macros without substitution text used for conditional compilation
   - Directives are only valid from the point of definition to the end of the file in which they are defined. Directives defined in one code file do not have impact on other code files in the same project. (See 2_C.cpp)

#### `2_D) Header files & includes` :

   - #include <> vs #include "" :
   
         a) #include "" has more scope of finding the include file over #include <>.
         b) When we use angled brackets, we’re telling the preprocessor that this is a header file we didn’t write ourselves. The compiler will search for the header ONLY in the directories specified by the include directories. The compiler will not search for the header file in your project’s source code directory.
         c) When we use double-quotes, we’re telling the preprocessor that this is a header file that we wrote. The compiler will first search for the header file in the current directory. If it can’t find a matching header there, it will then search the include directories.
         d) #include "iostream" (NOT SUGGESTED) and #include<iostream> will compile.
         e) #include<userDefined.hpp> won't compile but #include "userDefined.hpp" will.
         
   - Including header files from other directories :
         
         a) It's a bad way to include a relative path to the header file you want to include as part of the #include line. The downside of this approach is that it requires you to reflect your directory structure in your code. If you ever update your directory structure, your code won’t work anymore.
         b) A better method is to tell your compiler or IDE that you have a bunch of header files in some other location, so that it will look there when it can’t find them in the current directory. This can generally be done by setting an include path (in CMakeLists.txt or through command line eg. "g++ -o main -I/source/includes main.cpp").

#### `2_E) Header guards` :

   - Many compilers support a simpler, alternate form of header guards using the #pragma directive (#pragma once)
   - However, #pragma once is not an official part of the C++ language, and not all compilers support it.

### GOOD PRACTICE :
```
1) We should define our main function at the bottom of our code file, below other functions.
2) Use explicit namespace prefixes to access identifiers defined in a namespace. i.e avoid the using directive (using namespace <name>) at the top of your program. They violate the reason why namespaces were added in the first place.
3) It is recommended to avoid macros(especially object-like macros with substitution text) altogether and instead use const, constexpr.
4) function-like macros should be avoided as almost anything they can do can be done by a normal function.
5) Use double quotes to include header files that you’ve written or are expected to be found in the current directory. Use angled brackets to include headers that come with your compiler, OS, or third-party libraries you’ve installed elsewhere on your system.
6) Many of the libraries inherited from C that are still useful in C++ are given a c prefix (e.g. stdlib.h became cstdlib). Both works. But it's a good practice to use the C++ headers. i.e When including a header file from the standard library, use the no extension version (without the .h) if it exists.
7) Each file should explicitly #include all of the header files it needs to compile. Do not rely on headers included transitively from other headers.
8) Order your #includes as follows: your own user-defined headers first, then 3rd party library headers, then standard library headers, with the headers in each section sorted alphabetically.
9) Always include header guards
10) Each header file should have a specific job, and be as independent as possible.
11) Only #include what you need (don’t include everything just because you can).
12) Do not #include .cpp files.
