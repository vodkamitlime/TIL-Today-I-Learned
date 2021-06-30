# Time Complexity

## Time Complexity (시간복잡도) 란?
- 알고리즘의 로직을 코드로 구현할 때, 입력값에 따라 출력값을 내는데 걸리는 시간의 비율을 의미한다. 
- 시간 복잡도는 보통 Big-O Notation (Big-O 표기법) 을 활용하여 나타낸다. 
	- Big-O Notation 이외에도 Big-Omega(big-Ω),Big-Theta(big-Θ) Notation 등이 존재한다.
	- Big-Omega는 알고리즘 효율을 하한선을 기준으로 하고, Big-Theta는 상한선과 하한선의 사이를 기준으로 판단한다.
	- 이에 비해 Big-O 는 알고리즘 효율을 상한선 기준으로 표기하기 때문에 자주 사용된다. 즉, 알고리즘을 실행하는데 걸리는 시간의 최대값을 표기한다. 
> 시간 복잡도와 아울러 공간 복잡도 (Space Complexity) 가 자주 논의되곤 하는데, 이는 기억 영역과 파일 공간이 얼마나 필요한가를 평가한 것이다. 

## Big-O Notation 이란?
- 데이터의 개수에 따라 수행시간이 증가하는 비율을 표현하는 기법이다. (이러한 특징을 점근적 분석이라 한다.)
- 실행 시간을 직접 측정하여 표기한다기보다, 입력 데이터에 따른 연산의 실행 횟수를 표현한 것이라고 볼 수 있다. 
> TMI..) Big-O Notation 은 사실 프로그래밍 이외의 수학 영역에서도 오래 사용되어 왔다! 

## Big-O Notation 의 특징
1. 상수항은 무시한다.
	- 상수란 변하지 않는 일정한 값을 갖는 숫자를 의미한다. 가령, `2N` 에서 2는 고정된 값이므로 상수이며 N은 변하는 값이므로 변수이다. 
	- Big-O 를 엄밀히 따지면 상수가 붙는 경우가 많으나, 시간복잡도 자체는 입력값인 N에 따라 변하기 때문에 생략한다. 
	- Ex: `O(2N)` -> `N`
2. 영향령이 없는 항은 무시한다. 
	- 위와 같은 이유로 가장 영향력이 큰 항 이외의 부수적인 항들은 생략한다.
	- Ex: `O(N^2 + N + 1)` -> `O(N^2)`

## 주요 성능
![Big-O Functions](https://t1.daumcdn.net/cfile/tistory/99EF1E395C7EB4B601)
- 시간 복잡도의 속도를 한 번에 비교하면 다음과 같다. 
- `O(1) < O(log N) < O(N) < (O N log N) < O(N^2) < O(2^N)`
- 속도가 빠를수록 효율성이 높아지며, 성능이 좋아진다. 따라서 위의 성능 비교에서 O(1) 이 가장 효율성이 높으며, O(2^N) 이 가장 낮다.

![Big-O Table](./img-big-o.png)

### 1. O(1) Constant
- Case: 스택의 Push, pop 메서드
- 입력값 (N) 이 증가해도 실행시간은 언제나 동일하다. 즉, N에 관계없이 상수 시간이 소요된다. 
```js
Constant(num) {
	return num/2;
}
```

### 2. O(log N) logarithmic
- Case: 이진트리
- 연산이 한 번 실행될 때마다 데이터의 크기가 절반 감소한다. (이 때 log 의 지수는 2 이다.)
```js
logarithmic(arr, target) {
	let left = 0;
	let right = arr.length-1;
	while(left <= right){
		let middle = (left+right)/2;
		if(arr[middle] === target) return true;
		else if(arr[middle] > target) left = middle+1;
		else right = middle-1;
	}
	return false;
}
```

### 3. O(N) linear
- Case: For 반복문
- 입력값 (N) 이 증가함에 따라 실행시간 역시 선형적으로(linearly) 증가한다.
```js
Linear(arr, target) {

	for (let i=0; i<arr.length; i++){
		if(arr[i] === target) return true;
	}
}
```
- 위의 경우, target 이 반복문 초반에 발견된다면 함수가 일찍 종료되어 시간 복잡도가 O(N) 에 못 미치겠지만, 최악의 경우 target 이 arr 의 끝에 위치하여 결국 입력 값만큼 연산이 실행된다. 따라서 해당 알고리즘은 O(N)의 시간복잡도를 가진다고 볼 수 있다. 

### 4. O(N log N) linearithmic
- Case: 퀵/병합/힙 정렬
- Code Example: [Merge Sort in JavaScript. Time Complexity O(nlogn)](https://medium.com/@seunghunsunmoonlee/merge-sort-in-javascript-time-complexity-o-nlogn-ca311b94e722)

### 5. O(N^2) Quadratic
- Case: 이중 For 반복문, 삽입/거품/선택 정렬
```js
Quadratic(num){
	for(let i=1; i<num; i++){
		for(let j=1; j<num; j++){
			console.log(i*j)
		}
	}
}
``` 
- 위의 경우, N이 입력될 경우 첫 번째 for 문 (N) * 두 번째 for 문 (N) 만큼 연산이 이루어진다.

### 6. O(2^N) Exponential
- Case: Fibonacci 수열
```js
Exponential(num) {
  if (num <= 1) return 1;
  return fibonacci(num - 1) + fibonacci(num - 2);
}
```

### 배운 점:
- 알고리즘을 구현할 때 몇 가지 질문을 늘 고려하며 설계하면 좋다.
	1. 해당 알고리즘의 시간복잡도는 무엇인가?
	2. 해당 알고리즘의 런타임(실행 시간)은 어떻게 증가하는가?
- 시간복잡도를 파악하기 위해서는 함수 내부에서 입력값에 어떻게 접근하는지, 그리고 입력값이 증가하면 함수 작동이 어떻게 바뀌는지 파악해야 한다. 
- 해당 함수가 실행되었을 떄, "최악의 경우" 어떤 일이 일어나는지 생각해보면 쉽다. 

### 참고 자료
- [빅오 표기법 (big-O notation) 이란](https://noahlogs.tistory.com/27)
- [빅 오 표기법(Big O notation)](https://johngrib.github.io/wiki/big-O-notation/)
