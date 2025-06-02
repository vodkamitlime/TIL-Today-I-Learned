# File System

## Disk System
- File is saved in disk
- Disk pack
    - Saves data permanently
    - Consists of Sector, Track, Cylinder, Platter, Surface
- Disk drive
    - Device that is composed to read data from disk pack
    - Consists of Head, Arm, Positioner, Spindle
- Disk Address
    - Physical disk address (decides sector, physical data transmission unit)
    - Logical disk address (relative address, divides disk system data into blocks and applies numbers on them)
    - How to translate logical -> physical address? 
        - Drivers
- OS -- (Block #) --> Drivers -- (Physical Address) --> Disk Controller
- Data Access in Disk System
    - Seek Time (time to move disk head to cylinder)
    - Rotational delay (time it takes for sector to move to head)
    - Data transmission time (time it takes to read sector)

## File System
- part of OS that manages files used by users
- Structure
    - Files
    - Directory Structure
    - Partitions
- File Concept
    - Sum of related information that is saved on disk
    - Minimum unit of disk allocation
    - Sequence of bytes
- Classification
    - Of content: Program file / Data file
    - Of structure: Text file / Binary file
- File attributes
    - Name
    - Identifier
    - Type
    - Location
    - Size
    - Protection
    - User identification (owner)
    - Time, date
- File operations (provided by OS through system call)
    - Create
    - Write
    - Read
    - Reposition
    - Delete
- File access methods
    - Sequential access: accesses file by record (or bytes) sequentially
    - Directed access: accesses wanted block directly
    - Indexed access: references index and accesses data after finding wanted block
- File system organization
    - Partitions (minidisks, volumes)
        - virtual disk
    - Directory 
        - concept to classify and store files
- Mounting
    - attaching current FS to another FS
    - mount point

## Directory Structure
- Flat directory structure
    - just one directory exists in FS
    - Single-leve directory structure
    - Issues
        - File naming
        - File protection
        - File management
        - More problematic in multi user environment
- 2-Level directory structure
    - One directory per user
    - Structure
        - MFD (Master FD)
        - UFD (User FD)
    - Problems
        - Cannot create sub-directory
        - Impossible to share files with other users
- Hierarchical directory structure
    - able to use tree structure directory
    - User can create/manage sub directory
        - system call must be provided
- Acyclic graph directory structure
    - extension of hds
    - can place shared directory, shared file in directory
    - uses links
- General graph directory structure
    - allows cycles
    - Problems
        - infinite loop

## File Protection
- Prevents improper access to file
- File protection mechanisms
    - May vary per system size or application area
    1. Password mechanism
        - sets PW for all files
        - implausible
    2. Access matrix
        - Describes access rights among domain (user group, process) and object (file, device)
        - Implementation
            - Global table: maintains rights of all files in system in table
            - Access list: saves access rights per file
                - Alist(Fk) = { <D1, R1> , <D2, R2> ... <Dm, Rm>}
                - When file is created, each domain is given rights
                - When file is accessed, checks for rights
            - Capability list: saves access right per domain
                - Clist(D1) = { <F1, R1> , <F2, R2> ... <Fp, Rp>}
                - If capability exists, access rights exists
                - System has to save capability list in Kernel
            - Lock-key mechanism
                - Access list + Capability list
                - Object has lock, Domain has key (unique bit patterns)
                - When process of Domain accesses object, the key-lock pair must match
                - System has to manage key list

## File Sytstem Implementation
### Allocation Methods
- Continuous Allocation
    - Save file in continuous blocks of disk
    - Pros: Efficient file access 
    - Cons: Difficult to get space for new file / External fragmentation / difficult to decide file space size 
- Discontinuous Allocation
- Linked Allocation
    - Save blocks that saves files in linked list
    - Directory has pointer of first block of file
    - Pros: Simple / no external fragmentation
    - Cons: Diificult for direct access / Need space to save pointer / Integrity issues
    - Usage examples: FAT (File Allocation Table) - keeps next block number in each block's starting point
- Indexed Allocation
    - Keeps block information (pointer) of file in Index block
    - Efficient for direct access
    - Cons: Space overhead - Index block kept for each file / File size limited due to index block size

### Free Space Management
- Bit Vector
    - checks all block's usage in 1 bit flag
- Linked List
    - connects empty blocks in linked list
- Grouping
    - groups n empty blocks and connects them through linked list 
    - can easily find sequential empty blocks
- Counting 
    - keeps table of sequential empty blocks' first block address and their count