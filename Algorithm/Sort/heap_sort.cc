/*
  [ Heap sort ]
  Best time complexity    : O(nlog(n))
  Worst time complexity   : O(nlog(n))
  Average time complexity : O(nlog(n))
  Space complexity        : O(1)
  Stable                  : No
  Iterator Required       : Random access iterator
*/
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

template <typename Iter, typename Compare>
void adjust_heap(Iter top, size_t parent, size_t size, Compare cmp)
{
    auto child = (parent << 1) + 1;
    if (child < size)
    {
        auto rchild = child + 1;
        if (rchild < size && cmp(*(top + child), *(top + rchild)))
            child = rchild;
        if (cmp(*(top + parent), *(top + child)))
        {
            std::iter_swap(top + parent, top + child);
            adjust_heap(top, child, size, cmp);
        }
    }
}

// heap_sort
template <typename Iter, typename Compare = std::less<>>
void heap_sort(Iter first, Iter last, Compare cmp = Compare())
{
    auto len = last - first;
    for (auto i = (len >> 1) - 1; i >= 0; --i)
        adjust_heap(first, i, len, cmp);
    while (len > 1)
    {
        std::iter_swap(first, first + len - 1);
        adjust_heap(first, 0, --len, cmp);
    }
}

// test
#define SMALL_SORT_TEST(sort, count) do {                  \
    double t = 0.0;                                         \
    std::vector<int> v(count);                              \
    LARGE_INTEGER t1, t2, tc;                               \
    for (int i = 0; i < 10; ++i) {                          \
        for (auto& it : v) it = rand();                     \
        QueryPerformanceFrequency(&tc);                     \
        QueryPerformanceCounter(&t1);                       \
        sort(v.begin(), v.end());                           \
        QueryPerformanceCounter(&t2);                       \
        t += (t2.QuadPart - t1.QuadPart)*1e6 / tc.QuadPart; \
    }                                                       \
    t /= 10.0;                                              \
    printf(" %7d numbers cost : %fμs\n", count, t);         \
} while(0)

#define LARGE_SORT_TEST(sort, count) do {                  \
  std::vector<int> v(count);                                \
  for (auto& it : v) it = rand();                           \
  LARGE_INTEGER t1, t2, tc;                                 \
  QueryPerformanceFrequency(&tc);                           \
  QueryPerformanceCounter(&t1);                             \
  sort(v.begin(), v.end());                                 \
  QueryPerformanceCounter(&t2);                             \
  printf(" %7d numbers cost : %fms\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1e3 / tc.QuadPart);   \
} while(0)

int main()
{
    srand((int)time(0));

    /** [ Correctness verification ] **/
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    heap_sort(v.begin(), v.end(), std::greater<>());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 9 9 7 6 6 5 3 3 2 0

    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    heap_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    /** [ Small amount of data ] **/
    std::cout << "\n [ Small amount of data ]\n";
    SMALL_SORT_TEST(heap_sort, 16);
    SMALL_SORT_TEST(heap_sort, 32);
    SMALL_SORT_TEST(heap_sort, 64);
    SMALL_SORT_TEST(heap_sort, 128);
    SMALL_SORT_TEST(heap_sort, 512);
    SMALL_SORT_TEST(heap_sort, 1024);

    /** [ Large amount of data ] **/
    std::cout << "\n [ Large amount of data ]\n";
    LARGE_SORT_TEST(heap_sort, 10000);
    LARGE_SORT_TEST(heap_sort, 100000);
    LARGE_SORT_TEST(heap_sort, 1000000);
}

// I run 5 times for 'Small amount of data' and 'Large amount of data'.

// [ 1st time ]
// [ Small amount of data ]
//      16 numbers cost : 0.653145μs
//      32 numbers cost : 1.399597μs
//      64 numbers cost : 3.965525μs
//     128 numbers cost : 9.377301μs
//     512 numbers cost : 52.391585μs
//    1024 numbers cost : 106.089460μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.504100ms
//  100000 numbers cost : 17.945634ms
// 1000000 numbers cost : 290.635202ms

// [ 2nd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.653145μs
//      32 numbers cost : 2.519275μs
//      64 numbers cost : 4.618670μs
//     128 numbers cost : 9.470607μs
//     512 numbers cost : 52.624851μs
//    1024 numbers cost : 107.908937μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.619334ms
//  100000 numbers cost : 18.021679ms
// 1000000 numbers cost : 276.859901ms

// [ 3rd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.559839μs
//      32 numbers cost : 1.352944μs
//      64 numbers cost : 3.405686μs
//     128 numbers cost : 8.817462μs
//     512 numbers cost : 42.081220μs
//    1024 numbers cost : 95.172603μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.598806ms
//  100000 numbers cost : 17.385329ms
// 1000000 numbers cost : 279.768264ms

// [ 4th time ]
// [ Small amount of data ]
//      16 numbers cost : 0.559839μs
//      32 numbers cost : 1.446250μs
//      64 numbers cost : 3.405686μs
//     128 numbers cost : 8.397583μs
//     512 numbers cost : 42.127873μs
//    1024 numbers cost : 100.770991μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.404729ms
//  100000 numbers cost : 18.023545ms
// 1000000 numbers cost : 293.309833ms

// [ 5th time ]
// [ Small amount of data ]
//      16 numbers cost : 1.586210μs
//      32 numbers cost : 1.492904μs
//      64 numbers cost : 5.645042μs
//     128 numbers cost : 15.302262μs
//     512 numbers cost : 51.551827μs
//    1024 numbers cost : 104.969783μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.610003ms
//  100000 numbers cost : 17.756688ms
// 1000000 numbers cost : 271.849344ms

// [ average ]
// [ Small amount of data ]
//      16 numbers cost : 0.802436μs
//      32 numbers cost : 1.642194μs
//      64 numbers cost : 4.208122μs
//     128 numbers cost : 10.273043μs
//     512 numbers cost : 48.155471μs
//    1024 numbers cost : 102.982355μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.547394ms
//  100000 numbers cost : 17.826575ms
// 1000000 numbers cost : 282.484509ms
