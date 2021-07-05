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


## 2. Column oriented (Columnar)
- 각 데이터는 필드 단위로 기록되며, 메모리 상 필드끼리 수평적으로 저장된다. 
- 대표적으로 Redshift, BigQuery, Snowflake 등의 DB 가 있다. 
2-1. 장점 
	- 데이터 쿼리를 할 때 성능이 더 좋은 경우가 있다. 