#ifndef LCPP_DRAW_DIAMOND_H__
#define LCPP_DRAW_DIAMOND_H__

#include <cmath>
#include <iostream>

void diamond_OneToNine() 
{
	for (int i = 1, flag = 1; i != 0; ++flag, i += (flag <= 9) ? 1 : -1)
		for (int j = 1; j <= 16 + i * 2; 
			putchar(j < 16 + i * 2 ? (abs(17 - j) < i * 2 && j & 1) ? i + '0' : ' ' : '\n'), ++j) {}
}

#endif // !LCPP_DRAW_DIAMOND_H__
