#Constexpr

The keyword `constexpr` was introduced in `C++11` and improved in `C++14`. It means *constant expression*. Like `const`, it can be applied to variables so that a compiler error will be raised if any code attempts to modify the value. Unlike `const`, `constexpr` can also be applied to functions and class constructors. `constexpr` indicates that the value, or return value, is constant and, if possible, will be computed at compile time. A `constexpr` integral value can be used wherever a const integer is required, such as in template arguments and array declarations. And when a value can be computed at compile time instead of run time, it can help your program can run faster and use less memory.<br>

##constexpr variables
The primary difference between `const` and `constexpr` variables is that the initialization of a `const` variable can be deferred until run time whereas a `constexpr` variable must be initialized at compile time. All `constexpr` variables are `const`.
```c++
template <int N>
class test {
  int get() { return N; }
};

int main() {
  int X = 5;            // variable
  const int N = 1;      // constant
  constexpr int M = 1;  // compile-time constant

  const int N2 = X + 1;       // work
  constexpr int M2 = X + 1;   // error : x is not a compile-time constant
  constexpr int M3 = N + 1;   // work
  constexpr int M4 = N2 + 1;  // error : N2 is not a compile-time constant
  constexpr int M5 = M + 1;   // work

  int arr1[X];   // error : X is not a constant value
  int arr2[N];   // work
  int arr3[M];   // work
  int arr4[N2];  // error : N2 is not a constant value
  int arr5[M3];  // work

  test<X> t1;    // error : X is not a constant value
  test<N> t2;    // work
  test<M> t3;    // work
  test<N2> t4;   // error : N2 is not a constant value
  test<M3> t5;   // work
}
```

##constexpr functions
A `constexpr` function is one whose return value can be computed at compile when consuming code requires it. A `constexpr` function must satisfy the following requirements:
* it must not be virtual
* its return type must be literal types
* each of its parameters must be literal types
* there exists at least one set of argument values such that an invocation of the function could be an evaluated subexpression of a core constant expression

```c++
int get_int(int x) {
  return x;
}
const int get_int1(int x) {      
  return x;
}
constexpr int get_int2(int x) { 
  return x;
}
const int get_val1() {
  int x = 1;
  return x;
}
constexpr int get_val2() {  // error : return value is not a compile-time constant
  int x = 1;
  return x;
}
template <int N>
class test {
  int get() { return N; }
};

int main() {
  get_int1(get_int1(1));            // work
  get_int1(get_int2(1));            // work
  get_int2(get_int1(1));            // work
  get_int2(get_int2(1));            // work

  int arr1[get_int(1)];             // error : need constant value
  int arr2[get_int1(1)];            // error : need constant value
  int arr3[get_int2(1)];            // work

  int arr4[get_int1(get_int1(1))];  // error : need constant value
  int arr5[get_int1(get_int2(1))];  // error : need constant value
  int arr6[get_int2(get_int1(1))];  // error : need constant value
  int arr7[get_int2(get_int2(1))];  // work
  
  test<get_int(1)> t1;              // error : need constant value
  test<get_int1(1)> t2;             // error : need constant value
  test<get_int2(1)> t3;             // work

  test<get_int1(get_int1(1))> t4;   // error : need constant value
  test<get_int1(get_int2(1))> t5;   // error : need constant value
  test<get_int2(get_int1(1))> t6;   // error : need constant value
  test<get_int2(get_int2(1))> t7;   // work
}

```

***
>***Reference***<br>
[http://en.cppreference.com/w/cpp/language/constexpr](http://en.cppreference.com/w/cpp/language/constexpr)<br>
[https://msdn.microsoft.com/en-us/library/dn956974.aspx](https://msdn.microsoft.com/en-us/library/dn956974.aspx)<br>
[http://stackoverflow.com/questions/14116003/difference-between-constexpr-and-const](http://stackoverflow.com/questions/14116003/difference-between-constexpr-and-const)<br>
[http://stackoverflow.com/questions/4748083/when-should-you-use-constexpr-capability-in-c11?noredirect=1&lq=1](http://stackoverflow.com/questions/4748083/when-should-you-use-constexpr-capability-in-c11?noredirect=1&lq=1)
