# Dependency Injection (의존성 주입)

## 의존성 주입이란?
- "의존성" 이란 서로에게 영향을 받는 두 개의 다른 객체 또는 값을 의미한다. 
```js
let obj = {
	test: 1
}

let obj1 = {
	test1: () => {
		return obj.test
	}
}
```
- "주입"이란 하나의 객체에게 영향을 줄 수 있는 요소를 외부에서 넣어주는 것을 의미한다. 
```js
class A {
	this.number = 1

	change(func) {
		this.number = func(this.number)
	}
}

let a = new class A()
let aa = a.change((n) => n * 2)
```
- 의존성 주입은 하나의 패턴이다. 모듈 안에서 의존성을 불러오거나 새로 만드는 것을 피할 수 있다.
- service
```js
const User = require('./User');

function UsersService(usersRepository) { // check here
  async function getUsers() {
    return usersRepository.findAll();
  }
  
  async function addUser(userData) {
    const user = new User(userData);
  
    return usersRepository.addUser(user);
  }
  
  return {
    getUsers,
    addUser
  };
}

module.exports = UsersService
```
- classes
```js
class UsersService {
  constructor({ usersRepository, mailer, logger }) {
    this.usersRepository = usersRepository;
    this.mailer = mailer;
    this.logger = logger;
  }

  async findAll() {
    return this.usersRepository.findAll();
  }

  async addUser(user) {
    await this.usersRepository.addUser(user);
    this.logger.info(`User created: ${user}`);
    await this.mailer.sendConfirmationLink(user);
    this.logger.info(`Confirmation link sent: ${user}`);
  }
}

module.exports = UsersService;

const usersService = new UsersService({
  usersRepository,
  mailer,
  logger
});
```
- 의존성들을 모아두는 곳 = container 

## 장점
- 재사용성
- 테스트에 용이
- 코드 단순화
- 종속적인 코드 수 절감
- 코드 가독성
- 외부 변경에 대한 민감도 절감 
- 유연성과 확장성은 향상
- 객체간의 의존관계를 설정

## 비교 코드 
- DI 없이 작성한 코드
```js
// team.js
var User = require('./user');

function getTeam(teamId) {
  return User.find({teamId: teamId});
}

module.exports.getTeam = getTeam;
```
- DI로 작성한 코드
```js
// team.js
function Team(options) {
  this.options = options;
}

Team.prototype.getTeam = function(teamId) {
  return this.options.User.find({teamId: teamId})
}

function create(options) {
  return new Team(options);
}
```


### 참고 자료
- [Dependency Injection in Node.js](https://blog.risingstack.com/dependency-injection-in-node-js/)
- [DI(의존성주입) in JavaScript ! [번역]](https://velog.io/@moongq/Dependency-Injection)