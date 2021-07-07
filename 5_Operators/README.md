## README file for Chapter 5 : Operators

#### 5_A) Operator precedence & Associativity :

    - Post-increment/decrement operator has higher precedence over pre-increment/decrement.
    
#### 5_B) Increment and Decrement Operators :

    - The prefix increment/decrement operators are very straightforward. First, the operand is incremented or decremented, and then expression evaluates to the value of the operand.
    - Eg. int x{5};
          int y = ++x; // x is incremented to 6, x is evaluated to the value 6, and 6 is assigned to y. i.e. x = 6 and y = 6
    - The postfix increment/decrement operators are trickier. First, a copy of the operand is made. Then the operand (not the copy) is incremented or decremented. Finally, the copy (not the original) is evaluated.
    - Eg. int x{5};
          int y = x++; // x is incremented to 6, copy of original x is evaluated to the value 5, and 5 is assigned to y. i.e. x = 6 and y = 5

#### 5_C)  :

    - 

### GOOD PRACTICE :
```
1) Avoid using operator== and operator!= with floating point operands.
