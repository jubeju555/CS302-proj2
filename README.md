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


Time complexity table:

| **MODE**  | **SIZE** | **TIME** |
| --------- | -------- | -------- |
| **MERGE** | 100000   | 0.058    |
| **MERGE** | 500000   | 0.380    |
| **MERGE** | 1000000  | 0.841    |
| **MERGE** | 10000000 | 10.612   |
| **MERGE** | 25000000 | 29.083   |
| **QUICK** | 100000   | 0.071    |
| **QUICK** | 500000   | 0.560    |
| **QUICK** | 1000000  | 1.367    |
| **QUICK** | 10000000 | 19.013   |
| **QUICK** | 25000000 | 55.059   |
| **STL**   | 100000   | 0.079    |
| **STL**   | 500000   | 0.485    |
| **STL**   | 1000000  | 1.089    |
| **STL**   | 10000000 | 13.206   |
| **STL**   | 25000000 | 35.334   |
| **QSORT** | 100000   | 0.069    |
| **QSORT** | 500000   | 0.418    |
| **QSORT** | 1000000  | 0.912    |
| **QSORT** | 10000000 | 10.622   |
| **QSORT** | 25000000 | 27.734   |
>>>>>>> 3e7afcf (finished README.md)
