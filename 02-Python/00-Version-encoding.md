# Python Version Encoding

## Encoding 이란?
- 자연어(인간의 언어)의 문자열을 컴퓨터가 이해할 수 있는 바이트 시퀀스로 변환하는 규칙을 의미한다. 
- 인코딩 된 부호를 다시 복호화하여 본래 문자나 기호로 표현하는 작업을 디코딩(decoding)이라고 한다.
- Character Set (문자표) 를 통해 Encoding 되는 값을 확인할 수 있다. 

### Character Set (문자표)란?
- 정보를 표현하기 위한 글자나 기호들의 집합이다.
- 문자와 숫자를 1:1로 매칭시킨 표를 의미하기도 한다.
<br>
예시 이미지) 
![ASCII](https://www.google.com/url?sa=i&url=https%3A%2F%2Fbournetocode.com%2Fprojects%2FGCSE_Computing_Fundamentals%2Fpages%2F3-3-5-ascii.html&psig=AOvVaw2_j0byXWEfNR2eu92jGQj1&ust=1620637534519000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCODXhbefvPACFQAAAAAdAAAAABAJ)

## Python Version 별 기본 Encoding
- Version 2+: ASCII 
	- ASCII: American Standard Code for Information Interchange
- Version 3+: Utf-8 (Unicode Transformation Format)
	- Unicode: 전 세계의 모든 문자를 컴퓨터에서 일관되게 표현하고 다룰 수 있도록 설계된 표준
- 따라서 Python Version 2에서 별다른 명시 없이 파일을 실행할 경우, 영문이 아닌 언어로 작성된 변수나 문자열에 대한 올바른 디코딩 작업이 이루어지지 않게 된다.


### Reference:
- [유니코드](https://ko.wikipedia.org/wiki/%EC%9C%A0%EB%8B%88%EC%BD%94%EB%93%9C)
- [유니코드 HOWTO](https://docs.python.org/ko/3/howto/unicode.html)
