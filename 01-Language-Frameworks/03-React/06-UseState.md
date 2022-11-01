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

## 예제
```jsx
function someComponent(){
	const [arr, setArr] = useState([1,2,3])
	const [arr2, setArr2] = useState([4,5,6])

	function clicked() {
		arr.push(arr[arr.length-1] + 1)
	}

	function clickedRender(){
		setArr2([...arr2, 7])
	}
	return (
		<>
			<button onClick={() => clicked()}>
			{arr}
			</button>
			<button onClick={() => clickedRender()}>
			{arr2}
			</button>
		</>
		)
}
```
- 위의 예제에서 처음 화면에 표시되는 값은 두 개의 다른 상태인 [1,2,3] 과 [4,5,6] 이다.
- clicked() 함수는 직접 상태를 변경하고 있으므로 첫 번째 버튼을 아무리 눌러도 화면의 표시가 바뀌지 않는다. 화면 내 리렌더링을 명시하는 다른 요소가 작동할 경우에만 표시가 바뀐다.
- clickedRender() 버튼은 setState 함수인 setArr2를 통해 상태를 변경하고 있으므로 버튼을 누르는 즉시 렌더링이 되어 결과물이 출력된다. 

## 배운 점:
- console 에 변경된 상태값이 찍힌다고 해서 렌더링이 되었다는 의미는 아니다.

## 참고 자료
- [Why Not To Modify React State Directly](https://daveceddia.com/why-not-modify-react-state-directly/)
