/*
  [ Bubble sort ]
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
void bubble_sort(Iter first, Iter last)
{
    bool is_sorted = false;
    for (auto i = first; i < last - 1; ++i)
    {
        is_sorted = true;
        for (auto j = i + 1; j < last; ++j)
        {
            if (*j < *i)
            {
                std::iter_swap(i, j);
                is_sorted = false;
            }
        }
        if (is_sorted)
            return;
    }
}

#define BUBBLE_SORT_TEST(count) do {                      \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  bubble_sort(v.begin(), v.end());                         \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main()
{
    srand((int)time(0));

    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    bubble_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    bubble_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
    BUBBLE_SORT_TEST(10000);
    BUBBLE_SORT_TEST(100000);
    BUBBLE_SORT_TEST(1000000);
}

// for the BUBBLE_SORT_TEST, I test 5 times...It speet the longest time...

// [ 1st time ]
//   10000 numbers cost : 0.184335s
//  100000 numbers cost : 15.142908s
// 1000000 numbers cost : 648.958505s

// [ 2nd time ]
//   10000 numbers cost : 0.190002s
//  100000 numbers cost : 16.402173s
// 1000000 numbers cost : 592.056844s

// [ 3rd time ]
//   10000 numbers cost : 0.185633s
//  100000 numbers cost : 15.252405s
// 1000000 numbers cost : 568.771575s

// [ 4th time ]
//   10000 numbers cost : 0.185615s
//  100000 numbers cost : 15.072164s
// 1000000 numbers cost : 555.759856s

// [ 5th time ]
//   10000 numbers cost : 0.186481s
//  100000 numbers cost : 15.061057s
// 1000000 numbers cost : 651.580498s

// [ average ]
//   10000 numbers cost : 0.186413s
//  100000 numbers cost : 15.386141s
// 1000000 numbers cost : 603.425456s
