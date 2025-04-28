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


What is Paging in Operating Systems?

> Paging is a memory management technique where the operating system breaks up physical memory and logical memory into fixed-size blocks to manage them more efficiently.



Physical memory (RAM) is divided into frames (small, fixed-size blocks).

Logical memory (the memory as seen by a program) is divided into pages (blocks of the same size as frames).


When a program runs:

Its pages are loaded into any available frames in physical memory — they don't need to be contiguous.

This allows better use of RAM and avoids fragmentation problems.



---

Why use Paging?

Avoid external fragmentation: Because any page can go into any frame, you don’t need big contiguous free spaces.

Efficient memory use: You can fit many programs into RAM without worrying about how big they are.

Simpler allocation: The OS just needs to find any free frame.



---

Key Concepts


---

Simple Diagram

Logical memory (program)      Physical memory (RAM)
+---------+                   +---------+
| Page 0  | --> Frame 5        | Frame 0  |
| Page 1  | --> Frame 2        | Frame 1  |
| Page 2  | --> Frame 8        | Frame 2 <- Page 1
| Page 3  | --> Frame 1        | Frame 3  |
| ...     |                    | ...      |

Pages don't have to stay in order — they can be anywhere in RAM.

The Page Table keeps track of where each page is located.



---

Example

Imagine a program needs 20 KB of memory.

Suppose each page and frame is 4 KB.

The program will be split into 5 pages.

These 5 pages can be loaded into any 5 free frames in RAM.



---

Downsides of Paging

Overhead: Managing page tables requires extra memory and CPU work.

Internal fragmentation: The last page might not fully fill a frame, wasting some space.

Page faults: If many pages aren't in memory, the system slows down because it has to load them from disk often (this is called thrashing).



---

Quick Summary

> Paging splits memory into small blocks to use memory more efficiently and avoid fragmentation, but it adds some complexity in managing page tables.



