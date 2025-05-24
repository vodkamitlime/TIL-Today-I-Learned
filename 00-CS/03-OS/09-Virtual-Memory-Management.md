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