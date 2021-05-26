# React 와 Life Cycle (생명주기)

## Life Cycle 이란?
- 컴포넌트가 브라우저상에 나타나고(Mount), 업데이트 되고(Update), 사라지는 일련의 과정을 칭한다. 
- 이러한 과정에서 호출되는 메서드를 Life Cycle Method 라고 부르며, 클래스형 컴포넌트에서만 사용할 수 있다. (함수형 컴포넌트는 React 16.8 버전부터 도입되었으며, 현재는 useState 나 useEffect로 더욱 많이 활용된다)
- 각 단계별로 호출되는 메서드의 순서와 종류가 다르다. 

1. Mount : DOM 에 엘리먼트를 넣는 작업이다.
	1. constructor
		- 컴포넌트 클래스의 생성자 함수이며, 컴포넌트가 생성될 때 호출되는 함수이다.
		- State와 다른 값들의 초기값을 지정할 때 사용한다.
		- props 를 매개변수로 받으며, super(props) 를 선언해주어 부모의 메서드를 상속받을 수 있도록 한다. 
	2. getDerivedStateFromProps
		- props 와 state 값을 동기화한다.
	3. render (필수)
		- 리액트 요소를 반환한다.
	4. componentDidMount
		- 컴포넌트를 생성하고 첫 렌더링이 끝났을 때 호출된다. 

2. Update : 컴포넌트의 state 나 props 에 변화가 생길 때이다.
	1. getDerivedStateFromProps
	2. shouldComponentUpdate
		- true 를 반환하면 컴포넌트를 리렌더링하며, false 를 반환할 경우 리렌더링을 진행하지 않고 아래의 나머지 함수들도 호출하지 않는다.
	3. render
	4. getSnapshotBeforeUpdate
		- 변경된 요소가 DOM 에 반영되기 전에 호출된다.
	5. ComponentDidUpdate
		- 리렌더링 후에 호출된다.

3. Unmount : 컴포넌트가 DOM 에서 제거될 때이다.
	1. componentWillUnmount
		- 컴포넌트가 제거되기 전에 호출된다. 

### 배운 점
- React 가 Class 형 컴포넌트에서 함수형 컴포넌트로 바뀌었지만 여전히 Life Cycle 관리가 가능하다는 글을 종종 봤었는데 그 의미를 정확하게 파악하게 되었다.
- 함수형 컴포넌트가 도입된지 얼마 되지 않았으므로 (현 React Version: 17.0.2 / 함수형 컴포넌트 도입 Version: 16.8) 클래스형 컴포넌트의 활용 방법 역시 알아두어야 할 것 같다. 

### 참고 자료
- [React 리액트 - 컴포넌트 생명 주기 (Component Life Cycle)](https://lktprogrammer.tistory.com/130)
- [W3Schools](https://www.w3schools.com/react/react_lifecycle.asp)