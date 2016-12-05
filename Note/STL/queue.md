queue
===========
  This is some notes on FAQ and implementation details of queue in STL. The questions are not sequential.

***
###1.Why doesn't the top function return a value?</br>
  * Does not conform to exception-safe
  If there is a `pop` function like this
```c++
template<class T>
class queue
{
  T* buffer;
  size_t top_pos;
  // ...
  T pop()
  {
    auto value = buffer[top_pos];
    --top_pos;  // the state of the queue has been changed
    // ...
    return value;  // call copy constructor that may be throw an exception``
  }
  // ...
}
``` 
  If the copy constructor of T throws an exception when the function value is returned, the state of the queue has been changed,  simultaneously, the element will be removed and will not be returned.
  * Performance loss
  There is a loss of performance, whether it is a copy constructor or a move constructor. If we do need to return a value, we can call the `front` function first, it will return a value by-reference-to-const, this operation is not detrimental to performance. Not everyone need the `pop` function to return a value, so the `pop` operator and the `return` operator should not be combined.

>***Reference***</br>
[http://stackoverflow.com/questions/25035691/why-doesnt-stdqueuepop-return-value](http://stackoverflow.com/questions/25035691/why-doesnt-stdqueuepop-return-value)

