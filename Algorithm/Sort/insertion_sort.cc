/*
  [ Insertion sort ]
  Best time complexity    : O(n)
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
void insertion_sort(Iter first, Iter last)
{
    for (auto i = first + 1; i != last; ++i)
    {
        auto value = *i;
        if (!(*first < value))
        {
            std::copy(first, i, first + 1);
            *first = value;
            continue;
        }
        auto j = i;
        while (value < *--j)  *(j + 1) = *j;
        *(j + 1) = value;
    }
}

// test
#define INSERTION_SORT_TEST(count) do {                   \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  insertion_sort(v.begin(), v.end());                      \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main()
{
    srand((int)time(0));

    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    insertion_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    insertion_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
    INSERTION_SORT_TEST(10000);
    INSERTION_SORT_TEST(100000);
    INSERTION_SORT_TEST(1000000);
}

// for the INSERTION_SORT_TEST, I test 5 times

// [ 1st time ]
//   10000 numbers cost : 0.011086s
//  100000 numbers cost : 1.249847s
// 1000000 numbers cost : 144.757548s

// [ 2nd time ]
//   10000 numbers cost : 0.015646s
//  100000 numbers cost : 1.289624s
// 1000000 numbers cost : 143.507613s

// [ 3rd time ]
//   10000 numbers cost : 0.018521s
//  100000 numbers cost : 1.236715s
// 1000000 numbers cost : 139.605758s

// [ 4th time ]
//   10000 numbers cost : 0.013435s
//  100000 numbers cost : 1.248495s
// 1000000 numbers cost : 141.850593s

// [ 5th time ]
//   10000 numbers cost : 0.014114s
//  100000 numbers cost : 1.242814s
// 1000000 numbers cost : 138.598807s

// [ average ]
//   10000 numbers cost : 0.014560s
//  100000 numbers cost : 1.253499s
// 1000000 numbers cost : 141.664064s
