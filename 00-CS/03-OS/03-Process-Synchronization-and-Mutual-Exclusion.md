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
            - Proposed by Dijkstra, solved the busy waiting problem
            - unsigned integer variable (S)
            - Can only access it by initialization, P(), V() operations
                - P: Probern (Try)
                - V: Verhogen (Increment)
            - Every semaphore variable is allocated a ready queue
            - Types
                - **Binary Semaphore**
                    - S has only 0 or 1 value
                    - Usually used for mutual exclusion or process synchronization
                - **Counting Semaphore**
                    - S can have an integer value of 0 or above
                    - Solves the producer-consumer problem
            - Operations
                - Initialization
                - P(), V()
                ```c
                P(S)
                if (S > 0)
                    then S <- S - 1;
                else wait on the queue Q;
                    
                V(S)
                if (waiting processes on Q)
                    then wakeup one of them;
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