## Express error

- express 에서 MVC 패턴에 맞춰 router, controller, model 을 따로 구현해 controller 내부에서 signup 기능을 구현하다가 발생한 에러이다.
- 에러 내용: Error [ERR_HTTP_HEADERS_SENT]: Cannot set headers after they are sent to the client
- 함수 상단에서 이미 존재하는 유저일 경우 res.status(409).send() 를 통해 응답을 반환하도록 했는데, 이후에도 함수가 종료되지 않고 계속 실행되어 이미 전송된 응답에 메세지를 추가하려고 했기 떄문에 발생한 에러이다.
- 이 경우, res 문 앞에 return 을 붙여줌으로써 응답을 보냄과 동시에 함수를 종료하도록 선언해주면 된다. 