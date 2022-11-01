# Cookie & other error handling

## Path parameters 의 데이터 타입

### 에러 내용: 
- FE 에서 넘겨주는 path parameter 와 accessToken 의 payload 속 유저 Id 를 비교하는 과정에서 반복적으로 에러가 난 적이 있었다.
- 에러 코드는 401로, 권한이 없는 유저가 권한이 필요한 요청을 하게 될 경우 발생하는 에러였다. 

### 원인: 
- console 에 찍어 봐도 토큰 id 와 params id 가 같았는데, 다시 검토해 본 결과 path 
parameter 값은 무조건 문자열로 받아와진다는 점을 발견했다. 
- string 타입과 number 타입은 육안으로 보기에는 같아도 실제 값은 다르므로 계속 오류가 났던 것이었다. 

### 해결책:
- Path parameter 또는 query params 를 받아올 때 문자열이 아닌 다른 값은 타입 변환을 한 후 작업하면 된다.

## Hash password comparison

### 에러 내용:
- 백엔드에서 비밀번호를 해싱하여 저장하다보니, 프론트엔드 측에서 사용자 정보를 조회할 때 해싱된 비밀번호가 불러와졌다. 이 떄, 개인정보 수정을 하려면 비밀번호를 검토하는 단계가 있었는데, 사용자가 올바른 비밀번호를 입력했을 때 해싱값과 동일한지 검토하는 유효성 함수를 만들었다.
- 마이페이지에서 비밀번호 검토를 위해 텍스트 필드에 입력을 할 때마다 정보가 lagging 되어 느리게 입력되는 현상이 나타났다. 

### 원인:
- 비밀번호 유효성 검사를 위해 bcryptjs 모듈을 활용했는데, 해싱 값을 검사하는 메서드가 일반 문자열을 비교하는 함수보다 느리기 때문에 발생하는 일이었다. 

### 해결책: 
- debouncing 을 활용해, 사용자의 액션이 발생한 지 n 초 안에 새로운 액션이 발생하지 않을 경우에만 함수를 실행하도록 했다. 이번 경우 800 ms 을 기준으로 두어 사용자가 계속 정보를 입력하고 있을 때는 함수가 실행되지 않고, 완전히 멈춘 뒤에만 함수가 실행되도록 하였다. 

## res.clearCookie 

### 에러 내용:
- 사용자 개인정보 보호를 위해 로그아웃 시 쿠키에 저장된 access token 과 refresh token 을 삭제하려 했으나, res.cookie() 를 통해 쿠키의 내용을 빈 값으로 만드는 것도, 유효 시간을 0초로 하는 것도 작동하지 않았다.
- res.clearCookie 메서드를 찾아 사용해보았으나 여전히 로그아웃 시도 이후에도 쿠키가 삭제되지 않는 현상이 이어졌다.

### 원인:
- 원인은 공식문서 내용에서 찾을 수 있었다.
```md
Clears the cookie specified by name. For details about the options object, see res.cookie().

Web browsers and other compliant clients will only clear the cookie if the given options is identical to those given to res.cookie(), excluding expires and maxAge.
```

### 해결책: 
- 처음 쿠키 세팅을 할 때 사용했던 httpOnly, secure, crossOrign 등의 옵션과 동일한 내용의 옵션 설정을 추가해주었던 res.clearcookie 를 통해 정상적으로 쿠키를 삭제할 수 있었다. 



