# Library & Framework

## Library 란? 
- 프로그램을 개발하는데 필요한 여러 기능을 활용할 수 있도록 묶어놓은 함수나 기능의 집합이다.
- 자주 활용하거나 필요한 기능을 편리하게 사용할 수 있도록 해준다. 
- 제어권이 개발자에게 주어진다.
- 예 : JS 의 React 와 jQuery, Python 의 numpy

> Library 와 Module 의 차이는?
>	> Module: 함수와 클래스, 변수가 스크립트로 이루어져어 있는 하나의 파일이자 객체. import 하여 사용할 수 있다. <br>
>	> Library 는 module 의 집합체로 불리기도 하나, 그 범위가 다양하여 개발에서는 같은 개념으로 사용되곤 한다.

## Framework 란?
- 프로그램을 개발하기 위한 구조를 제공하는 개발 환경이다. (& 그 자체로 Application 이다.)
- 자주 사용되는 여러 클래스 (변수와 함수의 묶음) 를 정해둔 흐름에 맞춰 쓸 수 있도록 지원해준다. 
- Application 을 완성할 수 있는 기본적인 뼈대를 제공해준다. 
- 예 : JS 의 Vue.js 와 Angular, Java 의 Spring, Python 의 Django

## Library vs Framework:
- IoC (Inversion of Control)
	- Library 를 사용할 때 제어권(control)을 가지고 있는 주체는 코드 작성자이다. 코드 작성 중 필요에 따라 Library 를 호출하기 때문이다. 
	- Framework 을 사용할 때는 Framerwork 가 제어권을 가지고 있다. 따라서 코드 작성자는 코드 위치, 코드 작성법 등 Framework 의 규칙을 따라야 한다. 
![IoC](https://media.geeksforgeeks.org/wp-content/uploads/framework-vs-library.png)

## 배운 점 :
- 지난 2주간 React가 Framework인줄 알고 작업했는데, React 는 Library 가 맞다. ([공식문서](https://ko.reactjs.org/)에도 "사용자 인터페이스를 만들기 위한 JavaScript 라이브러리"로 표기되어 있다.
	> 하지만 더 알아볼수록 React 는 Library 가 아닌 Framework 라고 주장하는 진영도 있다는 점을 발견했다. 실질적으로 활용되는 방식이 Framework 와 유사해서 그런 듯 하다. 

### 참고자료
- [[주간 인프런 #12] 뉴비를 위한 개발 용어 사전 (1)](https://www.inflearn.com/pages/weekly-inflearn-12)
- [Software Framework vs Library](https://www.geeksforgeeks.org/software-framework-vs-library/)
- [Why is React a library and not a (simple) framework?](https://dev.to/renannobile/why-is-react-a-library-and-not-a-simple-framework-1mle)
