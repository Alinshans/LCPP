#include <cmath>
#include <iostream>

/*
  [description]
  draw a pictrue like this: 
              1
            2 2 2
          3 3 3 3 3
            .....
  n n n ... n n n ... n n n 
            .....
          3 3 3 3 3
            2 2 2
              1
  [note]
  n should be in [0, 9], otherwise, the behavior is unexpected.
*/
void diamond_digit(int n) 
{
  for (int i = 1, flag = 1; i != 0; ++flag, i += (flag <= n) ? 1 : -1)
    for (int j = 1; j <= 2 * (n + i) - 2; putchar(j < 2 * (n + i) - 2 ? (abs(2 * n - 1 - j) < i * 2 && j & 1) ? i + '0' : ' ' : '\n'), ++j) { }
}

int main()
{
	diamond_digit(0);
	diamond_digit(1);
	diamond_digit(4);
	diamond_digit(7);
	diamond_digit(9);
}
