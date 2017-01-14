[Sorting Algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm "Wikipedia")
====

#Summary
There are a lot of sorting algorithms, I have only done on a part of the exercises and tests, and there are a lot of tests that are not tested because of their time complexity (e.g. bogo sort) or implementation complexity (e.g. tim sort). Here are some of the tests I did:
* **Comparison sorts**
  * binary_tree_sort
  * bubble_sort
  * comb_sort
  * heap_sort
  * insertion_sort
  * merge_sort
  * odd_even_sort
  * quick_sort
  * selection_sort
  * shell_sort
  * smooth_sort
* **Non-comparison sorts**
  * bucket_sort
  * counting_sort
  * radix_sort
* **Other**
  * sleep_sort

***
#Overview
The following information is in my algorithm implementation.<br>
###**Binary tree sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(nlog(n))|O(nlog(n))|O(n)|Yes|[binary_tree_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/binary_tree_sort.cc)|

####Dynamic display<br>
None.

###**Bubble sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|O(n²)|O(n²)|O(1)|Yes|[bubble_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/bubble_sort.cc)|

####Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/bubble_sort.gif)

###**Bucket sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n+k)|O(n²)|O(n+k)|O(n+k)|Yes|[bucket_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/bucket_sort.cc)|

####Dynamic display<br>
None.

###**Comb sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(n²)|O(n²/(2^p))|O(1)|No|[comb_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/comb_sort.cc)|

####Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/comb_sort.gif)

###**Counting sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|-|O(n+r)|O(n+r)|O(n+r)|Yes|[counting_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/counting_sort.cc)|

####Dynamic display<br>
None.

###**Heap sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(nlog(n))|O(nlog(n))|O(1)|No|[heap_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/heap_sort.cc)|

####Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/heap_sort.gif)

###**Insertion sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|O(n²)|O(n²)|O(1)|Yes|[insertion_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/insertion_sort.cc)|

####Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/insertion_sort.gif)

###**Merge sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(nlog(n))|O(nlog(n))|O(n)|Yes|[merge_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/merge_sort.cc)|

####Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/merge_sort.gif)

###**Odd even sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|O(n²)|O(n²)|O(1)|Yes|[odd_even_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/odd_even_sort.cc)|

####Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/odd_even_sort.gif)

###**Quick sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(n²)|O(nlog(n))|O(log(n))|No|[quick_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/quick_sort.cc)|

####Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/quick_sort.gif)

###**Radix sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|-|O(wn)|O(w+n)|Tes|[radix_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/radix_sort.cc)|

####Dynamic display<br>
None.

###**Selection sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n²)|O(n²)|O(n²)|O(1)|No|[selection_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/selection_sort.cc)|

####Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/selection_sort.gif)

###**Shell sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n^(7/6))|O(n^(4/3))|-|O(1)|No|[shell_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/shell_sort.cc)|

####Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/shell_sort.gif)

###**Sleep sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(1)|-|-|O(n)|No|[sleep_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/sleep_sort.cc)|

####Dynamic display<br>
None.

###**Smooth sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|O(nlog(n))|O(nlog(n))|O(1)|No|[smooth_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/smooth_sort.cc)|

####Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/smooth_sort.gif)

***
##Test
I chose some of the commonly used sorting algorithms to show their run times in various orders of magnitude.<br>

| Sorting algorithm | 16 | 32 | 64 | 128 | 512 | 1024 | 10000 | 100000 | 1000000 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Bubble sort|0.000653ms|0.002986ms|0.007185ms|0.025099ms|0.402337ms|1.591248ms|0.186413s|15.386141s|603.425456s|
|Insertion sort|0.000280ms|0.000840ms|0.001493ms|0.003452ms|0.034990ms|0.131189ms|0.014560s|1.253499s|141.664064s|
|Selection sort|0.000653ms|0.001866ms|0.004945ms|0.014836ms|0.155542ms|0.510386ms|0.044447s|3.926242s|402.915603s|
