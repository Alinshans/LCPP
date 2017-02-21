//
// Generates prime numbers using compilation error messages...
//
#include <cstdio> 

template <size_t, size_t, bool> 
struct Check;

template <size_t i, size_t p> 
struct Check<i, p, true> 
{
  enum { value = Check<i, p - 1, i % p != 0>::value };
}; 

template <size_t i, size_t p> 
struct Check<i, p, false> 
{ 
  enum { value = false }; 
}; 

template <size_t i>
struct Check<i, 1, true> 
{ 
  enum { value = true }; 
}; 

// The code can run after uncomment this part.
template<size_t i, bool b> 
//struct Prime 
//{ 
// enum { is_prime = Check<i, i - 1, true>::value }; 
//}
;

template<size_t i> 
struct Prime<i, false> 
{ 
  enum { is_prime = false };
}; 

template <size_t i> 
struct PrintPrime 
{ 
  enum 
  { count = PrintPrime<i - 1>::count +
    (Prime<i, Check<i, i - 1, true>::value>::is_prime ? 1 : 0)
  }; 
  PrintPrime() 
  {
    PrintPrime<i - 1>();
    if (Prime<i, Check<i, i - 1, true>::value>::is_prime)
    { 
      printf(" No.%d : %d\n", count, i);
    } 
  }
};

template <> 
struct PrintPrime<1>
{ 
  enum { count = 0 };
  PrintPrime() {} 
};

int main() 
{
  PrintPrime<0x1f3>(); // 499
}

// In vs2015, will get this message from compiler(clear some notes):

//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<2, true>”
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2065 : “is_prime”: 未声明的标识符
//1>d:\code\dosomething\dosomething\main.cpp(208) : error C2056 : 非法表达式
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<3, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<3, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<5, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<5, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<7, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<7, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<11, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<11, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<13, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<13, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<17, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<17, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<19, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<19, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<23, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<23, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<29, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<29, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<31, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<31, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<37, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<37, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<41, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<41, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<43, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<43, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<47, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<47, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<53, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<53, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<59, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<59, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<61, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<61, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<67, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<67, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<71, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<71, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<73, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<73, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<79, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<79, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<83, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<83, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<89, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<89, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<97, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<97, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<101, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<101, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<103, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<103, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<107, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<107, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<109, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<109, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<113, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<113, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<127, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<127, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<131, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<131, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<137, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<137, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<139, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<139, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<149, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<149, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<151, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<151, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<157, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<157, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<163, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<163, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<167, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<167, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<173, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<173, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<179, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<179, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<181, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<181, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<191, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<191, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<193, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<193, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<197, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<197, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<199, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<199, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<211, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<211, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<223, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<223, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<227, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<227, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<229, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<229, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<233, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<233, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<239, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<239, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<241, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<241, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<251, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<251, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<257, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<257, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<263, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<263, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<269, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<269, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<271, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<271, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<277, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<277, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<281, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<281, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<283, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<283, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<293, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<293, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<307, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<307, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<311, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<311, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<313, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<313, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<317, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<317, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<331, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<331, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<337, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<337, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<347, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<347, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<349, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<349, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<353, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<353, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<359, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<359, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<367, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<367, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<373, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<373, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<379, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<379, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<383, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<383, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<389, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<389, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<397, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<397, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<401, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<401, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<409, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<409, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<419, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<419, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<421, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<421, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<431, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<431, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<433, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<433, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<439, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<439, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<443, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<443, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<449, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<449, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<457, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<457, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<461, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<461, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<463, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<463, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<467, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<467, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<479, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<479, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<487, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<487, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<491, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<491, true>”的声明
//1>d:\code\dosomething\dosomething\main.cpp(207) : error C2027 : 使用了未定义类型“Prime<499, true>”
//1>  d:\code\dosomething\dosomething\main.cpp(207) : note: 参见“Prime<499, true>”的声明
