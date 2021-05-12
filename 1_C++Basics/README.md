## README file for Chapter 1 : C++ Basics

All required examples in this section will be named based on the section they are present in this README.

i.e An example program that demonstrates the concept of 1_C section of this README shall be named as "1_C.cpp"

`1_A) Comments` :

    - Multi-line style comments can not be nested.
    - Don’t use multi-line comments inside other multi-line comments. Wrapping single-line comments inside a multi-line comment is okay.

`1_B) Variables` :

    - RAM is used to hold data while the program is running.

`1_C) Variables assignment & Initialization` :
    
    - C++ supports 3 ways to initialize variables.
        a) Copy initialization ('=')
            Eg. int a = 5;
        b) Direct initialization ('()')
            Eg. int a(5);
        c) List initialization ('{}')
            Eg. int a{5}; OR int a = {5};
            
    - For simple data types (like integers), copy and direct initialization are essentially the same.
    - Value initialization : initilizes a variable with its default value. Eg. int a{}; => a = 0
    - List initialization has the added benefit of disallowing “narrowing” conversions. This means that if you try to use list initialization to initialize a variable with a value it can not safely hold, the compiler will throw a warning or an error.
     Eg. int a{4.5}; gives an error, whereas int a(4.5); or int a = 4.5; won't give error and store a = 4

`1_D) Introduction to iostream: cout, cin, and endl` :

    - std::endl vs ‘\n’ : 
        (i) Using std::endl can be a bit inefficient, as it actually does two jobs : 
            (a) it moves the cursor to the next line.
            (b) it “flushes” the output (makes sure that it shows up on the screen immediately).
        (ii) When writing text to the console using std::cout, std::cout usually flushes output anyway.
        (iii) The ‘\n’ character moves the cursor to the next line, but doesn’t do the redundant flush, so it performs better.

    - Note that you don’t need to use ‘\n’ when accepting input (std::cin), as the user will need to press the enter key to have their input accepted, and this will move the cursor to the next line.

`1_E) Keywords & Naming identifiers` :

    - As of C++20, C++ has 92 keywords (or reserver words).
    - C++ also defines special identifiers : override, final, import, and module. These have a specific meaning when used in certain contexts but are not reserved.
    - It is a convention in C++ that variable names should begin with a lowercase letter.
    - Identifier names that start with a capital letter are typically used for user-defined types (such as structs, classes, and enumerations).

`1_F) Whitespace and basic formatting` :

    - Quoted text separated by nothing but whitespace (spaces, tabs, or newlines) will be concatenated.

### GOOD PRACTICE :
```
1) Favor direct list initialization whenever possible.
2) Initialize your variables upon creation.
3) Prefer ‘\n’ over std::endl when outputting text to the console.
4) When working in an existing program, use the conventions of that program (even if they don’t conform to modern best practices). Use modern best practices when you’re writing new programs.
5) You should avoid naming your identifiers starting with an underscore, as these names are typically reserved for OS, library, and/or compiler use.
6) Your lines should be no longer than 80 chars in length.
