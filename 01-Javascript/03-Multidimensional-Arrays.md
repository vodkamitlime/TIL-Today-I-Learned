# Multidimensional Arrays

## 다차원 배열이란? 
- 배열 안에 배열이 담긴 형식의 객체이다. 
```js
let twod = [[1,2,3], [4,5,6], [7,8,9]]
let threed = [[1, [2,3] ], [4, [5,6] ], [7, [8,9] ]]
```

### 다차원 배열에 값 추가하기
- 접근하고자 하는 값의 인덱스를 순서대로 대괄호로 감싼 뒤에 값을 할당해주면 된다.
```js
twod[0] // [1,2,3]
twod[0][1] // 2
twod[0][1] = 'ha'
twod // [[1,'ha,3], [4,5,6], [7,8,9]]

threed[2] // [7, [8,9] ]
threed[2][1] // [8,9]
threed[2][1][0] // 8
threed[2][1][0] = 'hey'
threed // [[1, [2,3] ], [4, [5,6] ], [7, ['hey',9] ]]
```

### 배운 점 (=== 오늘의 삽질)
- 알고리즘을 풀던 중 다차원 배열을 새로 생성하여 값을 변경해주고자 했는데, 하나의 행에 접근하여 특정 값을 변경하면 나머지 행에도 동일한 변화가 적용된다는 사실을 발견했다. 
```js
const possibleValues = Array(board.length).fill(Array(board.length).fill(null))

possibleValues[0][3] = 'true'
possibleValues[0][3] // 'true'
possibleValues[1][3] // 'true'
possibleValues[2][3] // 'true'
```
- 위와 같은 방법을 적용하여 2차원 배열을 만든 뒤, 0번째 배열의 3번째 값을 변경해주면 1, 2, 3... n번째 배열의 3번째 값이 전부 'true' 로 변경되었다.
- (의아해하며 원인을 고민하고 약 30분 가량 삽질한 결과) 배열을 만들 때 동일한 참조값을 가진 배열로 채워주었기(fill) 때문이라는 사실을 깨달았다. 
	- JS는 배열을 생성 시 배열의 속성을 힙이라는 저장 공간에 담고, 해당 속성을 참조하는 참조값을 메모리에 담는다는 특성이 있다. 
	- 새로운 Array 를 만들 때 fill 을 활용하여 안에 어떠한 값으로 채울 것인지 정할 수 있는데, 나는 이 때 null 로 채워진 Array 로 1차원 배열을 채워주었다.
	- 이에 따라 1차원 배열 안에는 동일한 참조값을 가진 배열이 여러개 들어가게 되었고, 어떠한 배열에 접근하여 값을 수정하든 다른 배열들에도 동일한 결과가 적용되었던 것이다. 
- 이로써 다차원 배열을 만들 때는 Array.fill(Array) 를 사용하면 안된다는 깨우침을 얻었다.
```js
let possibleValues = new Array(9).fill(null);
possibleValues = possibleValues.map(el => Array(9).fill(null))

possibleValues[0][3] = 'true'
possibleValues[0][3] // 'true'
possibleValues[1][3] // null
possibleValues[2][3] // null
```
- 위와 같은 방법, 또는 다른 방법을 알아보고 활용하도록 하자. 

### 참고자료
