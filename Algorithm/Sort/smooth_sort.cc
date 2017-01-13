/*
  [ Smooth sort ]
  Best time complexity    : O(n)
  Worst time complexity   : O(nlog(n))
  Average time complexity : O(nlog(n))
  Space complexity        : O(1)
  Iterator Required       : Random access iterator
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

/**
 * Code Reference:
 * https://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Smoothsort#C.2B.2B
 */

typedef uint32_t ui;
typedef uint64_t ull;

/**
 * The Leonardo numbers are similar to the Fibonacci numbers, and defined as :
 * L(0) = L(1) = 1
 * L(k + 2) = L(k + 1) + L(k) + 1
 */
struct LeonardoNumber
{
    ui a;  // Actual number
    ui c;  // Companion number

    LeonardoNumber() :a(1), c(1) {}
    LeonardoNumber(const LeonardoNumber& rhs) :a(rhs.a), c(rhs.c) {}

    ui gap() const { return a - c; }

    LeonardoNumber& operator++()
    {
        ui t = a;
        a = a + c + 1;
        c = t;
        return *this;
    }
    LeonardoNumber& operator--()
    {
        ui t = c;
        c = a - c - 1;
        a = t;
        return *this;
    }
    operator ui() const { return a; }
};

/**  Perform a "sift up" operation.  **/
template <typename Iter>
inline void sift(Iter first, ui root, LeonardoNumber l)
{
    ui r;
    while (l >= 3)
    {
        if (!(*(first + root - l.gap()) < *(first + root - 1)))
        {
            r = root - l.gap();
        }
        else
        {
            r = root - 1;
            --l;
        }
        if (!(*(first + root) < *(first + r)))
            break;
        std::iter_swap(first + root, first + r);
        root = r;
        --l;
    }
}

/**  Perform a "trinkle" operation.  **/
template <typename Iter>
inline void trinkle(Iter first, ui root, ull p, LeonardoNumber l)
{
    while (p)
    {
        for (; !(p % 2); p >>= 1) ++l;
        if (!--p || !(*(first + root) < *(first + root - l)))
            break;
        if (l == 1)
        {
            std::iter_swap(first + root, first + root - l);
            root -= l;
        }
        else if (l >= 3)
        {
            ui r1 = root - l.gap(), r2 = root - l;
            if (!(*(first + root - 1) < *(first + r1)))
            {
                r1 = root - 1;
                p <<= 1;
                --l;
            }
            if (!(*(first + r2) < *(first + r1)))
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
    sift(first, root, l);
}

/**  Perform a "semi-trinkle" operation.  **/
template <typename Iter>
inline void semitrinkle(Iter first, ui root, ull p, LeonardoNumber l)
{
    if (!(*(first + root - l.c) < *(first + root)))
    {
        std::iter_swap(first + root - l.c, first + root);
        trinkle(first, root - l.c, p, l);
    }
}

// function template
template <typename Iter>
void smooth_sort(Iter first, Iter last)
{
    if (first == last || first == last - 1) 
        return;
    ull p = 1;
    LeonardoNumber l;
    ui len = std::distance(first, last);
    for (ui i = 0; ++i < len; ++p)
    {
        if (p % 8 == 3)
        {
            sift(first, i - 1, l);
            ++++l; 
            p >>= 2;
        }
        else if (p % 4 == 1)
        {
            if (i + l.c < len)
            {
                sift(first, i - 1, l);
            }
            else
            {
                trinkle(first, i - 1, p, l);
            }
            for (p <<= 1; --l > 1; p <<= 1) {}
        }
    }
    trinkle(first, len - 1, p, l);
    for (--p; len-- > 1; --p)
    {
        if (l == 1)
        {
            for (; !(p % 2); p >>= 1) ++l;
        }
        else if (l >= 3)
        {
            if (p)  
                semitrinkle(first, len - l.gap(), p, l);
            --l, p <<= 1, ++p;
            semitrinkle(first, len - 1, p, l);
            --l, p <<= 1, ++p;
        }
    }
}

#define SMOOTH_SORT_TEST(count) do {                      \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  smooth_sort(v.begin(), v.end());                         \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main()
{
    srand((int)time(0));

    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    smooth_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    smooth_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
    SMOOTH_SORT_TEST(10000);
    SMOOTH_SORT_TEST(100000);
    SMOOTH_SORT_TEST(1000000);
}

// for the SMOOTH_EVEN_SORT_TEST, I test 5 times.

// [ 1st time ]
//   10000 numbers cost : 0.002628s
//  100000 numbers cost : 0.032627s
// 1000000 numbers cost : 0.466694s

// [ 2nd time ]
//   10000 numbers cost : 0.002329s
//  100000 numbers cost : 0.028346s
// 1000000 numbers cost : 0.396155s

// [ 3rd time ]
//   10000 numbers cost : 0.002868s
//  100000 numbers cost : 0.026766s
// 1000000 numbers cost : 0.402680s

// [ 4th time ]
//   10000 numbers cost : 0.002171s
//  100000 numbers cost : 0.034045s
// 1000000 numbers cost : 0.440406s

// [ 5th time ]
//   10000 numbers cost : 0.002179s
//  100000 numbers cost : 0.027729s
// 1000000 numbers cost : 0.407534s

// [ average ]
//   10000 numbers cost : 0.002435s
//  100000 numbers cost : 0.029903s
// 1000000 numbers cost : 0.422694s
