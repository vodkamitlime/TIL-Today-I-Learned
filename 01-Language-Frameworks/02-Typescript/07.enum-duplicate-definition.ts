/**
 * TS enum 사용 시 주의할 점 하나: enum 은 중복 선언이 가능하다.
 * 하나의 모듈 안에서 동일한 이름을 갖는 enum 을 여러 번 선언하여 사용할 수 있는데,
 * 이 때 각 enum 안의 값들은 intersect 되듯 하나로 통합된다.
 */

enum Example {
  A = 1,
  B,
  C
}

enum Example {
  E = 1,
  F,
  G
}

console.log(Example.A === Example.E) // true 반환
console.log(Example) 
// {
  // "1": "E",
  // "2": "F",
  // "3": "G",
  // "A": 1,
  // "B": 2,
  // "C": 3,
  // "E": 1,
  // "F": 2,
  // "G": 3
// } 

/**
 * 원인: enum 은 TS 에서 객체를 enum 처럼 쓸 수 있도록 wrapping 해 준 sugar coat 에 가깝다.
 * 때문에 별도의 enum 타입을 갖는 것이 아니라, 객체일 뿐이다.
 * 위의 enum 선언 코드를 컴파일한 JS 코드를 까 보면 아래와 같다.
 */

"use strict";
var Example;
(function (Example) {
    Example[Example["A"] = 1] = "A";
    Example[Example["B"] = 2] = "B";
    Example[Example["C"] = 3] = "C";
})(Example || (Example = {}));
(function (Example) {
    Example[Example["E"] = 1] = "E";
    Example[Example["F"] = 2] = "F";
    Example[Example["G"] = 3] = "G";
})(Example || (Example = {}));
console.log(Example);

/**
 * 위의 JS 파일을 보면, Example 이라는 변수가 먼저 선언된 뒤, 
 * 첫 번째 함수 안에서 객체형 전달인자를 받아 객체에 key-value 값들을 지정해주고 있다.
 * 이때 전달인자로는 Example 값을 받게 되는데, 
 * 첫 번째 함수 실행 당시의 Example 변수에는 어떠한 값도 할당되지 않았으므로 빈 객체가 들어간다.
 * 하지만 두 번째 함수 실행 시점에는 Example 변수에 이미 객체가 할당되어 있으므로, Example 이라는 값이 인자로 전달된다.
 * 객체는 참조 타입이므로 전달인자로 받은 객체에 key-value 값들을 업데이트하면 해당 객체를 참조하는 모든 곳에서 동일한 수정사항이 발생하는 것처럼 보인다.
 * 위와 같은 간단한 이유 때문에 enum 중복 설정이 가능했다는 것을 알 수 있다.
 */