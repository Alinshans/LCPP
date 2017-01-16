/*
  [ Insertion sort ]
  Best time complexity    : O(n)
  Worst time complexity   : O(n²)
  Average time complexity : O(n²)
  Space complexity        : O(1)
  Stable                  : Yes
  Iterator Required       : Random access iterator
*/
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

// insertion_sort
template <typename Iter, typename Compare = std::less<>>
void insertion_sort(Iter first, Iter last, Compare cmp = Compare())
{
    if (first == last || first == last - 1)
        return;
    for (auto i = first + 1; i != last; ++i)
    {
        auto value = *i;
        if (cmp(value, *first))
        {
            std::copy(first, i, first + 1);
            *first = value;
            continue;
        }
        auto j = i;
        while (cmp(value, *--j))
        {
            *(j + 1) = *j;
        }
        *(j + 1) = value;
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
    insertion_sort(v.begin(), v.end(), std::greater<>());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 9 9 7 6 6 5 3 3 2 0

    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    insertion_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    /** [ Small amount of data ] **/
    std::cout << "\n [ Small amount of data ]\n";
    SMALL_SORT_TEST(insertion_sort, 16);
    SMALL_SORT_TEST(insertion_sort, 32);
    SMALL_SORT_TEST(insertion_sort, 64);
    SMALL_SORT_TEST(insertion_sort, 128);
    SMALL_SORT_TEST(insertion_sort, 512);
    SMALL_SORT_TEST(insertion_sort, 1024);

    /** [ Large amount of data ] **/
    std::cout << "\n [ Large amount of data ]\n";
    LARGE_SORT_TEST(insertion_sort, 10000);
    LARGE_SORT_TEST(insertion_sort, 100000);
    LARGE_SORT_TEST(insertion_sort, 1000000);
}

// I run 5 times for 'Small amount of data' and 'Large amount of data'.

// [ 1st time ]
// [ Small amount of data ]
//      16 numbers cost : 0.373226μs
//      32 numbers cost : 0.653145μs
//      64 numbers cost : 1.586210μs
//     128 numbers cost : 3.872219μs
//     512 numbers cost : 47.866221μs
//    1024 numbers cost : 131.842047μs
//
// [ Large amount of data ]
//   10000 numbers cost : 11.111868ms
//  100000 numbers cost : 1205.229921ms
// 1000000 numbers cost : 137913.015973ms

// [ 2nd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.466532μs
//      32 numbers cost : 0.653145μs
//      64 numbers cost : 1.492904μs
//     128 numbers cost : 3.825565μs
//     512 numbers cost : 39.468638μs
//    1024 numbers cost : 134.407975μs
//
// [ Large amount of data ]
//   10000 numbers cost : 10.917790ms
//  100000 numbers cost : 1194.971341ms
// 1000000 numbers cost : 138694.361583ms

// [ 3rd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.466532μs
//      32 numbers cost : 0.559839μs
//      64 numbers cost : 1.306291μs
//     128 numbers cost : 3.778912μs
//     512 numbers cost : 39.235372μs
//    1024 numbers cost : 140.892775μs
//
// [ Large amount of data ]
//   10000 numbers cost : 10.878602ms
//  100000 numbers cost : 1200.486687ms
// 1000000 numbers cost : 138650.762267ms

// [ 4th time ]
// [ Small amount of data ]
//      16 numbers cost : 0.186613μs
//      32 numbers cost : 0.793105μs
//      64 numbers cost : 1.679517μs
//     128 numbers cost : 5.085203μs
//     512 numbers cost : 34.476742μs
//    1024 numbers cost : 127.689909μs
//
// [ Large amount of data ]
//   10000 numbers cost : 11.402984ms
//  100000 numbers cost : 1197.811123ms
// 1000000 numbers cost : 142548.843606ms

// [ 5th time ]
// [ Small amount of data ]
//      16 numbers cost : 0.279919μs
//      32 numbers cost : 0.653145μs
//      64 numbers cost : 1.446250μs
//     128 numbers cost : 3.825565μs
//     512 numbers cost : 36.902710μs
//    1024 numbers cost : 137.393782μs
//
// [ Large amount of data ]
//   10000 numbers cost : 11.047486ms
//  100000 numbers cost : 1196.668119ms
// 1000000 numbers cost : 144638.275062ms

// [ average ]
// [ Small amount of data ]
//      16 numbers cost : 0.354564μs
//      32 numbers cost : 0.662476μs
//      64 numbers cost : 1.502234μs
//     128 numbers cost : 4.077493μs
//     512 numbers cost : 39.589937μs
//    1024 numbers cost : 134.445298μs
//
// [ Large amount of data ]
//   10000 numbers cost : 11.071746ms
//  100000 numbers cost : 1199.033438ms
// 1000000 numbers cost : 140489.051698ms
