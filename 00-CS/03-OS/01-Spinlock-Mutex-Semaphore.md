## Spinlock, Mutex, Semaphore

### Background
- Race condition: A condition where the results of code can differ from its intentions due to multiple threads/processes accessing the same resource at the same time, mostly due to timing issues
- Synchronization: A mechansim to maintain coherence of the shared resource even when multiple threads/processes are running
- Critical Section: An area of code where only one proess/thread may access exclusively (mutual exclusion)

### How to guarantee mutex?
- lock/unlock the area that needs mutex
- Synchronization objects can be acquired or released
- Commonly discussed synchronization objects are mutex, semaphore, and spinlock

### Mutex vs Spinlock
- Both are objects that allows one process/thread to acquire a lock before entering a critical section, however they differ in ways that other proccesses/threads acquire the lock once it is released
- In mutex:
    1. P1 enters Critical Section
    2. P1 acquires lock
    3. P2 enters Critical Section
    4. P2 tries to acquire lock
    5. P2 goes to sleep (allowing other Processes to make use of the CPU resource)
    6. P1 releases lock
    7. P2 wakes up
    8. P2 acquires lock
- In spinlock:
    1. P1 enters Critical Section
    2. P1 acquires lock
    3. P2 enters Critical Section
    4. P2 tries to acquire lock
    5. P2 busy waits (polls for mutex acquirement, using up CPU resource)
    6. P1 releases lock
    7. P2 acquires lock

### Semaphore
- Semaphore is a signaling mechanism oriented around wait() and signal(), indicates whether a process is acquiring or releasing a resource
- Binary vs Counting Sempahore
    - Counting:  synchronization mechanisms with values varying in a range [0,n], where n is a non-negative integer value greater than one (1). 
    - Binary: synchronization mechanisms with integer values varying between zero (0) and one (1).