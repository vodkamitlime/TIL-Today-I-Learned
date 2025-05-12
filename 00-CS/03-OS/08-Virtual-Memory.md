## Virtual Memory

### Non-continuous allocation
- Divides user program to many blocks
- Only loads necessary blocks on memory during runtime (leftover blocks exist in swap device)

### Address Mapping
- Mapping virtual (relative) address to real(physical) address
- Virtual address
    - Logical address
    - Address assuming that memory is continuous
- Real address
    - Absolute, physical address
    - real address of loaded memory

### Mapping techniques
- Block Mapping
    - User program is divided & managed in blocks
    - Information of each block's address mapping is maintained
    - Virtual address : v = (b, d)
        - b = block number
        - d = displacement (offset) in a block
    - Use BMT (Block map table)
        - Manages Address mapping information
        - Each process in Kernel space has BMT
        - Block number + residence bit (1 if loaded, 0 if not) + real address
    - Sequence
        1. Access process BMT
        2. find entry of block from BMT
        3. Check Residence bit 
            - If 0, get block from swap device, and update BMT
            - If 1, check real address of block
        4. Calculate real address (r = a + d)
        5. Access memory

### Paging System
- Dividing program into blocks (pages) of equal size
- Page: divided blocks
- Page frame: Divided area of memory, same size as page
- Characteristics:
    - Not logical division, but of size (complicated page sharing and protection process>)
    - Simple and efficient (compared to segmentation)
    - No external fragmentation 
- Address Mapping
    - Virtual address: v = (p, d)
        - p : page number
        - d : displacement (offset)
    - Address mapping
        - PMT (Page Map Table)
    - Address mapping mechanism
        - Direct mapping
            - Similar to block mapping
            - PMT is saved in kernel
            - Has entry size, page size
        - Associative mapping
            - TLB (Translation Look-aside buffer)
            - Loads PMT on TLB, parallel search for address mapping
            - Low overhead, high speed
            - Expensive hardware (difficult to deal with large PMT)
        - Hybrid direct/associative mapping
            - Save PMT in memory (kernel space)
            - Use small size TLB -> save partial entries of PMT (recently used pages)
            - Locality 
- Memory Management
    - Memory is divided into same sizes as page (== Page frame)
    - Frame table
        - Each page frame has one entry
        - Composes of:
            - Allocated/available field - if the frame is usable
            - PID field
            - Link field (for free list) - information of available spaces
            - AV (free list header)
- Page sharing
    - Multiple process are able to share specific page
    - Pages that are possible for sharing
        - Procedure pages (Pure code, functions)
        - Data pages 
            - R/O data
            - R/W data (only possible under concurrency management)
- Page protection
    - When many processes are sharing a page, use protection bit

### Segmentation System
- Divides program/process into logical blocks (segments)
- Blocks may have different sizes
- Characteristics
    - Does not divide memory beforehand
    - Has advantages in Semgment sharing/protection 
    - High overhead in address mapping and memory management
    - No internal fragmentation
- Address mapping
    - Virtual address: v = (s, d)
        - s: segment number
        - d: displacement (offset)
    - SMT, Segment Map Table
    - Mapping mechanism similar to Paging
    - Procedure
        1. Oricess accesses address b which saves process' SMT
        2. Finds entry of semgent s from SMT
            - location of entry of s  b + s * entrySize
        3. For the entry found:
            - If residence bit is 0, missing segment fault, gets segemnt from swap device and loads on memory, refreshes SMT
            - if d > segment length, calls segment overflow exception module
            - If unallowed operation (protection bit field test), calls segment protection exception module
        4. calculates real address (r = a + d)
        5. accesses memory with r
- Memory Management
    - Similar to VPM, When loading semne,t divides it into specific size and then loads

### Hybrid paging/segmentation system
- Program division
    1. Divides it into logical units, segments
    2. Then again divides each segment into fixed sizes of pages
    3. Loads pages onto memory
- Address mapping
    - Virtual address: v = (s, p, d)
        - s: segment number
        - p: page number 
        - d: displacement (offset)
    - Uses both SMT, PMT
        - Each process has SMT
        - Each segment has PMT

        