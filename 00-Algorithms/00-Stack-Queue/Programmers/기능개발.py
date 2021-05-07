from collections import deque 

def solution(progresses, speeds):

    progresses = deque(progresses)
    speeds = deque(speeds)
    answer = []

    while len(progresses) > 0:
        for i in range(len(progresses)):
            progresses[i] = progresses[i] + speeds[i]

        count = 0
        while True:
            if len(progresses) > 0:
                if progresses[0] >= 100:
                    progresses.popleft() 
                    speeds.popleft() 
                    count += 1
                else:
                    break
            else: break

        if (count>0):
            answer.append(count)


    return answer