/*
  [ Binary tree sort ]
  Best time complexity    : O(nlog(n))
  Worst time complexity   : O(nlog(n))
  Average time complexity : O(nlog(n))
  Space complexity        : O(n)
  Stable                  : Yes
  Iterator Required       : Forward iterator
*/
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <ctime>
#include <set>

#include <Windows.h>

// For convenience and performance, I use std::multiset directly.

// binary_tree_sort
template <typename Iter, typename Compare = std::less<>>
void binary_tree_sort(Iter first, Iter last, Compare cmp = Compare())
{
    std::multiset<typename std::iterator_traits<Iter>::value_type, Compare> tree(first, last);
    std::copy(tree.begin(), tree.end(), first);
}

// test
#define SMALL_SORT_TEST(sort, count) do {                  \
    double t = 0.0;                                         \
    std::vector<int> v(count);                              \
    LARGE_INTEGER t1, t2, tc;                               \
    for (int i = 0; i < 10; ++i) {                          \
        for (auto& it : v) it = rand();                     \
        QueryPerformanceFrequency(&tc);                     \
        QueryPerformanceCounter(&t1);                       \
        sort(v.begin(), v.end());                           \
        QueryPerformanceCounter(&t2);                       \
        t += (t2.QuadPart - t1.QuadPart)*1e6 / tc.QuadPart; \
    }                                                       \
    t /= 10.0;                                              \
    printf(" %7d numbers cost : %fμs\n", count, t);         \
} while(0)

#define LARGE_SORT_TEST(sort, count) do {                  \
  std::vector<int> v(count);                                \
  for (auto& it : v) it = rand();                           \
  LARGE_INTEGER t1, t2, tc;                                 \
  QueryPerformanceFrequency(&tc);                           \
  QueryPerformanceCounter(&t1);                             \
  sort(v.begin(), v.end());                                 \
  QueryPerformanceCounter(&t2);                             \
  printf(" %7d numbers cost : %fms\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1e3 / tc.QuadPart);   \
} while(0)

int main()
{
    srand((int)time(0));

    /** [ Correctness verification ] **/
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    binary_tree_sort(v.begin(), v.end(), std::greater<>());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 9 9 7 6 6 5 3 3 2 0

    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    binary_tree_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    /** [ Small amount of data ] **/
    std::cout << "\n [ Small amount of data ]\n";
    SMALL_SORT_TEST(binary_tree_sort, 16);
    SMALL_SORT_TEST(binary_tree_sort, 32);
    SMALL_SORT_TEST(binary_tree_sort, 64);
    SMALL_SORT_TEST(binary_tree_sort, 128);
    SMALL_SORT_TEST(binary_tree_sort, 512);
    SMALL_SORT_TEST(binary_tree_sort, 1024);

    /** [ Large amount of data ] **/
    std::cout << "\n [ Large amount of data ]\n";
    LARGE_SORT_TEST(binary_tree_sort, 10000);
    LARGE_SORT_TEST(binary_tree_sort, 100000);
    LARGE_SORT_TEST(binary_tree_sort, 1000000);
}

// I run 5 times for 'Small amount of data' and 'Large amount of data'.

// [ 1st time ]
// [ Small amount of data ]
//      16 numbers cost : 3.825565μs
//      32 numbers cost : 8.397583μs
//      64 numbers cost : 15.628834μs
//     128 numbers cost : 33.123798μs
//     512 numbers cost : 138.000274μs
//    1024 numbers cost : 253.467035μs
//
// [ Large amount of data ]
//   10000 numbers cost : 3.124834ms
//  100000 numbers cost : 48.196992ms
// 1000000 numbers cost : 1208.592220ms

// [ 2nd time ]
// [ Small amount of data ]
//      16 numbers cost : 3.592299μs
//      32 numbers cost : 10.217059μs
//      64 numbers cost : 16.421939μs
//     128 numbers cost : 34.196823μs
//     512 numbers cost : 134.361322μs
//    1024 numbers cost : 234.012636μs
//
// [ Large amount of data ]
//   10000 numbers cost : 3.054854ms
//  100000 numbers cost : 47.756119ms
// 1000000 numbers cost : 1207.914815ms

// [ 3rd time ]
// [ Small amount of data ]
//      16 numbers cost : 3.778912μs
//      32 numbers cost : 8.817462μs
//      64 numbers cost : 15.675488μs
//     128 numbers cost : 33.403718μs
//     512 numbers cost : 129.556038μs
//    1024 numbers cost : 263.310868μs
//
// [ Large amount of data ]
//   10000 numbers cost : 3.135564ms
//  100000 numbers cost : 46.943886ms
// 1000000 numbers cost : 1215.437183ms

// [ 4th time ]
// [ Small amount of data ]
//      16 numbers cost : 3.312380μs
//      32 numbers cost : 7.837744μs
//      64 numbers cost : 14.089277μs
//     128 numbers cost : 29.904725μs
//     512 numbers cost : 129.089506μs
//    1024 numbers cost : 268.489378μs
//
// [ Large amount of data ]
//   10000 numbers cost : 3.072116ms
//  100000 numbers cost : 64.484104ms
// 1000000 numbers cost : 1275.706633ms

// [ 5th time ]
// [ Small amount of data ]
//      16 numbers cost : 3.685606μs
//      32 numbers cost : 8.397583μs
//      64 numbers cost : 15.675488μs
//     128 numbers cost : 34.803315μs
//     512 numbers cost : 143.178784μs
//    1024 numbers cost : 236.718523μs
//
// [ Large amount of data ]
//   10000 numbers cost : 3.698202ms
//  100000 numbers cost : 49.869511ms
// 1000000 numbers cost : 1204.850630ms

// [ average ]
// [ Small amount of data ]
//      16 numbers cost : 3.638952μs
//      32 numbers cost : 8.733486μs
//      64 numbers cost : 15.498205μs
//     128 numbers cost : 33.086476μs
//     512 numbers cost : 134.837185μs
//    1024 numbers cost : 251.199688μs
//
// [ Large amount of data ]
//   10000 numbers cost : 3.217114ms
//  100000 numbers cost : 51.450122ms
// 1000000 numbers cost : 1222.500296ms
