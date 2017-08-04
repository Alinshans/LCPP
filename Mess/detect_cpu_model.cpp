// Detects your cpu model.

#include <cstdint>
#include <iostream>
#if defined(__GNUC__) || defined(__clang__)
#include <cpuid.h>
#elif defined _MSC_VER
#include <intrin.h>
#else
#error unknown complier
#endif

static void cpuid(std::uint32_t func, std::uint32_t sub, std::uint32_t data[4])
{
#if defined(__GNUC__) || defined(__clang__)
  __cpuid_count(func, sub, data[0], data[1], data[2], data[3]);
#elif defined _MSC_VER
  __cpuidex(reinterpret_cast<int*>(data), func, sub);
#endif
}

int main()
{
  std::uint32_t data[4];
  char str[48];
  for (int i = 0; i < 3; ++i)
  {
    cpuid(0x80000002 + i, 0, data);
    for (int j = 0; j < 4; ++j) reinterpret_cast<std::uint32_t*>(str)[i * 4 + j] = data[j];
  }
  std::cout << str << "\n";
}
