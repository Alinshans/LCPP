/*
  [ Radix sort ]
  Best time complexity    : O(n)
  Worst time complexity   : -
  Average time complexity : O(wn) ( w is the average key length )
  Space complexity        : O(w+n)
  Iterator Required       : Random access iterator

  [ Note ]
  The sorted element types apply only to integer types.
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <queue>

#include <Windows.h>

// Implementation with std::queue

// function template
template <typename Iter>
void radix_sort(Iter first, Iter last)
{
    std::queue<typename std::iterator_traits<Iter>::value_type> buckets[10];
    for (int i = 0; i < 10; ++i)
    {
        for (auto cur = first; cur != last; ++cur)
        {
            buckets[static_cast<size_t>(*cur / std::pow(10, i)) % 10].push(*cur);
        }
        ptrdiff_t pos = 0;
        for (int j = 0; j < 10; ++j)
        {
            while (!buckets[j].empty())
            {
                *(first + pos++) = buckets[j].front();
                buckets[j].pop();
            }
        }
    }
}

#define RADIX_SORT_TEST(count) do {                       \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  radix_sort(v.begin(), v.end());                          \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main()
{
    srand((int)time(0));

    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    radix_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    radix_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
    RADIX_SORT_TEST(10000);
    RADIX_SORT_TEST(100000);
    RADIX_SORT_TEST(1000000);
}

// for the RADIX_SORT_TEST, I test 5 times

// [ 1st time ]
//   10000 numbers cost : 0.003830s
//  100000 numbers cost : 0.042243s
// 1000000 numbers cost : 0.392614s

// [ 2nd time ]
//   10000 numbers cost : 0.003612s
//  100000 numbers cost : 0.038788s
// 1000000 numbers cost : 0.397871s

// [ 3rd time ]
//   10000 numbers cost : 0.003611s
//  100000 numbers cost : 0.039692s
// 1000000 numbers cost : 0.401122s

// [ 4th time ]
//   10000 numbers cost : 0.004970s
//  100000 numbers cost : 0.052571s
// 1000000 numbers cost : 0.527749s

// [ 5th time ]
//   10000 numbers cost : 0.003811s
//  100000 numbers cost : 0.044737s
// 1000000 numbers cost : 0.488080s

// [ average ]
//   10000 numbers cost : 0.003967s
//  100000 numbers cost : 0.043606s
// 1000000 numbers cost : 0.441487s
