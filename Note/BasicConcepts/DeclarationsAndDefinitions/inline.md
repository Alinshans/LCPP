inline
=====

##1. inline must be together with definition

**Don't**
```c++
inline void foo();  // The function will not be inline.
```
**Do:**
```c++
inline void foo() { ... } // OK, the function may be inline.
```

##2. Do not use inline when defining a function in a class definition

**Don't:**
```c++
class foo {
public:
  inline void bar() {}
}
```
**do:**
```c++
class foo {
public:
  void bar() {}
}
```

##3. Where to use inline

Simply, if you want to use `inline`, must use it in header file, otherwise you will get a link error.<br>
**Use:**
```c++
// header file : some.h
class foo {
public:
  void bar();
}

// inline function
inline void foo::bar() { ... }
```

##4. When to use inline

Nowadays, the vast majority of cases do not need to use `inline`. If it's a good idea to inline a function, the compiler will do it without your help. Otherwise, the complier can refuse your request.
So I think, I will use `inline` only in this situation:
```c++
// header file : some.h
inline int max(int a, int b)
{
  return a < b ? b : a;
}
```
In other cases, especially the member function in class, just believe the complier, it can do better. :)

>***Reference***<br>
[http://llvm.org/docs/CodingStandards.html#don-t-use-inline-when-defining-a-function-in-a-class-definition](http://llvm.org/docs/CodingStandards.html#don-t-use-inline-when-defining-a-function-in-a-class-definition)<br>
[http://stackoverflow.com/questions/5057021/why-are-c-inline-functions-in-the-header?noredirect=1&lq=1](http://stackoverflow.com/questions/5057021/why-are-c-inline-functions-in-the-header?noredirect=1&lq=1)<br>
[http://stackoverflow.com/questions/1759300/when-should-i-write-the-keyword-inline-for-a-function-method?rq=1](http://stackoverflow.com/questions/1759300/when-should-i-write-the-keyword-inline-for-a-function-method?rq=1)<br>
[My blog](http://www.cnblogs.com/GodA/p/6554591.html)
