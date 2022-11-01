# Redux

## Redux 란?
- JS 앱을 위한 상태관리 컨테이너이다. 

## Redux 의 특징
- 예측가능성: 일정하게 작동하는 앱을 작성하도록 도우며, 다를 환경에서도 실행 가능하도록 한다. 
- 중앙화: 상태가 전역으로 관리될 수 있도록 중앙으로 모아준다. 
- 디버깅: 상태 로깅이 가능하여 어디에서 에러가 났는지 확인을 쉽게 할 수 있다. 
- Flexible: 다양한 UI 계층에 적용 가능하다. 

## React-redux
- React 내에도 상태관리를 돕는 useState hooks 가 존재하나, 이는 컴포넌트 하나 내부의 상태를 생성하고 관리할 때 가장 용이하다. 하나의 컴포넌트의 상태에 나머지 (전역) 컴포넌트가 의존하게 될 경우 상태를 일일이 전달해야 하는 어려움이 생기는데, 이를 해소하기 위해 Redux 를 사용할 수 있다. 

## 기본 개념
1. Action
- 앱의 상태 저장소 (store) 에 data 를 보내는 방법이다. 
- 기본적으로 객체 형태이며, 문자열 type 과 text 또는 payload 가 함께 return 된다. 
- 상태를 변경할 행동(과 내용)을 정의하는 것이다. 
```jsx
const ADD_TODO = 'ADD_TODO'

function addTodo(text, quantity){
	return {
		type: ADD_TODO,
		text, 
		quantity
	}
}
```
2. Reducer
- action 의 type 에 따라 변화된 state 를 반환하게 된다. 
```jsx
function todoApp(state = initialState, action) {
  switch (action.type) {
  	case ADD_TODO:
  		return Object.assign({}, state, {
  			newitem: action.text
  			})
  	case 'DELETE_TODO':
  		console.log('delete!')
  		break;
  	case 'SOMETHING':
  		return [...state, 'new something!']
  default:
  	return state
  }
 }
```
3. Store
- reducer 를 저장하는 객체이다. (전체 어플리케이션에 하나만 존재한다.)
- store 를 생상하고 reducer 를 연결하면 앱에 연결하게 된다. 
```jsx
import { createStore } from 'redux';
import todoApp from './reducers';

let store = createStore(todoApp);
```

![Redux flow](https://이듬.run/react-master/images/simple-redux.jpg)

## View 에서 State 사용하기
1. useSelector() Hooks
- 컴포넌트가 렌더될 때마다, 그리고 action 이 dispatch 될 때마다 실행된다. 
2. useDispatch() Hooks
- 리듀서에 action 을 담아 전달하는 역할을 한다.

## 배운 점:
- Action-Reducer-Store 의 흐름을 명확하게 이해하게 되었다.

## 참고 자료
- [React-Redux Hooks](https://react-redux.js.org/api/hooks)