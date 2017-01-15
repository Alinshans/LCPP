/*
  [ Comb sort ]
  Best time complexity    : O(nlog(n))
  Worst time complexity   : O(n²)
  Average time complexity : O(n²/(2^p)) ( p is the number of increments )
  Space complexity        : O(1)
  Stable                  : No
  Iterator Required       : Forward iterator
*/
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

// comb_sort
template <typename Iter, typename Compare = std::less<>>
void comb_sort(Iter first, Iter last, Compare cmp = Compare())
{
    static constexpr double shrink = 1.247330950103979;
    typedef typename std::iterator_traits<Iter>::difference_type Diff;
    Diff gap = std::distance(first, last);
    bool isSorted = false;
    while (!isSorted || (gap > 1))
    {
        if (gap > 1)
            gap = static_cast<Diff>(gap / shrink);
        isSorted = true;
        Iter left = first;
        Iter right = first;
        std::advance(right, gap);
        for (; right != last; ++left, ++right)
        {
            if (cmp(*right, *left))
            {
                std::iter_swap(left, right);
                isSorted = false;
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
    comb_sort(v.begin(), v.end(), std::greater<>());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 9 9 7 6 6 5 3 3 2 0

    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    comb_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    /** [ Small amount of data ] **/
    std::cout << "\n [ Small amount of data ]\n";
    SMALL_SORT_TEST(comb_sort, 16);
    SMALL_SORT_TEST(comb_sort, 32);
    SMALL_SORT_TEST(comb_sort, 64);
    SMALL_SORT_TEST(comb_sort, 128);
    SMALL_SORT_TEST(comb_sort, 512);
    SMALL_SORT_TEST(comb_sort, 1024);

    /** [ Large amount of data ] **/
    std::cout << "\n [ Large amount of data ]\n";
    LARGE_SORT_TEST(comb_sort, 10000);
    LARGE_SORT_TEST(comb_sort, 100000);
    LARGE_SORT_TEST(comb_sort, 1000000);
}

// I run 5 times for 'Small amount of data' and 'Large amount of data'.

// [ 1st time ]
// [ Small amount of data ]
//      16 numbers cost : 0.513186μs
//      32 numbers cost : 1.073024μs
//      64 numbers cost : 2.286009μs
//     128 numbers cost : 5.551735μs
//     512 numbers cost : 29.158273μs
//    1024 numbers cost : 61.069087μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.067893ms
//  100000 numbers cost : 10.311765ms
// 1000000 numbers cost : 128.819850ms

// [ 2nd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.513186μs
//      32 numbers cost : 1.073024μs
//      64 numbers cost : 2.379315μs
//     128 numbers cost : 5.458429μs
//     512 numbers cost : 28.645087μs
//    1024 numbers cost : 61.255700μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.018440ms
//  100000 numbers cost : 10.550629ms
// 1000000 numbers cost : 125.709946ms

// [ 3rd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.466532μs
//      32 numbers cost : 1.119678μs
//      64 numbers cost : 2.332662μs
//     128 numbers cost : 5.505082μs
//     512 numbers cost : 28.785047μs
//    1024 numbers cost : 66.667475μs
//
// [ Large amount of data ]
//   10000 numbers cost : 0.931665ms
//  100000 numbers cost : 10.705052ms
// 1000000 numbers cost : 128.120518ms

// [ 4th time ]
// [ Small amount of data ]
//      16 numbers cost : 0.606492μs
//      32 numbers cost : 1.166331μs
//      64 numbers cost : 2.332662μs
//     128 numbers cost : 5.551735μs
//     512 numbers cost : 29.111620μs
//    1024 numbers cost : 61.069087μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.019840ms
//  100000 numbers cost : 10.548297ms
// 1000000 numbers cost : 124.165723ms

// [ 5th time ]
// [ Small amount of data ]
//      16 numbers cost : 0.466532μs
//      32 numbers cost : 1.119678μs
//      64 numbers cost : 2.425968μs
//     128 numbers cost : 5.505082μs
//     512 numbers cost : 29.298233μs
//    1024 numbers cost : 63.308442μs
//
// [ Large amount of data ]
//   10000 numbers cost : 0.902740ms
//  100000 numbers cost : 11.276554ms
// 1000000 numbers cost : 126.012725ms

// [ average ]
// [ Small amount of data ]
//      16 numbers cost : 0.513186μs
//      32 numbers cost : 1.110347μs
//      64 numbers cost : 2.351323μs
//     128 numbers cost : 5.514413μs
//     512 numbers cost : 28.999652μs
//    1024 numbers cost : 62.673958μs
//
// [ Large amount of data ]
//   10000 numbers cost : 0.988116ms
//  100000 numbers cost : 10.678459ms
// 1000000 numbers cost : 126.565752ms
