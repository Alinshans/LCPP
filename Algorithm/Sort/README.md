#[Sorting Algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm "Wikipedia")
***
##Summary
There are a lot of sorting algorithms, I have only done on a part of the exercises and tests, and there are a lot of tests that are not tested because of their time complexity (e.g. bogo sort) or implementation complexity (e.g. tim sort). Here are some of the tests I did:
* Comparison sorts
  * [binary_tree_sort](#Binary tree sort)
  * [bubble_sort](#Bubble sort)
  * [comb_sort](#Comb sort)
  * [heap_sort](#Heap sort)
  * [insertion_sort](#Insertion sort)
  * [merge_sort](#Merge sort)
  * [odd_even_sort](#Odd even sort)
  * [quick_sort](#Quick sort)
  * [selection_sort](#Selection sort)
  * [shell_sort](#Shell sort)
  * [smooth_sort](#Smooth sort)
* Non-comparison sorts
  * [bucket_sort](#Bucket sort)
  * [counting_sort](#Counting sort)
  * [radix_sort](#Radix sort)
* Other
  * [sleep_sort](#Sleep sort)

##Overview
The following information is in my algorithm implementation.
###Binary tree sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(nlog(n))|O(nlog(n))|O(n)|Yes|[binary_tree_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/binary_tree_sort.cc)|

**Display**<br>
None.

###Bubble sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|O(n²)|O(n²)|O(1)|Yes|[bubble_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/bubble_sort.cc)|

**Display**<br>
[![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/bubble_sort.gif)

###Bucket sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n+k)|O(n²)|O(n+k)|O(n+k)|Yes|[bucket_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/bucket_sort.cc)|

**Display**<br>
None.

###Comb sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(n²)|O(n²/(2^p))|O(1)|No|[comb_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/comb_sort.cc)|

**Display**<br>
[![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/comb_sort.gif)

###Counting sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|-|O(n+r)|O(n+r)|O(n+r)|Yes|[counting_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/counting_sort.cc)|

**Display**<br>
None.

###Heap sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(nlog(n))|O(nlog(n))|O(1)|No|[heap_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/heap_sort.cc)|

**Display**<br>
[![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/heap_sort.gif)

###Insertion sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|O(n²)|O(n²)|O(1)|Yes|[insertion_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/insertion_sort.cc)|

**Display**<br>
[![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/insertion_sort.gif)

###Merge sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(nlog(n))|O(nlog(n))|O(n)|Yes|[merge_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/merge_sort.cc)|

**Display**<br>
[![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/merge_sort.gif)

###Odd even sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|O(n²)|O(n²)|O(1)|Yes|[odd_even_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/odd_even_sort.cc)|

**Display**<br>
[![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/odd_even_sort.gif)

###Quick sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(n²)|O(nlog(n))|O(log(n))|No|[quick_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/quick_sort.cc)|

**Display**<br>
[![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/quick_sort.gif)

###Radix sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|-|O(wn)|O(w+n)|Tes|[radix_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/radix_sort.cc)|

**Display**<br>
None.

###Selection sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n²)|O(n²)|O(n²)|O(1)|No|[selection_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/selection_sort.cc)|

**Display**<br>
[![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/selection_sort.gif)

###Shell sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n^(7/6))|O(n^(4/3))|-|O(1)|No|[shell_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/shell_sort.cc)|

**Display**<br>
[![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/shell_sort.gif)

###Sleep sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(1)|-|-|O(n)|No|[sleep_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/sleep_sort.cc)|

**Display**<br>
None.

###Smooth sort
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|O(nlog(n))|O(nlog(n))|O(1)|No|[smooth_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/smooth_sort.cc)|

**Display**<br>
[![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/smooth_sort.gif)

##Test
I chose some of the commonly used sorting algorithms to show their run times in various orders of magnitude.
| Sorting algorithm | 16 | 32 | 64 | 128 | 512 | 1024 | 10000 | 100000 | 1000000 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Bubble sort|0.000933ms|0.002333ms|0.015862ms|0.031724ms|0.368560ms|1.623532ms|0.186413s|15.386141s|603.425456s|
|Insertion sort|0.000467ms|0.001400ms|0.001866ms|0.013529ms|0.041521ms|0.146958ms|
