/*
  [ Smooth sort ]
  Best time complexity    : O(n)
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

typedef uint32_t ui;
typedef uint64_t ull;

/**
 * The Leonardo numbers are similar to the Fibonacci numbers, and defined as :
 * L(0) = L(1) = 1
 * L(k + 2) = L(k + 1) + L(k) + 1
 */
class LeonardoNumber
{
public:
    ui a;  // Actual number
    ui c;  // Companion number

public:
    LeonardoNumber() :a(1), c(1) {}
    LeonardoNumber(const LeonardoNumber& rhs) :a(rhs.a), c(rhs.c) {}

    // difference between actual number and companion number
    ui d() const { return a - c; }

    LeonardoNumber& operator++()
    {
        auto t = a;
        a = a + c + 1;
        c = t;
        return *this;
    }
    LeonardoNumber& operator--()
    {
        auto t = c;
        c = a - c - 1;
        a = t;
        return *this;
    }
    operator ui() const { return a; }
};

/**  Perform a "sift up" operation.  **/
template <typename Iter, typename Compare>
inline void sift(Iter first, ui root, LeonardoNumber l, Compare cmp)
{
    ui r;
    while (l >= 3)
    {
        if (!cmp(*(first + root - l.d()), *(first + root - 1)))
        {
            r = root - l.d();
        }
        else
        {
            r = root - 1;
            --l;
        }
        if (!cmp(*(first + root), *(first + r)))
            break;
        std::iter_swap(first + root, first + r);
        root = r;
        --l;
    }
}

/**  Perform a "trinkle" operation.  **/
template <typename Iter, typename Compare>
inline void trinkle(Iter first, ui root, ull p, LeonardoNumber l, Compare cmp)
{
    while (p)
    {
        for (; !(p % 2); p >>= 1) 
            ++l;
        if (!--p || !cmp(*(first + root), *(first + root - l)))
            break;
        if (l == 1)
        {
            std::iter_swap(first + root, first + root - l);
            root -= l;
        }
        else if (l >= 3)
        {
            ui r1 = root - l.d(), r2 = root - l;
            if (!cmp(*(first + root - 1), *(first + r1)))
            {
                r1 = root - 1;
                p <<= 1;
                --l;
            }
            if (!cmp(*(first + r2), *(first + r1)))
            {
                std::iter_swap(first + root, first + r2);
                root = r2;
            }
            else
            {
                std::iter_swap(first + root, first + r1);
                root = r1;
                --l;
                break;
            }
        }
    }
    sift(first, root, l, cmp);
}

/**  Perform a "semi-trinkle" operation.  **/
template <typename Iter, typename Compare>
inline void semitrinkle(Iter first, ui root, ull p, LeonardoNumber l, Compare cmp)
{
    if (!cmp(*(first + root - l.c), *(first + root)))
    {
        std::iter_swap(first + root - l.c, first + root);
        trinkle(first, root - l.c, p, l, cmp);
    }
}

// smooth_sort
template <typename Iter, typename Compare = std::less<>>
void smooth_sort(Iter first, Iter last, Compare cmp = Compare())
{
    if (first == last || first == last - 1) 
        return;
    ull p = 1;
    LeonardoNumber l;
    ui len = last - first;
    for (ui i = 0; ++i < len; ++p)
    {
        if (p % 8 == 3)
        {
            sift(first, i - 1, l, cmp);
            ++++l; 
            p >>= 2;
        }
        else if (p % 4 == 1)
        {
            if (i + l.c < len)
            {
                sift(first, i - 1, l, cmp);
            }
            else
            {
                trinkle(first, i - 1, p, l, cmp);
            }
            for (p <<= 1; --l > 1; p <<= 1) {}
        }
    }
    trinkle(first, len - 1, p, l, cmp);
    for (--p; len-- > 1; --p)
    {
        if (l == 1)
        {
            for (; !(p % 2); p >>= 1) 
                ++l;
        }
        else if (l >= 3)
        {
            if (p)  
                semitrinkle(first, len - l.d(), p, l, cmp);
            --l, p <<= 1, ++p;
            semitrinkle(first, len - 1, p, l, cmp);
            --l, p <<= 1, ++p;
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
    smooth_sort(v.begin(), v.end(), std::greater<>());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 9 9 7 6 6 5 3 3 2 0

    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    smooth_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    /** [ Small amount of data ] **/
    std::cout << "\n [ Small amount of data ]\n";
    SMALL_SORT_TEST(smooth_sort, 16);
    SMALL_SORT_TEST(smooth_sort, 32);
    SMALL_SORT_TEST(smooth_sort, 64);
    SMALL_SORT_TEST(smooth_sort, 128);
    SMALL_SORT_TEST(smooth_sort, 512);
    SMALL_SORT_TEST(smooth_sort, 1024);

    /** [ Large amount of data ] **/
    std::cout << "\n [ Large amount of data ]\n";
    LARGE_SORT_TEST(smooth_sort, 10000);
    LARGE_SORT_TEST(smooth_sort, 100000);
    LARGE_SORT_TEST(smooth_sort, 1000000);
}

// I run 5 times for 'Small amount of data' and 'Large amount of data'.

// [ 1st time ]
// [ Small amount of data ]
//      16 numbers cost : 1.119678μs
//      32 numbers cost : 2.752541μs
//      64 numbers cost : 6.858026μs
//     128 numbers cost : 16.002060μs
//     512 numbers cost : 80.430180μs
//    1024 numbers cost : 169.257943μs
//
// [ Large amount of data ]
//   10000 numbers cost : 2.359721ms
//  100000 numbers cost : 24.864309ms
// 1000000 numbers cost : 337.557162ms

// [ 2nd time ]
// [ Small amount of data ]
//      16 numbers cost : 1.026371μs
//      32 numbers cost : 2.845847μs
//      64 numbers cost : 6.671413μs
//     128 numbers cost : 16.002060μs
//     512 numbers cost : 80.010301μs
//    1024 numbers cost : 169.491209μs
//
// [ Large amount of data ]
//   10000 numbers cost : 2.107793ms
//  100000 numbers cost : 25.691004ms
// 1000000 numbers cost : 354.635979ms

// [ 3rd time ]
// [ Small amount of data ]
//      16 numbers cost : 1.026371μs
//      32 numbers cost : 2.565928μs
//      64 numbers cost : 6.531453μs
//     128 numbers cost : 14.509157μs
//     512 numbers cost : 74.551872μs
//    1024 numbers cost : 164.919192μs
//
// [ Large amount of data ]
//   10000 numbers cost : 2.012621ms
//  100000 numbers cost : 25.329442ms
// 1000000 numbers cost : 356.663062ms

// [ 4th time ]
// [ Small amount of data ]
//      16 numbers cost : 1.073024μs
//      32 numbers cost : 2.519275μs
//      64 numbers cost : 6.158227μs
//     128 numbers cost : 14.602463μs
//     512 numbers cost : 75.344977μs
//    1024 numbers cost : 171.730564μs
//
// [ Large amount of data ]
//   10000 numbers cost : 2.088199ms
//  100000 numbers cost : 25.508124ms
// 1000000 numbers cost : 350.590210ms

// [ 5th time ]
// [ Small amount of data ]
//      16 numbers cost : 0.979718μs
//      32 numbers cost : 2.565928μs
//      64 numbers cost : 6.158227μs
//     128 numbers cost : 14.555810μs
//     512 numbers cost : 74.831792μs
//    1024 numbers cost : 164.825885μs
//
// [ Large amount of data ]
//   10000 numbers cost : 2.112925ms
//  100000 numbers cost : 25.595365ms
// 1000000 numbers cost : 352.679809ms

// [ average ]
// [ Small amount of data ]
//      16 numbers cost : 1.045032μs
//      32 numbers cost : 2.649904μs
//      64 numbers cost : 6.475469μs
//     128 numbers cost : 15.134310μs
//     512 numbers cost : 77.033824μs
//    1024 numbers cost : 168.044959μs
//
// [ Large amount of data ]
//   10000 numbers cost : 2.136252ms
//  100000 numbers cost : 25.397649ms
// 1000000 numbers cost : 350.425244ms
