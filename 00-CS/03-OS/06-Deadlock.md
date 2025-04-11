## Deadlock

### Introduction
- Blocked/Asleep State
    - State in which a process is waiting for a specific event
    - State in which a process is waiting for a resource
- Deadlock State
    - Case where a process is waiting for an event that has no possibility of occuring: process is in deadlock state
    - If there is a process which is in deadlock state in system: system is in deadlock state

### Deadlock vs Starvation
- Deadlock
    - Blocked/Asleep state (waiting for impossible event)
- Starvation
    - Ready state (waiting for CPU)

### Resources
- Resource classification methods
    - Hardware vs software
    - Preemptible vs Non-preemptible
        - Preemptible: A resource that does not cause problems even after being preempted and resumed (ex. Processor, memory)
        - Non-preemptible: A resource that causes problems even after being preempted and resumed (ex. disk drive)
    - Total allocation vs partitioned allocation
        - Total allocation: Allocates entire resource (ex. Processor, disk drive)
        - Partitioned allocation: divides single resource into multiple pieces and allocates them to process (ex. Memory)
    - Exclusive allocation vs shared allocation
        - Exclusive allocation: One process can use resource at once (ex. Process, memory, disk drive)
        - Shared allocation: Multiple proccesses can use resource at once (ex. Program, shared data)
    - SR vs CR
        - SR (Serially-reusable): Resource that always exists in system, other process can use it after end of use (ex. Processor, memory, disk drive, program)
        - CR (Consumable): Resource that vanishes after process uses it (ex. signal, message)
- Types of resource that can invoke deadlock:
    - Non-preemptible resources
    - Exclusive allocation resources
    - Serially reusable resources