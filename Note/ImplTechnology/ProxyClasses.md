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

___
###2. Implement multidimensional arrays
For example, we want to implememt a two-dimensional array of template, we might write this code:
```c++
template <class T>
class Array2d {
public:
    Array2d(int x, int y);
    //...
}
```
Then we want to output the data in the array like native array:
```c++
Array2d<int> arr(10,10);
cout << arr[1][1];
```
We are going to do this by overloading the operator, but we quickly realize that there is no `operator[][]`! So we play tricks again. See the code:
```c++
template <class T>
class Array2d {
public:
    class Array1d {
    public:
        T& operator[](int index);
        const T& operator[](int index) const;
        //...
    };
    Array1d operator[](int index);
    const Array1d operator[](int index) const;
    //...
};
```
Now this code is legal:
```c++
Array2d<int> arr(10,10);
cout << arr[1][1];
```

___
###3. Distinguish lvalue/rvalue
Let's think about such situation: we have a string class, and we overload `operator[]`. A `operator[]` can be used in following two cases:
```c++
String s1, s2;
// ...
cout << s1[1];  // read s1
s1[2] = 'x';    // write s1
s1[3] = s2[4];  // write s1, read s2
```
the `operator[]` can be used to read a character or write a character. The read action is `rvalue usages` while the write action is `lvalue usages`. Sometimes we hope to distinguish between the `rvalue usages` and the `lvalue usages`, for the read action is much faster than the write action(sometimes). If we do in this way:
```c++
class String {
public:
    const char& operator[](int index) const;  // for read
    char& operator[](int index);              // for write
    //...
};
```
Oh, it's trivial! The complier can not distinguish between `read action` and `write action`, even if we overload `operator[]`. Although we do not know the `operator[]` is used in `lvalue` or `rvalue`, we can distinguish between read and write. As long as the action we are going to process is delayed untill we know how the return result of `operator[]` is used. This is also a case of `lazy evaluation`.<br>
So let's think about the following code:



