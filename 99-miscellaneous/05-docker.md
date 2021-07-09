# Docker

## Docker 란?
- 리눅스의 응용 프로그램을 컨테이너 단위로 실행하고 관리하는 오픈 소스 컨테이너 기술이다.

## Docker vs VM (Virtual Machine) vs VE (Virtual Environment)
- 가상 환경은 로컬 PC 에 종속이 되므로 다른 환경에서 동일하게 사용할 수 없다.
- 가상 머신은 Hypervisor위에서 하나의 App 마다 각자의 Guest OS 가 실행이 되는데, 이 과정에서 많은 Overhead 가 발생한다.
	- Hypervisor: 호스트 컴퓨터에서 다수의 운영 체제를 동시에 실행할 수 있도록 하여 여러 가상 머신을 호스팅할 수 있는 프로그램이다. 
	- Overhead: 실행 시 처리 시간, 발생 메모리
- Docker 는 호스트의 OS 위에서 바로 실행되기 때문에 효율적으로 컴퓨팅 자원을 활용할 수 있다.

![docker vs vm](https://miro.medium.com/max/1400/1*wOBkzBpi1Hl9Nr__Jszplg.png)

## Docker 을 사용하는 이유
- 개발 환경 표준화
	- 개발자마다 운영 체제 및 개발 환경이 다를 수 있는데, 동일한 작업을 하기 위해 환경을 동일하게 설정해주려면 시간과 비용이 비효율적으로 소모된다.
	- Docker 는 특정한 환경을 얼려서 (캡쳐해서) 다른 OS 에서 그대로 사용할 수 있게 함으로써 개발 환경을 표준화한다. 

## 이미지와 컨테이너
- 하나 또는 여러 개의 프로그램으로 구성된 환경, 또는 이러한 환경에서 작동하고 있는 애플리케이션이 이미지이다.
- 이미지를 활용하여 만든 하나의 독립적인 환경이 컨테이너이다. 

## 배운 점:
- 클라이언트와 서버를 개발할 때 동일한 환경에서 개발하기 때문에 localhost 와 port 번호를 활용해 통신을 하는 경우가 많다. 그런데 서버와 클라이언트가 각각 다른 컨테이너에 올라가 다른 ip 주소를 할당받을 경우 localhost 로 더 이상 접속이 불가할 것이라고 생각했으며, 개별적으로 run 한 경우 이 사실이 맞다. 그러나 여러 개의 컨테이너를 하나의 네트워크에서 실행하게 해주는 docker compose 를 활용하면 이 문제를 해결할 수 있다.
- Docker Compose 는 하나의 디폴트 네트워크에 모든 컨테이너를 연결한다. yaml 파일이 위치한 디렉토리 이름 뒤에 `_default` 가 붙는다. 그리고 필요에 따라 다른 네트워크도 추가해줄 수 있다.
- Docker compose up 실행 시 먼저 네트워크를 생성해놓고 각 컨테이너를 구동한 후 네트워크에 연결시킨다. 

### 참고 자료:
- [도커 컨테이너와 가상머신, 가상환경](https://jhleed.tistory.com/199)
- [Docker Compose 네트워크](https://www.daleseo.com/docker-compose-networks/)
- [Networking in Compose](https://docs.docker.com/compose/networking/)