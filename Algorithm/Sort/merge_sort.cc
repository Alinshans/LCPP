/*
  [ Merge sort ]
  Best time complexity    : O(nlog(n))
  Worst time complexity   : O(nlog(n))
  Average time complexity : O(nlog(n))
  Iterator Required       : Random access iterator
*/
#ifdef _MSC_VER
#pragma warning(disable : 4996)
#endif // _MSC_VER

#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

template <typename T>
void merge_helper(T *arr, size_t left, size_t mid, size_t right)
{
    auto len1 = mid - left + 1, len2 = right - mid;
    T *l = new T[len1];
    T *r = new T[len2];
    size_t i = 0, j = 0, z = left;
    std::uninitialized_copy(arr + left, arr + mid + 1, l);
    std::uninitialized_copy(arr + mid + 1, arr + right + 1, r);
    while (i < len1 && j < len2)  arr[z++] = r[j] < l[i] ? r[j++] : l[i++];
    while (i < len1)              arr[z++] = l[i++];
    while (j < len2)              arr[z++] = r[j++];
    delete[]l;
    delete[]r;
}

template <typename T>
void merge_sort_helper(T *arr, size_t left, size_t right)
{
    if (left < right)
    {
        auto mid = (left + right) / 2;
        merge_sort_helper(arr, left, mid);
        merge_sort_helper(arr, mid + 1, right);
        merge_helper(arr, left, mid, right);
    }
}

// function template : merge_sort
template <typename Iter>
void merge_sort(Iter first, Iter last)
{
    if (first == last || first == last - 1) return;
    typedef typename std::iterator_traits<Iter>::value_type T;
    T *arr = new T[last - first];
    std::uninitialized_copy(first, last, arr);
    merge_sort_helper(arr, 0, last - first - 1);
    std::copy(arr, arr + (last - first), first);
    delete[]arr;
}

// test
#define MERGE_SORT_TEST(count) do {                       \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  merge_sort(v.begin(), v.end());                          \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main()
{
    srand((int)time(0));

    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    merge_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    merge_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
    MERGE_SORT_TEST(10000);
    MERGE_SORT_TEST(100000);
    MERGE_SORT_TEST(1000000);
}

// for the MERGE_SORT_TEST, I test 5 times.

// [ 1st time ]
//   10000 numbers cost : 0.004426s
//  100000 numbers cost : 0.048915s
// 1000000 numbers cost : 0.368160s

// [ 2nd time ]
//   10000 numbers cost : 0.003565s
//  100000 numbers cost : 0.037457s
// 1000000 numbers cost : 0.358801s

// [ 3rd time ]
//   10000 numbers cost : 0.003133s
//  100000 numbers cost : 0.034335s
// 1000000 numbers cost : 0.414295s

// [ 4th time ]
//   10000 numbers cost : 0.004541s
//  100000 numbers cost : 0.036790s
// 1000000 numbers cost : 0.366309s

// [ 5th time ]
//   10000 numbers cost : 0.004316s
//  100000 numbers cost : 0.035001s
// 1000000 numbers cost : 0.366878s

// [ average ]
//   10000 numbers cost : 0.003996s
//  100000 numbers cost : 0.038500s
// 1000000 numbers cost : 0.374889s
