## Monitor
- Set of shared data and critical section
- Has conditional variable and special operations

### Structure
- Entry queue
    - Allows only one proces at a time to enter
    - Exists as much as number of procedure (function) in monitor
- Mutual exclusion
    - Only one process can enter monitor
- Information hiding
    - Only process inside monitor can access shared variable
- Condition queue
    - Queue in which processes are waiting for special event to happen in monitor
- Signaler queue
    - There is always one signaler queue in monitor
    - Queue where a process stays temporarily to call signal()

### Pros and Cons
- Pros
    - Easy to use
    - Low error rates (ex deadlock)
- Cons
    - Supported by language, so has language dependency
    - Compiler should have understanding of OS