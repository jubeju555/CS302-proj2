# CS302-proj2
CS302 project 2

Group:  Keaton Wyrick and Judah Benjamin
Github:   Keatonium         jubeju555


Discuss the relative preformance of each sorting method and try to explain the differences.

    Based on our markdown table, the preformance of QSort was the best in terms of time coplexity. 
    This was followed by merge sort, stl sort, and quicksort in that order. It makes sense that quicksort 
    is last because it's worst-case time complexity is 0(n^2). All of the other sorting methods have a worst
    case time complexity of O(n*logn). Merge sort splits apart the list and merges it back together to divide 
    sorting recursively. This method makes the sorting time complexity very consistent when compared to quick.
    

What do these results reveal about the relationship between theoretical complexity discussed in class and actual performance?

    Judah: as for me theoretically quicksort there is a n log n time complexity, but practically, it could go up 
    to n^2 because there is a chance the list is inversely ordered. 
    Keaton: for merge and stl sorts there is a O(n*logn) time complexity the worst case. These two methods are 
    more stable than quick because they consistently output at O(n*logn).

In your opinion, which sorting mode is the best? Justify your conclusion by examining the trade-offs for the chosen mode.

    Judah: personally because i understand quick the best i feel that it is the best. as for the merging i feel like 
    combining at the end could have issues later on. but with a pivot and a partition its becomes easier to track where the nodes go. 
    Keaton: Personally, I feel like merge sort is the best. While Qsort did preform better than it, I liked the implementation of
    merge more and writing it was really fun. I also don't really understand what goes on under the hood for the qsort algorithm even 
    after researching it so it's hard to make a case for or against it.

A brief summary of each individual group members contributions to the project.

    Judah: i did both qsort and quick, as well as set up the scripts for the times with the set amounts of numbers and time them. 
    Keaton: I did both stl sort and merge sort. I timed all of the sorting algorithms and put them into the markdown table.


Time complexity and Memory table:

| **MODE**  | **SIZE** | **TIME** | Memory (bytes) |
| --------- | -------- | -------- | -------------- |
| **MERGE** | 100000   | 0.058    | 4,881,920      |
| **MERGE** | 500000   | 0.380    | 24,081,920     |
| **MERGE** | 1000000  | 0.841    | 48,081,920     |
| **MERGE** | 10000000 | 10.612   | 480,081,920    |
| **MERGE** | 25000000 | 29.083   | 1,200,081,968  |
| **QUICK** | 100000   | 0.071    | 4,881,920      |
| **QUICK** | 500000   | 0.560    | 24,084,922     |
| **QUICK** | 1000000  | 1.367    | 48,084,992     |
| **QUICK** | 10000000 | 19.013   | 480,084,992    |
| **QUICK** | 25000000 | 55.059   | 1,200,085,040  |
| **STL**   | 100000   | 0.079    | 6,982,136      |
| **STL**   | 500000   | 0.485    | 32,473,592     |
| **STL**   | 1000000  | 1.089    | 64,862,200     |
| **STL**   | 10000000 | 13.206   | 748,520,440    |
| **STL**   | 25000000 | 35.334   | 1,871,301,120  |
| **QSORT** | 100000   | 0.069    | 7,782,136      |
| **QSORT** | 500000   | 0.418    | 36,473,592     |
| **QSORT** | 1000000  | 0.912    | 72,862,200     |
| **QSORT** | 10000000 | 10.622   | 828,520,440    |
| **QSORT** | 25000000 | 27.734   | 2,071,301,100  |
