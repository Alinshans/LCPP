/*
  sleep sort
  Time complexity : none
  Create n threads for n number, let the nth thread sleep a time as long as the nth number,
  then ouput it. So the bigger the number, the later the output.
  But, this method is only suitable for small data size, and these data are almost non-repetitive.
  Otherwise, there will be errors in sorting.
  For entertainment only!
*/


#include <iostream>
#include <thread>

int main()
{
	std::vector<int> v;
	srand((int)time(0));
	for (int i = 0; i < 50; ++i)	
		v.push_back(rand());
	std::cout << " before sort :";
	for (auto& it : v)	
		std::cout << " " << it;
	const int size = v.size();
	std::vector<std::thread> threads;
	for (int i = 0; i < size; ++i) {
		threads.push_back(std::thread([v,i](){std::this_thread::sleep_for(
			std::chrono::milliseconds(v[i]));
			std::cout << " " << v[i];
		}));
	}
	std::cout << std::endl << " after sort :";
	clock_t start = clock();
	for (auto& t : threads)
		t.join();
	std::cout << std::endl << " runtimes " << clock() - start << "ms" << std::endl;
}
