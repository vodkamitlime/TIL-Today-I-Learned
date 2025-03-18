## Process Synchronization and Mutual Exclusion

### Background
- Multi-programming system has many processes that work independently
- Synchronization: mechanism in which processes share information with each other
- Asynchronous: state where processes do not have information about each other
- Concurrence: state where many processes are existing in a system at the same time
- When concurrent asynchronous processes are accessing a shared resource, this could lead to a problem

### Mutual Exclusion
- primitives
    1. **EnterCS()** primitive: checks if there is another process in critical section before entering
    2. **ExitCS()** primitive: system alerts when exits critical section
- Requirements for ME primitives
    - **Mutual exclusion** : if a process exists in critical section, other processes should be refrained from entering
    - **Progress** : other processes besides the process that exists in the critical section should not interrupt them from entering the critical section
    - **Bounded waiting** : processes’ time allowed within critical section should be finite
- How to guarantee all three of the primitives?
    - SW Solutions
    1. Dekker’s Algorithm
    2. Peterson’s Algorithm
    3. Dijkstra’s Algorithm 
    - problems:
        - slow speed
        - complicated implementation
        - preemption during ME primitive
        - busy waiting
    - HW Solutions
        - TAS Solution (Test And Set)
    - OS Supported Solutions
        - Spinlock
            - integer type variable
            - Can only access it by initialization, P(), V() operations
            - P(), V() are atomic operations guaranteed by OS
            ```c
            int S; // <- spinlock variable
            
            // lock
            P(S) {
                while (S <= 0) do
                endwhile;
                S <- S - 1;
            }
            
            // unlock
            V(S) {
                S <- S + 1;
            }
            ```
            - Problems:
                1. Busy Waiting 
                2. Can only use in multi process environments
        - Semaphore