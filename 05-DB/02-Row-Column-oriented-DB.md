## Row-oriented DB, Column-oriented DB

## Row vs Column oriented DB
- RDBMS (관계형 데이터베이스) 를 관리하는 두 가지 방법이다. 
- Row oriented Database 는 레코드 (행) 으로 관리되는 데이터베이스이다.
- Column oriented Database (Columnar 또는 C-store) Database 는 열로 관리되는 데이터베이스이다.

## 1. Row oriented
- 각 데이터는 레코드 단위로 기록되며, 메모리 상 레코드끼리 수평적으로 저장된다. 
- 가령, 해당 데이터의 경우:

![데이터](https://dataschool.com/assets/images/data-modeling-101/row_vs_col_databases/modeling1.png)

이런 식으로 저장된다.

![데이터 2](https://dataschool.com/assets/images/data-modeling-101/row_vs_col_databases/modeling2.png)

- 대표적으로 Postgres, MySQL 등의 DB 가 있다.
- 전통적인 DB 관리 방법이며, 행 단위를 읽는데 최적화 되어 있다. 
1-1. 장점
	- 데이터의 끝에 행을 추가하기만 하면 되기 때문에 저장 속도가 빠르다.
	- OLTP (Online transactional Processing) 스타일 애플리케이션에 최적화 되어 있다. 
1-2. 단점
	- 행 단위 데이터를 불러오는 속도는 빠르나, 데이터 간의 집합을 만드는 경우 (aggregation) 속도 저하 현상이 발생한다. (필요한 것 이상의 데이터를 불러오기 때문)
		- 가령, 위의 예시에서 유저의 평균 나이를 구하고자 할 경우, 데이터 조각 9개를 전부 불러들인 뒤 함수 적용을 하게 된다. 이는 불필요한 연산 시간을 초래한다. 
	- 따라서 데이터를 입력하는 것은 간편할 수 있으나, 출력하는 과정에서 필요 이상의 메모리 소모가 발생할 수 있다. 


## 2. Column oriented (Columnar)
- 각 데이터는 필드 단위로 기록되며, 메모리 상 필드끼리 수평적으로 저장된다. 
- 가령, 앞선 예시의 경우: 

![데이터](https://dataschool.com/assets/images/data-modeling-101/row_vs_col_databases/modeling1.png)

이런 식으로 저장된다.

![데이터 3](https://dataschool.com/assets/images/data-modeling-101/row_vs_col_databases/modeling9.png)

- 대표적으로 Redshift, BigQuery, Snowflake 등의 DB 가 있다. 
2-1. 장점 
	- 데이터 쿼리를 할 때 성능이 더 좋은 경우가 있다. 
	- OLAP (Online Analytical Processing) 스타일 용도에 최적화 되어 있다.
	- 데이터 집합을 만드는 경우 추가 메모리 소모 없이 필요한 결과를 출력할 수 있으며, 이에 따라 성능이 크게 향상된다. 
2-2. 단점
	- 모든 데이터가 같은 메모리 공간에 저장될 경우, 각 열의 마지막 데이터의 위치를 조회하여 옆에 추가해야 하기 때문에 메모리 전체를 조회해야 한다. (이 부분은 열마다 저장되는 메모리 공간을 분리함으로써 해결 가능하다.)

## 배운 점:
- 데이터 모델링 시 단순히 관계형 / 비관계형 DB 중에서 양자택일 할 것이 아니라, 서비스의 세부적인 필요와 요구사항에 따라 구체적인 설계를 할 수 있다. 
- 관계형 데이터베이스의 경우, 그 첫 걸음이 row/column oriented db 가 될 수 있다. 

### 참고 자료
- [https://dataschool.com/data-modeling-101/row-vs-column-oriented-databases/](https://dataschool.com/data-modeling-101/row-vs-column-oriented-databases/)
