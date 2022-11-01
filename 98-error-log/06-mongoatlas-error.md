# MongoDB ENODATA 에러

## 에러 내용
```js
{ Error: querySrv ENODATA _mongodb._tcp.dev.wazet.mongodb.net
    at QueryReqWrap.onresolve [as oncomplete] (dns.js:197:19)
  errno: 'ENODATA',
  code: 'ENODATA',
  syscall: 'querySrv',                        
  hostname: '_mongodb._tcp.dev.wazet.mongodb.net' 
```

## 원인
- 공용 네트워크를 사용하거나, 기타 다른 설정으로 인해 DNS 서버가 SRV 레코드를 반환하지 않는 경우에 발생한다. 
- DNS (Domain Name System) 은 도메인 이름을 IP 주소로 변환시켜주는 인터넷 전화번호부와 같다. 
- DNS SRV (service) 레코드 (record) 는 특정 서비스를 위해 구체적인 호스트와 포트 번호를 명시한다. 대부분의 DNS record 는 서버나 IP 주소만을 명시하지만, SRV record 가 포함되면 IP 주소의 포트 번호도 명시한다. 


## 해결책
- 연결되어 있는 네트워크를 변경하거나 +SRV 되어 있는 Connection String 으로 다시 연결을 시도한다.
