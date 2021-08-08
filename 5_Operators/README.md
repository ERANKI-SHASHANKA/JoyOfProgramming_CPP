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

#### 5_C) Logical Operators :

    - C++ provides Logical AND(&&),OR(||) and NOT(!) operators, but no logical EXOR operator as they can't be short circuit evaluated.
    - Short-circuit evaluation means, say (x > 5 && x < 8 && x==7), if the first AND evaluates to false, it doesn't check the next AND, as it knows the result is going to be false. Similarly is atleast one of the expression in Logical OR evaluates to true, it doesn't check for the other ORs.
    - Logical XOR can be mimiced using the != operator. Because in logical XOR if one operand is not equal to other operand, it evaluates to true.

### GOOD PRACTICE :
```
1) Avoid using operator== and operator!= with floating point operands.
2) When mixing logical AND and logical OR in a single expression, explicitly parenthesize each operation to ensure they evaluate how you intend.
