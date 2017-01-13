Proxy classes
========
##Usages
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
```c++
class String {
public:
    class CharProxy {
    public:
        CharProxy(String& str, int index) :m_str(str), char_index(index) {}
        CharProxy& operator=(const CharProxy& rhs) {  // lvalue usage
            cout << "write action\n";                 // print some info
            m_str.data[char_index] = rhs.m_str.data[rhs.char_index];
            return *this;
        }
        CharProxy& operator=(char c) {  // lvalue usage
            cout << "write action\n";   // print some info
            m_str.data[char_index] = c;
            return *this;
        }
        operator char() const {       // rvalue usage
            cout << "read action\n";  // print some info
            return m_str.data[char_index]; 
        }
    private:
        String& m_str;
        int char_index;
    };

public:
    friend class CharProxy;
    String(const char* s) {
        data = static_cast<char*>(malloc(strlen(s) + 1));
        memcpy(data, s, strlen(s));
    }
    const CharProxy operator[](int index) const {
        return CharProxy(const_cast<String&>(*this), index);
    }
    CharProxy operator[](int index) {
        return CharProxy(*this, index);
    }

private:
    char* data;
    int len;
};
```
Ok, I add some output informations to some functions in `CharProxy` class to test we are not really realized.
**main.cpp**
```c++
int main() {
    String s1("abc");
    String s2("def");
    cout << s1[0] << endl;
    s1[0] = 'c';
    s1[1] = s2[0];
}
```
**Output**
```
read action
a
write action
write action
```
Yeah! It can correctly distinguish between `rvalue usages` and `lvalue usages`. Let's take a look at how it works.<br>
Think about this code:
```c++
cout << s1[0] << endl;
```
The expression `s1[0]` products a `CharProxy` object, but the `CharProxy` object does not have `operator<<`, so the complier will go to find an implicit conversion that can use `operator<<`, yes it found it. `operator char()` is what the complier need. So the object that s1[0] products will be converted to `char`, which is we hope.<br>
Now think about this code:
```c++
s1[0] = 'c';
```
Like we just said, the expression `s1[0]` products a `CharProxy` object, now it need an assignment operator, so it will call the assignment operator of `CharProxy` object, which belongs to `lvalue usages`.<br>
By the same token, the following code:
```c++
s1[1] = s2[0];
```
`s1[1]` is `lvalue usages` and `s2[0]` is 'rvalue usages'.<br>
Now our purpose was achieved, it can correctly distinguish between `rvalue usages` and `lvalue usages` by using a `Proxy class`.

___
###Limit
`Proxy classes` is not omnipotent, we hope that the proxy objects can seamlessly replace the object their represent, but it is difficult to achieve.<br>
Such as the `String` class above, if now we write:
```c++
String s1("hello");
char *p = &s1[0];    // error
```
Now it can not work, because there is not a function can convert `CharProxy*` to `char*`, so we need to add the following code into `CharProxy` class:
```c++
class CharProxy {
public:
    //...
    char* operator&();
    const char* operator&() const;
    //...
}
```
And let's think about the `Array` class template:
```c++
Array<int> arr;
//...
arr[1] = 1;   // ok
arr[2]++;     // error
arr[3] += 3;  // error
```
Now you know, if you want these operator can work with `operator[]` of `proxy classes`, you have to define these functions one by one for `proxy classes`, this workload can be no small.<br>


Another situation is user passes them to a function that accepts `"references to non-const"` objects:
```c++
void swap(char& lhs, char& rhs);
String s("+C+");   // oh no! I want to turn it to "C++"
swap(s[0], s[1]);  // error
```
`String::operator[]` returns a `CharProxy`, swap requires `char&` as an argument, but there is not a function can do that. Even if you can convert, the `char` that was converted can not be bound to swap parameters, because that `char` is a temporary object and the complier refuses to bind the temporary object to `non-const reference` parameters.<br>


There is another reason that the proxy objects can not seamlessly replace the real object --- Implicit type conversion. When a proxy object is implicitly converted to the real object it represents, a user-defined conversion function is called, and the behavior of a "user-defined conversion function" is limited to one time. Let's see the following code:
```c++
class TVStation {  // representatives of TV channels
public:
    TVStation(int channel);
    //...
}

void watchTV(const TVStation& station);
```
If we do this:
```c++
watchTV(10);  // ok
```
But if we do this:
```c++
Array<int> arr(52);
arr[1] = 10;
watchTV(arr[1]);  // error
```
If we think carefully, we will understand why it does not work.

___
>***Reference***<br>
Scott Meyers."***More Effective C++***"[M]. 2015. P24-31, P213-228<br>
[http://stackoverflow.com/questions/5718901/c-proxy-class](http://stackoverflow.com/questions/5718901/c-proxy-class)
