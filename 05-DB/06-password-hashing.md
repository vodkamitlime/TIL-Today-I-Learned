# Password hashing

## 해싱 vs 암호화
- 해싱과 암호화 모두 서비스의 보안을 향상시키기 위해 필요한 암호화 수단이다.
- 해싱은 단방향으로 이루어지며 복호화 (decryption)이 불가능하다.
- 암호화(encryption)는 양방향으로, 복호화도 가능하다. 

## 단방향 해싱
- 단방향 해시 함수는 알고리즘을 통해 기존 데이터를 다른 데이터로 변환시킨다. 복화화를 할 수 없으며, 해시 값을 통해 원본 데이터를 구할 수 없다. 
- 대표적인 알고리즘으로 SHA, MD, HAS, WHIRLPOOL 등이 있다. 
	- MD : Message-Digest Algorithm, 메세지 축약 알고리즘
	- SHA : Secure Hash Algorithm, 안전한 해시 알고리즘 (SSL, TLS 등 여러 보안 프로토콜에서도 사용됨)

### 단방향의 문제점
- 원본에 대한 해시 값이 항상 같은 결과를 내기 때문에 다이제스트 (암호화된 메세지) 을 모아놓은 레인보우 테이블 (Rainbow Table) 을 활용하여 원본 데이터를 복호화 할 수 있다. 
- 즉, 많은 사용자들이 쓰는 패스워드는 해시 값 역시 동일하기 때문에 해커들 또는 중간 공격자들이 여러 값을 대입해봄으로써 원본 값을 쉽게 유추할 수 있다. 

### 단방향의 해결 방법
- 스트레칭: 동일한 해시 함수를 여러 차례 실행하면 해시 값이 몇 차례 바뀌고, 이 횟수는 개발자만 알고 있기 때문에 보안을 조금 증진할 수 있다. 
- 솔트: 임의의 문자열인 솔트 (Salt) 값을 활용하여 패스워드와 함께 해싱함으로써, 원본 값을 해독하는 것을 어렵게 만들 수 있다. 
	- 32비트 이상의 문자열로, 사용자마다 다른 값이 부여된다. 
- 위 두 가지 방법을 함께 사용함으로써 보안을 높일 수 있다. 
	
![해시 솔트](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FIXlg8%2FbtqEninP4Tk%2FWX8MQoYGMlWVufAcoHJAZk%2Fimg.png)

## 배운 점
- 보안은 서비스의 생명이자 안전망이라고도 할 수 있다. 법적인 쟁점에 휘말리지 않기 위해서라도, 그리고 서비스를 사용하는 사용자들이 서비스를 신뢰할 수 있도록 하기 위해서라도 (백엔드로서) 보안에 더 신경을 기울여야 할 것이다.

### 참고 자료
- [패스워드 암호화와 저장](https://st-lab.tistory.com/100)
- [비밀번호와 Hash](https://ktko.tistory.com/entry/%EB%B9%84%EB%B0%80%EB%B2%88%ED%98%B8%EC%99%80-Hash%ED%95%B4%EC%8B%9C)