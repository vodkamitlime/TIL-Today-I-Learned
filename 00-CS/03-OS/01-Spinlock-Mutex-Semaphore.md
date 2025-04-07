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
- Allocates a ready queue to random variable S
- Binary vs Counting Sempahore
    - Counting:  synchronization mechanisms with values varying in a range [0,n], where n is a non-negative integer value greater than one (1). Used usually to solve Producer-Consumer problems.
    - Binary: synchronization mechanisms with integer values varying between zero (0) and one (1). Used usually to solve mutual exclusion or for process synchronization
- Initialization function
    - Allocates initial value to variable S
- P()
    ```c
    // P(S)
    if (S>0)
    then S <- S - 1;
    else wait on the queue Q;
    ```
- V()
    ```c
    // V(S)
    if (some waiting processes on Q)
    then wake up one of them;
    else S <- S + 1;
    ```
- How Semaphore solves Mutual exclusion
    - Variable S is set to 0 (process exits in critical section)
    - Pi enters P(S) → critical section
    - Pj enters P(S) → instead of busy waiting, it waits in ready queue
    - Pi exits critical section and enters V(S), wakes Pijin ready queue
    - Pj wakes up → enters critical section → V(S)
- How Semaphore solves process synchronization problem
    - Semaphores are useful for synchronizing processes’ running order
    - Variable S set to 0 (no available sync object)
    - Process Pj already has S
    - Pi enters P(S) → enters ready queue
    - Pj enters V(S) → S is set to 1  → wakes up Pi in ready queue
- How Semaphore solves Producer-Consumer problem
    - Producer process: process group that produces message
    - Consumer process: process group that receives message
        
        ```
        Producers | Shared Memory buffer | Consumers
        
        P1 -------->                  -----> C1
        
        P2 -------->                  -----> C2
        
        P3 -------->                  -----> C3
        
        Ex)
        
        Printer Driver --> Text           -----> Printer
        
        Compiler --------> Assembly code  -----> Assembler
        
        Assembler ------->  Module        -----> Loader
        ```
        
    - If two producer processes try to access shared memory buffer at once, there may be a problem, synchronization is necessary
    - Case: Single buffer
    
    ```
    (shared variables)
    consumed ---> semaphore
    produced ---> semaphore
    	buffer ---> messageQ;
    	
    Producer Pi ---> buffer ---> Consumer Cj
    
    // Producer
    
    create new message M
    P(consumed) --> waits in queue until buffer can be consumed
    buffer <- M
    V(produced) --> alerts consumer in queue
    
    // Consumer
    P(produced) --> waits in queue until there is production
    m <- buffer
    V(consumed)
    consume the message m;
    ```