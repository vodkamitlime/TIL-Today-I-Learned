# Axios

## Axios 란?
- Fetch API 와 비슷하게. javascript 에서 http url 로 요청을 보낼 수 있도록 하는 모듈이다. 
- 기본적으로 promise 로 동작하기 때문에 async 함수와 await, then 메서드를 활용할 수 있다. 

## 사용법:
- 기본 사용법: 
	1. promise.then() 체인 활용
```js
axios.get('https://localhost:8080/user', {
    params: {
      ID: 12345
    }
  })
  .then(function (response) {
    console.log(response);
  })
```
	2. async, await 활용
```js
async function getUser() {
	const response = await axios.get('/user?ID=12345');
	console.log(response)
}
```
- 요청별 사용법:
```js
axios.get()
axios.post()
```
- 여러 개의 요청 동시에 실행할 경우:
	- Promise.all() 활용
```js
function getUserAccount() {
  return axios.get('/user/12345');
}

function getUserPermissions() {
  return axios.get('/user/12345/permissions');
}

Promise.all([getUserAccount(), getUserPermissions()])
  .then(function (results) {
    const acct = results[0];
    const perm = results[1];
  });
```
## 요청 설정:
- 몇 가지 기본 설정은 다음과 같다.
```js
{
	baseURL: 'https://some-domain.com/api/', // 제공된 url 이 절대경로가 아닐 때 url 이전에 붙는다
	headers: {'X-Requested-With': 'XMLHttpRequest'}, // 요청 헤더
	params: {
    	ID: 12345 // url 에 붙는 파라미터 ex ) localhost/12345
  	},
  	data: {
  		name: 'haeun' // 요청 body 로 보낼 데이터이며, 'PUT', 'POST', 'DELETE , 'PATCH' 요청에만 유효함
  	} 
  	timeout: 1000, // 요청이 유효한 시간을 millisecond 단위로 표현, 시간이 지나면 요청은 종료됨
  	auth: {} // http 기본 권한 설정을 해 줌 , Authorization 헤더 생성
  	...
}


```

## 응답 스키마:
```js
{
  data: {}, // 서버가 보낸 payload
  status: 200, // 서버의 응답 코드
  statusText: 'OK', // 응답 메세지
  headers: {}, // HTTP 헤더, 전부 소문자 
  config: {}, // 추가 일괄설정을 한 경우 
  request: {} // 해당 응답을 요청한 요청 객체
}
```

## 배운 점:
- axios 의 withCredentials 설정을 true 로 바꿔주어야 쿠키, 권한 등의 데이터가 요청에 포함된다.
```js
axios.defaults.withCredentials = true;
//또는
await axios.post('https://localhost:4000/login', {
      withCredentials = true;
  })
```

### 참고 자료:
- [Github Axios](https://github.com/axios/axios)