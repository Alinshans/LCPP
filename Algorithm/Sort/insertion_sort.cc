#include <iostream>
#include <algorithm>
#include <vector>

#include <Windows.h>

template <typename Iter>
void insertion_sort(Iter first, Iter last)
{
    auto len = std::distance(first, last);
    for (auto i = first + 1; i != last; ++i)
    {
        auto value = *i;
        if (value <= *first)
        {
            std::copy(first, i, first + 1);
            *first = value;
            continue;
        }
        auto j = i;
        --j;
        while (j!=first && value < *j)
        {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = value;
    }
}

int main()
{
    int a[] = { 9,8,8,7,6,6,6,5,4,2,1,1,1 };
    insertion_sort(a, a + 13);
    for (auto& it : a)
        std::cout << " " << it;
    std::cout << std::endl;
    std::vector<int> v(10000);
    for (auto& it : v) it = rand();
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    insertion_sort(v.begin(), v.end());
    QueryPerformanceCounter(&t2);
    printf("10000 numbers cost : %fs", (t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);
}
