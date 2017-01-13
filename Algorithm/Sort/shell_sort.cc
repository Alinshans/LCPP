/*
  [ Shell sort ]
  Best time complexity    : O(n^(7/6))
  Worst time complexity   : O(n^(4/3))
  Average time complexity : -
  Iterator Required       : Random access iterator
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

// This sequence of steps is proposed by Sedgewick
constexpr size_t step[] = {
    0,
    1,           5,
    19,          41,
    109,         209,
    505,         929,
    2161,        3905,
    8929,        16001,
    36289,       64769,
    146305,      260609,
    587521,      1045505,
    2354689,     4188161,
    9427969,     16764929,
    37730305,    67084289,
    150958081,   268386305,
    603906049,   1073643521,
    2415771649u, 4294770689u,
};

// function template
template <typename Iter>
void shell_sort(Iter first, Iter last)
{
    int len = last - first;
    int k = 0;
    while (step[k + 1] < static_cast<size_t>(len)) ++k;
    for (int inc = step[k]; inc > 0; inc = step[--k])
    {
        for (auto i = inc; i < len; ++i)
        {
            for (auto j = i - inc; j >= 0 && *(first + j + inc) < *(first + j); j -= inc)
            {
                std::iter_swap(first + j, first + j + inc);
            }
        }
    }
}

#define SHELL_SORT_TEST(count) do {                       \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  shell_sort(v.begin(), v.end());                          \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main()
{
    srand((int)time(0));

    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    shell_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    shell_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
    SHELL_SORT_TEST(10000);
    SHELL_SORT_TEST(100000);
    SHELL_SORT_TEST(1000000);
}

// for the SHELL_SORT_TEST, I test 5 times

// [ 1st time ]
//   10000 numbers cost : 0.001157s
//  100000 numbers cost : 0.015571s
// 1000000 numbers cost : 0.178859s

// [ 2nd time ]
//   10000 numbers cost : 0.001293s
//  100000 numbers cost : 0.015740s
// 1000000 numbers cost : 0.190875s

// [ 3rd time ]
//   10000 numbers cost : 0.001186s
//  100000 numbers cost : 0.016806s
// 1000000 numbers cost : 0.176640s

// [ 4th time ]
//   10000 numbers cost : 0.001181s
//  100000 numbers cost : 0.015493s
// 1000000 numbers cost : 0.174109s

// [ 5th time ]
//   10000 numbers cost : 0.001171s
//  100000 numbers cost : 0.016294s
// 1000000 numbers cost : 0.193354s

// [ average ]
//   10000 numbers cost : 0.001198s
//  100000 numbers cost : 0.015974s
// 1000000 numbers cost : 0.182767s
