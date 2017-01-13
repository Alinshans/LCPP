/*
  [ Odd even sort ]
  Best time complexity    : O(n)
  Worst time complexity   : O(n²)
  Average time complexity : O(n²)
  Space complexity        : O(1)
  Iterator Required       : Random access iterator
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

// function template
template <typename Iter>
void odd_even_sort(Iter first, Iter last)
{
    const auto len = std::distance(first, last);
    bool isSorted = false;
    for (int i = 0; i < len; ++i)
    {
        isSorted = true;
        for (int j = i & 1 ? 2 : 1; j < len; j += 2)
        {
            if (*(first + j) < *(first + j - 1))
            {
                std::iter_swap(first + j, first + j - 1);
                isSorted = false;
            }
        }
        if (isSorted)
            break;
    }
}

#define ODD_EVEN_SORT_TEST(count) do {                    \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  odd_even_sort(v.begin(), v.end());                       \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main()
{
    srand((int)time(0));

    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    odd_even_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    odd_even_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
    ODD_EVEN_SORT_TEST(10000);
    ODD_EVEN_SORT_TEST(100000);
    ODD_EVEN_SORT_TEST(1000000);
}

// for the ODD_EVEN_SORT_TEST, I test 5 times...
// Although on small data odd_even_sort is a little bit faster than bubble_sort, it is much slower on large data!!

// [ 1st time ]
//   10000 numbers cost : 0.072000s
//  100000 numbers cost : 11.789294s
// 1000000 numbers cost : 1416.717648s

// [ 2nd time ]
//   10000 numbers cost : 0.073348s
//  100000 numbers cost : 10.690876s
// 1000000 numbers cost : 1332.606154s

// [ 3rd time ]
//   10000 numbers cost : 0.072807s
//  100000 numbers cost : 10.965167s
// 1000000 numbers cost : 1463.238965s

// [ 4th time ]
//   10000 numbers cost : 0.068327s
//  100000 numbers cost : 9.927881s
// 1000000 numbers cost : 1198.989810s

// [ 5th time ]
//   10000 numbers cost : 0.072662s
//  100000 numbers cost : 10.630529s
// 1000000 numbers cost : 1204.947700s

// [ average ]
//   10000 numbers cost : 0.071829s
//  100000 numbers cost : 10.800749s
// 1000000 numbers cost : 1323.300005s
