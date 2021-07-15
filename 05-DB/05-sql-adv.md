# SQL advanced

## date_format 
- datetime 형태의 레코드에서 특정 값의 날짜 형태로 변환시켜주는 함수이다. 
```sql
SELECT animal_id, name, date_format(datetime,'%Y-%m-%d')
from animal_ins
```
- specifier (%a, %Y 등) 에 따라 원하는 날짜형을 선택할 수 있다. 
- 자주 사용되는 specifier:
	- %a : 요일 이름 (Mon, Tue, Wed)
	- %b : 월 이름 (Jan, Feb, Mar)
	- %c, %m : 월 (1, 2, 3)
	- %H (24시) , %h (12시) : 시간 
	- %Y, %y : 연도
	- %M(full name), %m (숫자형): 월 

## where in 
- 특정 조건이 적용된 레코드를 선택한 뒤, 해당 레코드가 갖는 값들을 선택하고자 할 때 사용한다.
```sql
select * from places
where host_id in (
	select host_id 
	from places 
	group by host_id 
	having count(host_id) > 1)
```

## timestampdiff 함수 
- 두 날짜간의 차이를 특정 단위를 기준으로 구할 때 사용하는 함수이다.
- TIMESTAMPDIFF(단위, 날짜1, 날짜2);
```sql
order by timestampdiff(second, o.datetime, i.datetime)
/* 이 경우 결과값은 두 날짜 간의 차이를 초로 표기한다.*/
```
- 단순히 일(day) 단위로 차이를 구할 때는 datediff 함수를 사용하면 된다.
- DATEDIFF(날짜1, 날짜2);

## if like
- select 문 안에서 조건문을 쓸 수 있는 함수이다. 
- if( 조건, 조건에 맞는 경우 출력할 값, 조건에 맞지 않는 경우 출력할 값)
```sql
SELECT animal_id, name, if(sex_upon_intake like 'Neutered%' or sex_upon_intake like 'Spayed%', 'O', 'X') as neut
```


## ifnull
- 선택한 열의 레코드가 null 값일 경우 레코드의 이름을 다른 값으로 바꿔주는 함수이다. 
```sql
SELECT animal_type, ifnull(name, 'No name'), sex_upon_intake
FROM animal_ins
```


### 참고 자료
- [프로그래머스](https://programmers.co.kr/learn/challenges)