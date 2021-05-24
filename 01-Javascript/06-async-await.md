# Async 함수와 Await

## Async 함수란?
- Promise 를 조금 더 편리하게 사용할 수 있는 함수이다. 
- 함수 선언 앞에 `async` 키워드를 붙여서 사용할 수 있으며, 해당 함수는 항상 Promise 를 반환한다. 
	- return 값이 Promise 가 아니더라도 Resolved Promise 로 해당 값을 감싸서 반환한다. 
```js
async function Callback(){
	// some code here 
}
```

## Await 이란?
- Async 함수 내부에서만 호출 가능한 키워드이다. 
- Promise 가 처리될 때까지 함수 실행을 기다린 후에 결과를 반환하도록 한다.
- 프라미스가 처리되길 기다리는 동안에 엔진이 다른 일을 할 수 있도록 한다. 
```js
async function f() {

  let promise = new Promise((resolve, reject) => {
    setTimeout(() => resolve("완료!"), 1000)
  });

  let result = await promise; // 프라미스가 이행될 때까지 기다림

  alert(result); // "완료!"
}
```

### Test:
```js
f()
console.log('first')

// ------- console -------- //
// 'first'
// undefined
// alert '완료'
```

### 배운 점:
- Promise 의 본질은 자바스크립트 엔진이 다른 작업을 하는 동안 web api 영역에서 작업을 수행하고 queue 에 결과를 옮길 수 있도록 하는 것이다. 
- Async 와 Await 의 본질은 이러한 promise 의 처리 과정을 조금 더 직관적으로 이해할 수 있도록 돕는 것이다. 

### 참고 자료
- [async와 await](https://ko.javascript.info/async-await)