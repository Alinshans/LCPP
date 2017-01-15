/*
  [ Merge sort ]
  Best time complexity    : O(nlog(n))
  Worst time complexity   : O(nlog(n))
  Average time complexity : O(nlog(n))
  Space complexity        : O(n)
  Stable                  : Yes
  Iterator Required       : Random access iterator
*/
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

template <typename Iter, typename Compare>
void merge_helper(Iter first, size_t left, size_t mid, size_t right, Compare cmp)
{
    typedef typename std::iterator_traits<Iter>::value_type T;
    auto len1 = mid - left + 1, len2 = right - mid;
    T *l = new T[len1];
    T *r = new T[len2];
    size_t i = 0, j = 0, z = left;
    std::uninitialized_copy(first + left, first + mid + 1, l);
    std::uninitialized_copy(first + mid + 1, first + right + 1, r);
    while (i < len1 && j < len2)
    {
        *(first + z++) = cmp(r[j], l[i]) ? r[j++] : l[i++];
    }
    while (i < len1)
    {
        *(first + z++) = l[i++];
    }
    while (j < len2)
    {
        *(first + z++) = r[j++];
    }
    delete[]l;
    delete[]r;
}

template <typename Iter, typename Compare>
void divide_helper(Iter first, size_t left, size_t right, Compare cmp)
{
    if (left < right)
    {
        auto mid = (left + right) / 2;
        divide_helper(first, left, mid, cmp);
        divide_helper(first, mid + 1, right, cmp);
        merge_helper(first, left, mid, right, cmp);
    }
}

// merge_sort
template <typename Iter, typename Compare = std::less<>>
void merge_sort(Iter first, Iter last, Compare cmp = Compare())
{
    if (first == last || first == last - 1)
        return;
    divide_helper(first, 0, last - first - 1, cmp);
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
    merge_sort(v.begin(), v.end(), std::greater<>());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 9 9 7 6 6 5 3 3 2 0

    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    merge_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    /** [ Small amount of data ] **/
    std::cout << "\n [ Small amount of data ]\n";
    SMALL_SORT_TEST(merge_sort, 16);
    SMALL_SORT_TEST(merge_sort, 32);
    SMALL_SORT_TEST(merge_sort, 64);
    SMALL_SORT_TEST(merge_sort, 128);
    SMALL_SORT_TEST(merge_sort, 512);
    SMALL_SORT_TEST(merge_sort, 1024);

    /** [ Large amount of data ] **/
    std::cout << "\n [ Large amount of data ]\n";
    LARGE_SORT_TEST(merge_sort, 10000);
    LARGE_SORT_TEST(merge_sort, 100000);
    LARGE_SORT_TEST(merge_sort, 1000000);
}

// I run 5 times for 'Small amount of data' and 'Large amount of data'.

// [ 1st time ]
// [ Small amount of data ]
//      16 numbers cost : 4.012178μs
//      32 numbers cost : 9.283994μs
//      64 numbers cost : 19.034521μs
//     128 numbers cost : 37.882428μs
//     512 numbers cost : 148.543906μs
//    1024 numbers cost : 288.830189μs
//
// [ Large amount of data ]
//   10000 numbers cost : 3.343171ms
//  100000 numbers cost : 33.544610ms
// 1000000 numbers cost : 351.684229ms

// [ 2nd time ]
// [ Small amount of data ]
//      16 numbers cost : 4.292098μs
//      32 numbers cost : 9.144034μs
//      64 numbers cost : 19.641013μs
//     128 numbers cost : 40.355050μs
//     512 numbers cost : 171.077419μs
//    1024 numbers cost : 297.461038μs
//
// [ Large amount of data ]
//   10000 numbers cost : 3.852158ms
//  100000 numbers cost : 32.216393ms
// 1000000 numbers cost : 329.973212ms

// [ 3rd time ]
// [ Small amount of data ]
//      16 numbers cost : 4.432057μs
//      32 numbers cost : 8.677502μs
//      64 numbers cost : 16.935125μs
//     128 numbers cost : 41.941260μs
//     512 numbers cost : 154.235601μs
//    1024 numbers cost : 308.937734μs
//
// [ Large amount of data ]
//   10000 numbers cost : 3.375828ms
//  100000 numbers cost : 32.919457ms
// 1000000 numbers cost : 339.982664ms

// [ 4th time ]
// [ Small amount of data ]
//      16 numbers cost : 4.525364μs
//      32 numbers cost : 8.910768μs
//      64 numbers cost : 18.288069μs
//     128 numbers cost : 37.882428μs
//     512 numbers cost : 149.896850μs
//    1024 numbers cost : 278.333210μs
//
// [ Large amount of data ]
//   10000 numbers cost : 3.296984ms
//  100000 numbers cost : 32.983838ms
// 1000000 numbers cost : 330.263395ms

// [ 5th time ]
// [ Small amount of data ]
//      16 numbers cost : 4.198791μs
//      32 numbers cost : 9.050728μs
//      64 numbers cost : 18.707948μs
//     128 numbers cost : 40.168437μs
//     512 numbers cost : 153.535802μs
//    1024 numbers cost : 384.376018μs
//
// [ Large amount of data ]
//   10000 numbers cost : 3.248465ms
//  100000 numbers cost : 32.323229ms
// 1000000 numbers cost : 328.938443ms

// [ average ]
// [ Small amount of data ]
//      16 numbers cost : 4.292098μs
//      32 numbers cost : 9.013405μs
//      64 numbers cost : 18.521335μs
//     128 numbers cost : 39.645921μs
//     512 numbers cost : 155.457916μs
//    1024 numbers cost : 311.587638μs
//
// [ Large amount of data ]
//   10000 numbers cost : 3.423321ms
//  100000 numbers cost : 32.797505ms
// 1000000 numbers cost : 336.168389ms
