# 구조분해, Rest, Spread 

## 구조분해 할당(Destructuring)이란? 
- 배열이나 객체의 속성을 해체하여 값을 개별 변수에 담을 수 있게 해주는 표현식이다. Python 등의 언어에도 동일한 기능이 존재한다. 
```js
// 구조분해 할당 : 배열
let [a, b] = [1, 2]
console.log(a) // 1
console.log(b) // 2

let x = [1, 2, 3, 4, 5];
let [y, z] = x;
console.log(y); // 1
console.log(z); // 2

// 구조분해 할당 : 객체
let {a, b} = {a: 4, b: 10}
console.log(a) // 4
console.log(b) // 10

let {x} = {x: 10}
let {y} = {y: 20}
let z = {x, y}
console.log(z) // {x: 10, y: 20}
````
- 변수에 기본값을 할당하여 분해한 값이 undefined 인 경우 사용할 값을 미리 지정할 수 있다. 
```js
let a, b;

[a=5, b=7] = [1]; // 또는 {a, b=7} = {a:1}
console.log(a); // 1
console.log(b); // 7
````
- 두 변수의 값을 교환할 수도 있다. 
```js
let a = 1;
let b = 3;

[a, b] = [b, a];
console.log(a); // 3
console.log(b); // 1
````
- 객체의 원본 프로퍼티 값을 분해하여 다른 변수에 할당할 수 있다.
```js
let o = {p: 42, q: true};

// { 객체 프로퍼티: 목표 변수 }
let {p: foo, q: bar} = o;

console.log(foo); // 42
console.log(bar); // true
console.log(p) // undefined
````

## Rest 문법이란? 
- 변수 앞에 점 세 개 `...` 를 붙임으로써 구조분해 할당 시 여러 개의 값을 한 번에 가져올 수 있도록 하는 문법이다. 
```js
// 구조분해 할당 + rest 문법
let [a, b, ...rest] = [1, 2, 3, 4, 5]
console.log(a) // 1
console.log(b) // 2
console.log(rest) // [3,4,5]

({a, b, ...c} = {a: 10, b: 20, c: 30, d: 40});
console.log(a); // 10
console.log(b); // 20
console.log(c); // {c: 30, d: 40}
```

## Spread 문법이란?
- Rest 문법과 반대로 기존의 배열 또는 객체의 값을 다른 변수에 할당할 때 활용한다.
```js
const slime = {
  name: '슬라임'
};

const cuteSlime = {
  ...slime,
  attribute: 'cute'
};

const animals = ['개', '고양이', '참새'];
const anotherAnimals = [...animals, '비둘기'];
````

### 주의할 점
- 객체 구조분해 할당 연산 시 let 또는 var 를 활용하여 변수를 선언하면 상관 없지만, 기존에 있던 변수에 분해한 값을 할당하려 한다면 중괄호 `{}` 를 괄호 `()` 로 감싸주어야 한다. 
```js
let title, width, height;

// Syntax Error
{title, width, height} = {title: "Menu", width: 200, height: 100};

// 올바른 방법
({title, width, height} = {title: "Menu", width: 200, height: 100});
````
- 중첩된 배열이나 객체의 정보를 추출하고자 하는 경우, 중첩 구조 분해 (nested destructuring) 을 해야 한다. 
```js
let options = {
  size: {
    width: 100,
    height: 200
  },
  items: ["Cake", "Donut"],
  extra: true
};

let {
  size: { 
    width,
    height
  },
  items: [item1, item2], 
} = options;

console.log(size) // not defined
console.log(width) // 100
console.log(title) // "Menu"
````

## 배운 점
- 구조분해 할당에 대해 자세히 알아보지 않고 그냥 넘겼더니 오류가 잦았다 (특히 변수 재할당의 경우). 객체 구조분해를 할 때 새로운 변수를 선언해주는 것이 아니라 재할당 해주는 경우 중괄호 `{}` 안에 변수를 담아주기만 할 경우 js 엔진이 이를 코드 블럭으로 인식해 나는 오류였다. 

## 참고 자료
- [MDN 구조 분해 할당](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Operators/Destructuring_assignment)
- [벨로퍼트와 함께하는 모던 자바스크립트](https://learnjs.vlpt.us/useful/07-spread-and-rest.html)
- [코어 자바스크립트: 구조 분해 할당](https://ko.javascript.info/destructuring-assignment)