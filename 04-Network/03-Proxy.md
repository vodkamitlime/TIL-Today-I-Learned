# Proxy

## Proxy 서버란?
- 클라이언트의 요청을 대리해서 처리해주는 서버로, 보통 보안상의 문제로 인해 직접 서버와 통신하지 못할 때 중계하는 역할을 맡는다.
- 실제 접근 호스트가 아닌 다른 호스트에서 접속한 것처럼 위장할 수 있어, 익명성을 보장한다.
- 캐싱 기능이 있어 접속 속도를 향상시킬 수 있으며, 불필요한 외부와의 연결을 줄여 트래픽을 감소할 수 있다. 
- 서버의 위치에 따라 크게 Forward Proxy 와 Reverse Proxy 로 나뉘지만, 하나의 프록시에서 두 기능을 모두 수행할 수 있다.

![프록시 서버](https://img1.daumcdn.net/thumb/R800x0/?scode=mtistory2&fname=https%3A%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F996F8D455A5049630B)

## Forward Proxy
- 클라이언트와 인터넷 사이에 위치한다.
- 클라이언트 대신 서버에 요청을 보내준다. 

## Reverse Proxy
- 인터넷과 서버 사이에 위치한다.
- 서버의 응답을 클라이언트에 대신 전달해준다. 

### Load Balancing? 
- "분산처리" 를 의미하며 요청량이 많을 때 이를 적절히 분배하여 여러 대의 서버에 나눠서 분산처리할 수 있도록 조정하는 작업이다.
- 프록시 서버를 부하 분산 장치 (Load Balancer) 로 사용할 수 있다. 

## 배운 점
- 클라이언트 요청이 많은 경우 서버 한 대를 scale-up 하여 처리할 수 있는 데이터의 양을 늘리는 방법도 있지만, 한 번에 처리할 수 있는 요청의 수는 동일하다. (그리고 데이터가 많아지면 과부하가 올 수도 있다)
- scale-up 대신 load balancing 을 선택할 경우 한 번에 처리할 수 있는 요청의 수가 늘어난다.

## 참고 자료 
- [Proxy란?](https://hardner.tistory.com/34)
- [10분 테코톡: Proxy](https://youtu.be/u4O4zHdiFhk)