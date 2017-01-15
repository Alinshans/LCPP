/*
  [ Selection sort ]
  Best time complexity    : O(n²)
  Worst time complexity   : O(n²)
  Average time complexity : O(n²)
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

// selection_sort
template <typename Iter, typename Compare = std::less<>>
void selection_sort(Iter first, Iter last, Compare cmp = Compare())
{
    if (first == last || first == last - 1)
        return;
    while (first != last)
    {
        auto value = *first;
        auto i = first;
        auto j = first;
        for (; i != last; ++i)
        {
            if (cmp(*i, value))
            {
                value = *i, j = i;
            }
        }
        std::iter_swap(first, j);
        ++first;
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
    selection_sort(v.begin(), v.end(), std::greater<>());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 9 9 7 6 6 5 3 3 2 0

    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    selection_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    /** [ Small amount of data ] **/
    std::cout << "\n [ Small amount of data ]\n";
    SMALL_SORT_TEST(selection_sort, 16);
    SMALL_SORT_TEST(selection_sort, 32);
    SMALL_SORT_TEST(selection_sort, 64);
    SMALL_SORT_TEST(selection_sort, 128);
    SMALL_SORT_TEST(selection_sort, 512);
    SMALL_SORT_TEST(selection_sort, 1024);

    /** [ Large amount of data ] **/
    std::cout << "\n [ Large amount of data ]\n";
    LARGE_SORT_TEST(selection_sort, 10000);
    LARGE_SORT_TEST(selection_sort, 100000);
    LARGE_SORT_TEST(selection_sort, 1000000);
}

// I run 5 times for 'Small amount of data' and 'Large amount of data'.

// [ 1st time ]
// [ Small amount of data ]
//      16 numbers cost : 0.606492μs
//      32 numbers cost : 2.425968μs
//      64 numbers cost : 3.965525μs
//     128 numbers cost : 14.462503μs
//     512 numbers cost : 153.349189μs
//    1024 numbers cost : 509.733265μs
//
// [ Large amount of data ]
//   10000 numbers cost : 39.874055ms
//  100000 numbers cost : 3840.340961ms
// 1000000 numbers cost : 387073.169070ms

// [ 2nd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.746452μs
//      32 numbers cost : 1.632863μs
//      64 numbers cost : 4.805283μs
//     128 numbers cost : 14.369197μs
//     512 numbers cost : 148.963785μs
//    1024 numbers cost : 491.958382μs
//
// [ Large amount of data ]
//   10000 numbers cost : 39.204581ms
//  100000 numbers cost : 3893.785509ms
// 1000000 numbers cost : 387814.321517ms

// [ 3rd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.559839μs
//      32 numbers cost : 1.539557μs
//      64 numbers cost : 4.245445μs
//     128 numbers cost : 13.109560μs
//     512 numbers cost : 139.866404μs
//    1024 numbers cost : 468.818376μs
//
// [ Large amount of data ]
//   10000 numbers cost : 39.922574ms
//  100000 numbers cost : 3870.865240ms
// 1000000 numbers cost : 388238.903761ms

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
