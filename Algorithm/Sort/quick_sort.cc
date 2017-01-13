/*
  [ Quick sort ]
  Best time complexity    : O(nlog(n))
  Worst time complexity   : O(n²)
  Average time complexity : O(nlog(n))
  Space complexity        : O(log(n))
  Iterator Required       : Random access iterator
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

template <typename Iter>
void quick_sort_helper(Iter first, size_t left, size_t right)
{
    size_t i = left, j = right;
    auto pivot = *(first + (left + right) / 2);
    while (i <= j)
    {
        while (*(first + i) < pivot) { ++i; }
        while (pivot < *(first + j)) { --j; }
        if (i <= j)
        {
            std::iter_swap(first + i, first + j);
            ++i, --j;
        }
    }
    if (left < j)
        quick_sort_helper(first, left, j);
    if (i < right)
        quick_sort_helper(first, i, right);
}

// function template
template <typename Iter>
void quick_sort(Iter first, Iter last)
{
    if (first == last || first == last - 1) 
        return;
    quick_sort_helper(first, 0, last - first - 1);
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
    srand((int)time(0));

    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    quick_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    quick_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
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
