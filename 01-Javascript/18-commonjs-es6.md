# CommonJS vs ES6

## 배경
- ES5 까지는 모듈이라는 개념 부족, 각 모듈 간 의존성 처리에 제한 있었음
- HTML 내부에 <script /> 를 활용한 JS 파일 삽입을 주로 활용, 하지만 이 경우 모두 window 객체의 속성이 되므로 다른 파일에 위치해도 동일한 변수명을 사용할 경우 에러가 발생
- 이를 위해 도입한 표준이 CommonJS, AMD
- ES6 module 은 CommonJS 와 AMD 를 혼용해서 지원

## ES6
- NodeJS 에서 사용하고자 할 경우 Babel과 같은 ES6 코드를 변환(transpile)해주는 도구를 사용
- export
```js
// 모듈 전체를 export, 파일내 한번만 사용가능하다.
var module = {};
export default module


// 모든 속성을 export
export *;


// 함수를 직접 export
export function moduleFunc() {};
var property = "some property";
export {property};
```
- import 
```js
// 모듈 전체를 import
import module
import module as myModule


// 모든 속성 import
import * from module


// 특정 멤버(함수 등)만 import
import {moduleFunc, moduleFunc2} from module
```
- ES 모듈만 불러올 수 있음 

## CommonJS
- NodeJS에서는 CommonJS를 기본 모듈 시스템으로 채택
- export
```js
// 모듈 전체를 export
module.exports = module

// 함수를 직접 export
exports.moduleFunc = function() {}
```
- import
```js
// 모듈 전체를 import
var module = require('./someModule.js')
```

## CommonJS vs ES6 import (&Export)
- require 는 작성된 순서를 지키지만, import 문은 맨 위에 있는 것과 같이 취급된다
- require 를 통해 코드를 바로 실행할 수 있지만, import 를 통해서는 module feature flag 를 사용해야 한다
- require 로 모듈화를 하고 싶다면 .js 로, import 로 모듈화를 하고 싶다면 .mjs 로 확장자를 지정해야 한다 

### 주의:
- require 문과 import 문을 같은 node 프로그램에서 동시에 사용할 수 없다.

### 참고자료
- [[javascript] require vs import (CommonJs와 ES6)](https://blueshw.github.io/2017/05/16/ES-require-vs-import/)
- [JavaScript- require vs import (CommonJs와 ES6) 차이점](https://hsp0418.tistory.com/147)