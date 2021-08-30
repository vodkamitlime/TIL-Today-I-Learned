# Redis

## Redis 란?
- Redis 의 공식문서에 나와 있는 설명에 따르면, Redis 는 In-memory 데이터 저장소이다.
- 사용 목적에 따라 캐시 , DB, 메세지 브로커로 사용된다.

### In-memory 란? 
- 컴퓨터의 주요 기억장치는 Memory 와 Storage 로 나뉜다.
- Memory 는 RAM 처럼, 일시적으로 데이터를 보존하는 임시 저장장치이다. 접근 속도가 빠른 대신 용량이 작고, 컴퓨터가 꺼지는 즉시 모든 데이터가 날아가는 휘발성이 있다.
- Storage 는 반면 SSD 나 USB 처럼 데이터를 오래 보존하는 장기 저장장치이다. 컴퓨터 전원이 꺼져도 데이터가 날아가지 않지만, Memory 에 비해 데이터를 불러오는 속도가 느리다는 특징이 있다.
- Redis 는 둘 중에서 임시로 데이터를 보존하는 Memory 에 데이터를 보관하기 때문에 “In-memory 데이터 저장소”라고 불린다. 
	- 따라서 Redis 를 사용하면, 외부 DB 나 Storage DB 에서 데이터를 불러올 때보다 훨씬 빠른 속도로 데이터를 얻을 수 있다는 장점이 있다. 

## Redis 를 활용한 Caching
- Read-through Method:
	- 어플리케이션에서 캐시를 확인하고 Cache miss 할 경우, DB 에서 데이터를 불러오는 길에 Cache 를 저장하여 이후부터는 Cache hit 가 발생하도록 하는 전략이다. 
- Write-through Method: 
	- 어플리케이션에서 요청이 들어올 때마다 Cache 와 DB 를 동시에 업데이트하는 방식이다. 

### 참고자료:
- [공식문서](redis.io)
