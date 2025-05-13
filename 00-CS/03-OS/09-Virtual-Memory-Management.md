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