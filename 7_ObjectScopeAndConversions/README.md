## README file for Chapter 7 : Object Scopes and Conversions

#### `7_A) Scopes and Default values` :
 
   - Unlike local variables, which are uninitialized by default, static variables are zero-initialized by default.
   - Non-constant global variables are also zero-initialized by default.

#### `7_B) Internal linkage` :

   - An identifier with internal linkage can be seen and used within a single file, but it is not accessible from other files (that is, it is not exposed to the linker). This means that if two files have identically named identifiers with internal linkage, those identifiers will be treated as independent.
   - Non-const Global variables by default have external linkage. In order to make them have have internal linkage, attach 'static' keyword. 
   - Const and constexpr global variables have internal linkage by default (and thus don’t need the static keyword)

#### `7_C) External linkage` :

   - An identifier with external linkage can be seen and used both from the file in which it is defined, and from other code files (via a forward declaration). In this sense, identifiers with external linkage are truly “global” in that they can be used anywhere in your program.
   - Functions have external linkage by default.
   - Global variables with external linkage are sometimes called external variables. To make a global variable external (and thus accessible by other files), we can use the 'extern' keyword

#### `7_D) Sharing global constants across multiple files` :

   - (I) Global constants as inline variables :
   1) Create a header file to hold these constants 
   2) Inside this header file, define a namespace 
   3) Add all your constants inside the namespace (make sure they’re constexpr) 
   4) #include the header file wherever you need it 
   Eg. constexpr double pi = 3.14;
   
   - Drawbacks :
   1) Changing a single constant value would require recompiling every file that includes the constants header, which can lead to lengthy rebuild times for larger projects.
   2) If the constants are large in size and can’t be optimized away, this can use a lot of memory.
   -----------------------------------------------------------

   - (II) Global constants as external variables :
   One way to avoid the above drawbacks is by turning these constants into external variables, since we can then have a single variable (initialized once) that is shared across all files. In this method, we’ll define the constants in a .cpp file (to ensure the definitions only exist in one place), and put forward declarations in the header (which will be included by other files).
   We use const instead of constexpr in this method because constexpr variables can’t be forward declared, even if they have external linkage.
   Eg. extern const double pi = 3.14;
   
   - Drawbacks :
   1) These constants are now considered compile-time constants only within the file they are actually defined in. In other files, the compiler will only see the forward declaration, which doesn’t define a constant value (and must be resolved by the linker). This means in other files, these are treated as runtime constant values, not compile-time constants.
   2) Because compile-time constants can typically be optimized more than runtime constants, the compiler may not be able to optimize these as much.
   -------------------------------------------------------------

   - (III) Global constants as inline variables :
   1) C++17 introduced a new concept called "inline variables".
   2) Inline variables have two primary restrictions that must be obeyed:
      a) All definitions of the inline variable must be identical (otherwise, undefined behavior will result). 
      b) The inline variable definition (not a forward declaration) must be present in any file that uses the variable. 
   3) The linker will consolidate all inline definitions of a variable into a single variable definition
   Eg. inline constexpr double pi { 3.14159 };




