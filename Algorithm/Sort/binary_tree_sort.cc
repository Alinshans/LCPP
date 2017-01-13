/*
  [ Binary tree sort ]
  Best time complexity    : O(nlog(n))
  Worst time complexity   : O(nlog(n))
  Average time complexity : O(nlog(n))
  Space complexity        : O(n)
  Iterator Required       : Forward iterator
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <set>

#include <Windows.h>

// For convenience and performance, I use std::multiset directly.

// function template
template <typename Iter>
void binary_tree_sort(Iter first, Iter last)
{
    std::multiset<typename std::iterator_traits<Iter>::value_type> tree(first, last);
    std::copy(tree.begin(), tree.end(), first);
}

#define BINARY_TREE_SORT_TEST(count) do {                 \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  binary_tree_sort(v.begin(), v.end());                    \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main()
{
    srand((int)time(0));

    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    binary_tree_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    binary_tree_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
    BINARY_TREE_SORT_TEST(10000);
    BINARY_TREE_SORT_TEST(100000);
    BINARY_TREE_SORT_TEST(1000000);
}

// for the BINARY_TREE_SORT_TEST, I test 5 times.

// [ 1st time ]
//   10000 numbers cost : 0.003503s
//  100000 numbers cost : 0.065074s
// 1000000 numbers cost : 1.458672s

// [ 2nd time ]
//   10000 numbers cost : 0.003174s
//  100000 numbers cost : 0.058337s
// 1000000 numbers cost : 1.364507s

// [ 3rd time ]
//   10000 numbers cost : 0.003132s
//  100000 numbers cost : 0.058386s
// 1000000 numbers cost : 1.437054s

// [ 4th time ]
//   10000 numbers cost : 0.003939s
//  100000 numbers cost : 0.066762s
// 1000000 numbers cost : 1.448976s

// [ 5th time ]
//   10000 numbers cost : 0.003353s
//  100000 numbers cost : 0.059279s
// 1000000 numbers cost : 1.421921s

// [ average ]
//   10000 numbers cost : 0.003420s
//  100000 numbers cost : 0.061694s
// 1000000 numbers cost : 1.426226s
