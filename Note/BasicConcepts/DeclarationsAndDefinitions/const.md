const
=====
  When modifying a data declaration, the `const` keyword specifies that the object or variable is not modifiable.
___
##Usage
* [Const values](#Const values)
* Const member functions

___
###Const values
  The `const` keyword specifies that a variable's value is constant and tells the compiler to prevent the programmer from modifying it.<br>
```c++
int main() {
    const int i = 1;  // declaration
    i = 2;            // error
    i++;              // error
}
```
   In C++, you can specify the size of an array with a `const` variable as follows:<br>
```c++
int main() {
    const int MaxArrayNum = 1024;
    int array[MaxArrayNum];        // allowed in C++; not allowed in C  
}
```
  **Note:** In C, constant values default to external linkage, so they can appear only in source files. In C++, constant values default to internal linkage, which allows them to appear in header files.<br>
  
###Const && pointer && reference
  We have the following four expressions like this:
```c++
int* a;              // pointer to int
const int* a;        // pointer to const int
int* const a;        // const pointer to int
const int* const a;  // const pointer to const int
```
