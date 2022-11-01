# XSS, CSRF

## XSS 란?
- Cross-Site Scripting 의 약어로, 웹 페이지의 스크립트를 악의적으로 조작하여 실행되도록 하는 공격이다. 

### XSS의 유형
1. 저장 XSS
- 웹사이트의 서버에 악성 스크립트를 저장하여 서버에 접속하는 클라이언트의 브라우저에서 스크립트를 실행하도록 한다.
2. 반사 XSS
- 악성 스크립트를 삽입한 url 을 피해자에게 노출하여 의도적으로 실행되도록 만든다. 

### XSS 대응 방법
- `<` 또는 `>` 대신 &lt; 를 사용한다.

## CSRF 란?
- Cross-Site Request Forgery 의 약어로, 사용자가 의도하지 않은 요청을 서버에 보내도록 하는 공격이다. 

### CSRF 대응 방법
- Anti CSRF 토큰 (Randomized Token) 을 활용한다. (해당 토큰이 없는 요청에 대해서는 처리를 하지 않도록 한다)

## 배운 점
- XSS 공격에 대응하는 것은 백엔드 개발자의 기초적인 역량 중 하나이다. 기초 XSS 공격에 취약한 서버는 잘 설계된 서버가 아니다. 
- 대부분의 사이트는 XSS 에 잘 대응하나 CSRF 와 같은 변칙적인 공격에 대응하지 못하는 경향을 보인다. 

## 참고 자료
- [IT wiki](itwiki.kr)
- [동빈나 웹 해킹 강좌](https://www.youtube.com/watch?v=nzoUgKPwn_A&ab_channel=%EB%8F%99%EB%B9%88%EB%82%98%EB%8F%99%EB%B9%88%EB%82%98)