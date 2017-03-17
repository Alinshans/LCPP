static
=======
The `static` keyword can be used to declare variables and functions at global scope, namespace scope, and class scope. Static variables can alse be declared at local scope.<br>

Static duration means that the object or variable is allocated when the program starts and is deallocated when the program ends. External linkage means that the name of the variable is visible from outside the file in which the variable is declared. Conversely, internal linkage means that the name is not visible outside the file in which the variable is declared. By default, an object or variable that is defined in the global namespace has static duration and external linkage. 

***
## When to use
* 1. When you declare a variable or function at file scope (global and/or namespace scope), the `static` keyword specifies that the variable or function has internal linkage. When you declare a variable, the variable has static duration and the compiler initializes it to 0 unless you specify another value.
* 2. When you declare a variable in a function, the `static` keyword specifies that the variable retains its state between calls to that function.
* 3. When you declare a data member in a class declaration, the `static` keyword specifies that one copy of the member is shared by all instances of the class. A static data member must be defined at file scope. An integral data member that you declare as `const static` can have an initializer.
* 4. When you declare a member function in a class declaration, the `static` keyword specifies that the function is shared by all instances of the class. A static member function cannot access an instance member because the function does not have an implicit `this` pointer. To access an instance member, declare the function with a parameter that is an instance pointer or reference.
* 5. You can not declare the members of a union as static. However, a globally declared anonymous union must be explicitly declared `static`.

***

## Use with
### Static data members
* Static data members are not associated with any object. They exist even if no objects of the class have been defined. If the static member is declared thread_local (since C++11), there is one such object per thread. Otherwise, there is only one instance of the static data member in the entire program, with static storage duration.
* Static data members cannot be `mutable`.
* Static data members of a class in namespace scope have `external linkage` if the class itself has external linkage (i.e. is not a member of unnamed namespace). Local classes (classes defined inside functions) and unnamed classes, including member classes of unnamed classes, cannot have static data members.

### Static member functions
* Static member functions are not associated with any object. When called, they have no `this` pointer.
* Static member functions cannot be `virtual`, `const`, or `volatile`.
* The address of a static member function may be stored in a regular pointer to function, but not in a pointer to member function.

###Constant static members
* If a static data member of integral or enumeration type is declared `const` (and not `volatile`), it can be initialized with a initializer in which every expression is a constant expression, right inside the class definition.
* If a static data member of `LiteralTyp`e is declared `constexpr`, it must be initialized with a initializer in which every expression is a constant expression, right inside the class definition.
* If const non-inline (since C++17) static data member or a constexpr static data member (since C++11) is [odr-used](http://en.cppreference.com/w/cpp/language/definition#ODR-use), a definition at namespace scope is still required, but it cannot have an initializer. This definition is deprecated for constexpr data members (since C++17).
* If a static data member is declared `constexpr`, it is implicitly `inline` and does not need to be redeclared at namespace scope. This redeclaration without an initializer (formerly required as shown above) is still permitted, but is deprecated. (since C++17)

***

## Example to use
**Example 1**
```c++
#include <iostream>

void print(int i) {
    static int g_num;  // declare a static variable and initialize it to 0
    g_num += i;        
    std::cout << " The g_num is " << g_num << std::endl;
}

int main() {
    for (int i = 0; i < 5; ++i)
        print(i);
}
```
**Output**
```
 The g_num is 0
 The g_num is 1
 The g_num is 3
 The g_num is 6
 The g_num is 10
```

***

**Example 2**
```c++
#include <iostream>

class MyClass {
public:
    static int m_num;
    void add() { ++m_num; }
};

//  Static data members must be defined outside the class definition.
int MyClass::m_num = 1;  

int main() {
    MyClass c1;
    MyClass c2;
    std::cout << c1.m_num << " " << c1.m_num << std::endl;
    c1.add();
    std::cout << c1.m_num << " " << c1.m_num << std::endl;
    c2.add();
    std::cout << c1.m_num << " " << c1.m_num << std::endl;
}
```
**Output**
```
1 1
2 2
3 3
```

***

**Example 3**
```c++
class MyClass {
public:
    const static int n = 1;
    const static int m{ 2 };  // since C++11
    const static int k;
};
const int MyClass::k = 3;
```

***

**Example 4**
```c++
class MyClass {
public:
    constexpr static int arr[] = { 1, 2, 3 };        // OK
    constexpr static std::complex<double> n = { 1,2 }; // OK
    constexpr static int k; // Error: constexpr static requires an initializer
};
```

***

**Example 5**
```c++
class MyClass {
public:
    static const int n = 1;
    static constexpr int m = 2;
};
const int *p = &MyClass::n, *q = &MyClass::m;  // MyClass::n and MyClass::m are odr-used
const int MyClass::n, MyClass::m;              // so a definition is necessary (except for MyClass::m in C++17)
```

***

>***Reference***<br>
[https://msdn.microsoft.com/en-us/library/y5f6w579.aspx#static](https://msdn.microsoft.com/en-us/library/y5f6w579.aspx#static)<br>
[http://en.cppreference.com/w/cpp/language/static](http://en.cppreference.com/w/cpp/language/static)<br>
[http://stackoverflow.com/questions/15235526/the-static-keyword-and-its-various-uses-in-c](http://stackoverflow.com/questions/15235526/the-static-keyword-and-its-various-uses-in-c)<br>
[http://stackoverflow.com/questions/30929941/definition-of-the-static-data-member](http://stackoverflow.com/questions/30929941/definition-of-the-static-data-member)<br>
[http://stackoverflow.com/questions/26196095/static-constexpr-odr-used-or-not](http://stackoverflow.com/questions/26196095/static-constexpr-odr-used-or-not)<br>

