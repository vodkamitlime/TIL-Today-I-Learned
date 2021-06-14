# Environment Variables (환경변수)

## 환경변수란?
- 운영체제(OS) 에서 설정해주는 변수를 의미한다. 
- 이름과 값이 쌍으로 구성되어 있다. 

## CLI 명령어
- `printenv` : 현재 터미널의 환경 변수를 확인할 수 있다.
- `echo $variable_name` : 특정 변수의 내용을 확인할 수 있다.
- `export test_variable=test` 의 형태로 임시 설정을 할 수 있다. (단, 임시 설정은 해당 터미널 환경 내에서만 유효하다.)

## NodeJS 에서 환경변수 사용하기
- 코드를 안전하게 캡슐화하여 환경변수에 영향을 받을 때마다 수정하지 않아도 되도록 만든다. 
- 보안이 중요한 정보를 코드에 포함하지 않는 방법을 마련한다. 
- 앱 초기화 단계에서 OS 의 환경변수는 `process.env` 파일에 저장된다. 이는 fetch 또는 dotenv 모듈 등을 통해 접근 가능하다. 

### dotenv 사용하기
- 개발자마다 개발을 하게 되는 실행환경이 다르기 때문에 일관된 방법으로 환경변수를 설정해주는 코드가 필요하며, 이를 돕는 것이 dotenv 모듈이다.
```js
//index.js
const dotenv = require('dotenv')

dotenv.config();
```
- app 폴더 내에 `.env` 파일을 만들어 수정함으로써 환경 변수를 설정할 수 있다. 
```js
//.env

PORT=3000

//index.js
const PORT = process.env.PORT // 3000
//
```
- .env 파일에는 민감한 정보가 담길 수 있는데, 이에 따라 gitignore 파일에 .env 가 포함되었는지 확인하여 외부에 공유되지 않도록 한다. (기본값으로 설정되어 있긴 함)

## 배운 점
- 생각 없이 깃허브 또는 오픈소스 플랫폼에 코드를 올리다가 민감한 정보가 유출될 수 있다는 사실을 다시금 깨달았으며 환경변수의 활용이 코드의 보안을 높여줄 수 있다는 점을 앞으로도 유용하게 다룰 수 있을 것이라고 느낀다. 

## 참고 자료
- [An Introduction to Environment Variables and How to Use Them](https://medium.com/chingu/an-introduction-to-environment-variables-and-how-to-use-them-f602f66d15fa)