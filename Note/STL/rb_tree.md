[Red-black Tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree "Wikipedia")
===========
Red-black tree is a kind of self-balancing binary search tree, it is much more efficient than the AVL tree in terms of insertion efficiency. It is used as the underlying mechanism for `std::set` and `std::map`.<br>

___
###1. Why use the red-black tree as an implementation of associated containers(std::set/set::map)?
  Red-black tree does not strictly control the height of the left and right subtrees, but the average height of red-black tree is still log(n), the worst case will not exceed 2log(n). For any unbalanced situation, the red-black tree can solve it in three rotations. Red-black tree sacrificed strict height balance to make insert, delete, search and other operations more efficient.<br>
  
###2. Why there is a `header` node, and let its left node points to the `left-most` node, let its right node points to the `right-most` node?
  This is an implementation technique. If there is no `header` node and it does not have the `left` member, the time complexity of calling the `begin()` will be O(logn), beceuse it have to start from root node and traverse until the `left-most` node. In order to let the call of `begin()` keep constant time complexity, so it did.<br>
  And why its right node points to the `right-most` node? We know the time complexity of `end()` is O(1), it only need to construct an iterator using the header directly. Here is a comment in the source code:
```
  // (1) the header cell is maintained with links not only to the root
  // but also to the leftmost node of the tree, to enable constant
  // time begin(), and to the rightmost node of the tree, to enable
  // linear time performance when used with the generic set algorithms
  // (set_union, etc.)
```
  That means, if you insert elements in order of size, it will be linear time complexity rather than O(nlogn). In addition, the time complexity of calling `insert(value)` is usually O(logn), but if call `insert(iterator, value)` and the actual insertion position is exactly the position of `iterator`, then its time complexity will become O(1). And I did a test:
```c++
#include <set>
#include <iostream>

#include <Windows.h>

int main() {
    using namespace std;
    set<int> s;
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    for (int i = 0; i < 1000000; ++i) {
        //s.insert(rand());     // #1
        //s.insert(i);          // #2
        //s.insert(s.end(), i); // #3
    }
    QueryPerformanceCounter(&t2);
    printf(" Runtime: %fs\n", (t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);
}
```
See the three lines of `#1`, `#2`, `#3`.<br>
If I uncomment the `#1`, the average running time is 0.25s.<br>
If I uncomment the `#2`, the average running time is 0.21s.<br>
If I uncomment the `#3`, the average running time is 0.10s.<br>
From these data, we should be able to understand the contents of the above mentioned.

###3. Why the `header` node has a `color` member and let it be red?
  This allows you to use the following code to quickly determine if an `iterator` is `end()`:
```c++
if (node->color == rb_tree_red && node->parent->parent == node)
```

###4. Why iterator's increments / decrements after apportionment is constant time?
  We can make a simple proof. Because the traversal to the `end()` from the `begin()`, each edge up to traverse twice. A tree has N nodes, N-1 sides,  up to traverse 2\*(N-1) times, so, the average increments / decrements take two steps.<br>
  
>***Reference***<br>
[http://www.cnblogs.com/Solstice/archive/2013/01/20/2868455.html](http://www.cnblogs.com/Solstice/archive/2013/01/20/2868455.html)
