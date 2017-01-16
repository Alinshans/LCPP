/*
  [ Bubble sort ]
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

// bubble_sort
template <typename Iter, typename Compare = std::less<>>
void bubble_sort(Iter first, Iter last, Compare cmp = Compare())
{
    bool is_sorted = false;
    for (auto i = first; !is_sorted && i < last - 1; ++i)
    {
        is_sorted = true;
        for (auto j = i + 1; j < last; ++j)
        {
            if (cmp(*j, *i))
            {
                std::iter_swap(i, j);
                is_sorted = false;
            }
        }
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
    bubble_sort(v.begin(), v.end(), std::greater<>());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 9 9 7 6 6 5 3 3 2 0

    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    bubble_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    /** [ Small amount of data ] **/
    std::cout << "\n [ Small amount of data ]\n";
    SMALL_SORT_TEST(bubble_sort, 16);
    SMALL_SORT_TEST(bubble_sort, 32);
    SMALL_SORT_TEST(bubble_sort, 64);
    SMALL_SORT_TEST(bubble_sort, 128);
    SMALL_SORT_TEST(bubble_sort, 512);
    SMALL_SORT_TEST(bubble_sort, 1024);

    /** [ Large amount of data ] **/
    std::cout << "\n [ Large amount of data ]\n";
    LARGE_SORT_TEST(bubble_sort, 10000);
    LARGE_SORT_TEST(bubble_sort, 100000);
    LARGE_SORT_TEST(bubble_sort, 1000000);
}

// I run 5 times for 'Small amount of data' and 'Large amount of data'.

// [ 1st time ]
// [ Small amount of data ]
//      16 numbers cost : 0.886411μs
//      32 numbers cost : 2.425968μs
//      64 numbers cost : 8.444236μs
//     128 numbers cost : 30.697830μs
//     512 numbers cost : 452.256477μs
//    1024 numbers cost : 1773.476142μs
//
// [ Large amount of data ]
//   10000 numbers cost : 183.830548ms
//  100000 numbers cost : 14509.479005ms
// 1000000 numbers cost : 544751.176361ms

// [ 2nd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.653145μs
//      32 numbers cost : 2.286009μs
//      64 numbers cost : 8.164316μs
//     128 numbers cost : 29.531499μs
//     512 numbers cost : 472.037449μs
//    1024 numbers cost : 2209.777212μs
//
// [ Large amount of data ]
//   10000 numbers cost : 218.574613ms
//  100000 numbers cost : 17847.828805ms
// 1000000 numbers cost : 573350.263637ms

// [ 3rd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.606492μs
//      32 numbers cost : 2.519275μs
//      64 numbers cost : 8.630849μs
//     128 numbers cost : 31.024402μs
//     512 numbers cost : 446.611435μs
//    1024 numbers cost : 1798.762196μs
//
// [ Large amount of data ]
//   10000 numbers cost : 193.914645ms
//  100000 numbers cost : 14642.575557ms
// 1000000 numbers cost : 548324.842289ms

// [ 4th time ]
// [ Small amount of data ]
//      16 numbers cost : 0.513186μs
//      32 numbers cost : 2.052742μs
//      64 numbers cost : 10.310365μs
//     128 numbers cost : 29.624805μs
//     512 numbers cost : 427.203689μs
//    1024 numbers cost : 1784.346346μs
//
// [ Large amount of data ]
//   10000 numbers cost : 182.409024ms
//  100000 numbers cost : 14804.657766ms
// 1000000 numbers cost : 545618.315408ms

// [ 5th time ]
// [ Small amount of data ]
//      16 numbers cost : 0.933065μs
//      32 numbers cost : 2.332662μs
//      64 numbers cost : 8.164316μs
//     128 numbers cost : 30.324604μs
//     512 numbers cost : 457.808212μs
//    1024 numbers cost : 1816.723692μs
//
// [ Large amount of data ]
//   10000 numbers cost : 184.894242ms
//  100000 numbers cost : 14818.642074ms
// 1000000 numbers cost : 547953.493254ms

// [ average ]
// [ Small amount of data ]
//      16 numbers cost : 0.718460μs
//      32 numbers cost : 2.323331μs
//      64 numbers cost : 8.742816μs
//     128 numbers cost : 30.240628μs
//     512 numbers cost : 451.183452μs
//    1024 numbers cost : 1876.617118μs
//
// [ Large amount of data ]
//   10000 numbers cost : 192.724614ms
//  100000 numbers cost : 15324.636641ms
// 1000000 numbers cost : 551999.618190ms
