Proxy classes
========
##Usage
The Proxy classes can:
  * Suppress implicit conversions
  * Implement multidimensional arrays
  * Distinguish lvalue/rvalue

___
###Suppress implicit conversions
Now we have a class template like this
```c++
template <class T>
class Array {
public:
    Array(int size);
    T& operator[](int index);
    // ...
};
```
If we want to write such code:
```c++
Array<int> a(10);
Array<int> b(10);
for (int i = 0; i < 10; ++i) {
    if (a == b[i]) {  // oh no! "a" should be "a[i]"
        // do something
    }
    else {
        // do something
    }
}
```
 We made a mistake! But we hope that the compiler will help us find the error, but it won't! Because the compiler will try to find matching function calls, then it found that as long as call a constructor of Array<int>, you can convert an int to an Array<int>, so it did.
```c++
for(int i = 0; i < 10; ++i) {
    if ( a == static_cast<Array<int>>(b[i])
    // ...
}
```
