# Compiler & Interpreter

## 컴파일러와 인터프리터
- 둘 다 고급 언어 (개발자가 작성한 source code)를 기계가 이해할 수 있는 언어(machine code)로 번역해주는 프로그램이다. 
> 고급 언어란? 사람이 이해할 수 있는 언어이다 (C, python 등 대부분의 프로그래밍 언어)

![저급 언어 고급 언어](https://media.vlpt.us/images/andthensome/post/269d158d-94e5-4764-a705-40e95340a2dd/image.png)


## 컴파일러 vs 인터프리터
- 컴파일러:
	* 프로그램 전체를 스캔한 뒤 한꺼번에 기계어로 번역한다.
	* 스캔이 완료될 때까지 에러 메세지를 표시하지 않기 때문에 디버깅이 어렵다. 
	* 컴파일이 완료된 이후의 프로그램 실행 속도가 빠르다는 장점이 있다.
	* 중간 언어(Intermidiate code)를 생성하기 때문에 더 많은 메모리가 필요하다.
		> 중간 언어란? 컴파일러가 원시 언어로 된 프로그램을 목적 코드로 번역하는 과정에서 생성되는 내부적 코드이다.
	* 대표적인 컴파일드 언어: C, C++ 
- 인터프리터:
	* 프로그램을 한 줄씩 기계어로 번역하며 실행한다.
	* 프로그램 실행 속도가 느리지만, 에러를 발견하는 순간 실행을 멈추기 때문에 디버깅이 쉽다. 
	* 중간 언어를 생성하지 않으며, 따라서 메모리를 덜 차지한다.
	* 대표적인 인터프리티드 언어: Javascript, Python, PHP


### 배운 점 :
- C 와 C++ 이 빠르다는 이야기는 들었지만 그 이유를 자세히 몰랐는데, 컴파일 언어와 인터프리터 언어의 차이에서 비롯된 것임을 알게 되었다. 
- 인터프리터 언어만 접해봐서 컴파일 언어에 대한 감이 잘 오지 않는데, 앞으로 한 번쯤 컴파일 언어를 공부해볼 기회를 만들어봐야겠다. 


### 참고자료
- [Difference between Compiler and Interpreter](https://www.businessinsider.in/difference-between-compiler-and-interpreter/articleshow/69523408.cms)
- [노마드코더](https://www.youtube.com/watch?v=9sSxdhYGYSM&ab_channel=%EB%85%B8%EB%A7%88%EB%93%9C%EC%BD%94%EB%8D%94NomadCoders)





