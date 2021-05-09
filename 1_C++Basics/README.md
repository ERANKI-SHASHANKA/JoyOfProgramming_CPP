All required examples in this section will be named based on the section they are present in this README. 
i.e An example program that demonstrates the concept of 1_C section of this README shall be named as "1_C.cpp"

1_A) Comments :
    - Multi-line style comments can not be nested.
    - Don’t use multi-line comments inside other multi-line comments. Wrapping single-line comments inside a multi-line comment is okay.

1_B) Variables :
    - RAM is used to hold data while the program is running.

1_C) Variables assignment & Initialization :
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

1_D) Introduction to iostream: cout, cin, and endl :




GOOD PRACTICE :
1) Favor direct list initialization whenever possible.
2) Initialize your variables upon creation.
