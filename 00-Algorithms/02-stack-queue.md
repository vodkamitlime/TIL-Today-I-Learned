# Stack 과 Queue 란? 

- 스택과 큐는 자주 활용되는 자료구조이다.
- 많은 양의 데이터 중 원하는 데이터를 찾는 과정에 활용된다. 

## 스택 (Stack)

- 먼저 들어온 데이터가 나중에 나가는 형식의 자료구조 (입출구 하나)
	> 후입선출 (LIFO; Last in First Out)
- 삽입과 삭제가 일어나는 위치: Top
- 비어있는 스택에서 원소를 추출하려고 할 때:  stack underflow, 스택이 넘치는 경우: stack overflow
- 예시 1: 모바일 앱 화면
    - 사용자가 현재 보고 있는 화면: Top
    - 다음 화면 클릭: 새 화면 추가하고 이동
    - 이전 화면으로 가기: 현재 화면 지우고 바로 이전 화면으로 이동
- 예시 2: Ctrl + z 기능 실행
    - 가장 마지막에 수행한 작업부터 차례로 취소

## 큐 (Queue)

- 먼저 들어온 데이터가 먼저 나가는 형식의 자료구조 (입출구 병렬하여 두개)
	> 선입선출 (FIFO; First in First Out)
- 데이터 입력은 enQueue (위치 : 꼬리/Rear), 출력은 deQueue 라고 함 (위치 : 머리/Front)
- 예시 1: 게임 매칭 시스템
    - deQueue 로 유저들 입장
    - 정해진 인원만큼 순서대로 끊어서 매칭
    - enQueue 로 퇴장

![Stack, Queue Image](https://miro.medium.com/max/612/1*GNA2E1NFiJMc6cTHHPa6kw.png)

### 참고자료:
- [[이것이 코딩 테스트다 with Python] 16강 스택과 큐 자료구조](https://youtu.be/7iLoLcna7Hw)
- [[자료구조] 스택(Stack)과 큐(Queue) 이해하기](https://brightwon.tistory.com/8)