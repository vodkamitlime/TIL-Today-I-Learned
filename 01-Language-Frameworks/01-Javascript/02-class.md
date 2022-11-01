# Class

## Class 란?
- 객체를 생성하기 위한 템플릿이다. 
- ES6부터는 `class` 키워드로 생성할 수 있다.
```js
class Student{
	constructor(name, age, major){ // constructor(생성자) 함수, 그리고 instance 의 properties(attributes)
		//instance 속성 정의
		this.name = name;
		this.age = age;
		this.major = major; // this = 생성되는 인스턴스
	}
}
```

### Class 의 특징:
- 함수형 Class 는 호이스팅이 일어나지만, 선언형 Class 는 호이스팅이 일어나지 않는다. 
- 클래스 안에는 하나의 `constructor` 메서드만 존재할 수 있으며, 여러 개의 `constructor` 메서드가 있을 경우 SyntaxError 가 발생한다.
- `extends` 키워드를 통해 클래스 상속을, `super` 키워드를 통해 속성 상속을 할 수 있다. 

## Instance 란?
- 클래스의 고유한 속성과 메서드를 갖는 객체이다. 
- `new` 키워드로 생성할 수 있다.
```js
let firstStudent = new Student('Meryl', 65, 'Art')
// this = firstStudent
// firstStudent.name = 'Meryl'
```

## Method 란?
- 객체의 속성인 함수이다.


### 배운 점 :
- Instance에 속성을 부여하려면 꼭 constructor 함수를 써야 한다. 
```js
class Student{
	newStudent(name, age, major){ // constructor(생성자) 함수
		//instance 가 생성될 때 실행되는 코드 
		this.name = name;
		this.age = age;
		this.major = major; // this = 생성되는 인스턴스
	}
}

let testStudent = new Student('lol', 15, 'game')
// typeof testStudent === 'object'
// testStudent.name === 'undefined'
```


### 참고자료
- [MDN Class](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Classes)