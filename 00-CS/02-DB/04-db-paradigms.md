## DB 패러다임

## DB 패러다임의 필요성
- DB 패러다임이란 DB 를 저장하고 관리하는 방법을 의미한다.  
- 각 패러다임마다 최적의 사용 환경과 조건이 존재한다. 

## 1. Key-Value DB
- DBMS: Redis, Memcached, Etcd 등
- 특징: 
	- Javascript 의 object 또는 python 의 dictionary 데이터 타입과 비슷하다.
	- 유일한 key 값이 존재하며, 각 key에 상응하는 value 를 가진 데이터 구조이다. 
- 장점:
	- 대부분의 다른 DB 는 디스크에 저장되지만, Key-Value DB 메모리에 저장된다. 모든 작업마다 디스크에 접근하지 않아도 되기 때문에 속도가 굉장히 빠르다.
- 단점:
	- 저장할 수 있는 데이터의 용량에 한계가 있다. 	
	- 쿼리를 지원하지 않기 때문에 속도는 빠르지만 데이터 모델링의 한계가 존재한다. 
- 사용 케이스: 
	- 캐시

![key-value](https://fireship.io/lessons/top-seven-database-paradigms/img/key-value.png)

## 2. Wide-Column DB
- DBMS: Cassandra, Apache HBase 등
- 특징: 
	- key-value DB 에 차원을 하나 더 추가한 것과 유사하다. 
	- key 하나당 한 개 이상의 column 을 보유하며, column 에 맞춰 정렬된 여러 개의 행이 존재한다. 이는 관계가 있는 데이터끼리 묶음 처리를 할 수 있도록 한다.
	- RDB 와는 달리 스키마를 적용하지 않는다. 따라서 구조가 없는 데이터베이스를 관리하기에 용이하다.
	- SQL 과 유사한 CQL 이라는 언어를 활용한다.
- 장점:
	- 수평적 확장에 용이하며, 데이터 복제를 간편하게 할 수 있다.
- 단점:
	- CQL은 조인이나 복잡한 쿼리를 실행하지 못한다. 
- 사용 케이스: 
	- 시계열 데이터 (넷플릭스의 시청 기록 데이터)
	- 데이터가 자주 입력되지만 읽거나 수정되지는 않는 경우 

![wide-column](https://fireship.io/lessons/top-seven-database-paradigms/img/wide-column.png)

> 1번, 2번 패러다임은 primary app DB 로 활용되지는 않는다.

## 3. Document Oriented DB
- DBMS: MongoDB, Firestore, CouchDB 등
- 특징:
	- 각 Document 별 key-value pair 가 존재하며, 비구조적이고 스키마를 요구하지 않는다. Document 들끼리 다시 하나의 collection 으로 묶이는데, collection 간 서열화가 가능하다.
	- 조인을 지원하지 않으나, 데이터를 모아 하나의 document 로 병합함으로써 관계형 데이터를 일정 수준까지 다룰 수 있게 된다. 
- 장점:
	- 데이터 출력 (read) 속도는 RDBMS 보다 빠르다.
	- 객체지향적이기 때문에 개발자 친화적이다.
- 단점:
	- 데이터 수정 또는 입력은 복잡하기 때문에 속도가 느리다. 
- 사용 케이스: 
	- iot, 컨텐츠 관리, 모바일 게임
> SNS 와 같이 무수히 많으며 관계 설정이 필요한 데이터가 존재할 경우에 부적합하다. 

![document](https://fireship.io/lessons/top-seven-database-paradigms/img/document.png)

## 4. Relational DB
- DMBS: MySQL, Postgres, SQL Server, CockroachDB 등 
- 특징:
	- 가장 오래되었으며 자주 사용되는 DB 의 유형 중 하나이다. 
	- SQL 을 활용하여 데이터베이스에 접근하고 출력한다. 
	- 테이블의 데이별로 primary key 가 부여되며, primary key들을 활용(조인)하여 테이블 간의 관계 설정을 할 수 있다. 
- 장점:
	- 복잡한 쿼리 작업이 가능하다. 
- 단점:
	- 스키마(데이터와 관계의 구조)가 필요하기 때문에 구성에 오래 걸린다.
- 사용 케이스: 
	- 데이터 간의 관계가 중요한 서비스

![RDB](https://fireship.io/lessons/top-seven-database-paradigms/img/relational.png)

## 5. Graph DB
- DBMS: Neo4j, DGraph, Janus Graph 등
- 특징:
	- 데이터 자체는 노드로(정점) 표현되며, 데이터 간의 관계는 엣지로(간선) 표현된다. 
	- Cypher 라는 언어를 활용하여 쿼리를 날린다. 
- 장점:
- 조인테이블 없이 엣지를 활용하여 관계를 설정하기 때문에 쿼리문이 훨씬 간결해진다. 
- 사용 케이스: 
	- 조인의 빈번한 활용으로 인해 성능이 저하될 때
	- 추천 엔진 (에어비앤비 등)

![Graph](https://fireship.io/lessons/top-seven-database-paradigms/img/graph.png)

## 6. Search Engine DB
- DBMS: ElasticSearch, Algolia, MeiliSearch, Solr 등
- 특징:
	- 입력값에 알맞게 거대한 db 에서 유사한 값을 찾아 출력해야 하는 경우에 활용된다.
	- document 와 유사하게, 하나의 인덱스에 데이터 객체 여러 개를 추가한다.
	- documnet 와 달리, 문서 내의 모든 텍스트에 인덱스 값을 부여하여 검색 가능한 단어의 인덱스를 만든다.
- 사용 케이스:
	- Search Engine 

![search](https://fireship.io/lessons/top-seven-database-paradigms/img/search-engine.png)

## 7. Multi-model DB
- DMBS: FaunaDB, CosmosDB 등
- 특징:
	- 서버리스 DB 이며, GUI 를 활용하여 document 형 데이터에 접근할 수 있다. 
- 장점:
	- 여러 형태의 데이터베이스를 유연하게 다룰 수 있다.
	- 서버를 무한히 확장 가능하다.

![multi-model](https://fireship.io/lessons/top-seven-database-paradigms/img/multi-model.png)


## 배운 점:
- 한 가지 데이터베이스 유형에 갇혀서 생각할 것이 아니라, 서비스의 특수성을 고려하여 필요한 데이터베이스 패러다임을 잘 배우고 활용해야 한다. 
- 데이터베이스 패러다임은 계속 변하며 발전해간다. 특히 데이터 시대에 접어들었으니 DB 파트의 중요성을 강조하며 공부해나가는 것이 좋을 것이다. 

### 참고 자료
- [7 Database Paradigms](https://youtu.be/W2Z7fbCLSTw)