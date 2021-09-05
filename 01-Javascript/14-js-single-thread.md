# JS 는 싱글스레드인가? 멀티스레드인가? 

## Thread
- 프로세스 내에서 실행되는 여러 흐름의 단위이며, 프로세스가 할당받은 시스템 자원 (CPU 시간, 메모리 영역 등)을 이용하는 실행 단위이다. 
- Thread 는 프로세스 내에서 각각 Stack만 따로 할당받고 Code, Data, Heap 영역은 공유한다. 

### 프로세스의 메모리
- 프로세스의 메모리는 크게 Code, Data, BSS, Heap, Stack의 영역으로 나뉜다. 
	- Code: 가장 하단에 위치한 영역이며, 작성한 기계어 또는 코드가 들어간다. 함수, 제어문, 상수 등이 들어간다. Read-only 영역이며, 컴파일러가 만든 코드라고 봐도 무방하다.  
	- Data: 전역변수, 정적변수, 배열, 구조체 등이 저장되는 공간이다. 또한, 초기화 (initialized) 된 데이터가 저장되는 공간이다. 즉, 초기값이 있는 static 변수가 들어간다. 
	- BSS (Block-stated Symbol): 초기화되지 않은 (초기값이 없는) 데이터가 저장된다. 
		- Code, Data, BSS 모두 정적인 영역이며, compile time 에 킉가 결정되어 이후에 변동되지 않는다. 또한, 프로세스가 종료될 때까지 계속 작동한다.
	- Heap: 프로그래머가 동적으로 사용하는 영역으로, 동적 객체 데이터의 할당 또는 반환이 이루어지는 영역이다.
	- Stack: 함수가 포함되어 있고, 함수 내의 지역변수, 매개변수 등이 저장되어 있는, 프로그램이 자동으로 사용하는 임시 메모리이다. LIFO 정책을 사용하며, 함수 호출 시 생성되고 함수 종료시 반환된다. 
		- Heap 의 영역이 증가하여 Stack 영역을 침범하는 Heap Overflow 의 상황이 되거나, Stack 의 영역이 증가하여 Heap 의 영역을 침범하는 Stack Overflow 의 상황이 될 때 사용되는 메모리의 자유 영역 또한 존재한다. 
- 속도는 Stack > Data > Code > Heap 순이다. 
<br>
![memory](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F9926A8335A17BAB30ECD61)
<br>

- 앞서 언급했듯, Thread 는 프로세스 내에서 각각 Stack만 따로 할당받고 Code, Data, Heap 영역은 공유한다. 따라서 힙 메모리는 서로 읽고 쓸 수 있으며, 한 스레드가 자원을 변경하면 다른 이웃 스레드도 그 결과를 즉시 볼 수 있다. 

## 싱글, 멀티 스레드
- Single Thread:
	- 하나의 프로세스에서 하나의 스레드를 실행하므로, 프로세스 내의 작업을 순차적으로 실행한다.
- Multi Thread: 
<br>
![thread](https://media.vlpt.us/images/eunjin/post/c63d6950-7ae7-439a-9ee8-d6f145d6808a/Screen%20Shot%202021-01-17%20at%204.18.53%20PM.png)
<br>

### 참고자료:
- [메모리 영역(Code, Data, Heap, Stack)](https://box0830.tistory.com/150)
- [메모리 영역의 이해](https://donghwada.tistory.com/entry/%EB%A9%94%EB%AA%A8%EB%A6%AC-%EC%98%81%EC%97%AD-Code-Data-BSS-HEAP-Stack-Little-Endian-Stack%EC%9D%98-%EC%9D%B4%ED%95%B4)
- [시스템 해킹 강좌 5강 - 메모리 구조 이해하기 (System Hacking Tutorial 2017 #5)](https://youtu.be/TxWOaKE5w_s)