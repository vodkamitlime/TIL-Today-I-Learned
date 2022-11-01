# Bcrypt

## Bcrypt 란?
- 비밀번호를 해싱하는 알고리즘 중 하나이다. nodejs 에서 간편하게 이를 실행할 수 있도록 해주는 bcryptjs 모듈도 존재한다.

## Bcryptjs 작동 원리
- 임의의 salt 값을 생성하여, 지정한 횟수만큼 비밀번호를 암호화한다.
```js
bcrypt.genSalt(10, (err, salt) => {
    bcrypt.hash(password, salt, (err, hash) => {
        console.log(hash);
    })
});
```
- 해싱된 값과 솔트 값을 조합한 최종 값을 비밀번호 DB 에 저장한다.
- 해싱된 값과 새로 입력한 문자열을 비교하고자 할 때, 해싱 값에 저장되어 있는 salt 값을 추출해 낸 뒤 문자열을 또 지정되었던 횟수만큼 해싱한다. 값이 일치할 경우 true 를, 일치하지 않을 경우 false 를 반환한다.
```js
bcrypt.compareSync(password, hash);
```