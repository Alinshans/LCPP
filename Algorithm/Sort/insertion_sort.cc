/*
  [ Insertion sort ]
  T(n) = O(n²)
  Iterator Required : Random access iterator
*/
#include <iostream>
#include <algorithm>
#include <vector>

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
    int a[] = { 9,8,8,7,6,6,6,5,4,2,1,1,1 };
    insertion_sort(a, a + 13);
    for (auto& it : a)
        std::cout << " " << it;
    std::cout << std::endl;
    // output: 1 1 1 2 4 5 6 6 6 7 8 8 9
    
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
