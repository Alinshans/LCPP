/*
  [ Counting sort ]
  Best time complexity    : -
  Worst time complexity   : O(n+r)
  Average time complexity : O(n+r)
  Space complexity        : O(n+r)

  [ Note ]
  Counting sort is an algorithm for sorting a collection
  of objects according to keys that are small integers.
  It is an integer sorting algorithm. It operates by counting
  the number of objects that have each distinct key value, 
  and using arithmetic on those counts to determine 
  the positions of each key value in the output sequence.
  Its running time is linear in the number of items and 
  the difference between the maximum and minimum key values,
  so it is only suitable for direct use in situations 
  where the variation in keys is not significantly greater than
  the number of items.
  
  The sorted element types apply only to integer types.
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

// function template
template <typename Iter>
void counting_sort(Iter first, Iter last)
{
    typedef typename std::iterator_traits<Iter>::value_type T;
    auto it = std::max_element(first, last);
    const auto max_size = *it + 1;
    T* map = new T[max_size];
    std::fill(map, map + max_size, 0);
    for (auto cur = first; cur != last; ++cur)
    {
        ++map[*cur];
    }
    for (T i = 0; i < max_size; ++i)
    {
        if (map[i])
        {
            first = std::fill_n(first, map[i], i);
        }
    }
    delete[]map;
}

#define COUNTING_SORT_TEST(count) do {                    \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  counting_sort(v.begin(), v.end());                       \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main()
{
    srand((int)time(0));

    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    counting_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    counting_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
    COUNTING_SORT_TEST(10000);
    COUNTING_SORT_TEST(100000);
    COUNTING_SORT_TEST(1000000);
}

// for the COUNTING_SORT_TEST, I test 5 times.

// [ 1st time ]
//   10000 numbers cost : 0.000291s
//  100000 numbers cost : 0.000914s
// 1000000 numbers cost : 0.005861s

// [ 2nd time ]
//   10000 numbers cost : 0.000353s
//  100000 numbers cost : 0.001005s
// 1000000 numbers cost : 0.005621s

// [ 3rd time ]
//   10000 numbers cost : 0.000290s
//  100000 numbers cost : 0.001330s
// 1000000 numbers cost : 0.005818s

// [ 4th time ]
//   10000 numbers cost : 0.000312s
//  100000 numbers cost : 0.000934s
// 1000000 numbers cost : 0.005940s

// [ 5th time ]
//   10000 numbers cost : 0.000340s
//  100000 numbers cost : 0.000925s
// 1000000 numbers cost : 0.005567s

// [ average ]
//   10000 numbers cost : 0.000317s
//  100000 numbers cost : 0.001022s
// 1000000 numbers cost : 0.005761s
