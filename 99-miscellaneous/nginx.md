# Nginx 란?

## Nginx
- 경량 웹 서버이다.
- HTTP 요청에 맞는 정적 파일을 응답해주는 HTTP 웹 서버 (WAS)로 활용되기도 하며, Reverse Proxy Server 로 활용되어 WAS 서버의 부하를 줄이는 로드밸런서로 활용되기도 한다. 

## Nginx 의 특징
- 비동기 이벤트 기반의 구조를 지니고 있어, 트래픽이 많은 웹사이트를 위해 사용될 수 있다. 
- Event loop 을 통해 request queue 를 처리한다. 더 적은 자원으로 더 빠르게 서비스할 수 있다. 

![loop](https://mblogthumb-phinf.pstatic.net/MjAxNzAzMjZfMTM3/MDAxNDkwNDk1NjMxNzgy.OHZ33nerX_6Hc92Mg_xjr51acwwi1P_mq3SIl7Cuhisg.niRsQQVM5CwGpXKcdOxl3bkNsmfBkqGV1ajcBpV6CvQg.GIF.jhc9639/mighttpd_e02.gif.gif?type=w800)

### Apache 와의 차이점? 
- 경쟁 서비스인 Apache 는 클라이언트 요청 하나당 하나의 쓰레드를 투입하여 처리하므로 자원 낭비가 심하고, 처리할 수 있는 요청의 개수에 제한이 있다 (C10K Problem)

## 배운 점:
- 웹 서버에도 비동기, 동기적으로 실행되는 엔진이 나뉜다.
- 비동기 서버끼리 프록시-was 로 사용하게 되면 시너지 효과가 나게 된다. 
- 비동기 요청의 중요성은 쓰레드 (그리고 곧 리소스) 의 효율적 사용과 연관성이 높다.

### 참고 자료:
- [Nodejs 서버 구성시 Nginx를 사용해야 하는가?](https://velog.io/@nawnoes/Nodejs-%EC%84%9C%EB%B2%84-%EA%B5%AC%EC%84%B1%EC%8B%9C-Nginx%EB%A5%BC-%EC%82%AC%EC%9A%A9%ED%95%B4%EC%95%BC-%ED%95%98%EB%8A%94%EA%B0%80)
- [node.jsreaddir과 readdirSync 성능비교와 비동기 그리고 동기](https://blog.naver.com/jhc9639/221108496101)
- [10분 테코톡 👃미스터코의 Apache MPM vs NGINX vs Node.js](https://youtu.be/QeBqwwbsBbM)