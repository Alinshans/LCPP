#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
  [ Sierpinski ]
  https://en.wikipedia.org/wiki/Sierpinski_triangle
*/

void helper(vector<char>& v, int w, int n, int x, int y)
{
    if (n == 0)
    {
        v[y*w + x] = '/';
        v[y*w + x + 1] = '\\';
    }
    else
    {
        helper(v, w, n - 1, x, y);
        helper(v, w, n - 1, x + (1 << n), y);
        helper(v, w, n - 1, x + (1 << (n - 1)), y - (1 << (n - 1)));
    }
}

void Sierpinski(int n)
{
    int w = 2 << n;
    int h = 1 << n;
    vector<char> v(w*h);
    helper(v, w, n, 0, h - 1);
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
            putchar(v[y*w + x]);
        putchar('\n');
    }
}

int main() {
    for (int i = 0; i < 6; ++i)
    {
        printf("\nn == %d:\n\n", i);
        Sierpinski(i);
    }
}
