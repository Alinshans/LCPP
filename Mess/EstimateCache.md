How to estimate the cache size by programming?
============
##Idea
Create a **contiguous block of memory** for **sequential**, **large**, **random**, and **meaningful** memory access. In this case, when the memory block can be put into the cache block, the access speed will be **significantly accelerated**. Observing the increase in memory size, we can find the **jump point** of average access time and estimate the cache size.<br>
___
##Code
```c++
/*
  [ Problem  ] Estimate the cache size
  [ Language ] C++
*/
#include <random>
#include <iostream>
#include <ctime>
#include <algorithm>

#define KB(x) ((size_t)(x) << 10)

using namespace std;

int main()
{
    vector<size_t> v;
    for (int i = 1; i < 18; ++i)  v.push_back(1 << i);

    random_device rd;
    mt19937 gen(rd());
    
    for (size_t size : v)
    {
        uniform_int_distribution<> dis(0, KB(size) - 1);
        vector<char> memory(KB(size));
        fill(memory.begin(), memory.end(), 1);

        int dummy = 0;

        clock_t begin = clock();
        for (int i = 0; i < (1 << 25); ++i)  dummy += memory[dis(gen)];
        clock_t end = clock();

        auto t = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
        cout << size << " KB, " << t << "secs, dummy: " << dummy << endl;
    }
}
```
**Output**
```
2 KB, 0.861secs, dummy: 33554432
4 KB, 0.872secs, dummy: 33554432
8 KB, 0.865secs, dummy: 33554432
16 KB, 0.877secs, dummy: 33554432
32 KB, 0.875secs, dummy: 33554432
64 KB, 0.881secs, dummy: 33554432
128 KB, 0.887secs, dummy: 33554432
256 KB, 0.937secs, dummy: 33554432
512 KB, 0.964secs, dummy: 33554432
1024 KB, 1.095secs, dummy: 33554432
2048 KB, 1.309secs, dummy: 33554432
4096 KB, 1.797secs, dummy: 33554432
8192 KB, 2.097secs, dummy: 33554432
16384 KB, 2.249secs, dummy: 33554432
32768 KB, 2.464secs, dummy: 33554432
65536 KB, 2.471secs, dummy: 33554432
131072 KB, 2.652secs, dummy: 33554432
```
___
##Conclusion
We draw the data from the column chart, you can find the rate of change in the largest place between **2048KB** and **4096KB**.<br>
![](https://github.com/Alinshans/LCPP/blob/master/Mess/Images/EstimateCache.png)

Ok, Let's check our conclusion! The following is my CPU information:
```
CPU
Intel(R) Core(TM) i5-5200U CPU @ 2.20GHz
L1 cache:	128 KB
L2 cache:	512 KB
L3 cache:	3.0 MB
```
Yeah, this is similar to our estimate! ^_^
