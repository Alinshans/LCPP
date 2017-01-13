/*
  [ Selection sort ]
  Best time complexity    : O(n²)
  Worst time complexity   : O(n²)
  Average time complexity : O(n²)
  Iterator Required       : Random access iterator
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

// function template
template <typename Iter>
void selection_sort(Iter first, Iter last)
{
    if (first == last || first == last - 1)
        return;
    while (first != last)
    {
        auto value = *first;
        auto i = first;
        auto j = first;
        for (; i != last; ++i)
        {
            if (*i < value)
            {
                value = *i, j = i;
            }
        }
        std::iter_swap(first, j);
        ++first;
    }
}

// test
#define SELECTION_SORT_TEST(count) do {                   \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  selection_sort(v.begin(), v.end());                      \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main() 
{
    srand((int)time(0));

    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    selection_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    selection_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
    SELECTION_SORT_TEST(10000);
    SELECTION_SORT_TEST(100000);
    SELECTION_SORT_TEST(1000000);
}

// for the SELECTION_SORT_TEST, I test 5 times...It took a really long time!

// [ 1st time ]
//   10000 numbers cost : 0.040697s
//  100000 numbers cost : 3.912810s
// 1000000 numbers cost : 394.184716s

// [ 2nd time ]
//   10000 numbers cost : 0.041063s
//  100000 numbers cost : 3.923906s
// 1000000 numbers cost : 414.782641s

// [ 3rd time ]
//   10000 numbers cost : 0.045584s
//  100000 numbers cost : 3.921748s
// 1000000 numbers cost : 411.752038s

// [ 4th time ]
//   10000 numbers cost : 0.044038s
//  100000 numbers cost : 3.917899s
// 1000000 numbers cost : 393.662278s

// [ 5th time ]
//   10000 numbers cost : 0.050582s
//  100000 numbers cost : 3.954847s
// 1000000 numbers cost : 400.196344s

// [ average ]
//   10000 numbers cost : 0.044447s
//  100000 numbers cost : 3.926242s
// 1000000 numbers cost : 402.915603s
