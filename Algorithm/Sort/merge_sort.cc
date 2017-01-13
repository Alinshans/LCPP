/*
  [ Merge sort ]
  Best time complexity    : O(nlog(n))
  Worst time complexity   : O(nlog(n))
  Average time complexity : O(nlog(n))
  Space complexity        : O(n)
  Iterator Required       : Random access iterator
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

template <typename Iter>
void merge_helper(Iter first, size_t left, size_t mid, size_t right)
{
    typedef typename std::iterator_traits<Iter>::value_type T;
    auto len1 = mid - left + 1, len2 = right - mid;
    T *l = new T[len1];
    T *r = new T[len2];
    size_t i = 0, j = 0, z = left;
    std::uninitialized_copy(first + left, first + mid + 1, l);
    std::uninitialized_copy(first + mid + 1, first + right + 1, r);
    while (i < len1 && j < len2)
    {
        *(first + z++) = r[j] < l[i] ? r[j++] : l[i++];
    }
    while (i < len1)
    {
        *(first + z++) = l[i++];
    }
    while (j < len2)
    {
        *(first + z++) = r[j++];
    }
    delete[]l;
    delete[]r;
}

template <typename Iter>
void divide_helper(Iter first, size_t left, size_t right)
{
    if (left < right)
    {
        auto mid = (left + right) / 2;
        divide_helper(first, left, mid);
        divide_helper(first, mid + 1, right);
        merge_helper(first, left, mid, right);
    }
}

// function template
template <typename Iter>
void merge_sort(Iter first, Iter last)
{
    if (first == last || first == last - 1)
        return;
    divide_helper(first, 0, last - first - 1);
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
//   10000 numbers cost : 0.003613s
//  100000 numbers cost : 0.034559s
// 1000000 numbers cost : 0.352965s

// [ 2nd time ]
//   10000 numbers cost : 0.004117s
//  100000 numbers cost : 0.033645s
// 1000000 numbers cost : 0.360408s

// [ 3rd time ]
//   10000 numbers cost : 0.003159s
//  100000 numbers cost : 0.034170s
// 1000000 numbers cost : 0.340123s

// [ 4th time ]
//   10000 numbers cost : 0.003426s
//  100000 numbers cost : 0.038650s
// 1000000 numbers cost : 0.343489s

// [ 5th time ]
//   10000 numbers cost : 0.003222s
//  100000 numbers cost : 0.034359s
// 1000000 numbers cost : 0.347924s

// [ average ]
//   10000 numbers cost : 0.003507s
//  100000 numbers cost : 0.035077s
// 1000000 numbers cost : 0.348982s
