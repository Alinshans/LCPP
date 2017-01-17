/*
  [ Impro sort ]
  Best time complexity    : O(n)
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

template <typename Iter, typename T>
Iter __impro_partition(Iter first, Iter last, T pivot)
{
    while (true)
    {
        while (*first < pivot)
            ++first;
        --last;
        while (pivot < *last)
            --last;
        if (!(first < last))
            return first;
        std::iter_swap(first, last);
        ++first;
    }
}

template <typename Iter, typename Compare>
void __impro_split(Iter first, Iter last, Compare cmp)
{
    while (last - first > 96)
    {
        auto pivot = *(first + (last - first) / 2);
        auto mid = __impro_partition(first, last, pivot);
        __impro_split(mid, last, cmp);
        last = mid;
    }
}

// impro_sort
template <typename Iter, typename Compare = std::less<>>
inline void impro_sort(Iter first, Iter last, Compare cmp = Compare())
{
    __impro_split(first, last, cmp);
    insertion_sort(first, last, cmp);
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
    printf(" %9d numbers cost : %fμs\n", count, t);         \
} while(0)

#define LARGE_SORT_TEST(sort, count) do {                  \
  std::vector<int> v(count);                                \
  for (auto& it : v) it = rand();                           \
  LARGE_INTEGER t1, t2, tc;                                 \
  QueryPerformanceFrequency(&tc);                           \
  QueryPerformanceCounter(&t1);                             \
  sort(v.begin(), v.end());                                 \
  QueryPerformanceCounter(&t2);                             \
  printf(" %9d numbers cost : %fms\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1e3 / tc.QuadPart);   \
} while(0)

int main()
{
    srand((int)time(0));

    /** [ Correctness verification ] **/
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    impro_sort(v.begin(), v.end(), std::greater<>());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 9 9 7 6 6 5 3 3 2 0

    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    impro_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    /** [ Small amount of data ] **/
    std::cout << "\n [ Small amount of data ]\n";
    SMALL_SORT_TEST(impro_sort, 16);
    SMALL_SORT_TEST(impro_sort, 32);
    SMALL_SORT_TEST(impro_sort, 64);
    SMALL_SORT_TEST(impro_sort, 128);
    SMALL_SORT_TEST(impro_sort, 256);
    SMALL_SORT_TEST(impro_sort, 512);
    SMALL_SORT_TEST(impro_sort, 1024);
    SMALL_SORT_TEST(impro_sort, 2048);
    SMALL_SORT_TEST(impro_sort, 4096);
    SMALL_SORT_TEST(impro_sort, 8192);

    /** [ Large amount of data ] **/
    std::cout << "\n [ Large amount of data ]\n";
    LARGE_SORT_TEST(impro_sort, 10000);
    LARGE_SORT_TEST(impro_sort, 100000);
    LARGE_SORT_TEST(impro_sort, 1000000);
    LARGE_SORT_TEST(impro_sort, 10000000);
    LARGE_SORT_TEST(impro_sort, 100000000);
}

// I run 5 times for 'Small amount of data' and 'Large amount of data'.

// [ 1st time ]
// [ Small amount of data ]
//        16 numbers cost : 0.419878μs
//        32 numbers cost : 0.746450μs
//        64 numbers cost : 1.586206μs
//       128 numbers cost : 4.478700μs
//       256 numbers cost : 9.283972μs
//       512 numbers cost : 22.346848μs
//      1024 numbers cost : 49.732234μs
//      2048 numbers cost : 105.902600μs
//      4096 numbers cost : 229.020205μs
//      8192 numbers cost : 436.393359μs
//
// [ Large amount of data ]
//     10000 numbers cost : 0.650345ms
//    100000 numbers cost : 6.837016ms
//   1000000 numbers cost : 78.621717ms
//  10000000 numbers cost : 727.584922ms
// 100000000 numbers cost : 7265.995608ms

// [ 2nd time ]
// [ Small amount of data ]
//        16 numbers cost : 0.326572μs
//        32 numbers cost : 0.653144μs
//        64 numbers cost : 1.492900μs
//       128 numbers cost : 4.292088μs
//       256 numbers cost : 8.864094μs
//       512 numbers cost : 19.221089μs
//      1024 numbers cost : 41.334671μs
//      2048 numbers cost : 96.991853μs
//      4096 numbers cost : 229.859961μs
//      8192 numbers cost : 503.760475μs
//
// [ Large amount of data ]
//     10000 numbers cost : 0.625152ms
//    100000 numbers cost : 6.987239ms
//   1000000 numbers cost : 78.721555ms
//  10000000 numbers cost : 721.831191ms
// 100000000 numbers cost : 7266.971125ms

// [ 3rd time ]
// [ Small amount of data ]
//        16 numbers cost : 0.886409μs
//        32 numbers cost : 1.399594μs
//        64 numbers cost : 3.545638μs
//       128 numbers cost : 11.243404μs
//       256 numbers cost : 21.740358μs
//       512 numbers cost : 49.405662μs
//      1024 numbers cost : 109.075013μs
//      2048 numbers cost : 234.012090μs
//      4096 numbers cost : 474.882189μs
//      8192 numbers cost : 470.963326μs
//
// [ Large amount of data ]
//     10000 numbers cost : 0.587363ms
//    100000 numbers cost : 7.569937ms
//   1000000 numbers cost : 87.520335ms
//  10000000 numbers cost : 720.045776ms
// 100000000 numbers cost : 7460.197184ms

// [ 4th time ]
// [ Small amount of data ]
//        16 numbers cost : 0.233266μs
//        32 numbers cost : 0.653144μs
//        64 numbers cost : 1.492900μs
//       128 numbers cost : 4.525353μs
//       256 numbers cost : 8.677482μs
//       512 numbers cost : 20.200804μs
//      1024 numbers cost : 43.154143μs
//      2048 numbers cost : 91.906662μs
//      4096 numbers cost : 210.918791μs
//      8192 numbers cost : 471.009980μs
//
// [ Large amount of data ]
//     10000 numbers cost : 0.655943ms
//    100000 numbers cost : 7.119267ms
//   1000000 numbers cost : 87.506339ms
//  10000000 numbers cost : 730.329059ms
// 100000000 numbers cost : 7482.457258ms

// [ 5th time ]
// [ Small amount of data ]
//        16 numbers cost : 0.466531μs
//        32 numbers cost : 0.979716μs
//        64 numbers cost : 2.425963μs
//       128 numbers cost : 7.091275μs
//       256 numbers cost : 13.249488μs
//       512 numbers cost : 27.012161μs
//      1024 numbers cost : 55.563875μs
//      2048 numbers cost : 100.864063μs
//      4096 numbers cost : 246.001944μs
//      8192 numbers cost : 516.263514μs
//
// [ Large amount of data ]
//     10000 numbers cost : 0.569168ms
//    100000 numbers cost : 7.638050ms
//   1000000 numbers cost : 91.230192ms
//  10000000 numbers cost : 722.140968ms
// 100000000 numbers cost : 7324.451044ms

// [ average ]
// [ Small amount of data ]
//        16 numbers cost : 0.466531μs
//        32 numbers cost : 0.886410μs
//        64 numbers cost : 2.108721μs
//       128 numbers cost : 6.326164μs
//       256 numbers cost : 12.363079μs
//       512 numbers cost : 27.637313μs
//      1024 numbers cost : 59.771987μs
//      2048 numbers cost : 125.935454μs
//      4096 numbers cost : 278.136618μs
//      8192 numbers cost : 479.678131μs
//
// [ Large amount of data ]
//     10000 numbers cost : 0.617594ms
//    100000 numbers cost : 7.230302ms
//   1000000 numbers cost : 84.720028ms
//  10000000 numbers cost : 724.386383ms
// 100000000 numbers cost : 7360.014444ms
