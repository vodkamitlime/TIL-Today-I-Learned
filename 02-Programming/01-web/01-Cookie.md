# Cookie & Session

## HTTP 쿠키란?
- 서버가 사용자의 웹 브라우저(를 이용하고 있는 컴퓨터)에 저장하는 임시 파일 (데이터) 이다.
	> HTTP에는 "비연결성"(Connectionless) 와 "비상태성"(Stateless)라는 특징이 있다. 이로 인해 매 요청마다 서버와의 연결이 해제의 과정을 거치고, 해제 후에는 상태 정보가 저장되지 않는다.
	>	> 그러나 쿠키를 사용하면 연결 해제 이후에도 브라우저의 상태와 관련된 정보를 재전송할 필요 없이 바로 접속할 수 있게 된다. 

## 특징 
- 각 쿠키마다 고유 아이디가 부여된다.
- 브라우저마다 저장되는 쿠키는 다르며, 서버에서는 브라우저가 다르면 다른 사용자로 인식한다.
- 세션 관리, 개인화, 트래킹 등의 목적을 위해 사용된다. 
	> 사용 예시:
	> 로그인 상태 유지, 최근 검색한 상품 추천 등 
- 만료기간이 정해져있어 일정 기간 동안만 데이터를 저장할 수 있다. 

## 세션이란?
- 세션이란 곧 브라우저가 서버에 접속해있는 상태이다.
- 서버는 일정 시간동안 같은 브라우저로부터 들어오는 요구를 하나의 상태로 보아, 브라우저가 종료될 때까지 세션을 유지한다. 

## 특징
- 세션 역시 만료기간이 정할 수 있으나, 만료기간에 관계없이 브라우저가 종료되면 기간이 끝난다. 


## 배운 점 :
- 가끔 웹에 접속할 때 뜨는 "Don't accept Cookies"와 같은 문구의 의미가 궁금했는데 이로써 해결되었다.
- 네트워크의 기초 원리를 잘 알아야 서버 개발을 할 수 있을 것이라고 느낀다. 


### 참고자료
- [쿠키(cookie)와 세션(session)의 개념/차이/용도/작동방식](https://devuna.tistory.com/23)
