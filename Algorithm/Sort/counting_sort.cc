/*
  [ Counting sort ]
  Best time complexity    : -
  Worst time complexity   : O(n+r)
  Average time complexity : O(n+r)

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
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

#ifndef MAXSIZE
#define MAXSIZE 100
#endif

// function template
template <typename Iter>
void counting_sort(Iter first, Iter last)
{
    int arr[MAXSIZE + 1];
    std::memset(arr, 0, sizeof(arr));
    for (; first != last; ++first)
    {
        ++arr[*first];
    }
    for (int i = 0; i < MAXSIZE; ++i)
    {
        for (int j = arr[i]; j > 0; --j)
        {
            std::cout << " " << i;
        }
    }
}

int main()
{
    srand((int)time(0));

    std::vector<int> v = { 2,3,6,9,0,3,9,6,5,7 };
    counting_sort(v.begin(), v.end());
    std::cout << "\n";
    // output:
    // 0 2 3 3 5 6 6 7 9 9

    std::vector<int> v2(100);
    for (auto& it : v2)
        it = rand() % 100;
    counting_sort(v2.begin(), v2.end());
    std::cout << "\n";
    // output:
    //  0 1 2 2 4 5 5 6 8 10 12 13 13 16 17 17 18 20 21 23 23 26 27 27 28 28 30 32 33 34 35 35 35 36 38 39 40 40 46 46 47 48 48 49 49 50 50 52 52 53 54 54 55 55 56 57 58 58 58 58 59 60 60 61 62 63 63 64 67 67 67 67 69 69 69 70 71 75 78 78 79 81 82 84 84 85 88 89 90 90 92 92 92 93 94 95 95 97 98 99
}
