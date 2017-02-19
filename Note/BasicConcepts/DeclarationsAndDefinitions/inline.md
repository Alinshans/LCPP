inline
=====

##`inline` must be together with definition
The following expression is useless：
```c++
inline void foo();  // The function will not be inline.
```
Use:
```c++
inline void foo() { ... } // OK, the function will be inline.
```

##Do not use `inline` when defining a function in a class definition
```c++
class foo {
public:
  inline void bar() {}
}
```
is same as
```c++
class foo {
public:
  void bar() {}
}
```

##Where to use `inline`
Simply, if you want to use `inline`, must use it in header file, otherwise you will get a link error.<br>
Use:
```c++
// header file : some.h
class foo {
public:
  void bar();
}

// inline function
inline void foo::bar() { ... }
```

##When to use `inline`
Nowadays, the vast majority of cases do not need to use `inline`. If it's a good idea to inline a function, the compiler will do it without your help. Otherwise, the complier can refuse your request.
So I think, I maybe use `inline` in this situation:
```c++
// header file : some.h
template <typename T>
inline T add(const T& lhs, const T& rhs) { return lhs + rhs; }
```
In other cases, especially the member function in class, just believe the complier, it can do better. :)

>***Reference***<br>
[http://llvm.org/docs/CodingStandards.html#don-t-use-inline-when-defining-a-function-in-a-class-definition](http://llvm.org/docs/CodingStandards.html#don-t-use-inline-when-defining-a-function-in-a-class-definition)<br>
[http://stackoverflow.com/questions/5057021/why-are-c-inline-functions-in-the-header?noredirect=1&lq=1](http://stackoverflow.com/questions/5057021/why-are-c-inline-functions-in-the-header?noredirect=1&lq=1)<br>
[http://stackoverflow.com/questions/1759300/when-should-i-write-the-keyword-inline-for-a-function-method?rq=1](http://stackoverflow.com/questions/1759300/when-should-i-write-the-keyword-inline-for-a-function-method?rq=1)<br>
