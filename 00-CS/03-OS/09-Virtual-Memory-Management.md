## Virtual Memory Management

### Cost Model for Virtual Memory system
- Page fault frequency
- Page fault rate
    - F(w) = Num of page faults during w / |w|
- Page reference string (d)
    - Order of page number that was referenced during process

### Hardware Components
- Address translation device
    - For efficiency of address mapping systesm (TLB, cache memories, etc)
- Bit Vectors
    - Bits used to save page usage situations
    - Reference bits (used bit)
        - Remembers if the page on memory was referenced recently 
        - All reference bits are initialized to 0 regularly
    - Update bits (modified bits, write bits, dirty bits)
        - Remembers if page was updated by process after it was loaded on memory
        - No regular initialization
        - Initalized when page is removed from memory 

### Software Components
- Allocation Strategies
    - How much memory will we allocate to each process?
        - Fixed allocation (memory is fixed during process execution)
        - Variable allocation (memory is dynamic during process execution)
    - Be cautious of too much allocation (memory waste) or too small allocation (page fault rate)
- Fetch Strategies
    - When will we load specific page on memory?
        - Demand fetch (demand paging)
            - Only loads pages referenced by process
            - Used by most systems
        - Anticipatory fetch (pre paging)
            - Loads pages that have possibility of being referenced in the near future
- Placement Strategies
    - Where will we load page/segment?
    - Unnecessary for paging system
    - Useful for Segmentation system 
- Replacement Strategies
    - Which page will we replace new page with? (When there is no empty frame)
- Cleaning Strategies
    - When will we write-back changed page? (when to apply updated contents to swap device)
    - Demand cleaning
        - When page is unloaded from memory
        - Most systems use this method
    - Anticipatory cleaning
        - When there is no more possibility of being changed
- Load Control Strategies
    - Controls system's multi-programming degree

### Replacement Strategies for Fixed ALlocation
- Fixed allocation
    - Giving process a fixed number of page frame

#### Algorithms
- MIN Algorithm (OPT Algorithm)
    - Minimizing page fault frequency 
    - Tactics
        - Replaces page that will not be referenced for the longest time in the near future
        - Tie-breaking rule: replaces page with biggest/smallest number
    - however, it is unrealizable, must know all page reference string beforehand
- Random Algorithm
    - selects page to replace randomly
- FIFO Algorithm
    - Replaces oldest page
    - Must have information of page loaded time 
    - There is high possibility that most frequently used page is replaced, no consideration of locality
    - FIFO Anomaly 
        - Page fault may increase even though more page frame have been allocated 
- LRU Algorithm (Least Recently Used)
    - Replaces page that hasn't been referenced longest
    - Have to keep record of page referenced time
    - Considers locality 
    - Mostly used 
    - Cons
        - Overhead (of recording)
        - Page fault increases rapidly if smaller number of page frame is allocated compared to necessary amount of loop executions
- LFU Algorithm (Least Frequently Used)
    - Replaces page that is least referenced
    - Have to cumulate reference count 
    - Uses locality 
- NUR Algorithm (Not Used Recently)
    - LRU approximation scheme
    - Lower overhead compared to LRU
    - Bit vector usage

### Replacement Strategies for Variable Allocation
- Variable Allocation
    - Size of memory given to process is dynamic

#### Algorithms
- Working Set ALgorithm
    - Working Set: group of pages that are frequently referenced at certain point of process == referenced pages for some recent time
    - W(t, delta)
        - t: working set of a process at time t
        - delta: window size, system parameter
    - Memory Management
        - Keeps working set in memory 
            - Lower page fault rate
            - Higher system quality 
        - Window size is fixed, important feature for deciding performance
- Page Fault Frequency Algorithm
    - decides residence set size depending on page fault rate
        - Low page fault rate -> decreases PF number allocated to process
        - High page fault rate -> increases PF number allocated to process
- Variable MIN algorithm
    - Optimal of average memory allocation and page fault rate 
    - However, it is unrealizable 