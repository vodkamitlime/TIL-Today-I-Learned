# UseState

## UseState 란?
- React의 Component 내의 상태를 지정해주고 관리해주기 위한 함수이다. 
```jsx
const [state, setState] = useState('')
```
- 여기서 state 는 상태가 담긴 변수가, setState 는 상태를 변경해주는 함수가 된다.

## UseState (setState)의 특징
- state 는 직접 수정되어서는 안되며, 반드시 setState 를 통해 수정되어야 한다.(또는 그러한 방식이 강권된다.)
- state 를 직접 수정해주거나 객체의 값 또는 속성을 수정해줄 수는 있으나, 직접 수정하게 될 경우 렌더링이 진행되지 않아 변동된 값이 즉각 적용되지 않는다. 
- setState 함수를 활용할 경우 렌더링이 이루어지기 때문에 변동된 값이 적용된다.

### 예제
```jsx
function someComponent(){
	const [arr, setArr] = useState([1,2,3])

	function clicked() {
		arr[1] = 
	}

	return (
		<>
			<button onClick={() => clicked(); clickedRender();}>
			</button>
		</>
		)
}
```