# Redis 란?

## Redis DB 
- Remote Dictionary Server (DB)로, 외부에 있는 객체를 사용하는 서버이다.
- In-memory Data structure Store 로, 메모리 상에 데이터를 저장한다. 
- 다양한 자료 구조를 저장한다.
- NoSQL DB 로 활용된다.
- 모든 데이터는 Key-value 쌍을 이룬다. 
- 속도가 느린 RDBMS 등의 DBMS 보다 활용도가 높은 케이스가 종종 있다.  

### Cache 와의 연관성
- 요청 결과를 저장해두었다가 동일한 데이터를 얻고자 하는 요청이 들어오면 저장한 결과를 바로 줄 수 있도록 하는 저장값이다.
- 자주 바뀌지 않지만 자주 접근되며, 접근 속도가 빨라야 한다는 특징을 가지고 있기 때문에 SSD 등의 Storage 가 아닌 Main memory (Redis) 에 저장되게 되었다. 

### 지원하는 자료 구조
- String
- List
- Set
- Sorted Set 
- Hash (Object)

## 배운 점
- 캐시를 본격적으로 다루려면 Redis 사용법을 꼭 알아두어야겠다는 생각이 든다. 
- In-memory 와 Disk 의 차이를 정확히 이해하지 못했었는데, 컴퓨터 구조와 함께 공부하니 이해도가 다소 상승했다. (하지만 아직 부족하다고 느낀다.)

### 참고 자료
- [What is Redis and What Does It Do?](https://youtu.be/8A_iNFRP0F4)
