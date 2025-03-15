## Process Scheduling

### Introduction
- Why do we need it?
    - Most systems exist as a multi-programming environment
    - Multiple processes access limited resource, and in this process the system has to choose which process to allocate its resource to
    - This process is also called **Scheduling**
- Resource Management
    - Time Sharing
        - Ex) Process scheduling, in which processes are allocated processor use time
    - Space Sharing
        - Ex) Memory scheduling
- Purpose of scheduling: System performance enhancement
    - Performance indices:
        - Response time
        - Throughput
        - Resource Utilization (Tr / Tc)
- Scheduling Criteria
    - Process Characteristic (I/O bound vs CPU bound)
        - CPU consists of CPU usage and I/O usage
        - CPU burst = CPU use time = If higher, process is CPU-bound
        - I/O burst = I/O wait time = If higher, process is IO-bound
    - System Characteristic (Batch system vs Interactive system)
    - Process Urgency (Real time vs Non-real time)
    - Process Priority
    - Process total service time
- Scheduling Level
    - Frequency of scheduling
    - Long-term (Job scheduling, creating process)
    - Mid-term (Memory scheduling, swap-in/out)
    - Short-term (Process scheduling, dispatching process)
- Scheduling Policy
    - Preemptive vs Non-preemptive
        - Preemptive: When allocated a resource, it can be interrupted before completion (due to end of allocation time, higher priority processes, etc)
            - (-) High context switching overhead
            - (+) Time sharing system, real time system
        - Non-preemptive: When allocated a resource, runs until it voluntarily releases CPU
            - (+) Low context switching overhead
            - (-) Priority Inversion
            - (-) Increase in average response time
    - Priority
        - Static priority vs Dynamic priority
        - Static priority: Priority of process determined at point of creation doesn’t change
        - Dynamic priority: Priority of process is changed constantly according to process state change

### Scheduling Algorithms
#### FCFS (First-Come-First-Serve)
- Policy: Non-preemptive
- Criteria: Arrival Time (Ready Queue)
- Allocates process which arrives at ready queue first
- (+) Low scheduling overhead, high resource utilization
- (+) Adequate for batch systems, (-) inadequate for interactive systems
- (-) Convoy effect
- (-) High average response time

#### RR (Round-Robin)
- Policy: preemptive
- Criteria: Arrival Time (Ready Queue)
- Allocates process which arrives at ready queue first, but each process has a time quantum (== time limit) Ex. if time quantum is set to 2 seconds, each process uses resource for 2 seconds, and turns it over to next process (Timer-runout)
- (+) Prevents resource monopoly
- (+) Adequate for messaging, time-sharing systems
- (-) High context switching overhead

#### SPN (Shortest-Process-Next)
- aka SJF (Shortest Job First)
- Policy: Non-preemptive
- Criteria: Burst Time
- Allocates process that has shortest burst time first
- (+) Low average wait time
- (+) Minimize process in system, low scheduling overhead, memory economy
- (+) High average response time for many processes
- (-) Starvation (Infinite wait), high BT processes won’t be allocated resource forever
- (-) Difficult to predict exact BT

#### SRTN (Shortest-Remaining-Time-Next)
- variation of SPN
- Policy: preemptive
- Criteria: Burst Time
- Allocates process that has shortest burst time when it is ready
- (+) All of SPN’s pros
- (-) Context switching overhaed
- (-) Difficult to predict exact BT, prediction algorithm overhead

#### HRRN (High-Response-Ration-Next)
- variation of SPN, but aging concepts enhanced
- Policy: Non-preemptive
- Criteria: Response ratio ((WT + BT) / BT)
- Aging concepts: Takes wait time into consideration in allocation
- Allocates process that has higher response ratio first
- (+) All of SPN’s pros + Starvation issue solved
- (-) Difficult to predict exact BT, prediction algorithm overhead

#### MLQ (Multi-Level-Queue)
- Have multiple ready queues, each queue has its own scheduling technique
- process is distributed to a queue, and it stays there
- Priority scheduling used among queues
- (+) Fast response time
- (-) Low priority queue may face starvation issue

#### MFQ (Multi-Level-Feedback-Queue)
- MLQ, but allows moving between queues
- Priority adjusted depending on feedback
- (-) Scheduling overhead
- (-) Low priority queue may face starvation issue