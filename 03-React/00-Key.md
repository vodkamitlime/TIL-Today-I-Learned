## React 와 리스트의 Key

### React 에서 Key란? 
- 엘리먼트 리스트를 만들 때 포함해야 하는 특수한 문자열 어트리뷰트이다.
- React가 어떤 항목을 변경, 추가 또는 삭제할지 식별하는 것을 돕는다.
```javascript
function NumberList(props) {
  return (
  	<ul className="test">
  		<li key='1'>1</ul>
  		<li key='2'>2</ul>
  		<li key='3'>3</ul>
  	</ul>
  	)
 }
````

### Key 의 특징은? 
- 고유한 값이어야 하며, 형제 노드인 다른 아이템과의 중복된 키 값은 허용되지 않는다.
- 컴포넌트의 구성요소로 전달되지 않는다. (따라서 props 에 key 가 포함되었다 해도 props.key 로 사용 불가하다)

### 주의할 점
- 컴포넌트 하나를 여러 차례 반복해서 나열할 경우 컴포넌트 자체가 하나의 list 가 된다.
- 이 경우, 컴포넌트 자체의 key 값을 변경해주어야 한다. 
```javascript
function ListItem(props) {
  // 맞습니다! 여기에는 key를 지정할 필요가 없습니다.
  return <li>{props.value}</li>;
}

function NumberList(props) {
  const numbers = props.numbers;
  const listItems = numbers.map((number) =>
    // 맞습니다! 배열 안에 key를 지정해야 합니다.
    <ListItem key={number.toString()} value={number} />
  );
  return (
    <ul>
      {listItems}
    </ul>
  );
}

const numbers = [1, 2, 3, 4, 5];
ReactDOM.render(
  <NumberList numbers={numbers} />,
  document.getElementById('root')
);
```

### 배운 점 :
- Component 가 listed item 처럼 나열될 경우 Key 를 작성해 줌으로써 고유성을 유지하도록 해줘야 한다. 


### 참고자료
[React 공식문서: List 와 Key](https://ko.reactjs.org/docs/lists-and-keys.html)

