# Synchronous, Asynchronous

## Synchronous vs Asynchronous
- 동기식 vs 비동기식
- 동기식: 코드의 execution 이 요청과 동시에 일어나며, 순차적으로 실행된다.
- 비동기식: 코드의 execution 이 요청과 동시에 일어나지 않으며, 병렬적으로 실행된다. 

### 예시
```js
작업 목록:
1. 화면에 영상 목록을 띄워라
2. 첫 번째 영상을 틀어라
3. 하단에 추천 영상 목록을 띄워라

동기식:
1 실행 -> 2 실행 -> 영상 정보 요청 -> 영상 정보 수신 -> 영상 출력 -> 3 실행 

비동기식:
1 실행 -> 2 실행 -> 3 실행
		|_ 영상 정보 요청 -> 영상 정보 수신 -> 영상 출력

```
- 동기식 방법을 따르면 첫 번째 영상의 데이터가 모두 들어오고, 끝까지 재생되기 전까지는 3을 실행할 수 없다. 
- 비동기식 방법을 따를 경우, 2가 실행되는 순간 데이터의 요청 작업과 3의 실행이 따로 이루어진다. 영상 재생은 데이터가 다 들어오는 순간 이루어진다. 

## AJAX란?
- Asynchronous Javascript And Xml의 약자로, Javascript 라이브러리이다.
	- XML: Extensible Markup Language의 약자이다. 
- JS 를 이용하여 클라이언트와 서버간에 XML 데이터를 주고받는 통신이다.
- CSR (Client Side Rendering)이 가능하도록 해준다. 
- 초기에는 XML HTTP request object 를 통해 이루어졌으나, 이후에는 jQuery 를 활용하게 되었고, ES6부터는 fetch API 가 활용되었다. 

### Fetch API 란?
- Promise 를 반환값으로 갖는 통신 API 이다. 
```js
fetch(resource, init(optional)) // resource = url, init = 설정 객체
.then(callback) // ex) response => response.json()
.catch(callback) 

// init 작성 예시

const init = {
	method: 'GET',
	headers: {
	  'Content-Type': 'application/json',
	},
	credentials: 'same-origin',
};

```

### 배운 점:
- 비동기 함수는 자바스크립트 프로그래밍의 기초가 된다. 정확하게 알아놓아야 한다. 

### 참고자료
- [MDN:Using Fetch](https://developer.mozilla.org/ko/docs/Web/API/Fetch_API/Using_Fetch)
- [Ajax,Fetch](https://velog.io/@ksh4820/Ajax-fetch)
