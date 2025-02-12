# CS302-proj2
CS302 project 2
What do these results reveal about the relationship between theoretical complexity discussed in class and actual performance?
judah: as for me theoretically quicksort there is a n log n time complexity, but practically, it could go up to n^2 because there is a chance the list is inversely ordered. 
Keaton:

In your opinion, which sorting mode is the best? Justify your conclusion by examining the trade-offs for the chosen mode.
Judah: personally because i understand quick the best i feel that it is the best. as for the merging i feel like combining at the end could have issues later on. but with a pivot and a partition its becomes easier to track where the nodes go. 
Keaton:
a brief summary of each individual group members contributions to the project.
Judah: i did both qsort and quick, as well as set up the scripts for the times with the set amounts of numbers and time them. 
Keaton: 


| **MODE**  | **SIZE** | **TIME** |
| --------- | -------- | -------- |
| **MERGE** | 100000   | 0.147    |
| **MERGE** | 500000   | 2.386    |
| **MERGE** | 1000000  | 6.036    |
| **MERGE** | 10000000 | 1:47.69  |
| **MERGE** | 25000000 | 2:32.79  |
| **QUICK** | 100000   | 0.208    |
| **QUICK** | 500000   | 2.425    |
| **QUICK** | 1000000  | 6.035    |
| **QUICK** | 10000000 | 1:46.50  |
| **QUICK** | 25000000 | 5:11.56  |
| **STL**   | 100000   | 0.195    |
| **STL**   | 500000   | 2.905    |
| **STL**   | 1000000  | 5.808    |
| **STL**   | 10000000 | 55.323   |
| **STL**   | 25000000 | 5:09.60  |
| **QSORT** | 100000   | 0.171    |
| **QSORT** | 500000   | 2.440    |
| **QSORT** | 1000000  | 5.307    |
| **QSORT** | 10000000 | 1:01.00  |
| **QSORT** | 25000000 | 2:43.36  |
