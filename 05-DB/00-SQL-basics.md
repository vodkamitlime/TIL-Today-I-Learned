## SQL

## SQL 이란?
- Structured Query Language 의 약자로, RDBMS(Relational Database Management System) 의 종류이다. 
- 데이터베이스에 보내는 하나의 요청을 쿼리(Query)라고 칭한다.

## SQL 의 특징
- 하나의 Database 는 여러개의 table (또는 entity)로 구성되어 있으며, table 에는 행(record), 열(field), 데이터 값(value) 가 있다.
![sql table](https://www.w3resource.com/w3r_images/component-of-a-database-table.gif)
- 쿼리는 Case-sensitive 하지 않기 때문에 대소문자 구분없이 사용 가능하나, 작업을 하는 컨벤션에 맞춰 작성하는 것이 좋다. 
- 하나의 쿼리를 보낼 때마다 세미콜론(;) 을 붙여주어야 한다.

## (MY)SQL 기본 문법
### CREATE
```sql
CREATE TABLE users(
	fieldname datatype PRIMARY KEY AUTO_INCREMENT
); 

CREATE TABLE name AS (SELECT * FROM othername);
```
- Constraints(제약조건)
```sql
PRIMARY KEY -- 한 column 이상 설정 가능, 테이블마다 한 개씩은 있어야 함
FOREIGN KEY
--FOREIGN KEY (PersonID) REFERENCES Persons(PersonID)
AUTO_INCREMENT
NOT NULL --null 값 삽입 불가능
UNIQUE --중복값 불가능
DEFAULT --아무것도 입력되지 않았을 때 부여되는 값 
CHECK
```
### SELECT + DISTINCT
```sql
SELECT 'hello'
SELECT 2 + 5 --or 2

SELECT Column_1, Column_2; --복수 열 선택
SELECT * FROM table_1; --전체 선택

--특성 내 유니크한 값 고를 때
SELECT DISTINCT name 
FROM users

SELECT DISTINCT name, age
FROM users
--age + name 의 유일한 조합만 남김
```
### WHERE
- 특정 조건을 충족하는 레코드만 추출
```sql
SELECT age -- 전체는 * (wildcard)
FROM users
WHERE age >= 20
-- WHERE age = 20, <, >, >=, <=
-- WHERE age <> 20  특정 값만 제외 (어떤 버전에서는 !=)
```
### ORDER BY
- 오름차순 (기본 정렬) 또는 내림차순 (DESC 설정) 가능
```sql
SELECT * FROM Customers
ORDER BY Country;

SELECT * FROM Customers
ORDER BY Country DESC;

SELECT * FROM Customers
ORDER BY Country, CustomerName;
-- Country 로 1차 정렬 후 
-- -> 같은 country 이름 가진 레코드에 대해서는 CustomerName 으로 정렬

SELECT * FROM Customers
ORDER BY Country ASC, CustomerName DESC;
```
### UPDATE
- 기존의 값들 수정
```sql

UPDATE Customers
SET City = 'Oslo'
-- 모든 레코드의 City 값을 Oslo 로 바꿈

UPDATE Customers
SET City = 'Oslo', ContactName = 'Haeun'
WHERE City = 'London'
-- City 값이 London 인 레코드에 대해 City 값을 Oslo 로 변환
```
### DELETE
- 레코드 삭제
```sql
DELETE FROM Customers -- 이것만 하면 전체 레코드 삭제
WHERE Country = 'Norway'

TRUNCATE TABLE table_name; -- 레코드만 전체 삭제
```
### DROP
- 테이블 삭제
```sql
DROP TABLE table_name;
```

### 참고 자료:
- [W3 Schools SQL Tutorial](https://www.w3schools.com/sql/)