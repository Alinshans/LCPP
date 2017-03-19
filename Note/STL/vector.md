# vector

## 1. Why some functions like `insert_aux` need a x_copy?

For example:
```c++
template <class T, class Alloc>
void vector<T, Alloc>::insert_aux(iterator position, const T& x)
{
  if (finish != end_of_storage)
  {
    construct(finish, *(finish - 1));
    ++finish;
    T x_copy = x;
    copy_backward(position, finish - 2, finish - 1);
    *position = x_copy;
  }
  // ...
}
```
Consider the following case:<br>
```c++
vector<int> x { 1, 2, 3 };
x.insert(x.begin(), x[1]);
```
After calling `copy_backward`, `x[1]` was changed to `1`, so we need to make a copy first.<br>

***Rederence***<br>
>[https://www.zhihu.com/question/56911557](https://www.zhihu.com/question/56911557)<br>

