extern
=====
Usage
-----
* Static storage duration with external linkage specifier
* Language linkage specification

======

##Static storage duration with external linkage specifier
`Extern` can be placed before the variable or function to mark the definition of variables or functions in other files. When you have a global variable or a global function, you can declare the existance of the variable or function in a header, and define it in other source files that include the header.<br>

**header.h**
```c++
#ifndef HEADER_H_
#define HEADER_H_

extern int g_num;
void print_g_num();

#endif // !HEADER_H_
```
**source.cpp**
```c++
#include <cstdio>
#include "header.h"

int g_num = 1;
void print_g_num()
{
    printf("%d\n", g_num);
}
```
**main.cpp**
```c++
#include <cstdio>
#include "header.h"

int main()
{
    print_g_num();
    g_num = 2;
    printf("%d\n", g_num);
    print_g_num();
}
```
**output**
```
1
2
2
```
>References<br>
[http://stackoverflow.com/questions/10422034/when-to-use-extern-in-c](http://stackoverflow.com/questions/10422034/when-to-use-extern-in-c)

====

##Language linkage specification
The C++ compiler compiles a unique name for every function within a program, but in C it is not necessary because C can not overload the function name. So in order for C++ and C compilers to produce compatible object files, we need to tell the C++ compiler that it should not rename some functions.<br>
Then we can use `extern "C"`. When `extern` is used with `"C"`, it means that a function has a C linkage. That will suppress the C++ `name mangling` program. Like this:<br>
```c++
extern "C" void foo();
```
If we have a lot of functions that they does not need `name mangling`, we can use `{ }` to wrap them. Like this:<br>
```c++
extern "C" {
    void foo();
    void goo();
    // ...
}
```
A common architecture for C++ and C headers is as follows:
```c++
#ifdef __cplusplus
extern "C" {
#endif
    void foo();
    // ...
    
#ifdef __cplusplus
}   // end of extern "C"
#endif
```
>References<br>
[https://msdn.microsoft.com/en-us/library/0603949d.aspx](https://msdn.microsoft.com/en-us/library/0603949d.aspx)<br>
[http://stackoverflow.com/questions/1041866/in-c-source-what-is-the-effect-of-extern-c](http://stackoverflow.com/questions/1041866/in-c-source-what-is-the-effect-of-extern-c)<br>
