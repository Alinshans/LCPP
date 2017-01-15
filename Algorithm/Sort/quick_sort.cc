/*
  [ Quick sort ]
  Best time complexity    : O(nlog(n))
  Worst time complexity   : O(n²)
  Average time complexity : O(nlog(n))
  Space complexity        : O(log(n))
  Stable                  : No
  Iterator Required       : Random access iterator
*/
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

template <typename Iter, typename UnaryPredicate>
Iter partition(Iter first, Iter last, UnaryPredicate unary_pred)
{
    while (true)
    {
        while (first != last && unary_pred(*first))
        {
            ++first;
        }
        if (first == last)
            break;
        --last;
        while (first != last && !unary_pred(*last))
        {
            --last;
        }
        if (first == last)
            break;
        std::iter_swap(first, last);
        ++first;
    }
    return first;
}

// quick_sort
template <typename Iter, typename Compare = std::less<>>
void quick_sort(Iter first, Iter last, Compare cmp = Compare())
{
    const auto len = last - first;
    if (len < 2)
        return;
    const auto pivot = *(first + len / 2);
    auto mid1 = ::partition(first, last, [&](const auto& e) { return cmp(e, pivot); });
    auto mid2 = ::partition(mid1, last, [&](const auto& e) { return !cmp(pivot, e); });
    quick_sort(first, mid1, cmp);
    quick_sort(mid2, last, cmp);
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
    quick_sort(v.begin(), v.end(), std::greater<>());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 9 9 7 6 6 5 3 3 2 0

    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    quick_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    /** [ Small amount of data ] **/
    std::cout << "\n [ Small amount of data ]\n";
    SMALL_SORT_TEST(quick_sort, 16);
    SMALL_SORT_TEST(quick_sort, 32);
    SMALL_SORT_TEST(quick_sort, 64);
    SMALL_SORT_TEST(quick_sort, 128);
    SMALL_SORT_TEST(quick_sort, 512);
    SMALL_SORT_TEST(quick_sort, 1024);

    /** [ Large amount of data ] **/
    std::cout << "\n [ Large amount of data ]\n";
    LARGE_SORT_TEST(quick_sort, 10000);
    LARGE_SORT_TEST(quick_sort, 100000);
    LARGE_SORT_TEST(quick_sort, 1000000);
}

// I run 5 times for 'Small amount of data' and 'Large amount of data'.

// [ 1st time ]
// [ Small amount of data ]
//      16 numbers cost : 1.026371μs
//      32 numbers cost : 2.099396μs
//      64 numbers cost : 4.338751μs
//     128 numbers cost : 9.237341μs
//     512 numbers cost : 42.314486μs
//    1024 numbers cost : 81.223285μs
//
// [ Large amount of data ]
//   10000 numbers cost : 0.949860ms
//  100000 numbers cost : 8.624784ms
// 1000000 numbers cost : 80.207644ms

// [ 2nd time ]
// [ Small amount of data ]
//      16 numbers cost : 1.119678μs
//      32 numbers cost : 2.052742μs
//      64 numbers cost : 6.391493μs
//     128 numbers cost : 9.610567μs
//     512 numbers cost : 43.107591μs
//    1024 numbers cost : 85.562036μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.083755ms
//  100000 numbers cost : 9.409958ms
// 1000000 numbers cost : 79.839084ms

// [ 3rd time ]
// [ Small amount of data ]
//      16 numbers cost : 2.099396μs
//      32 numbers cost : 2.239355μs
//      64 numbers cost : 4.338751μs
//     128 numbers cost : 9.283994μs
//     512 numbers cost : 42.081220μs
//    1024 numbers cost : 85.235464μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.101949ms
//  100000 numbers cost : 8.844054ms
// 1000000 numbers cost : 78.285997ms

// [ 4th time ]
// [ Small amount of data ]
//      16 numbers cost : 0.933065μs
//      32 numbers cost : 1.866129μs
//      64 numbers cost : 3.872219μs
//     128 numbers cost : 8.164316μs
//     512 numbers cost : 36.016299μs
//    1024 numbers cost : 82.576229μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.049698ms
//  100000 numbers cost : 8.754946ms
// 1000000 numbers cost : 78.433422ms

// [ 5th time ]
// [ Small amount of data ]
//      16 numbers cost : 1.959436μs
//      32 numbers cost : 2.752541μs
//      64 numbers cost : 4.851937μs
//     128 numbers cost : 9.190688μs
//     512 numbers cost : 39.048759μs
//    1024 numbers cost : 86.588407μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.039901ms
//  100000 numbers cost : 9.360972ms
// 1000000 numbers cost : 77.639384ms

// [ average ]
// [ Small amount of data ]
//      16 numbers cost : 1.4275892μs
//      32 numbers cost : 2.2020326μs
//      64 numbers cost : 4.7586302μs
//     128 numbers cost : 9.0973812μs
//     512 numbers cost : 40.513671μs
//    1024 numbers cost : 84.2370842μs
//
// [ Large amount of data ]
//   10000 numbers cost : 1.0450326ms
//  100000 numbers cost : 8.9989428ms
// 1000000 numbers cost : 78.8811062ms
