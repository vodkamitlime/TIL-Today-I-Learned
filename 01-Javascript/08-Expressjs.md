# ExpressJS (intro)

## Express란?
- Nodejs 를 위한 웹 서버 프레임워크이다. 

### 기본 사용 안내
- 설치
`npm install express`
- 서버 연결
```js
const express = require('express') 
const app = express()
const port = 3000

app.get('/', (req, res) => {
  res.send('Hello World!')
}) // '/' 로 라우팅 되지 않는 url 에 대한 get 요청에 대해서는 전부 404 에러가 반환된다

app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`)
})
```
- 웹 앱 뼈대 구성
`npx express-generator`

### 라우팅 (Routing)
- 앱이 특정 endpoint (url) 으로 온 요청을 처리하는 방식을 정의하는 작업을 의미한다. 
```js
app.METHOD(PATH, HANDLER) 
// method = http method
// path = url path (쿼리 스트링 미포함, 정규표현식 활용 가능)
// handler = 라우트가 일치할 때 실행되는 함수

app.get('/', function (req, res) {
  res.send('Hello World!')
}) // get, post, put 등 http 요청에 대해 가능
```
- `app.all()` 라우팅 메서드는 특정 path 로 오는 모든 요청에 대해 함수를 실행해준다. 
```js
app.all('/secret', function (req, res, next) {
  console.log('Accessing the secret section ...')
  next() // pass control to the next handler
})
````

### Middleware (미들웨어)
- 앱 내의 요청과 응답, 그리고 next() 함수에 접근할 수 있는 함수이다. 
	- next() 함수는 이어지는 middleware 를 호출하는 함수이다.
- 미들웨어는 보통 Application-level, Router-level, Error-handling, Built-in, Third-party 로 나뉜다. 
- Application-level 예시: `app.use()`
```js
const cors = require('cors');

app.use(cors()) // 모든 요청, 응답에 대해 cors() 헤더 사용
// 여기서 cors() 는 Third-party Middleware 이다. 
```
- Router-level 예시: `router.use()`
```js
let router = express.Router()

router.use(someFunction)
````

### 보너스 ) Static 파일 쓰기
- CSS 또는 javascript 와 같은 정적인 (static) 파일은 보통 앱의 public 파일에 저장되며, 내장 미들웨어를 통해 이러한 파일에 바로 접근 가능하다.
```js
app.use(express.static('public'))
// http://localhost:3000/js/app.js 접근 가능

//또는 path prefix 를 추가할 경우
app.use('/static', express.static('public'))
// http://localhost:3000/static/js/app.js 접근 가능

```

## Expressjs 의 장단점
- 장점
	- Javascript 로 작성되기 때문에 별도의 문법 없이 쉽게 사용할 수 있다. 
	- 온갖 API 와의 호환이 가능하다. 
	- 미들웨어를 쉽게 만들고 활용할 수 있다. 
- 단점
	- 보안 단계를 명시하지 않기 때문에 보안에 취약할 수 있다. 

## 배운 점
- 가장 중요하지만 계속 잊어버렸던 사실은 js 파일을 수정한 뒤에는 서버를 껐다 켜 주어야 반영이 된다는 점이다. 이러한 불편은 nodemon 등의 모듈을 활용하면 쉽게 해결할 수 있다. 
- 

## 참고 자료
- [Express 공식 문서](https://expressjs.com/en/starter/hello-world.html)
- [Pros and cons of express](https://www.quora.com/What-are-the-pros-and-cons-of-learning-ExpressJS)