/*
  [ Bucket sort ]
  Best time complexity    : O(n+k) (k -- the number of buckets)
  Worst time complexity   : O(n²)
  Average time complexity : O(n+k) (k -- the number of buckets)
  Space complexity        : O(n+k) (k -- the number of buckets)
  Iterator Required       : Random access iterator
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <queue>

#include <Windows.h>

// Implementation with std::queue

// function template
template <typename Iter>
void bucket_sort(Iter first, Iter last)
{
    typedef typename std::iterator_traits<Iter>::value_type T;
    std::queue<T> buckets[10];
    for (int digit = 1; digit <= 1000000000; digit *= 10)
    {
        for (auto cur = first; cur != last; ++cur)
        {
            buckets[(*cur / digit) % 10].push(*cur);
        }
        ptrdiff_t pos = 0;
        for (int i = 0; i < 10; ++i)
        {
            while (!buckets[i].empty())
            {
                *(first + pos++) = buckets[i].front();
                buckets[i].pop();
            }
        }
    }
}

#define BUCKET_SORT_TEST(count) do {                      \
  std::vector<int> v(count);                               \
  for (auto& it : v) it = rand();                          \
  LARGE_INTEGER t1, t2, tc;                                \
  QueryPerformanceFrequency(&tc);                          \
  QueryPerformanceCounter(&t1);                            \
  bucket_sort(v.begin(), v.end());                         \
  QueryPerformanceCounter(&t2);                            \
  printf(" %7d numbers cost : %fs\n",                      \
    count,(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);  \
} while(0)

int main()
{
    srand((int)time(0));

    // [ small data test ]
    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    bucket_sort(v.begin(), v.end());
    for (auto& it : v)
        std::cout << " " << it;
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    // [ big data test ]
    std::vector<int> v2(10000);
    for (auto& it : v2)
        it = rand();
    bucket_sort(v2.begin(), v2.end());
    std::cout << std::boolalpha << " " << std::is_sorted(v2.begin(), v2.end()) << "\n";
    // output:
    // true

    // [ performance test ]
    BUCKET_SORT_TEST(10000);
    BUCKET_SORT_TEST(100000);
    BUCKET_SORT_TEST(1000000);
}

// for the BUCKET_SORT_TEST, I test 5 times.

// [ 1st time ]
//   10000 numbers cost : 0.003494s
//  100000 numbers cost : 0.032847s
// 1000000 numbers cost : 0.345696s

// [ 2nd time ]
//   10000 numbers cost : 0.003346s
//  100000 numbers cost : 0.032564s
// 1000000 numbers cost : 0.350459s

// [ 3rd time ]
//   10000 numbers cost : 0.003411s
//  100000 numbers cost : 0.033163s
// 1000000 numbers cost : 0.351461s

// [ 4th time ]
//   10000 numbers cost : 0.003334s
//  100000 numbers cost : 0.032180s
// 1000000 numbers cost : 0.352333s

// [ 5th time ]
//   10000 numbers cost : 0.003315s
//  100000 numbers cost : 0.032503s
// 1000000 numbers cost : 0.350814s

// [ average ]
//   10000 numbers cost : 0.003380s
//  100000 numbers cost : 0.032651s
// 1000000 numbers cost : 0.350153s
