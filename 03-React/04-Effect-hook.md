# Effect Hook

## Effect Hook 란?
- 컴포넌트 내부에서 Side Effect 를 수행할 수 있도록 해주는 hook 이다. 
	> Hook 이란?
	>	> 컴포넌트 내부의 생애주기와 상태를 관리할 수 있도록 돕는 함수이다. 내장 Hook 으로는 State hook, Effect hook 등이 있다. (특정 동작이 발생하면 자동으로 특정 행동을 하도록 하는 것이 Hook 이라고 보면 된다.)
- 컴포넌트 내에서 특정 부분에 변화가 생긴 뒤에 (혹은 렌더링 이후에) 지정한 효과(===콜백함수)를 실행한다. 

## 매개변수 (parameters)
- useEffect(callback, state) 함수는 두 개의 전달인자를 받는다.
- 첫 번째 전달인자는 callback 함수이다.
- 두 번째 전달인자는 의존성을 담은 배열로, 어떤 환경(또는 조건)에서 callback 함수가 실행될지를 지정해준다. 이 부분이 전달되지 않는다면 컴포넌트가 렌더링 될 때마다 callback 이 실행된다.
```jsx
useEffect(() => {
  console.log('test state에 대해서만 호출!')
}, [test])

// 해당 hook 의 경우, 컴포넌트 내 test 라는 state 에 변화가 생길 때만 console.log 함수가 실행된다. 
```
- 컴포넌트가 처음에 렌더링 될 때 한 번만 실행하고 싶은 경우, 두 번째 전달인자에 빈 배열을 넘기면 된다.
```jsx
useEffect(() => {
  console.log('처음 한 번만 실행!')
}, [])
```

## UseEffect 와 Cleanup
- UseEffect 함수의 callback 함수에서 또 함수를 return 할 수 있으며, 이를 cleanup 함수라고 한다. 
```jsx
useEffect(() => {
  console.log('update count1');

  return () => {
    console.log('update count1 or unmount');
  };
}, [count]);
```
- cleanup 함수의 특징은 새로운 상태로 인해 Effect 가 실행될 때, 이전의 값을 유지한 상태에서 실행된다는 점이다. 
```jsx
  useEffect(() => {
    console.log(count);

    return () => {
      console.log("cleanup" + count);
    };
  }, [count]);
``` 
- 예를 들어 count 가 0 에서 1로 변화할 경우, 콘솔창에는 'cleanup0', '1'가 순서대로 찍힌다. 이어서 count 가 1에서 2로 변화할 경우, 콘솔창에는 'cleanup1', '2'가 순서대로 찍힌다. 
- cleanup 함수는 최종적으로 component 가 제거되기 전 (unmount 할 때) 한 번 더 실행된다.

### Hook 사용 시 주의할 점?
- 컴포넌트 내부에 선언을 해 주어야 효과를 줄 수 있다. 
- 컴포넌트 최상단에 선언을 해 주어야 한다 (조건문이나 반복문 안에 선언하면 효과가 없다.)

### 배운 점:
- React 가 업데이트 되기 전 Class 형태였을 때 Hook 을 더욱 복잡하게 사용했던 것 같은데, 함수형 컴포넌트로 바뀐 덕분에 조금 더 직관적인 코드 작성이 가능하게 되었다.
- State 와 UseEffect 는 서로와 상호작용할 때 더욱 많은 시너지를 낼 수 있다. 

### 참고자료
- [React 공식문서](https://reactjs.org/docs/hooks-effect.html)
- [때늦은 React Hooks 시리즈 2탄 - useEffect](https://gist.github.com/ninanung/0ea87bc3d14ed8b1f9e7488561a4b910)
- [React Hooks: useState, useEffect 알아보기](https://junhobaik.github.io/react-hooks/)