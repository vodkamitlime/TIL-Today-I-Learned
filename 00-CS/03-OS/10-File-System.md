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