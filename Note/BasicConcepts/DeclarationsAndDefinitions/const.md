const
=====
  When modifying a data declaration, the `const` keyword specifies that the object or variable is not modifiable.
___
##Usage
* [Const values](#1. Const values)
* [Const && pointer && reference](#2. Const && pointer && reference)
* [Const member functions](#3. Const member functions)

___
###1. Const values
  The `const` keyword specifies that a variable's value is constant and tells the compiler to prevent the programmer from modifying it.<br>
```c++
int main() {
    const int i = 1;  // declaration
    // i = 2;         // error
    // i++;           // error
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
  
###2. Const && pointer && reference
  We have the following four forms like this:
```c++
int*              // pointer to int
const int*        // pointer to const int
int* const        // const pointer to int
const int* const  // const pointer to const int
```
  Their role, as explained in the comments. `const int*` means `pointer to const int`, so we use it in the following situation:
```c++
int num1 = 1;
int num2 = 2;
const int* pNum;          // pointer to const int
pNum = &num1;             // ok
pNum = &num2;             // ok
// *pNum = 2;             // error, you change what you point to but not the value that you point to
// *pNum = num2;          // error
```
  `int* const` means `const pointer to int`, so we use it in the following situation:
```c++
int num1 = 1;
int num2 = 2;
int* const pNum = &num1;  // need to set pointer here because we can not change it later
// pNum = &num2;          // error
*pNum = 2;                // ok
*pNum = num2;             // ok
```
  `const int* const` means both the pointer and the value that point to can not be changed.<br>
  
  `reference` is similar to `pointer`, one of their differences is, Once a `reference` is bound to a variable, it can not be changed, this `reference` always represents the variable that was originally bound to it. So the `reference` is always `const reference`, That means `int& rNum` is equal to `int& const rNum`.
  
###3. Const member functions
Declaring a member function with the `const` keyword specifies that the function is a "read-only" function that does not modify the object for which it is called. A constant member function can not modify any non-static data members or call any member functions that aren't constant.To declare a constant member function, place the `const` keyword after the closing parenthesis of the argument list. The `const` keyword is required in both the declaration and the definition.<br>
```c++
class MyClass {
public:
    int returnValue_nonconst() { return value; }        // non-const member function
    int returnValue_const() const { return value; }     // const member function
    int get() const { return returnValue_nonconst(); }  // error: call non-const member function
    int get() const { return returnValue_const(); }     // ok
    void set(int x) { value = x; }
    int returnValue() { return get(); }
private:
    int value;
};
```
___
>***Reference***<br>
[https://msdn.microsoft.com/en-us/library/07x6b05d.aspx](https://msdn.microsoft.com/en-us/library/07x6b05d.aspx)<br>
[http://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const?rq=1](http://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const?rq=1)<br>
[http://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in](http://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in)<br>
[My answer in Zhihu :-)](https://www.zhihu.com/question/52468516/answer/130657574)
