# Object Deep Copy

## Object 란? 
- Javascript의 Reference type (객체/참조형 타입) 에 속하는 Data type 이다. 
- 한국어로는 '객체'로 불리우며, key 와 value 들로 구성되어 있다. 
- 객체는 Heap 라는 메모리 공간에 저장되며, 변수에는 해당 공간을 참조하는 주소값이 할당된다. 따라서 새로운 변수에 객체 변수 자체를 할당할 경우 객체 자체의 복사가 이루어지지 않으며, 객체를 바라보는 주소만 복사된다.
```js
// 참조 할당: 서로 다른 변수가 같은 객체를 참조하게 됨

let obj = {0:'zero', 1:'one'}
let obj1 = obj // obj의 객체 주소가 복사됨 
obj1.1 = 'changed one' // obj1 에서 값을 변경해주면
obj // {0:'zero', 1:'changed one'} // obj 에서도 값이 변경된 것을 확인할 수 있다. 
```

## Light(Shallow) Copy 란?
- 객체를 다른 변수로 복사하는 방법 중 하나이다. `Object.assign()` 또는 Spread Operator 를 사용할 수 있다. 예시는 `Object.assign()`을 활용하여 작성해본다. 
```js
let obj = { a: 1, b: 2} // 출처 객체
let target = { c: 3 } // 대상 객체

let newobj = Object.assign(target, obj)
newobj // { c: 3, a: 1, b: 2 }
```
- 이러한 방법의 문제점은 객체의 완전한 복사가 이루어지지 않는다는 것이다. 
```js
let obj = { a: 1, b: 2, c: {d:3, e:4}} // 출처 객체
let newobj = Object.assign({}, obj) // 출처 객체를 빈 객체에 복사해준다 

obj.a = 100 // 원본 객체의 속성값 변경
obj.c.d = 300 // 원본 객체의 속성값 변경

newobj.a // 1 
newobj.c.d // 300 
```
- 이처럼 객체의 속성으로 객체를 가지고 있으면 해당 key 에는 참조하는 주소가 할당된다.

> [MDN](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/assign) 설명:
>	> “For deep cloning, we need to use alternatives because Object.assign() copies property values. If the source value is a reference to an object, it only copies that reference value.”

## Deep Copy 란? 
- 위와 같은 문제가 발생하지 않도록, 객체에 대한 참조 없이 고유값만 전부 복사해주는 방법을 의미한다.

### JSON.stringify()
- `JSON.stringify` 와 `JSON.parse` 를 활용하면 Deep copy 를 수행할 수 있다. 
- `JSON.Stringify` 는 받아온 iterable 을 String으로 변환하며, `JSON.parse` 는 변환된 문자를 다시 객체로 되돌려주는 역할을 한다. 
```js
let obj = { a: 1, b: 2, c: {d:3, e:4}} 
let newobj = JSON.parse(JSON.stringify(obj))  
// 변환 시 이전 객체에 대한 참조가 사라짐

obj.a = 100 // 원본 객체의 속성값 변경
obj.c.d = 300 // 원본 객체의 속성값 변경

newobj.a // 1 
newobj.c.d // 3 
```
- 이 방법에는 다음과 같은 문제점들이 존재한다.
	- BigInt (ECMA 2020 도입) 을 처리할 수 없다. (에러 반환)
	- Date와 같은 객체는 Stringify 적용 시 보여지는 방식도 변환한다.
	- 함수, 정규표현식, Infinity 등의 데이터 역시 변환이 안 된다. 
	- 다른 방법에 비해 속도가 느리다.

### Lodash
- Lodash 라이브러리는 cloneDeep() 메서드를 통해 Deep Copy 를 할 수 있도록 지원한다. 이를 활용하면 손쉽게 Deep Copy 를 할 수 있다. 
```js
import * as _ from 'lodash'

const object1 = {
  a: 1,
  b: 2
};

const object2 = _.cloneDeep(object1);
object2.a = 100;

console.log(object2.a); //100
console.log(object2.b); //2

```

- 위의 두 가지 방법 외에도 직접 for 문을 돌리며 새로운 객체에 복사를 해줄 수 있다.

### 배운 점 :
- Deep Copy 라고 무조건 좋은 것은 아니며, Shallow Copy 라고 무조건 기피해야 할 것은 아니다. 코드의 목적과 객체의 용도에 따라 적절한 방법을 선택하는 것이 핵심이다.


### 참고자료
- [깊은 복사와 얕은 복사에 대한 심도있는 이야기](https://medium.com/watcha/%EA%B9%8A%EC%9D%80-%EB%B3%B5%EC%82%AC%EC%99%80-%EC%96%95%EC%9D%80-%EB%B3%B5%EC%82%AC%EC%97%90-%EB%8C%80%ED%95%9C-%EC%8B%AC%EB%8F%84%EC%9E%88%EB%8A%94-%EC%9D%B4%EC%95%BC%EA%B8%B0-2f7d797e008a)
- [자바스크립트 객체 복사하기](https://junwoo45.github.io/2019-09-23-deep_clone/)
- [Lodash | _.cloneDeep() Method](https://www.geeksforgeeks.org/lodash-_-clonedeep-method/)