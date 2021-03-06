# EC2 인스턴스 PORT

## EC2 란? 
- AWS (Amazon Web Services) 에서 제공하는 Compute Cloud, 즉 클라우드 컴퓨팅 용량이다. 클라우드 서버라고 생각하면 쉽다. 
- 장점: 확장 가능성이 높다. 물리적인 서버를 설치하면 서버의 부하나 필요 용량이 늘어나도 쉽게 수직적 확장을 할 수 없지만, AWS 에서 제공하는 인스턴스는 쉽게 주변 인스턴스와 연결되어 확장할 수 있다. 

## EC2 사용 시 주의사항 (오늘의 삽질)
- 로컬호스트에서 특정 port 로 서버를 연결한 후 그대로 ec2 인스턴스를 생성해 엔드포인트에 접속했으나 ERR_CONNECTION_REFUSED 에러가 뜨며 연결되지 않았다.
- ec2 ssh 연결을 통해 서버가 정상 작동하고 있는 것을 확인했기 때문에, 방화벽 (인바운드) 문제일 수밖에 없었다. 
- 인바운드 설정 시 기본으로 열려있는 포트인 SSH (22) 이외에 http (80), https(443) 만 추가로 열어주고, 로컬호스트에서 연결했던 port 번호는 열어두지 않아 발생했던 문제였다. 
	 - 인바운드 : AWS 보안그룹에서 외부에서 인스턴스로 들어오는 요청을 인바운드 요청이라고 한다. 
- 서버 포트를 80번으로 변경해 연결하니 정상 작동되는 것을 확인했다. 아마 서버를 처음 생성했던 포트를 연결해도 작동 되었을 것이라고 예상한다. 


### 참고 자료
- [EC2 보안그룹 설정](https://zamezzz.tistory.com/301)
- [how to open web server port](https://intellipaat.com/community/3700/how-to-open-a-web-server-port-on-ec2-instance)