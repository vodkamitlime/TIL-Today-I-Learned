## Deadlock

### Introduction
- Blocked/Asleep State
    - State in which a process is waiting for a specific event
    - State in which a process is waiting for a resource
- Deadlock State
    - Case where a process is waiting for an event that has no possibility of occuring: process is in deadlock state
    - If there is a process which is in deadlock state in system: system is in deadlock state
- Examples
```
Two processes: P1, P2
Two resources: R1, R2

In order of time
    P1 -> request R1
    P2 -> request R2
    P1 -> request R2
        (P1 waits for P2 to release R2)
    P2 -> request R1
        (P2 waits for P1 to release R1)

P1 waiting for P2, P2 waiting for P1 -> no possiblity of occuring 
```

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

### Deadlock requirements
- Exclusive use of resources
- Non-preemptible resources
- Hold & Wait (Partial allocation)
- Circular wait

### Deadlock prevention methods
- Get rid of all requirements?
    - Exclusive use of resources -> Allow all resources to be shared? -> NOT PLAUSIBLE
    - Non-preemptible resources -> Allow all resources to be premptible? -> NOT PLAUSIBLE
    - Hold & Wait (Partial allocation) -> Allow total allocation for all resources -> RESOURCE WASTE & INFINITE WAIT
    - Circular wait -> Allocate priority numbers to resources and make processes access resources in ascending order -> RESOURCE WASTE

### Deadlock avoidance methods
- Watch system state and suspend resource allocation if it seems to have possibility of deadlock
- Maintains system as safe state
    - Safe state
        - All processes can be normally terminated (At least one safe sequence exists)
        - It is guaranteed that system may not fall into deadlock 
    - Unsafe state
        - System has possibility of falling into deadlock state (does NOT mean it always will)
- Assumptions
    - Process numbers fixed
    - Resource numbers and types are fixed
    - We know the process requirements of resources and maximum quantity
    - Process always returns resource after use
- Not practical
    - High overhead
    - Low resource utilization

#### Dijkstra's banker's algorithm
- Assumption: multiple units of one resource type
- Always maintains system as safe state
- When a request for resource is made, system accepts/rejects the request according to a simulation processed in which a resource is assumed to be allocated to the process 

### Habermann's algorithm
- Dijkstra's algorithm extended, with multiple resources

### Deadlock detection and recovery methods
- Checks for deadlock regularly

#### Detection method
- Uses RAG (Resource Allocation Graph)
    - Directed, bipartite Graph
- Unblocked process: Process that can retrieve all resources it needs
- Detection method
    - Graph reduction: delete one edge at a time from RAG
    - Completely reduced
        - All edges are removed
        - There are no processes in deadlock
    - Irreducible
        - Edge that cannot be removed exists
        - One or more process in deadlock
- high overhead

#### Recovery method
- Process termination
    - Kills & restarts (some) process in deadlock
    - Selects process to kill depending on termination cost model
        - Lowest-termination cost process first
        - Minumum cost recovery
- Resource preemption
    - Selects resource to preempt to resolve deadlock
    - Kills process that has resource, that process is restarted