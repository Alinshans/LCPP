C-style string
==========
  C-style string is a null-terminated byte string (NTBS), which is a sequence of nonzero bytes followed by a byte with value zero (the terminating null character). </br>
  The types of C-style string are like `char*`, `const char*`, or `char[]`.
***
###function
* memcpy
  Defined in the header file `<cstring>`</br>
```c++
    void* memcpy( void* dest, const void* src, std::size_t count );
```
	Copies count bytes from the object pointed to by src to the object pointed to by dest. 
  ***Note:***
* The count should not be larger than sizeof(dest), otherwise, the progream will be crash.
* The `memcpy` funciton will not add '\0' automatically at the end. (So we must manually add '\ 0')
* If the objects overlap, the behavior is undefined. 
* If either dest or src is a null pointer, the behavior is undefined, even if count is zero. 
  
