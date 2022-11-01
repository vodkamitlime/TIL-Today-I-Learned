# Express error

## ERR_HTTP_HEADERS_SENT 에러
- express 에서 MVC 패턴에 맞춰 router, controller, model 을 따로 구현해 controller 내부에서 signup 기능을 구현하다가 발생한 에러이다.
- 에러 내용: Error [ERR_HTTP_HEADERS_SENT]: Cannot set headers after they are sent to the client
- 함수 상단에서 이미 존재하는 유저일 경우 res.status(409).send() 를 통해 응답을 반환하도록 했는데, 이후에도 함수가 종료되지 않고 계속 실행되어 이미 전송된 응답에 메세지를 추가하려고 했기 떄문에 발생한 에러이다.
- 이 경우, res 문 앞에 return 을 붙여줌으로써 응답을 보냄과 동시에 함수를 종료하도록 선언해주면 된다. 

## NODE_ENV undefined 에러 

- sequelize-cli init 을 실행한 뒤 생성되는 index.js 에 env 변수가 생기고, 여기에 process.env.NODE_ENV || 'development' 가 할당된다.
- process.env 를 사용하기 위해 dotenv 모듈을 설치하고 index.js 에 추가했는데, require('dotenv').config() 코드의 위치가 최상단이 아니었라 아래쪽에 있었기 때문에 config 이전에 기록된 process.env 코드는 제대로 환경변수를 가져오지 못하는 문제가 발생했다.
- require('dotenv').config() 의 위치를 최상단으로 변경하니 env 변수에 환경변수 할당이 정상적으로 이루어졌다.