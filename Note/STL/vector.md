# vector

## 1. Why some functions like `insert_aux` need a `x_copy`?

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

## 2. What the difference between `std::array` and `std::vector` that has a fixed size?

This question comes from [here](https://www.zhihu.com/question/60458295).

If we need a fixed dimension vector, what the difference of performance between `std::array` and `std::vecote` after allocating fixed memory? I made a test:
```c++
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <chrono>

#define USING_STD_VECTOR 0

template <std::size_t N>
class Vec
{
public:

#if USING_STD_VECTOR
  Vec() :c_(N) {}
#else
  Vec() = default;
#endif

  Vec(const Vec& rhs) :c_(rhs.c_) {}
  Vec(Vec&& rhs) :c_(std::move(rhs.c_)) {}

#if USING_STD_VECTOR
  Vec(std::initializer_list<double> ilist)
    :c_(N)
  {
    std::copy_n(ilist.begin(), N, c_.begin());
  }
#else
  Vec(std::initializer_list<double> ilist)
  {
    std::copy_n(ilist.begin(), N, c_.begin());
  }
#endif

  double& operator[](std::size_t index)
  {
    return c_[index];
  }
  friend Vec operator*(double n, const Vec& v)
  {
    Vec<N> tmp;
    auto&& it = v.c_.cbegin();
    std::generate(tmp.c_.begin(), tmp.c_.end(), [&]() {return n * (*it++); });
    return tmp;
  }
  friend Vec operator*(const Vec& v, double n)
  {
    return n * v;
  }
  double operator*(const Vec<N>& rhs)
  {
    return std::inner_product(c_.cbegin(), c_.cend(), rhs.c_.begin(), 0);
  }
private:
#if USING_STD_VECTOR
  std::vector<double> c_;
#else
  std::array<double, N> c_;
#endif
};

int main()
{
  Vec<3> v{ 1.0,1.0,1.0 };
  Vec<3> v2{ 1.0,2.0,3.0 };
  double n = 0;
  auto start = std::chrono::system_clock::now();
  for (double i = 0; i < 1000; ++i)
  {
    Vec<3> vn = i * v;
    n += v2 * vn;
  }
  auto end = std::chrono::system_clock::now();
  std::cout << "costs: " << std::chrono::nanoseconds(end - start).count() << "ns" << std::endl;
}
```

In my machine environment, I was surprised that the performance of using `std::array` is better than using `std::vector` 2~3 times. Later I thought for a while, the memory of `std::array` is allocated on the stack. You can see the implement of [`libcxx`'s](https://github.com/llvm-mirror/libcxx/blob/master/include/array):
```c++
template <class _Tp, size_t _Size>
struct _LIBCPP_TEMPLATE_VIS array
{
    // ...

    value_type __elems_[_Size > 0 ? _Size : 1];

    // ...
}
```
