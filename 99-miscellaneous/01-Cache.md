# Cache

## 캐시(Cache)란?
- 컴퓨터의 성능을 향상시키기 위해 사용되는 메모리이다.

## Caching(캐싱)이란? 
- **캐싱**: 어떤 것을 나중에 유용하게 사용하기 위해 저장하는 것이다. 브라우저나 웹에서는 프로그램과 웹사이트의 정적인 **자산**을 저장하는 것이다. 
	> 정적 자산: 이미지, HTML, CSS, JAVASCRIPT
- 즉, 이전에 이미 가져왔던 리소스들을 복사하여 저장해놓고 요청 시에 재사용하는 것이다.

## Caching 의 특징
- 웹과 앱의 성능을 향상하며, (캐시는 원본 리소스보다 클라이언트 사이드에 가까이 있으므로) 웹의 반응 속도를 높인다.

## Caching 의 종류
1. 사설 (Private) 
- 한 명의 사용자만 사용하는 캐시이다.
- 사설 브라우저 캐시는 사용자에 의해 HTTP로부터 다운로드한 모든 문서들을 가지고 있다. 이는 오프라인 브라우징을 개선한다. 
2. 공유 (Shared)
- 한 명 이상의 사용자에 의해 재사용되는 응답을 저장하는 캐싱이다. 

![Private-Shared-Cache](https://mdn.mozillademos.org/files/13777/HTTPCachtType.png)

## 배운 점 :
- 알고리즘에서도 memoization 을 활용하여 중복 연산을 예방하듯 웹 동작에도 불필요한 중복 렌더링을 방지하는 방법이 존재한다. 

### 참고자료
- [MDN:Http Caching](https://developer.mozilla.org/ko/docs/Web/HTTP/Caching)