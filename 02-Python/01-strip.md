# Python 의 string.strip() 메서드

## 특징
- string 타입의 변수에 적용하여 양 끝의 공백을 제거할 수 있는 메서드이다.
```py
test = '   fighting    '
print(test)
print(test.strip()) 
#    fighting    
# fighting
```

## 배운 점
- 파이썬으로 알고리즘 풀다가 문자열 양 끝이 특정 글자나 기호일 경우 제거해야 한다는 것을 보고 방법을 고민하다가, 문득 strip() 메서드와 비슷해 보여 검색을 해 보니 strip() 안에 전달인자를 넣어 줄 수 있다는 사실을 알게 되었다. 
- strip() 안에 특정 문자 또는 문자의 집합을 문자열로 표기하여 실행할 경우, 문자열의 양 끝의 문자가 해당 집합에 포함될 때 제거된다. 
```py
test = '...fighting.'
print(test)
print(test.strip('.')) 
# ...fighting.
# fighting

test = 'a..b.fighting.a'
print(test)
print(test.strip('.a')) 
# a..b.fighting.a
# b.fighting
```

### 참고 자료:
- [w3 schools](https://www.w3schools.com/python/ref_string_strip.asp)