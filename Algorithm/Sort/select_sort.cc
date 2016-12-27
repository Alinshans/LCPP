/*
  [ Select sort ]
  T(n) = O(n²)
  Iterator Required : Random access iterator
*/
#include <algorithm>
#include <vector>
#include <iostream>

#include <Windows.h>

// function template
template <typename Iter>
void select_sort(Iter first, Iter last) {
    if (first == last || first == last - 1) 
        return;
    while (first != last) {
        auto value = *first;
        auto i = first;
        auto j = first;
        for (; i != last; ++i) {
            if (*i < value) {
                value = *i, j = i;
            }
        }
        std::iter_swap(first, j);
        ++first;
    }
}

// test
#define SELECT_SORT_TEST(count) do {                      \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  select_sort(v.begin(), v.end());                      \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main() {
    std::vector<int> v{ 2,4,6,2,9,8,5,1,0,3 };
    select_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 1 2 2 3 4 5 6 8 9

    SELECT_SORT_TEST(10000);
    SELECT_SORT_TEST(100000);
    SELECT_SORT_TEST(1000000);
}

// for the SELECT_SORT_TEST, I test 5 times...It took a really long time!!!

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
