## String 

### Intro    
```c
char str[10] = "original";
str = "new"; // Error 
// str 은 주소인데, 데이터를 저장하려 하니 당연히 에러가 남
// 배열 원소 하나씩 바꿔주거나 str[1] = 'a';
// strcpy 사용 
```
    
### 입출력 stream (데이터 입출력 통로)
- 표준 standard stream
- Stdin 키보드 입력
- Stdout 출력
- Stderr 에러

### 대표 함수
- 문자 단위: int getchar, void putchar
- 줄 단위: char * gets, int puts

### EOF
- 파일의 끝을 표시하는 문자, 일반적으로 -1로 정의되어 있음
- OS 입장에서 표준 io 도 하나의 파일임
- Program < == buffer == > 입출력 장치
- 입출력을 버퍼에 보관했다가 특정 신호에 한 번에 전달
- I/O overhead decreased
- 입력된 문자열의 크기가 저장할 배열의 길이를 초과하는 경우 배열의 바깥에 쓰여지는 오류 == Buffer Overflow, Memory corruption

### 문자열 숫자 변환
- Sscanf 문자열에서 입력 받아서 변환해준다
- Atoi str → int
- Atof str → float

### 문자열 배열
- 2차원 char 배열
```c
// 문자열 배열은 2차원 char 배열
char strs[count_of_str][max_length_of_str]

char strs[3][6] = {"one", "two", "three"}; 

/**
메모리 구조
strs[0] o n e \0 _ _ 
strs[1] t w o \0 _ _
strs[2] t h r e e \0
*/

for (int i = 0; i < 3; i++) {
    printf("%s ", strs[i]);
}
```
- 문자열 상수는 text/code 영역에 저장되며 이를 가리키기 위해서는 포인터 사용
```c
char * strs[count_of_str]

char* strs[3] = { "first", "second", "third" };

for (int i = 0; i < 3; i++) {
    printf(" %s ", strs[i]); 
}
```t