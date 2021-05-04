## State

### State 란? 
- 컴포넌트 내에서 동적으로 변경되는 값이다.

### State 의 특징은?
- 컴포넌트 내부에서 제어(관리)된다. 
- State 업데이트는 비동기적(Asynchronous)이다.
  * DOM 은 State 가 변경될 때마다 re-rendering 되지 않는다.
  * 여러 차례의 setState 가 있다면 전부 통합하여 한 번에 re-rendering 한다. 
- State 를 props 로 자식 컴포넌트에 전달할 수 있다. (캡슐화 되었기 때문이다.)

### State 를 사용하는 방법은? 
- 함수형 컴포넌트에서는 useState 라는 훅(Hook)을 통해 사용할 수 있다.
  > "Hook" 이란? <br>
  > 함수형 컴포넌트에서 State 와 LifeCycle 기능을 사용할 수 있게 해 주는 컴포넌트이다. 
```jsx
import { useState } from 'react'

const Component = () => {

  const [ state, setState ] = useState('')

}
```
- useState 를 활용하여 state 의 초기값을 지정해줄 수 있다.
  * 초기값은 어떠한 자료형이든 될 수 있다. (문자열, 배열, 객체 등) 
- setState 는 state 를 갱신해주는 함수이며, 이를 통해서만 state의 값을 변경할 수 있다.


### 배운 점 :
- jsx 문법의 특징상, state 가 Boolean 값이어도 element 의 attribute value 로 전달되는 순간 문자열로 변환된다. 
- Boolean 값을 초기값으로 설정했다면 setState() 역시 state 를 Boolean 값으로 설정해준다. 
	> setState('') => false <br>
	> setState('a') => true 
- 비동기적이라는 특징으로 인해, 하나의 함수 내에서 변경한 state 를 바로 이어서 불러올 수는 없다. 

### 참고자료
[React 공식문서: State and Lifecycle](https://ko.reactjs.org/docs/state-and-lifecycle.html)

