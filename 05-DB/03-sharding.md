# Sharding

## Sharding 이란?
- Shard 는 조각, 파편이라는 의미를 담고 있는 단어이다. 이처럼 DB 를 조각으로 나누어 관리하는 개념을 "sharding" 이라고 한다. 
- Horizontal Partitioning 과 연관성이 높다. (동일한 개념으로 볼 수 있다)

### Partitioning 이란? 
- 데이터베이스 분할을 일컫는 용어로, DB를 여러 부분으로 분할하는 것이다. 분한된 각 부분을 '파티션' 이라고 부르며, 데이터가 너무 커져서 (VLDB : Very Large DBMS) 조회 시간이 길어지거나 성능 향상 등의 이유로 행해진다. 
- Horizontal Partitioning (Sharding): 테이블의 각 행을 다른 테이블에 분산시키는 것이다.
	- 장점: 데이터의 개수를 기준으로 나눌 수 있으며, 데이터 분할이 되며 index 의 개수도 작아지므로 성능 향상에 도움이 된다. 분할된 테이블은 같은 스키마를 갖는다. 
- Verical Partitioning: 테이블의 일부 열을 빼서 다른 테이블에 분산시키는 것이다. 
	- 장점: 자주 사용하는 컬럼을 분리시켜 성능을 향상시킬 수 있다.
![partitioning](https://hazelcast.com/wp-content/uploads/2020/02/31_Sharding.png)

### Partitioning 의 방법
1. Range Partitioning (Range based sharding)
	- 연속적인 숫자나 날짜 기준으로 행해지며, 특정 범위 안에 드는 경우 분리함 (ex 1~6월, 7~12월로 분리)
	- 손쉬운 방법이므로 관리 시간이 단축된다.
	- 데이터베이스가 고루 분배되지 못할 수 있다.
2. List Partitioning (Directory based sharding)
	- 값이 특정 목록 안에 포함될 경우 분리함 (ex Country 컬럼의 값이 ['Korea', 'Japan', 'China'] 에 포함되는 경우 분리)
	- 목록 안의 값이 테이블에 많이 포함되어 있는 경우 유용하다. 
3. Hash partitioning (Key based sharding)
	- Partition Key의 해시 함수의 값에 따라 분리 (ex 데이터의 key 를 해싱하여 일치하는 Shard ID 를 갖는 Shard 로 분리)
	- 데이터를 고루 분배할 수 있으며, 직접 데이터의 위치를 명령할 필요가 없다. 
	- 모든 데이터에 hash 함수를 적용해야 하므로 데이터 사용을 정지해야 할 수 있다. 
4. Composite Partitioning
	- 여러 개의 partitioning 기법을 혼합하여 사용한 것이다. 

## Sharding 의 특징
- Sharding 을 통해 나누어진 블록을 Shards 라고 한다. 이 때, 분리된 데이터는 Logical shards 이며, 분리된 database node 는 Physical shards 이다. 
- 장점:
	- 서버의 수평적 확장이 가능하다.
	- 스캔 범위를 줄여주기 때문에 쿼리 반응 속도가 빨라진다. 
- 단점:
	- 데이터를 적절히 분리하지 못하면 샤딩의 의미가 없어질 수 있다.
	- 한 번 분할되면 이전으로 다시 합치기 어렵다. 

## 배운 점:
- 샤딩이 일종의 로드밸런싱 기술이다. 로드밸런싱이란 작업 요청을 여러 개의 서버나 처리 장치에 분산하여 나누는 것을 의미하는데, 샤딩을 통해 데이터베이스를 여러 단위로 쪼갰을 경우 그 자체로 로드밸런싱을 수행하게 된다. 

### 참고 자료:
- [Database의 파티셔닝(Partitioning)이란?](https://nesoy.github.io/articles/2018-02/Database-Partitioning)
- [Database sharding이란?](https://velog.io/@matisse/Database-sharding%EC%97%90-%EB%8C%80%ED%95%B4)
