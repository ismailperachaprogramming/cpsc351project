# cpsc351project

**Collaborators:**
Ismail Peracha, Matthew Villanueva, Samir Shivji

**Email Addresses:**
ismailperacha@csu.fullerton.edu

**Contributions:**
Ismail:

Matthew:

Samir:

**Each team member is familiar with all functionality in this project.**

**We used C++ throughout this project**

**How to Execute Files**

Shell.cpp is a standalone file that runs on its own. When you run it, you as a user can input ps or ls or any other command, and the output will be given by fork(), wait(), and excelp().

Serial_Fetcher.cpp, as well as Parallel_fetcher.cpp need to be ran with the locations.txt file, in order for it to work.


**Execution Times**
Parallel Fetcher:
Serial Fetcher:

**Answers to Performance Comparison Questions**
1. In the output of time, the difference between real, user, and sys times is that real is actual elapsed time, user time is the amount of CPU time spent in user-mode code within the process, while sys time is the amount of CPU time spent in the kernel within the process.

2. User time is greater than sys time because in a GC event, most of the time is spent within the virtual machine code and only very less time is spent in the kernel.

3. When fetching all of the locations in the file, the parallel fetcher is faster than the serial fetcher, as the serial fetcher would distribute the task across multiple CPUs, while the parallel fetcher can fork multiple at a time.

4. If one fetcher child crashes, it should not affect the other children in a well-designed concurrent system, because each child process runs in its own address space with isolated memory. Advantages of isolating each fetch task within a different process is fault tolerance, where one task’s failure does not compromise the others. Disadvantages of isolating each fetch task within a different process is how it would be costly in terms of system resources.


**Extra Credit was not implemented.**

