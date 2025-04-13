## Main Memory Management

### Background
- Types of memory 
    - (High speed, small capacity) Register -> Cache -> Main Memory -> Auxiliary Storage (Low speed, large capacity)
    - HW (CPU) managed: Register, Cache
    - SW (OS) managed: Main Memory, Storage
    - Composed in this structure to resolve I/O bottleneck
- Data transmission unit
    - Register <-**Word**-> Main Memory <-**Block**-> Auxiliary Storage
    - Block
        - data transmission unit between main memory and auxiliary storage
        - Size: 1 ~ 4 kB
        - (Even if you just want to read 1 bit from storage, 1 ~ 4 kB of data is loaded on memory)
    - Word
        - data transmission unit between main memory and register
        - Size: 16 ~ 64 bits
        - (Computer bits ex. 32bit/64bit --> size of Word)
- Address binding
    - Task in which logical address of program is mapped to physical address
    - Binding times
        - Compile time binding
            - When compiler knows where process will be loaded on memory
            - Location is not changed
            - Program must be fully loaded on memory
        - Load time binding
            - When compiler doesn't know where process will be loaded on memory, substitutable relative memory is created (ex. start address : u, variable addresses: u + 100, u + 200...)
            - At load time, start address is applied and user code addresses are all substituted 
            - Program must be fully loaded on memory
        - Run time binding
            - Address binding is delayed until runtime
            - Process can move to another memory address while running
            - Needs help of HW (MMU/Memory Management Unit)
            - Used by most OS
- Dynamic Loading
    - All routines (ex. functions) are saved on disk as substitutable structure
    - Routines are not loaded on memory until actual call
    - Address binding happens when routine is called
- Swapping
    - Swap-out: When processor allocation is over, and process which is finished executing is sent to swap-device (Memory -> Storage)
    - Swap-in: Starting process is loaded on memory (Storage -> Memory)

### Memory Allocation

#### Continuous Memory Allocation
- Policy in which one process (context) is allocated in one continuous memory space (Ex. Program, data, stack)
- Elements to consider
    - Process # that can be loaded on memory at the same time (multiprogramming degree)
    - Size of memory space each process is allocated
    - Memory partitioning method
- Uni-programming
    - Multiprogramming degree = 1
    - Only one program exists on memory
    - Problem #1
        - What if program size > memory size?
        - Use overlay structure
            - Divide program into smaller parts
            - User/programmer has to intervene
    - Problem #2
        - How to protect kernel?
        - Use boundary register
- Multi-programming
    - Multiprogramming degree = 

#### Continuous Memory Allocation