/*
   Print fibnacci sequence.
*/
#include <iostream>

template <uint64_t N>
struct Fibnacci
{
    static enum { value = Fibnacci<N - 1>::previous + Fibnacci<N - 1>::value };
    static enum { previous = Fibnacci<N - 1>::value };
};

template <>
struct Fibnacci<1>
{
    static enum { previous = 0, value = 1 };
};

template <>
struct Fibnacci<0>
{
    static enum { previous = 0, value = 0 };
};

template <int N>
void printFibnacci()
{
    printFibnacci<N - 1>();
    std::cout << Fibnacci<N>::value << std::endl;
}

template <>
void printFibnacci<1>()
{
    std::cout << Fibnacci<1>::value << std::endl;
}

int main()
{
    printFibnacci<30>();
}

// output:
//  1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040
