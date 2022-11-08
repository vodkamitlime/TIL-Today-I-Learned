# Functional Programming 주요 개념들 (Node.js)

## Monad
- 모나드는 값을 캡슐화하고, 추가 기능을 더해 새로운 타입을 생성하는 구조체
- 하나의 타입으로, Generic 인자를 받고 / unit (return) operator 가 있고 / bind operator 가 있는 값임 
- iterable 인 값에 함수 연쇄 작용을 하고자 하는 경우, 값이 없을 땔 Error / NaN 을 내뱉는 경우를 대비하여 함수 자체를 실행하지 않도록 하는 장치
- 이떄, Promise.then 으로 함수를 합성하여 비동기로 값들을 chaining 하여, 값이 없을 때는 비동기 함수가 실행되지 않도록 할 수 있음 

## Kleisli Composition
- 오류가 있을 수 있는 상황에서 함수 합성을 안전하게 하는 규칙
- Promise 를 사용한다면, Reject & Catch 통해 에러 핸들링 가능

## Promise vs Callback
- Node.js 에서 Promise 의 역할은, 비동기 상황을 1급 객체로 다루는 것임 (함수의 인자로 전달 가능, 변수 할당 가능 등등)
- Promise 에는 Pending, Rejected, Resolved 의 3가지 상태가 존재하는데, 이는 각각 1급 객체로 취급될 수 있음 
- Callback 은 실행 context 를 반환하지 않으나, Promise 는 함수 실행 결과와 실행 context 를 담은 Promise 를 반환함 
- Promise.then 으로 체이닝 가능함


### 참고자료
- 유인동, 함수형 프로그래밍과 JavaScript ES6+