# API Gateway Pattern

## 개요
- API Gateway Pattern 이란? 
	- 여러 Microservice 로 나뉜 것을 하나로 묶어 클라이언트가 호출하도록 해주는 것.
	- 클라이언트의 요청을 받아 내부 MS 를 호출하는 로직을 직접 작성하고, 응답 내용도 취사 선택하여 필요한 것만 내보내는 것 
	- BFF (Backend For Frontend) 도 하나의 구현 방법 

## Monolithic Architecture
- 일반적으로 서비스는 아래의 구조를 띰
```
Client ---> Presentation Layer ---> Business Layer
 ____		 ________________		 ________________
|App/| 		|Filter	/ Facade/|		|AOP / Service   |	
|Web | ---> |Controller		 | ---> |Repository		 |
|____|		|________________|		|________________|

``
`
## MSA 와 계층형 아키텍처 
```
Client ---> Presentation Layer ---> Business Layer
 ____		 ________________		 ________________
|App/| 		|		API		 |		|  Microservices |	
|Web | ---> |	  Gateway	 | ---> |				 |
|____|		|________________|		|________________|

```
- 이를 구현하기 위해 AGF (API Gateway Framework) 을 많이 사용하곤 함. 하지만 AGF 는 아래와 같은 문제점이 있음
	1. 보안 취약성 - IDOR (Insecure Direct Object Reference)
	2. Client 에 구현 전가 - 클라이언트 개발자가 ui 처리에 집중하지 못하고, 비즈니스 로직을 서버/클라 사이드 모두에서 파악해야 함
	등..

- AGF 사용할 만한 경우
	- AGF 를 횡단 관심사처리를 위해 사용 (인증, Canary 처리, 동적 할당 처리 등등). Client -> AGF -> Api Gateway (Presentation layer) -> MS (Business layer)
	- Presentation layer -> AGF (Presentation layer 에 대한 권한 처리) -> MS 의 구조인 경우 
