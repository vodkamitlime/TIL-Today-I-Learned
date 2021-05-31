# JSON

## JSON 이란?
- Javascript Object Notation 의 약자로, XML (Extensible Markup Language) 이나 YAML 과 같은 데이터 형식 (객체) 중 하나이다. 
- 용량이 작고 지기관적으로 읽고 쓸 수 있다는 장점 덕분에 대부분의 웹 API 나 Configuration 파일에 활용된다. 
- Javascript 와의 호환성도 높으며, 대부분의 프로그래밍 언어에 JSON 데이터를 파싱할 수 있는 내외장 모듈이 존재한다. (ex: python 의 json 모듈)
- XML vs JSON
```xml
// xml

<?xml version="1.0" encoding="ISO-8859-1"?>  
<note>  
  <to>Tove</to>  
  <from>Jani</from>  
  <heading>Reminder</heading>  
  <body>Don't forget me this weekend!</body>  
</note>  
```
```JSON
// JSON

{
  "squadName": "Super hero squad",
  "homeTown": "Metro City",
  "formed": 2016,
  "secretBase": "Super tower",
  "active": true,
  "members": [
    {
      "name": "Molecule Man",
      "age": 29,
      "secretIdentity": "Dan Jukes",
      "powers": [
        "Radiation resistance",
        "Turning tiny",
        "Radiation blast"
      ]
    }
  ]
}
```

### Supported Data Types (지원되는 데이터 타입)
- String, Numbers, Booleans, Null, Arrays, Objects

### Unsupported Data Types (지원되지 않는 데이터 타입)
- Infinity, NaN

## JSON rules (몇 가지 규칙 및 문법)
- JSON 데이터는 기본적으로 객체 (Object) 형태로 전달된다.
- 모든 String 은 꼭 double quote (" ") 로 감싸주어야 한다.
	- Javascript 내 일반적인 객체나 배열, 문자열을 JSON.stringify() 로 감싸준다면 JSON 문법에 맞는 JSON 객체를 얻을 수 있다. 
	- JSON.stringify() 시 Function, Symbol, 값이 undefined 인 프로퍼티는 무시된다. 
  - 순환 참조되는 객체를 stringify 하려면 조금 더 까다로운 방법을 사용해야 한다 (참고자료 참조)
```js
JSON.stringify('haha') // '"haha"'
JSON.stringify({'one':'json'}) // '{"one":"json"}'
JSON.stringify(['one', 'haha']) // '["one", "haha"]'

let user = {
  sayHi() { // 무시
    alert("Hello");
  },
  [Symbol("id")]: 123, // 무시
  something: undefined // 무시
};

alert( JSON.stringify(user) ); // {} (빈 객체가 출력됨)
```
- JSON으로 인코딩 된 (직렬화 처리된 _serialized_, 문자열로 변환된 _stringified_, 직렬화된 _serialized_) 객체를 반대로 JSON 화 해주는 메서드는 JSON.parse() 이다. 

### More about JSON.stringify()
- JSON.stringify 의 매개변수는 `JSON.stringify(value, replacer, space)` 이다. 
- `value` : stringify 하길 원하는 값
- `replacer` : stringify 하길 원하는 프로퍼티가 담긴 배열 또는 매핑 함수
- `space` : 공백 문자 수
	- space 없이 메서드를 호출하게 되면 데이터는 일렬로 정렬되나, 가독성을 높이길 원한다면 space 의 값만큼 들여쓰기를 해 준다. 
```js
let user = {
  name: "John",
  age: 25,
  roles: {
    isAdmin: false,
    isEditor: true
  }
};

JSON.stringify(user)
// '{"name":"John","age":25,"roles":{"isAdmin":false,"isEditor":true}}'

JSON.stringify(user, null, 2)
// '{\n' +
//   '  "name": "John",\n' +
//   '  "age": 25,\n' +
//   '  "roles": {\n' +
//   '    "isAdmin": false,\n' +
//   '    "isEditor": true\n' +
//   '  }\n' +
//   '}'
```
- Date 객체에는 내장 toJSON 메서드가 존재하기 때문에 stringify 가 가능하다.
```js
JSON.stringify(new Date()) // '"2021-05-31T14:09:52.925Z"'
```

## 배운 점
- EffectJS 과제를 하며 전달받는 데이터 타입이 json 인지 text 인지에 따라 파싱하는 방법이 달라지는 점을 확인할 수 있었다. (이는 HTTP request, response 의 Content-type 에 영향을 받는데, application/json 일 경우 json 데이터를 주고받게 되지만 text/plain 인 경우 일반 string 데이터를 주고받게 된다.)
```js
// Response 의 Content-type : Application/json
fetch('someurl').then(res => res.json()) // body 를 json 으로 변환

// Response 의 Content-type : text/plain
fetch('someotherurl').then(res => res.text()) // body 를 string 으로 변환 
```
- JSON 객체의 특징과 용도를 이론적으로 이해하는 것은 비교적 쉬우나 HTTP 통신에 직접 적용해보려니 당혹스러운 순간이 여러 차례 있었다. JSON 화 된 데이터가 어떤 식으로 전달되어야 하는지 정확히 이해하지 못했기 때문에 발생한 일이었기에 이 기회에 기본을 다잡고자 했다. 

## 참고 자료
- [Learn JSON in 10 Minutes](https://www.youtube.com/watch?v=iiADhChRriM&ab_channel=WebDevSimplified)
- [JSON 과 메서드](https://ko.javascript.info/json)
