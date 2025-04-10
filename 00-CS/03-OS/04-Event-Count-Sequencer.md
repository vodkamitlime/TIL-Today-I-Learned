## Eventcount/Sequencer
- Can solve starvation problem of semaphore
- No busy waiting
- Able to control order or events  

### Sequencer
- Integer type variable
- Initialized with 0, does not decrease
- Maintains order of events
- Only accesible by ticket
    - ticket(S): Indivisible operation, returns count of ticket() call

### Eventcount
- Integer type variable
- Initialized with 0, does not decrease
- Maintains order of events
- Only accesible by read(E), advance(E), await(E, v)
    - read(E): Returns current Eventcount
    - advance(E): 
        - E <- E + 1
        - wakes up process waiting for E
    - await(E, v)
        - v is integer type variable
        - if (E<v), pushes process to QE connected to E, and calls CPU scheduler

### How this solves mutual exclusion
```
Pi

repeat 
v <- ticket(S);
await(E, v);

Critical Secition

advance(E);

until false
```
- Breakdown
- First process
    - v <- ticket(S);
        - v = 0; 
        - S = 1;
        - E = 0;
    - await(E, v);
        - E == v, does not wait in queue
- Second process
    - v <- ticket(S);
        - v = 1; 
        - S = 2;
        - E = 0;
    - await(E, v);
        - E < v, enter and wait in queue until E becomes 1
- First process
    - advance(E);
        - E = 1
        - wakes up Process 2 in queue

### Producer-Consumer problem
```
shared variables:
Pticket : sequencer
Cticket : sequencer
In, out : eventcount
buffer  : array[0..N-1] of message

Producer Pi

var t: integer;
repeat
    Create a new message M;
    t <- ticket(Pticket);
    await(In, t);
    await(Out, t - N + 1);
    buffer[t mod N] <- M;
    advance(In);
until false

<< Buffer 0 ... N - 1>>

Consumer Cj

var t: integer;
repeat
    u <- ticket(Cticket);
    await(Out, u);
    await(In, u + 1);
    buffer[u mod N];
    advance(Out);
    Consume the message m;
until false

```