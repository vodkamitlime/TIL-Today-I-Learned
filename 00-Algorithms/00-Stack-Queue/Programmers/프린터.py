from collections import deque

def solution(priorities, location):
    priorities = [ [p, i] for (i, p) in enumerate(priorities)]
    queue = deque(priorities)
    
    while True:
        queue.rotate(-queue.index(max(queue, key=lambda x:x[0])))
        if queue[0][1] == location:
            queue.popleft()
            break
        else:
            queue.popleft()
            
    return len(priorities) - len(queue)