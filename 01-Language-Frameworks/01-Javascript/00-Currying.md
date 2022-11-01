## Javascript 함수 : Currying (커링)


### Curry 함수란?
- 함수를 반환(return)하는 고차함수의 일종이다.
- 이때, 반환되는 함수를 클로저(Closure)라고 칭하기도 한다.
```javascript
function curry(func) {  // curry() 는 커리함수이다
  return (function closure(something){  // callback() 는 클로저이다
  	return (console.log(something))
  })
 }
````


### Currying(커링)이란? 
- 여러 개의 매개변수를 단일 호출에 처리하는 함수를, 각각의 매개변수가 개별로 호출될 수 있도록 변환하는 작업을 커링(Currying)이라고 한다. 
```javascript
function sum(a, b) {  // 일반 함수 sum() 을 커링하여 변환해보도록 한다.
	return a + b;
}

function curry(func) {  // func 안에는 커링을 할 함수가 들어오게 된다.
	return function(a) {
		return function(b){
			return func(a, b);
		}
	}
}

let curriedSum = curry(sum); 
// curriedSum 의 환경 안에는 sum 이 저장되었다.
// curriedSum에는 curry(sum)의 호출값인 function(a)가 저장되어 있다.

let firstNum = curriedSum(1);
// a 라는 매개변수 안에 1이 인자로 들어가게 되었다.
// firstNum의 환경 안에는 sum 과 1 이 저장되었다.
// firstNum에는 function(a) 의 호출값인 function(b)가 저장되어 있다.

let secondNum = firstNum(2);
// b 라는 매개변수 안에 2가 인자로 들어가게 되었다.
// function(b) 의 호출값은 func(a, b) 였으므로, sum(1, 2)가 실행되어 반환된다.
// sum(1, 2) 의 결과값은 3이다.

console.log(secondNum) // 3

// 이 과정은 다음과도 같다.
console.log(curriedSum(1)(2) // 3
````
- 위의 예제에서 curriedSum 또는 firstNum 처럼 최종값이 반환되기 이전, 인자가 고정된 환경에 접근할 수 있는 클로저를 "partial" 이라고 칭한다. 


### 커링의 장점
- 함수에 여러 개의 인자가 전달될 경우, 특정 값을 "고정"시킴으로써 함수의 변동성을 줄이고 안전성을 높일 수 있다. 
- 기 작성된 함수를 쉽게 재사용할 수 있다. 


### 배운 점: 
- 여러 개의 함수를 중첩해서 사용하면 구현하고자 하는 기능 또는 코드의 효율성을 높일 수 있을 것이다.
- 알고리즘을 풀 때 작성하는 함수와는 다소 다른 접근이 필요하며, 전달될 것으로 예상되는 인자의 변동성을 특히나 더 고려해야 할 것이다. 



### 참고자료
[코어 자바스크립트 - 커링](https://ko.javascript.info/currying-partials)