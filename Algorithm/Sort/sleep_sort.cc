/*
  [ Sleep sort ]
  Best time complexity    : O(1)
  Worst time complexity   : -
  Average time complexity : -
  
  [ Note ]
  Create n threads for n number, let the nth thread sleep a time as long as the nth number,
  then ouput it. So the bigger the number, the later the output.
  But, this method is only suitable for small data size, and these data are almost non-repetitive.
  Otherwise, there will be errors in sorting.
*/
#include <iostream>
#include <vector>
#include <thread>

int main()
{
    std::vector<int> v;
    srand((int)time(0));
    for (int i = 0; i < 30; ++i)
        v.push_back(rand());
    std::cout << " before sort :";
    for (auto& it : v)
        std::cout << " " << it;
    const int size = v.size();
    std::vector<std::thread> threads;
    for (int i = 0; i < size; ++i)
    {
        threads.push_back(std::thread([v, i]() {std::this_thread::sleep_for(
            std::chrono::milliseconds(v[i]));
        std::cout << " " << v[i];
        }));
    }
    std::cout << "\n\n after sort :";
    clock_t start = clock();
    for (auto& t : threads)
        t.join();
    std::cout << "\n\n Runtime : " << static_cast<double>(clock() - start)/CLOCKS_PER_SEC << "s\n";
}

// [ an example ]

// before sort : 18640 27616 23799 4874 19517 26644 28973 26418 7076 7038 25172 8405 14771 2467 17190 28627 7836 29315 6652 11828 13589 27524 26094 24763 10403 1197 32572 9662 26905 19988
//
// after sort : 1197 2467 4874 6652 7038 7076 7836 8405 9662 10403 11828 13589 14771 17190 18640 19517 19988 23799 24763 25172 26094 26418 26644 26905 27524 27616 28627 28973 29315 32572
//
// Runtime : 32.578s
