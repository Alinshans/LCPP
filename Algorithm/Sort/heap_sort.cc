/*
  [ Heap sort ]
  Best time complexity    : O(nlog(n))
  Worst time complexity   : O(nlog(n))
  Average time complexity : O(nlog(n))
  Iterator Required       : Random access iterator
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

template <typename Iter>
void adjust_heap(Iter top, size_t parent, size_t size)
{
    auto child = (parent << 1) + 1;
    if (child < size)
    {
        auto rchild = child + 1;
        if (rchild < size && *(top + child) < *(top + rchild))
            child = rchild;
        if (*(top + parent) < *(top + child))
        {
            std::iter_swap(top + parent, top + child);
            adjust_heap(top, child, size);
        }
    }
}

// function template
template <typename Iter>
void heap_sort(Iter first, Iter last)
{
    auto len = last - first;
    for (auto i = (len >> 1) - 1; i >= 0; --i)
        adjust_heap(first, i, len);
    while (len > 1)
    {
        std::iter_swap(first, first + len - 1);
        adjust_heap(first, 0, --len);
    }
}

#define HEAP_SORT_TEST(count) do {                        \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  heap_sort(v.begin(), v.end());                           \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main()
{
    srand((int)time(0));
  
    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    heap_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    heap_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
    HEAP_SORT_TEST(10000);
    HEAP_SORT_TEST(100000);
    HEAP_SORT_TEST(1000000);
}

// for the HEAP_SORT_TEST, I test 5 times

// [ 1st time ]
//   10000 numbers cost : 0.001460s
//  100000 numbers cost : 0.019324s
// 1000000 numbers cost : 0.313392s

// [ 2nd time ]
//   10000 numbers cost : 0.001503s
//  100000 numbers cost : 0.015128s
// 1000000 numbers cost : 0.318157s

// [ 3rd time ]
//   10000 numbers cost : 0.001556s
//  100000 numbers cost : 0.017766s
// 1000000 numbers cost : 0.309217s

// [ 4th time ]
//   10000 numbers cost : 0.001373s
//  100000 numbers cost : 0.020636s
// 1000000 numbers cost : 0.309385s

// [ 5th time ]
//   10000 numbers cost : 0.001476s
//  100000 numbers cost : 0.017781s
// 1000000 numbers cost : 0.312568s

// [ average ]
//   10000 numbers cost : 0.001474s
//  100000 numbers cost : 0.018127s
// 1000000 numbers cost : 0.312544s
