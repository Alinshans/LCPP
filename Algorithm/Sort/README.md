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
|O(n)|O(n²)|O(n²)|O(1)|No|[insertion_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/insertion_sort.cc)|

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
#Test
I chose some of the sorting algorithms that are commonly used or work better to show their performances in various orders of magnitude. <br>
* **Small amount of data (In microseconds)**
| Sorting algorithm | 16 | 32 | 64 | 128 | 512 | 1024 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Bubble sort|0.718460μs|2.323331μs|8.742816μs|30.240628μs|451.183452μs|1876.617118μs|
|Insertion sort|0.354564μs|0.662476μs|1.502234μs|4.077493μs|39.589937μs|134.445298μs|
|Selection sort|0.615823μs|1.726170μs|4.404065μs|13.939987μs|150.167438μs|493.693882μs|
|Merge sort|4.292098μs|9.013405μs|18.521335μs|39.645921μs|155.457916μs|311.587638μs|
|Heap sort|0.802436μs|1.642194μs|4.208122μs|10.273043μs|48.155471μs|102.982355μs|
|Quick sort|1.427589μs|2.202033μs|4.758630μs|9.097381μs|40.513671μs|84.237084μs|
|Shell sort|0.690468μs|1.091686μs|2.957815μs|6.680743μs|36.912041μs|87.633440μs|
|Smooth sort|1.045032μs|2.649904μs|6.475469μs|15.134310μs|77.033824μs|168.044959μs|
|Comb sort|0.513186μs|1.110347μs|2.351323μs|5.514413μs|28.999652μs|62.673958μs|

* **Large amount of data (In milliseconds)**
| Sorting algorithm | 10000 | 100000 | 1000000 |
|:---:|:---:|:---:|:---:|
|Bubble sort|192.724614ms|15324.636641ms|551999.618190ms|
|Insertion sort|11.071746ms|1199.033438ms|140489.051698ms|
|Selection sort|39.881986ms|3896.193842ms|394233.806428ms|
|Merge sort|3.423321ms|32.797505ms|336.168389ms|
|Heap sort|1.547394ms|17.826575ms|282.484509ms|
|Quick sort|1.045033ms|8.998943ms|78.881106ms|
|Shell sort|1.200761ms|15.585073ms|180.192715ms|
|Smooth sort|2.136252ms|25.397649ms|350.425244ms|
|Comb sort|0.988116ms|10.678459ms|126.565752ms|
