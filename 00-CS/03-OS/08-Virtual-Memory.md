## Virtual Memory

### Non-continuous allocation
- Divides user program to many blocks
- Only loads necessary blocks on runtime (leftover blocks exist in swap device)

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
- Dividing program into blocks of equal size
- Page: divided blocks
- Page frame: Divided area of memory, same size as page
- Characteristics:
    - Not logical division, but of size 
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
        - Associative mapping
        - Hybrid