
#### 1. Why (void) between two comma separated statements?

We can see such a code usually:
```c++
// std::transform
template <class _InputIterator, class _OutputIterator, class _UnaryOperation>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
transform(_InputIterator __first, _InputIterator __last, _OutputIterator __result, _UnaryOperation __op)
{
    for (; __first != __last; ++__first, (void) ++__result)
        *__result = __op(*__first);
    return __result;
}
```

Notes that, in the for loop, there is a `void` before `++__result`, so why need that?

**Answer:**

Because if the type of the value returned by `++__first` has overloaded comma operator, then `++__first, ++__result` will invoke it. so casting result of `++__result` to `void` to avoid that, since overloaded operators can not take `void` parameters.

**Reference:**
>[https://stackoverflow.com/questions/43973484/why-void-between-two-comma-separated-statements-in-a-for-loop](https://stackoverflow.com/questions/43973484/why-void-between-two-comma-separated-statements-in-a-for-loop)<br>[https://stackoverflow.com/questions/38357089/why-does-stdtransform-and-similar-cast-the-for-loop-increment-to-void](https://stackoverflow.com/questions/38357089/why-does-stdtransform-and-similar-cast-the-for-loop-increment-to-void)

#### 2. Implementation of `std::min`?

Why do it like this:
```c++
template <class T>
const T& min(const T& a, const T& b)
{
  return b < a ? b : a;
}
```
instead of:
```c++
template <class T>
const T& min(const T& a, const T& b)
{
  return a < b ? a : b;
}
```

**Answer:**
Because the standard provides: Returns the first argument when the arguments are equivalent. See [N4713 [alg.min.max]](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/n4713.pdf)
