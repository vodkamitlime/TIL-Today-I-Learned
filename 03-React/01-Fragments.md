## Fragment

### React.Fragment 란? 
- 컴포넌트의 리턴문 내부에서 별도의 노드를 추가하지 않고 여러 엘리먼트를 그룹화할 수 있도록 함
```jsx
const Component = () => {
  return (
    <React.Fragment>
      <OtherComponent / >
      <SomeOtherComponent / >
    </React.Fragment>
    )
}

```

### Fragments 의 특징은? 
- Key 를 전달할 필요가 없는 경우 빈 태그처럼 사용할 수 있다. 
```jsx
const Component = () => {
  return (
    <>
      <OtherComponent / >
      <SomeOtherComponent / >
    </>
    )
}
```
- Key 가 있다면 <React.Fragment> 를 명시해주어야 한다. 

### Fragments 의 장점은?
- React 문법 특성상 하나의 컴포넌트 당 하나의 엘리먼트만 반환할 수 있기에, 반환문을 div 나 여타 태그로 전체 엘리먼트를 감싸주어야 한다.
- 이는 불필요한 마크업을 유발하거나, HTML 자체가 렌더링되지 않도록 하는 문제를 야기한다. 
- Fragments 를 활용함으로써 이러한 문제를 방지할 수 있다. 

### 배운 점 :
- 엘리먼트가 너무 많아질 때는 최상단과 하단에 Fragments을 추가해 그룹화 하는 방법을 활용하는 것도 괜찮다. 
- map 과 함께 활용하면 매우 유용하다. 


### 참고자료
[React 공식문서: Fragments](https://ko.reactjs.org/docs/fragments.html#short-syntax)

