/*
  [ Shell sort ]
  Best time complexity    : O(n^(7/6))
  Worst time complexity   : O(n^(4/3))
  Average time complexity : -
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

// This sequence of steps is proposed by Sedgewick
constexpr static size_t step[] = {
    0,
    1,           5,
    19,          41,
    109,         209,
    505,         929,
    2161,        3905,
    8929,        16001,
    36289,       64769,
    146305,      260609,
    587521,      1045505,
    2354689,     4188161,
    9427969,     16764929,
    37730305,    67084289,
    150958081,   268386305,
    603906049,   1073643521,
    2415771649u, 4294770689u,
};

// shell_sort
template <typename Iter, typename Compare = std::less<>>
void shell_sort(Iter first, Iter last, Compare cmp = Compare())
{
    auto len = last - first;
    if (len < 2)
        return;
    size_t k = 0;
    while (step[k + 1] < static_cast<size_t>(len)) 
        ++k;
    for (int inc = step[k]; inc > 0; inc = step[--k])
    {
        for (auto i = inc; i < len; ++i)
        {
            for (auto j = i - inc; j >= 0 && cmp(*(first + j + inc), *(first + j)); j -= inc)
            {
                std::iter_swap(first + j, first + j + inc);
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
    shell_sort(v.begin(), v.end(), std::greater<>());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 9 9 7 6 6 5 3 3 2 0

    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    shell_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    /** [ Small amount of data ] **/
    std::cout << "\n [ Small amount of data ]\n";
    SMALL_SORT_TEST(shell_sort, 16);
    SMALL_SORT_TEST(shell_sort, 32);
    SMALL_SORT_TEST(shell_sort, 64);
    SMALL_SORT_TEST(shell_sort, 128);
    SMALL_SORT_TEST(shell_sort, 512);
    SMALL_SORT_TEST(shell_sort, 1024);

    /** [ Large amount of data ] **/
    std::cout << "\n [ Large amount of data ]\n";
    LARGE_SORT_TEST(shell_sort, 10000);
    LARGE_SORT_TEST(shell_sort, 100000);
    LARGE_SORT_TEST(shell_sort, 1000000);
}

// I run 5 times for 'Small amount of data' and 'Large amount of data'.

// [ 1st time ]
// [ Small amount of data ]
//      16 numbers cost : 0.559839μs
//      32 numbers cost : 1.119678μs
//      64 numbers cost : 2.565928μs
//     128 numbers cost : 6.484800μs
//     512 numbers cost : 36.482831μs
//    1024 numbers cost : 85.701996μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.192923ms
//  100000 numbers cost : 16.191472ms
// 1000000 numbers cost : 179.318713ms

// [ 2nd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.419879μs
//      32 numbers cost : 1.026371μs
//      64 numbers cost : 2.705888μs
//     128 numbers cost : 6.531453μs
//     512 numbers cost : 36.296218μs
//    1024 numbers cost : 83.369334μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.195722ms
//  100000 numbers cost : 15.968003ms
// 1000000 numbers cost : 179.756321ms

// [ 3rd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.559839μs
//      32 numbers cost : 1.212984μs
//      64 numbers cost : 3.125767μs
//     128 numbers cost : 7.324558μs
//     512 numbers cost : 41.661340μs
//    1024 numbers cost : 87.754738μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.212984ms
//  100000 numbers cost : 15.017677ms
// 1000000 numbers cost : 180.792956ms

// [ 4th time ]
// [ Small amount of data ]
//      16 numbers cost : 1.446250μs
//      32 numbers cost : 0.979718μs
//      64 numbers cost : 3.545646μs
//     128 numbers cost : 6.298187μs
//     512 numbers cost : 33.497024μs
//    1024 numbers cost : 97.505265μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.204587ms
//  100000 numbers cost : 15.579382ms
// 1000000 numbers cost : 180.861536ms

// [ 5th time ]
// [ Small amount of data ]
//      16 numbers cost : 0.466532μs
//      32 numbers cost : 1.119678μs
//      64 numbers cost : 2.845847μs
//     128 numbers cost : 6.764719μs
//     512 numbers cost : 36.622791μs
//    1024 numbers cost : 83.835866μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.197589ms
//  100000 numbers cost : 15.168833ms
// 1000000 numbers cost : 180.234050ms

// [ average ]
// [ Small amount of data ]
//      16 numbers cost : 0.690468μs
//      32 numbers cost : 1.091686μs
//      64 numbers cost : 2.957815μs
//     128 numbers cost : 6.680743μs
//     512 numbers cost : 36.912041μs
//    1024 numbers cost : 87.633440μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.200761ms
//  100000 numbers cost : 15.585073ms
// 1000000 numbers cost : 180.192715ms
