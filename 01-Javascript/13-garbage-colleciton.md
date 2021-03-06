# Garbage Collection

## Garbage Collection 이란?
- 자바스크립트에서 사용되는 모든 원시값과 객체는 메모리를 차지하는데, 이 모든 것이 항상 유효하지는 않다. 
- 메모리가 오래 사용되지 않을 때 자바스크립트는 도달 가능성(reachability) 라는 개념을 활용하여 메모리 관리를 수행하는데, 이렇게 메모리 관리를 통해 객체를 모니터링하고 불필요한 객체를 삭제하는 것을 가비지 컬렉션이라고 한다. 

## 도달 가능성
- 자료형이 어떻게든 접근 가능하거나 사용할 수 있는 상태에 놓여 있으면 "도달 가능"하다고 표현하며, 도달 가능한 값은 메모리에서 삭제되지 않는다.
- 전역 변수, 현재 함수의 지역 변수와 매개변수 등은 루트(root)라고 불리우며 도달 가능하다.
- 루트가 참조하는 값 또는 체이닝을 통해 참조할 수 있는 값은 도달 가능한 값이다. 
- 예시)
```js
let user = {name: "John"}
// 메모리에 user 원시값, {name: "John"} 참조값 저장

user = null;
// user 에 null 재할당하므로 {name: "John"} 은 도달할 수 없는 상태가 됨 
// 가비지 컬렉터는 이를 삭제함 (John 에 저장된 데이터까지)
```

## 작동 알고리즘
- 가비지 컬렉션은 mark-and-sweep 이라는 알고리즘으로 인해 작동한다.
1. root 정보 수집하고 기억(mark) 함
2. root 가 참조하고 있는 모든 객체를 방문하고 이를 mark 함
3. mark 된 모든 객체에 방문, 객체들이 참조하는 객체도 mark 함
4. 모든 도달 가능한 객체를 방문할 때까지 반복
5. mark 되지 않은 객체 메모리에서 삭제 

### 최적화 기법
1. Generational Collection(세대별 수집) : 새로 생긴 객체일수록 역할을 다할 가능성이 높기 때문에 더 많이 감시하고, 오래 살아남은 객체는 덜 감시
2. Incremental Collection(점진적 수집) : 컬렉션을 여러 부분으로 분리하여 별도로 수행함으로써 작업을 분리하고 지연 시간을 줄임 
3. Idle-time Collection(유휴 시간 수집) : CPU 가 유휴 상태일 때만 실행 

## 배운 점:
- js 의 가비지 컬렉션은 dfs 알고리즘과 상당히 유사하게 작동한다. 알고리즘을 공부해야 하는 필요성이 여기서도 나타난다.
- 가비지 컬렉션이 작동하는 방식을 알아야 메모리 관리를 효율적으로 할 수 있을 것이다.

### 참고 자료
- [가비지 컬렉션](https://ko.javascript.info/garbage-collection)