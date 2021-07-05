# Image

## Img tag 란? 
- 이미지를 불러올 수 있는 HTML 태그를 의미하며, DOM을 통해서도 작동 가능하다.
- React 에서의 img 태그는 기본적으로 HTML 태그와 동일한 attribute 를 가지며, class 만 className (리액트 문법) 으로 변경하여 지정해주면 된다.
```HTML
<img src='mintchoco.jpg' className='mintlover' />
```

## React 에서 이미지 불러오기:
- 웹 url 을 통해 이미지를 불러오고자 한다면 src='###' 안에 url 을 문자열로 작성해주면 된다. 
- 로컬 디렉토리에 저장되어 있는 이미지를 불러오고자 한다면 
1. React App 의 Public 폴더 내에서 불러오는 방법
2. 상대 경로와 import문을 활용하여 불러오는 방법 
두 가지가 있다. 

## 방법 1 ) Public 폴더 내에서 불러오기
- React App 최초 생성 시 App 의 root(최상위) 경로에 Public 폴더가 자동 생성된다.
- React 서버의 기본 경로는 바로 이 Public 폴더이다. 
- 따라서 파일을 Public 폴더 안에 저장하면, 별도의 import 문 없이 바로 경로를 활용하여 이미지를 불러올 수 있다. 
```jsx
// Public 폴더 안에 'mintchoco.jpg'가 있는 경우
<img src='mintchoco.jpg' />

// Public 폴더 안에 Dessert 폴더를 만들고, Dessert 폴더 안에 'mintchoco.jpg'가 있는 경우
<img src='/Dessert/mintchoco.jpg' />
```

## 방법 2 ) 상대 경로와 import 활용하기
- 이미지 파일 역시 여타 컴포넌트와 같은 '파일'이기 때문에, import 문을 활용하여 이미지를 불러올 수 있다. 
- Public 폴더가 아닌 다른 경로에 파일을 저장했다면, 코드를 작성하는 파일을 기준으로 경로를 입력해주어야 한다. 
```jsx
// src/Pages/Drink/mintchoco.jpg 가 파일이 저장된 경로이며, 
// src/Pages/Component.js 에서 코드를 작성하는 경우

import mintchoco from './Drink/mintchoco.jpg'

const Component = () => {
	return 
	<div>
	<h1>Happy Minchodan!</h1>
	<img src={mintchoco} />
	</div>
}
```

## 배운 점 :
- 이미지를 Public 폴더에서 불러올 경우, Public 폴더보다 상위 경로로 벗어나는 상대 경로는 활용할 수 없다. 
- import 문을 사용할 경우 경로값이 고정되어 편하지만, 여러 장을 한 번에 불러오기엔 번거롭다는 단점이 있다.


### 참고자료
[Using the image tag in React](https://daveceddia.com/react-image-tag/)

