## DFS, BFS
- DFS 와 BFS 는 각각 Depth-First Search 와 Breadth-First Search 로, 깊이우선탐색과 너비우선탐색을 뜻한다. 

## BFS
- 그래프 자료구조형에서 가장 가까운 노드부터 우선적으로 탐색하는 알고리즘이다.
- 큐를 이용하여 구현할 수 있다.
- 구현 과정:
    1. 큐에 탐색 시작 노드를 삽입한다.
    2. 큐의 front 를 방문할 때마다 방문 표시를 하고, popleft() 를 한다.
    3. 현재 방문하고 있는 노드에 방문하지 않은 인접 노드가 있다면 그 노드를 큐에 넣는다
    4. 현재 방문하고 있는 노드에 방문하지 않은 인접 노드가 없다면 큐의 front 을 꺼낸다
    5. 반복 실행하여 큐가 완전히 빌 때 종료한다

```PY
from collections import deque # Python 에서 popleft() 를 하기 위한 모듈

# 노드의 번호에 따라 연결된 정보를 2차원 배열 표현할 수 있다. 
# 가령, 1 - 3 - 2 - 4 형태로 연결된 그래프라면, [[], [3], [3, 4], [1, 2], [2]] 로 표현 가능하다.
graph = [[], [3], [3, 4], [1, 2], [2]]

# 방문 처리를 위한 1차원 배열
# 초기값을 False 로 설정해주어야 node 를 방문하면 True 로 전환하여 표시할 수 있다.
visited = [False] * (len(graph))

# 방문해야할 목록을 담은 queue을 만들어 while 문 실행
queue = deque([1]) # 첫 번째로 방문할 노드
while len(queue) > 0 :
	cur = queue.popleft()
    print(cur)
    for item in graph[cur]:
    	if visited[item] == False:
        	queue.append(item)
            visited[cur] = True

    	
```

## DFS
- 그래프 자료구조형에서 가장 깊은 부분을 (즉, 트리 구조에서 가장 하위에 있는 노드를) 먼저 방문하여 탐색하는 알고리즘이다.
- 스택 또는 재귀를 이용하여 구현할 수 있다.
- 구현 과정:
    1. 스택에 탐색 시작 노드를 삽입한다
    2. 스택의 top 을 방문할 때마다 pop 으로 삭제하고, 방문 표시를 한다
    3. 현재 방문하고 있는 노드에 방문하지 않은 인접 노드가 있다면 그 노드를 스택에 넣는다
    4. 현재 방문하고 있는 노드에 방문하지 않은 인접 노드가 없다면 스택의 top 을 꺼낸다
    5. 반복 실행하여 스택이 완전히 빌 때 종료한다

```py
# 노드의 번호에 따라 연결된 정보를 2차원 배열 표현할 수 있다. 
# 가령, 1 - 3 - 2 - 4 형태로 연결된 그래프라면, [[], [3], [3, 4], [1, 2], [2]] 로 표현 가능하다.
graph = [[], [3], [3, 4], [1, 2], [2]]

# 방문 처리를 위한 1차원 배열
# 초기값을 False 로 설정해주어야 node 를 방문하면 True 로 전환하여 표시할 수 있다.
visited = [False] * (len(graph))

# 방법 1
# 방문해야할 목록을 담은 stack을 만들어 while 문 실행
stack = [1] # 첫 번째로 방문할 노드
while len(stack) > 0 :
	cur = stack.pop()
    print(cur)
    visited[cur] = True
    for item in graph[cur]:
    	if visited[item] == False:
        	stack.append(item)

방법 2
# 재귀적으로 실행하여 방문 순서를 출력하는 함수
dfs(graph, node, visited):
	visited[node] = True
    print(node)
    for item in graph[node]:
    	if not visited[node]:
        	dfs(graph, item, visited)
    for i in graph[node]:
    	
```

## 배운 점:
- DFS, BFS 와 재귀는 알고리즘의 기초이기 때문에 잘 익혀두어야 어떠한 케이스를 만나든 잘 해결할 수 있게 된다.

### 참고 자료: 
- [(이코테 2021 강의 몰아보기) 3. DFS & BFS](https://youtu.be/7C9RgOcvkvo)