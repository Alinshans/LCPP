/*
  [ Comb sort ]
  Best time complexity    : O(nlog(n))
  Worst time complexity   : O(n²)
  Average time complexity : O(n²/2^(1.3))
  Iterator Required       : Forward iterator
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

#include <Windows.h>

// function template
template <typename Iter>
void comb_sort(Iter first, Iter last)
{
    static constexpr double shrink = 1.247330950103979;
    typedef typename std::iterator_traits<Iter>::difference_type Diff;
    Diff gap = std::distance(first, last);
    bool isSorted = false;
    while (!isSorted || (gap > 1))
    {
        if(gap > 1)
            gap = static_cast<Diff>(gap / shrink);
        isSorted = true;
        Iter left = first;
        Iter right = first;
        std::advance(right, gap);
        for (; right != last; ++left, ++right)
        {
            if (*right < *left)
            {
                std::iter_swap(left, right);
                isSorted = false;
            }
        }
    }
}

#define COMB_SORT_TEST(count) do {                        \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  comb_sort(v.begin(), v.end());                           \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main()
{
    srand((int)time(0));

    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    comb_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    comb_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
    COMB_SORT_TEST(10000);
    COMB_SORT_TEST(100000);
    COMB_SORT_TEST(1000000);
}

// for the COMB_SORT_TEST, I test 5 times

// [ 1st time ]
//   10000 numbers cost : 0.000870s
//  100000 numbers cost : 0.010638s
// 1000000 numbers cost : 0.120450s

// [ 2nd time ]
//   10000 numbers cost : 0.000858s
//  100000 numbers cost : 0.010342s
// 1000000 numbers cost : 0.125358s

// [ 3rd time ]
//   10000 numbers cost : 0.000835s
//  100000 numbers cost : 0.012659s
// 1000000 numbers cost : 0.125669s

// [ 4th time ]
//   10000 numbers cost : 0.000902s
//  100000 numbers cost : 0.011145s
// 1000000 numbers cost : 0.132911s

// [ 5th time ]
//   10000 numbers cost : 0.001193s
//  100000 numbers cost : 0.012088s
// 1000000 numbers cost : 0.135358s

// [ average ]
//   10000 numbers cost : 0.000932s
//  100000 numbers cost : 0.011374s
// 1000000 numbers cost : 0.127949s
