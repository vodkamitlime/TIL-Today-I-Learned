# HTTPS password

## HTTPS 와 평문 비밀번호
- HTTPS 는 HTTP 프로토콜의 암호화된 버전으로, 클라이언트와 서버간의 정보를 암호화하여 공유할 수 있도록 하는 SSL 과 같은 방식을 활용한다.
- 그렇다면 클라이언트에서 서버로 비밀번호와 같은 민감한 정보를 보낼 때, https 를 사용한다면 평문 그대로 보내도 될까? 

## HTTPS 와 평문 패스워드 
- https 를 사용하는지 여부와 DB 는 별개의 영역이라고 보아도 된다. 따라서 사용자의 비밀번호를 안전하게 "보관" 하기 위해서는 해싱이나 암호화를 적용하여 저장해야 한다.
- 그러나 https 를 사용하면 클라이언트에서 서버로 전송되는 패킷은 기본적으로 SSL 또는 TLS 로 암호화 되어 있다. 따라서 중간자가 패킷을 취득하거나 읽으려 해도, 복호화가 가능한 키를 가지고 있지 않은 이상 비밀번호를 읽거나 접근할 수 없다. 
- 혹여 패킷을 분해하여 비밀번호에 접근했다고 해도, 암호화된 비밀번호를 일반 비밀번호와 같이 서버와 데이터를 자유롭게 주고받는데 사용할 수 있다. 
- 따라서 https 에서의 비밀번호 암호화는 실익이 없다.
- 보안을 강화하고 싶다면 비밀번호를 암호화할 것이 아니라 SSL / TLS 연결을 자주 확인하고 공개키 또는 개인키가 안전하게 보호되도록 하는 것이 좋다. 

### 참고자료
- [HTTPS를 쓰면 패스워드를 평문으로 보내도 될까?](https://yoonhogo.github.io/blog/2020-09-08/HTTPS-plain-text-safety/)
- [Is it ok to send plain-text password over HTTPS? [duplicate]](https://security.stackexchange.com/questions/110415/is-it-ok-to-send-plain-text-password-over-https)