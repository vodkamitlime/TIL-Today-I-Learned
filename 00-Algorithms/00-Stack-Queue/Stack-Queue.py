# 파이썬에서 Stack 구현하기

stack = [0, 1, 2, 3]

stack.append(4) # 데이터 삽입
print(stack) # [0, 1, 2, 3, 4]

stack.pop() # 4, 데이터 삭제
print(stack) # [0, 1, 2, 3]

# top 순서대로 출력하고 싶을 경우:
# 방법 1)
print(stack[::-1]) # 3, 2, 1, 0
# 방법 2)
stack.reverse() 
print(stack) # [3, 2, 1, 0]


# 파이썬에서 Queue 구현하기
# Deque : Double-ended queue
# Collections 모듈에 있는 객체로 stack/queue 알고리즘에 자주 활용

from collections import deque

temp = [0, 1, 2, 3]
queue = deque(temp) 
print(queue) # deque([0, 1, 2, 3])

queue.append(4) # 데이터 삽입
print(queue) # deque([0, 1, 2, 3, 4])

queue.popleft() # 0, 데이터 삭제
print(queue) # deque([1, 2, 3, 4])

# 비어있는 queue 만들고 싶을 경우:
queue = deque()

queue = deque([0,1,2,3])


# 알아두면 좋을 추가 메서드들

# rotate()
queue.rotate(1) # [3, 0, 1, 2]
queue.rotate(2) # [2, 3, 0, 1]
queue.rotate(-1) # [1, 2, 3, 0]

# extend(), extendleft()
queue.extend('ab') # [0, 1, 2, 3, a, b]
queue.extendleft('ab') # [b, a, 0, 1, 2, 3]

# clear()
queue.clear() # []