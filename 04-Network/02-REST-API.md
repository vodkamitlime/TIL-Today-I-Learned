# REST API

## REST API 란?
- Representational State Transfer API 의 약자이다. 
- HTTP URI(Uniform Resource Identifier)를 통해 자원(Resource)을 명시하고, HTTP Method를 통해 해당 자원에 대한 CRUD Operation을 적용하는 것을 의미한다.
> API 란?
>	> Application Programming Interface 의 약자로, 서버가 클라이언트에게 제공하는, 리소스 활용 방법이 담긴 인터페이스이다. 
> 구체적인 개념:

## 구성 요소
- REST API 는 아키텍쳐 원칙 세트로, 자원(Resource), 행위(Verb : HTTP Method), 그리고 표현(Representation) 으로 구성되어 있다. 
1. 자원(Resource) : URI
	- 자원은 서버에 저장되어 있으며, 해당 자원에 접근할 수 있는 uri 가 존재한다.
	- client 는 uri 를 통해 해당 자원을 조작할 수 있다. (create, read, update, delete)
2. 행위(Verb) : HTTP Method
	- POST, GET, PUT, DELETE 와 같은 메서드이다.
3. 표현(Representation of Resource)
	- Client 가 상태 조작을 요구하는 요청(request)를 보내면 서버는 이에 대한 응답(Representation) 을 보낸다. 

## 주요 원칙
1. URI 는 정보의 자원을 표현한다.
	- resource 는 소문자, 단수 명사 사용을 지향한다.
	- HTTP method 가 포함되면 안된다. 
	- 파일확장자는 포함하지 않는다.
	- Spinal-case 를 사용한다. 
2. 행위는 HTTP Method 로 표현한다.
	- uri 에 포함되면 안된다.
3. 활용할 수 있는 문자의 규칙을 따른다.
	- `-` 는 가독성을 높일 때만 사용한다.
	- `_` 는 사용하지 않는다.
	- `/` 는 계층 관계를 나타내며, 마지막 문자로 사용하지 않는다. 


### REST의 주요 특징
1. 자원(data 등)을 이름/표현으로 구분하여 상태를 전달한다.
	- ex) `/movies` 에 요청하면 영화 목록(자원)을 볼 수 있다. 
	- 상태 전달 : JSON 또는 XML 형태로 전달된다.
2. 서버-클라이언트 구조로 구성되어 있다. 
3. Stateless(무상태)
	- Client 의 상태를 서버에 저장하지 않는다.
	- 각각의 요청을 별개의 것으로 인식하므로 이전 요청을 다음 요청과 연관짓지 않는다.
4. 캐시 처리가 가능하다.
5. Layered System(계층화)
	- REST Server 는 다층으로 구성된다. 

## 배운 점
- REST API 를 도입함으로써 api 를 구성하는 표준이 생기고, 클라이언트-서버 간의 소통이 용이해졌다는 점을 명확하게 이해했다. 
- 지금 당연하게 활용하는 것들이 오랜 시간의 기준 정립을 통해 이루어졌다는 점을 새로 배웠다.  

## 참고 자료
- [What is a REST API?](https://youtu.be/SLwpqD8n3d0)
- [[Network] REST란? REST API란? RESTful이란?](https://gmlwjd9405.github.io/2018/09/21/rest-and-restful.html)