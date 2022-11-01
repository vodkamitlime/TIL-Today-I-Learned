# Fetch API

## Fetch API 란?
- 원격 API를 호출할 수 있도록 하는 함수이다.
- 전달인자로 url 과 options 를 받는다.
	- url 에는 API 주소를 입력한다.
	- options 에는 request 내용을 세부적으로 추가한다. 
```js
let url = 'http://something.com'
let options = {
  method: 'POST',
  body: JSON.stringify({
  	username:"아이스", 
  	text:"아메리카노"
  }),
  headers: {
    'Accept': 'application/json',
    'Content-Type': 'application/json'
  }
 }

fetch(url, options)
  .then((response) => console.log("response:", response))
  .catch((error) => console.log("error:", error));
```

## Fetch API 사용 방법 (Node, browser)
- 브라우저에는 내장되어 있으므로 바로 사용 가능하다.
- node 에서 실행하기 위해서는 별도의 모듈 설치가 필요하다.
	- `node-fetch` 모듈을 유용하게 활용할 수 있다. 
	- `npm install node-fetch` 를 진행한 이후, js 파일에서 import 를 해주면 된다. 
```js
const fetch = require('node-fetch'); // import 하는 방법 : js 파일 최상단에 해당 구문 입력 
```

## Fetch API 의 특징 
- HTTP 상태 코드가 400 또는 500대를 반환해도 상태 코드를 reject 하지 않으며, 네트워크 장애 또는 요청이 완료되지 못한 경우에만 reject 를 한다. 
- 대신 상태 코드가 400 또는 500이 반환될 경우 ok 상태가 false 가 된다. 
- options 추가 설정을 통해 쿠키, 파일 첨부 등의 고급 설정을 할 수 있다. 

### 배운 점:
- 개발자 콘솔에서 Fetch 로 POST 요청을 처음 보내보았는데 options 설정을 잘못해 조금 헤맸다. 서버가 요구하는 options 에 정확히 맞춰 요청을 보내야 성공적으로 처리된다. 

### 참고 자료
- [MDN Fetch API](https://developer.mozilla.org/ko/docs/Web/API/Fetch_API/Using_Fetch)