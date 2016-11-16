C-style string
==========
  C-style string is a null-terminated byte string (NTBS), which is a sequence of nonzero bytes followed by a byte with value zero (the terminating null character). </br>
  The types of C-style string are like `char*`, `const char*`, or `char[]`.
***
##catalog
* Character array manipulation
    * [memcpy](#memcpy)
    
_______

###memcpy
  Defined in the header file [<cstring>](http://en.cppreference.com/w/cpp/header/cstring)</br>
```c++
  void* memcpy( void* dest, const void* src, std::size_t count );
```
  `dest`  -  pointer to the memory location to copy to</br>
  `src`  -  pointer to the memory location to copy from</br>
  `count`  -  number of bytes to copy</br>
  Copies count bytes from the object pointed to by `src` to the object pointed to by `dest`. </br>
***Notes:***
* The `memcpy` funciton will not add '\0' automatically at the end, so we must ensure that the end of `dest` has a '\0'.</br>
Example 1:
```c++
  char str1[] = "abc";  // sizeof(str1) : 4
  char str2[4];  // sizeof(str2) : 4
  
  memcpy(str2, str1, sizeof(str2));  // ok
  puts(str2);  // abc
  
  memcpy(str2, str1, 8);  // ok
  puts(str2);  // abc
  
  // add '\0' manually
  memcpy(str2, str1, 3);
  str2[3] = '\0';  // ok
  puts(str2);  // abc
  
  memcpy(str2, str1, 2);
  str2[2] = '\0';  // ok
  puts(str2);  // ab
  
  memcpy(str2, str1, 1);
  str2[3] = '\0';  // str2[1], str[2] is uninitialized value
  puts(str2);  // undefined
```
Example 2:
```c++
  char str1[] = "abcde";  // sizeof(str1) : 6
  char str2[4];  // sizeof(str2) : 4
  
  memcpy(str2, str1, sizeof(str2));  // no '\0' at the end
  puts(str2);  // undefined
  
  memcpy(str2, str1, sizeof(str1));  // In Debug mode the program will crash
  puts(str2);  // abcde
  
  memcpy(str2, str1, sizeof(str2));
  str2[3] = '\0';  // ok
  puts(str2);  // abc
```
* If the objects overlap, the behavior is undefined.</br>
Example 1:
```c++
  char str1[] = "abcde";  // sizeof(str1) : 6
  memcpy(str1 + 1, str1, sizeof(str1));  // In Debug mode the program will crash
  
  memcpy(str1, str1 + 3, 2);  // ok
  puts(str1);  // decde
```
* If either dest or src is a null pointer, the behavior is undefined, even if count is zero.</br>
Example 1:
```c++
  char* str1 = nullptr;
	char str2[3];
	
	memcpy(str2, str1, sizeof(str2));  // the program will crash
	puts(str2);
  
  memcpy(str2, str1, 0); 
	puts(str2);  // undefine
```
Example 2:
```c++
  char* str1 = "abc";
	char* str2 = nullptr;
	
	memcpy(str2, str1, sizeof(str2));  // the program will crash
	puts(str2);
  
  memcpy(str2, str1, 0);  // crash, too
	puts(str2);
```
