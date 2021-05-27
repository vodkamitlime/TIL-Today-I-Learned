#CORS

## CORS (정책) 이란?
- 2009년에 등장한 보안 정책으로, Cross-Origin Resource Sharing 의 약자이다.
- 웹 생태계에서 다른 출처로의 리소서 요청을 제한하는 것과 관련된 정책 중 하나이다.
	> 다른 하나는 SOP(Same-Origin Policy)이다.
- 점차 웹에서 다른 출처에 있는 리소스를 가져와서 사용하는 일이 흔해지자, "몇 가지 예외 조항에 해당하는 (===CORS 정책을 지킨) 리소스 요청"에 한해서는 허용해주자는 정책이 바로 CORS 정책이다. 
- 즉, 정해진 헤더를 지킨 요청에 한해서는 같은 출처가 아닌 url 끼리도 통신이 가능하게 하겠다는 의미이다. 

### SOP란?
- 일종의 보안 정책으로, "같은 출처에서만 리소스를 공유할 수 있다"는 규칙을 가진 정책이다.

------
1. Does it fulfill the SOP policy? (y/n)
	-> y : 리소스 요청
	-> n : 
	2. Does it fulfill the CORS policy? 
		-> y: 리소스 요청
		-> n: 리소스 요청 불가 
------

### "같은" 출처란?
- url 의 scheme, host, port 가 동일한 경우를 일컫는다. 
- 위의 3가지가 같다면 query 나 path 가 달라도 동일한 출처로 인식된다.

## Access Control Scenarios 
- CORS 가 작동하는 3가지 방식이다. 
1. Simple Requests(간단한 요청)
	- 다음 조건들을 만족하는 경우에 해당한다.
		- GET, HEAD, POST 메서드 요청
		- 자동적으로 설정되는 헤더와 Accept, Accept-Language, Content-Language, Content-Type 만 존재하는 요청
		- Content-Type 가 application/x-www-form-urlencoded, multipart/form-data, text/plain 중 하나에 속하는 요청
	- 간단한 요청의 경우, 서버에서 `Access-Control-Allow-Origin:` 헤더를 추가한 응답을 보낸다. 
	![Simple Request](https://developer.mozilla.org/en-US/docs/Web/HTTP/CORS/simple-req-updated.png)
2. Preflight Requests(사전 요청)
	- 



3. Credential Requests(인증을 이용하는 요청)

### 배운 점
- 

### 참고자료
- [CORS는 왜 이렇게 우리를 힘들게 하는걸까?](https://evan-moon.github.io/2020/05/21/about-cors/)
- [CORS(Cross-Origin Resource Sharing)이 나오게 된 배경 이야기](https://youtu.be/yTzAjidyyqs)
- [MDN:CORS](https://developer.mozilla.org/en-US/docs/Web/HTTP/CORS)