# Promise

## Promise 란?
- 향후 사용하게 될 비동기 연산의 결과값을 처리하도록 도와주는 JS 객체이다.
- 비동기 메서드에서 동기 메서드처럼 값을 반환할 수 있다. 
- 예제)
```js
const testing = new Promise((resolve, reject) => {
	if (something) resolve(something)
	else reject(error message)
})

testing
.then(() => return something2)
.catch(() => return error)
.finally(() => return final)
```

### Promise 의 3가지 상태:
- Fulfilled: 연산이 성공적으로 완료된 상태이다.
- Rejected: 연산이 실패한 상태이다. 
- Pending: Resolve 나 Reject 가 호출되기 전까지의 순간

### .then(), .catch(), .finally()
1. then(callback1, callback2)
- callback1: resolve 된 케이스를 다루는 함수 
- callback2: reject 된 케이스를 다루는 함수
```js
let a = 10
const prom = new Promise((resolve, reject) =>{
    if (a === 9) resolve(a)
    else reject(a)
})

prom
.then(
	()=>console.log('success'), 
	() => console.log('rejected...')
)

// 'rejected...'

```
- callback 1, 2 는 모두 이전 promise 에서 resolve 로 반환된 값을 전달인자로 받는다.
- Promise link 는 .then() 이 promise 객체를 반환하지 않더라도 계속 이어지므로, 일일이 reject 에 대응하는 함수를 만들어주지 않아도 된다. 에러를 바로 처리해주어야 하는 경우가 아니라면, 마지막에 catch 로 한번에 처리 가능하다. 
2. catch()
- 이전 Promise 에서 reject 된 값을 전달인자로 받아 처리하는 메서드이다.
```js
//위의 예시 차용
prom
.then(
	()=>console.log('success'), 
)
.catch(
	(err) => console.log(err)
	) // 10
```
3. finally()
- Promise 가 settled 된 순간 반환하게 되는 모든 값을 처리하는 메서드이다. 
- 전달인자를 받지 않는다. 
```js
.then(onFinally, onFinally) // 와 동일하다

prom.then((a)=>{
    console.log(a)
})
.catch((a) => console.log('caught!'))
.finally(() => console.log('finally..'))

// 'caught!'
// 'finally..'
```

### 배운 점:
- Promise 는 비동기 프로그래밍의 기초이다. 프로그램을 구성할 때 실행 시간이 조금 걸리거나 lagging 할 수 있는 요소들을 파악하여 잘 적용할 수 있을 것이다. 

### 참고자료
- [MDN: finally](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/finally)
- [MDN: promise](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise)