Proxy classes
========
##Usage
The Proxy classes can:
  * Suppress implicit conversions
  * Implement multidimensional arrays
  * Distinguish lvalue/rvalue

___
###1. Suppress implicit conversions
Now we have a class template like this:
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
We want to avoid the disater, a simple way to use the `explicit` keyword.
```c++
template <class T>
class Array {
public:
    // ...
    explicit Array(int size);  // use explicit
    // ...
};
```
But sometimes, we need a way, not only allow an integer as a constructor argument, but also to prevent an integer from being implicitly converted to a temporary Array object. So we get the following approach:
```c++
template <class T>
class Array {
public:
    class ArraySize {  // add new class, to represent the array size
    public:
        ArraySize(int num) :m_size(num) {}
        int size() const { return m_size; }
    private:
        int m_size;
    };
    Array(ArraySize size);  // note this new declaration
};
```
We nest a new class named `ArraySize` in `Array`, use it to represent the array size. Now if we write such code:
```c++
Array<int> a(10);
```
The complier need an `ArraySize` object as constructor argument, but we give an integer. The complier find that `int` can be converted to a temporary `ArraySize` object, so it did and the constrcutor call was succeed.
And let's think about the following code again:
```c++
for (int i = 0; i < 10; ++i) {
    if (a == b[i]) {  // oh no! "a" should be "a[i]"
```
Yes, the complier does issus an error! Because if it converts an `int` to `ArraySize`, it needs to call user-defined conversion behaviors twice, which is forbidden. The class like `ArraySize` is often called `Proxy classes`, each of its objects exist for another class object, just like the proxy of other class object. 
