# Sequelize migration 실행  시 발생하는 오류

## Validation Error

![err1](https://media.discordapp.net/attachments/865425795040542752/867596886449061908/Screen_Shot_2021-07-22_at_11.40.12.png)


- 시드 실행 시 뜨는 validation error 는 테이블의 필드에 지정된 datatype 과 입력하고자 하는 datatype 이 안 맞아서 발생한다.
- 또는 FK 데이터를 삽입하고자 하는 경우, 존재하지 않는 외래키 value 를 넣고자 할 때도 똑같은 에러가 발생한다.
- sequelize (&mysql) 은 따로 pk 시작값을 0으로 해주지 않는 이상 1부터 increment 를 한다. dummydata 삽입 시 pk 가 전부 0부터 시작하도록 설정되어 있따면 seed 를 여러 번 삽입하여 migrate 하는동안 0값이 계속 increment 되어 51, 52, 53 등 의도치 않은 값을 갖게 된다. 이 때, 조인 테이블에 시드 데이터를 넣을 때 없는 값을 참조하게 되는 경우가 발생하기 때문에 validation error가 발생한다.


## Dialect Error

- config 에 문제가 있기 때문에 발생하는 에러이다. 
- npx sequelize-cli 는 migration 또는 seed를 실행할 때 init 실행 때 제공한 configuration 변수명을 찾는다. (development, test, production)
- 해당 내용을 수정하고 다른 변수명을 지정하면 migration 실행이 안된다. 이 때 나오는 에러는 "Error: Dialect needs to be explicitly supplied as of v4.0.0" 이다.

## Foreign Key Error

![err2](https://media.discordapp.net/attachments/865425795040542752/867636877179224074/Screen_Shot_2021-07-22_at_14.18.56.png)

- 에러 내용: Cannot add or update a child row: a foreign key constraint fails (galleryport_dev.project_contents, CONSTRAINT project_contents_ibfk_1 FOREIGN KEY (project_id) REFERENCES projects (id) ON DELETE SET NULL ON UPDATE CASCADE)
- 테이블 간 association 설정을 belongsToMany 로만 해두어서 발생하는 문제다. db.table.associates 로 상호 참조도 걸어주면 해결된다.

## 기타 배운 점
- sequelize.date 데이터 타입은 문자열로 넣으면 된다. 
- 한 번 실행한 시드 마이그레이션은 다시 실행이 안된다. db:seed:all 을 실행했을 경우 db:seed:undo:all 로 전체를 되돌려준 뒤, 다시 실행하면 된다. (단, seed 파일에 있는 down 함수들이 제대로 작성되어 있어야 한다)

