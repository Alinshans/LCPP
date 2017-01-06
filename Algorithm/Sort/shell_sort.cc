/*
  [ Shell sort ]
  Best time complexity    : O(nlog(n))
  Worst time complexity   : O(nlog²(n))
  Average time complexity : O(nlog(n))
  Iterator Required       : Random access iterator
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

// function template
template <typename Iter>
void shell_sort(Iter first, Iter last)
{
    auto len = last - first;
    for (auto step = len >> 1; step > 0; step >>= 1)
    {
        for (auto i = step; i < len; ++i)
        {
            for (auto j = i - step; j >= 0; j -= step)
            {
                if (*(first + j + step) < *(first + j))
                    std::iter_swap(first + j, first + j + step);
            }
        }
    }
}

#define SHELL_SORT_TEST(count) do {                      \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  shell_sort(v.begin(), v.end());                         \
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
