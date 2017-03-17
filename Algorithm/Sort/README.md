[Sorting Algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm "Wikipedia")
====

# Summary
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
# Overview
The following information is in my algorithm implementation.<br>
### **Binary tree sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(nlog(n))|O(nlog(n))|O(n)|Yes|[binary_tree_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/binary_tree_sort.cc)|

#### Dynamic display<br>
None.

### **Bubble sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|O(n²)|O(n²)|O(1)|Yes|[bubble_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/bubble_sort.cc)|

#### Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/bubble_sort.gif)

### **Bucket sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n+k)|O(n²)|O(n+k)|O(n+k)|Yes|[bucket_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/bucket_sort.cc)|

#### Dynamic display<br>
None.

### **Comb sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(n²)|O(n²/(2^p))|O(1)|No|[comb_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/comb_sort.cc)|

#### Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/comb_sort.gif)

### **Counting sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|-|O(n+r)|O(n+r)|O(n+r)|Yes|[counting_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/counting_sort.cc)|

#### Dynamic display<br>
None.

### **Heap sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(nlog(n))|O(nlog(n))|O(1)|No|[heap_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/heap_sort.cc)|

#### Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/heap_sort.gif)

### **Insertion sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|O(n²)|O(n²)|O(1)|Yes|[insertion_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/insertion_sort.cc)|

#### Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/insertion_sort.gif)

### **Merge sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(nlog(n))|O(nlog(n))|O(n)|Yes|[merge_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/merge_sort.cc)|

#### Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/merge_sort.gif)

### **Odd even sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|O(n²)|O(n²)|O(1)|Yes|[odd_even_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/odd_even_sort.cc)|

#### Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/odd_even_sort.gif)

### **Quick sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(nlog(n))|O(n²)|O(nlog(n))|O(log(n))|No|[quick_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/quick_sort.cc)|

#### Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/quick_sort.gif)

### **Radix sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|-|O(wn)|O(w+n)|Tes|[radix_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/radix_sort.cc)|

#### Dynamic display<br>
None.

### **Selection sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n²)|O(n²)|O(n²)|O(1)|No|[selection_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/selection_sort.cc)|

#### Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/selection_sort.gif)

### **Shell sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n^(7/6))|O(n^(4/3))|-|O(1)|No|[shell_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/shell_sort.cc)|

#### Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/shell_sort.gif)

### **Sleep sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(1)|-|-|O(n)|No|[sleep_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/sleep_sort.cc)|

#### Dynamic display<br>
None.

### **Smooth sort**
|Best time complexity|Worst time complexity|Average time complexity|Memory|Stable|Source code|
|:---:|:---:|:---:|:---:|:---:|:---:|
|O(n)|O(nlog(n))|O(nlog(n))|O(1)|No|[smooth_sort.cc](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/smooth_sort.cc)|

#### Dynamic display<br>
![Sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/Images/smooth_sort.gif)

***

# Test
I chose some of the sorting algorithms that are commonly used or work better to show their performances in various orders of magnitude, and compared them to `std::sort`. (Only for **integers**)<br>
* **Small amount of data (In microseconds)**

| Sorting algorithm | 16 | 32 | 64 | 128 | 512 | 1024 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Bubble sort|0.718460μs|2.323331μs|8.742816μs|30.240628μs|451.183452μs|1876.617118μs|
|Insertion sort|**0.354564μs**|**0.662476μs**|**1.502234μs**|**4.077493μs**|39.589937μs|134.445298μs|
|Selection sort|0.615823μs|1.726170μs|4.404065μs|13.939987μs|150.167438μs|493.693882μs|
|Merge sort|4.292098μs|9.013405μs|18.521335μs|39.645921μs|155.457916μs|311.587638μs|
|Heap sort|0.802436μs|1.642194μs|4.208122μs|10.273043μs|48.155471μs|102.982355μs|
|Quick sort|1.427589μs|2.202033μs|4.758630μs|9.097381μs|40.513671μs|84.237084μs|
|Shell sort|0.690468μs|1.091686μs|2.957815μs|6.680743μs|36.912041μs|87.633440μs|
|Smooth sort|1.045032μs|2.649904μs|6.475469μs|15.134310μs|77.033824μs|168.044959μs|
|Comb sort|0.513186μs|1.110347μs|2.351323μs|5.514413μs|**28.999652μs**|**62.673958μs**|
|std::sort|0.438540μs|0.821097μs|2.621912μs|5.924961μs|31.798846μs|66.770113μs|

* **Large amount of data (In milliseconds)**

| Sorting algorithm | 10000 | 100000 | 1000000 |
|:---:|:---:|:---:|:---:|
|Bubble sort|192.724614ms|15324.636641ms|551999.618190ms|
|Insertion sort|11.071746ms|1199.033438ms|140489.051698ms|
|Selection sort|39.881986ms|3896.193842ms|394233.806428ms|
|Merge sort|3.423321ms|32.797505ms|336.168389ms|
|Heap sort|1.547394ms|17.826575ms|282.484509ms|
|Quick sort|1.045033ms|**8.998943ms**|**78.881106ms**|
|Shell sort|1.200761ms|15.585073ms|180.192715ms|
|Smooth sort|2.136252ms|25.397649ms|350.425244ms|
|Comb sort|**0.988116ms**|10.678459ms|126.565752ms|
|std::sort|0.845077ms|10.250556ms|104.314305ms|

From the above table, we can see that (In my sorting algorithms implementation):<br>
* When the amount of data is less than 128, `insertion_sort` is more advantageous.
* When the amount of data is between 128 and 10000, `comb_sort` is more advantageous.
* When the amount of data is greater than 10000, `quick_sort` is more advantageous.

In order to get more accurate data, I have done a further test.<br>

| Sorting algorithm | 16 | 32 | 64 | 128 | 256 | 512 | 1024 | 2048 | 4096 | 8192 | 10000 | 100000 | 1000000 | 10000000 | 100000000 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Insertion sort|**0.401218μs**|**0.690468μs**|**1.558218μs**|**4.198791μs**|**13.090898μs**|45.300293μs|167.597088μs|518.410767μs|2153.046876μs|9295.592109μs|-|-|-|-|-|
|Comb sort|0.606492μs|1.250307μs|2.836517μs|6.494131μs|16.561899μs|36.277557μs|84.600980μs|163.528925μs|330.892747μs|747.338199μs|0.901061ms|12.528727ms|140.981603ms|1540.349918ms|16413.311661ms|
|Quick sort|1.166331μs|2.286009μs|4.870598μs|10.459656μs|22.356231μs|47.968858μs|102.991685μs|180.827946μs|386.783325μs|804.982939μs|0.942489ms|10.484755ms|**91.543914ms**|**865.948456ms**|**8535.924019ms**|
|std::sort|0.485194μs|0.951726μs|2.799194μs|6.596768μs|14.947697μs|**33.711629μs**|**74.971752μs**|**138.485468μs**|**308.657814μs**|**629.482793μs**|**0.817458ms**|**9.687451ms**|100.566277ms|961.007785ms|9889.731343ms|

Now I am sure that:
* When the amount of data is less than 256, `insertion_sort` has a very good performance, even better than `std::sort`.
* When the amount of data is between 256 and 10000, the performance of `comb_sort` is slightly better than `quick_sort`.
* When the amount of data is between 256 and 100000, the performance of `std::sort` is the best.
* When the amount of data is greater than 100000, the performance of `std::sort` is not as good as `quick_sort`.

How can I beat `std::sort`? So I referred to the practice of introsort, but did not control the split depth. I call it [Impro sort](https://github.com/Alinshans/LCPP/blob/master/Algorithm/Sort/impro_sort.cc), and now use it to compare with `quick_sort` and `std::sort`.<br>

| Sorting algorithm | 16 | 32 | 64 | 128 | 256 | 512 | 1024 | 2048 | 4096 | 8192 | 10000 | 100000 | 1000000 | 10000000 | 100000000 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Quick sort|1.166331μs|2.286009μs|4.870598μs|10.459656μs|22.356231μs|47.968858μs|102.991685μs|180.827946μs|386.783325μs|804.982939μs|0.942489ms|10.484755ms|91.543914ms|865.948456ms|8535.924019ms|
|Impro sort|**0.466531μs**|**0.886410μs**|**2.108721μs**|**6.326164μs**|**12.363079μs**|**27.637313μs**|**59.771987μs**|**125.935454μs**|**278.136618μs**|**479.678131μs**|**0.617594ms**|**7.230302ms**|**84.720028ms**|**724.386383ms**|**7360.014444ms**|
|std::sort|0.485194μs|0.951726μs|2.799194μs|6.596768μs|14.947697μs|33.711629μs|74.971752μs|138.485468μs|308.657814μs|629.482793μs|0.817458ms|9.687451ms|100.566277ms|961.007785ms|9889.731343ms|

From the latest test can be seen, no matter in which respect, `Impro sort` havs improved than `Quick sort`, that's why I call it `Impro sort`, which means "Improved sort". And in my test, `Impro sort` achieved a comprehensive victory, even faster than `std::sort`. Oh yeah! Although the results may not be so accurate, this shows that there is space for improvement in sorting algorithm, and we can do better through our efforts.
