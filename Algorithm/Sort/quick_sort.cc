/*
  [ Quick sort ]
  T(n) = O(nlogn)
  Iterator Required : Random access iterator
*/

#include <iostream>
#include <cstddef>
#include <memory>
#include <iterator>
#include <vector>

#include <Windows.h>

template <typename T>
void quick_sort_helper(T arr[], size_t left, size_t right)
{
    size_t i = left, j = right;
    auto pivot(arr[(left + right) / 2]);
    while (i <= j)
    {
        while (arr[i] < pivot) { ++i; }
        while (pivot < arr[j]) { --j; }
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            ++i, --j;
        }
    }
    if (left < j)
        quick_sort_helper(arr, left, j);
    if (i < right)
        quick_sort_helper(arr, i, right);
}

// function template
template <typename Iter>
void quick_sort(Iter first, Iter last)
{
    if (first == last || first == last - 1)  return;
    typedef typename std::iterator_traits<Iter>::value_type T;
    T* arr = new T[last - first];
    std::uninitialized_copy(first, last, arr);
    quick_sort_helper(arr, 0, last - first - 1);
    std::copy(arr, arr + (last - first), first);
    delete[]arr;
}

// test
#define QUICK_SORT_TEST(count) do {                       \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  quick_sort(v.begin(), v.end());                          \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main()
{
    int a[] = { 9,8,7,6,5,4,3,2,1 };
    std::vector<double> v{ 1.5,2.7,4.7,3.8,3.7,15.9,12.0,19 };

    quick_sort(a, a + 9);
    for (auto& it : a)
        std::cout << " " << it;
    std::cout << "\n";

    quick_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";

    // output:
    // 1 2 3 4 5 6 7 8 9
    // 1.5 2.7 3.7 3.8 4.7 12 15.9 19

    QUICK_SORT_TEST(10000);
    QUICK_SORT_TEST(100000);
    QUICK_SORT_TEST(1000000);
}

// for the QUICK_SORT_TEST, I test 5 times.

// [ 1st time ]
//   10000 numbers cost : 0.000763s
//  100000 numbers cost : 0.008873s
// 1000000 numbers cost : 0.087893s

// [ 2nd time ]
//   10000 numbers cost : 0.000873s
//  100000 numbers cost : 0.008664s
// 1000000 numbers cost : 0.087339s

// [ 3rd time ]
//   10000 numbers cost : 0.000788s
//  100000 numbers cost : 0.008628s
// 1000000 numbers cost : 0.096946s

// [ 4th time ]
//   10000 numbers cost : 0.000768s
//  100000 numbers cost : 0.008622s
// 1000000 numbers cost : 0.089252s

// [ 5th time ]
//   10000 numbers cost : 0.000763s
//  100000 numbers cost : 0.009155s
// 1000000 numbers cost : 0.088516s

// [ average ]
//   10000 numbers cost : 0.000791s
//  100000 numbers cost : 0.008788s
// 1000000 numbers cost : 0.089989s
