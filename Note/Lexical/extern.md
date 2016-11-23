extern
=====
Usage
-----
* [Static storage duration with external linkage specifier](#Static storage duration with external linkage specifier)
* Language linkage specification

===
###Static storage duration with external linkage specifier
`Extern` can be placed before the variable or function to mark the definition of variables or functions in other files. When you have a global variable or a global function, you can declare the existance of the variable or function in a header, and define it in other source files that include the header.<br>

**header**
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
>References
>[http://stackoverflow.com/questions/10422034/when-to-use-extern-in-c](http://stackoverflow.com/questions/10422034/when-to-use-extern-in-c)
