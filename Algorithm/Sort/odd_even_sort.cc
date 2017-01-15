/*
  [ Odd even sort ]
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

// odd_even_sort
template <typename Iter, typename Compare = std::less<>>
void odd_even_sort(Iter first, Iter last, Compare cmp = Compare())
{
    const auto len = last - first;
    bool isSorted = false;
    for (int i = 0; i < len; ++i)
    {
        isSorted = true;
        for (int j = i & 1 ? 2 : 1; j < len; j += 2)
        {
            if (cmp(*(first + j), *(first + j - 1)))
            {
                std::iter_swap(first + j, first + j - 1);
                isSorted = false;
            }
        }
        if (isSorted)
            break;
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
    printf("// %7d numbers cost : %fμs\n", count, t);         \
} while(0)

#define LARGE_SORT_TEST(sort, count) do {                  \
  std::vector<int> v(count);                                \
  for (auto& it : v) it = rand();                           \
  LARGE_INTEGER t1, t2, tc;                                 \
  QueryPerformanceFrequency(&tc);                           \
  QueryPerformanceCounter(&t1);                             \
  sort(v.begin(), v.end());                                 \
  QueryPerformanceCounter(&t2);                             \
  printf("// %7d numbers cost : %fms\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1e3 / tc.QuadPart);   \
} while(0)

int main()
{
    srand((int)time(0));

    /** [ Correctness verification ] **/
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    odd_even_sort(v.begin(), v.end(), std::greater<>());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 9 9 7 6 6 5 3 3 2 0

    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    odd_even_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    /** [ Small amount of data ] **/
    std::cout << "\n// [ Small amount of data ]\n";
    SMALL_SORT_TEST(odd_even_sort, 16);
    SMALL_SORT_TEST(odd_even_sort, 32);
    SMALL_SORT_TEST(odd_even_sort, 64);
    SMALL_SORT_TEST(odd_even_sort, 128);
    SMALL_SORT_TEST(odd_even_sort, 512);
    SMALL_SORT_TEST(odd_even_sort, 1024);

    /** [ Large amount of data ] **/
    std::cout << "//\n// [ Large amount of data ]\n";
    LARGE_SORT_TEST(odd_even_sort, 10000);
    LARGE_SORT_TEST(odd_even_sort, 100000);
    LARGE_SORT_TEST(odd_even_sort, 1000000);
}

// I run 5 times for 'Small amount of data' and 'Large amount of data'.

// [ 1st time ]
// [ Small amount of data ]
//      16 numbers cost : 0.559839μs
//      32 numbers cost : 1.772823μs
//      64 numbers cost : 5.738348μs
//     128 numbers cost : 19.174480μs
//     512 numbers cost : 244.976146μs
//    1024 numbers cost : 842.790722μs
//
// [ Large amount of data ]
//   10000 numbers cost : 108.089951ms
//  100000 numbers cost : 11540.397971ms
// 1000000 numbers cost : 1199569.698536ms

// [ 2nd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.606492μs
//      32 numbers cost : 1.959436μs
//      64 numbers cost : 6.531453μs
//     128 numbers cost : 21.087263μs
//     512 numbers cost : 255.566431μs
//    1024 numbers cost : 854.873910μs
//
// [ Large amount of data ]
//   10000 numbers cost : 107.003397ms
//  100000 numbers cost : 11183.463854ms
// 1000000 numbers cost : 1197772.424112ms

// [ 3rd time ]
// [ Small amount of data ]
//      16 numbers cost : 0.699799μs
//      32 numbers cost : 2.146049μs
//      64 numbers cost : 6.484800μs
//     128 numbers cost : 21.040610μs
//     512 numbers cost : 263.637441μs
//    1024 numbers cost : 824.082774μs
//
// [ Large amount of data ]
//   10000 numbers cost : 107.693865ms
//  100000 numbers cost : 11500.014463ms
// 1000000 numbers cost : 1188684.744485ms

// [ 4th time ]
// [ Small amount of data ]
//      16 numbers cost : 0.699799μs
//      32 numbers cost : 2.146049μs
//      64 numbers cost : 6.391493μs
//     128 numbers cost : 21.180569μs
//     512 numbers cost : 258.692198μs
//    1024 numbers cost : 1031.689678μs
//
// [ Large amount of data ]
//   10000 numbers cost : 106.175769ms
//  100000 numbers cost : 11451.304751ms
// 1000000 numbers cost : 1183510.172738ms

// [ 5th time ]
// [ Small amount of data ]
//      16 numbers cost : 0.653145μs
//      32 numbers cost : 2.286009μs
//      64 numbers cost : 6.251534μs
//     128 numbers cost : 21.180569μs
//     512 numbers cost : 256.032963μs
//    1024 numbers cost : 1006.870156μs
//
// [ Large amount of data ]
//   10000 numbers cost : 104.280714ms
//  100000 numbers cost : 11660.575309ms
// 1000000 numbers cost : 1223757.897227ms

// [ average ]
// [ Small amount of data ]
//      16 numbers cost : 0.643815μs
//      32 numbers cost : 2.062073μs
//      64 numbers cost : 6.279526μs
//     128 numbers cost : 20.732698μs
//     512 numbers cost : 255.781036μs
//    1024 numbers cost : 912.061448μs
//
// [ Large amount of data ]
//   10000 numbers cost : 106.648739ms
//  100000 numbers cost : 11467.151270ms
// 1000000 numbers cost : 1198658.987420ms
