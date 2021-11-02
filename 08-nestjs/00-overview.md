# NestJS Overview

## Controller 
- 항상 모듈에 속함, @module 데코레이터 내에 controllers 배열을 포함하고 클래스 이름을 넣어야 함
- @Controller() 데코레이터 사용 
- CLI 명령어 `nest g controller cats`
- 데코레이터 괄호 () 안이 기본 path 가 됨 
- 세부 HTTP 요청은 메서드 데코레이터를 사용 ex) `@Get()` (이 역시 내부가 path 가 됨)
```ts
import { Controller, Get } from '@nestjs/common';

@Controller('cats')
export class CatsController {
  @Get()
  findAll(): string {
    return 'This action returns all cats';
  }
}
```
- host 옵션 사용하여 HTTP host 지정 가능
```ts
@Controller({ host: 'admin.example.com' })
export class AdminController {
  @Get()
  index(): string {
    return 'Admin page';
  }
}
```

### Response 상태 코드 
- 공식문서 발췌
```md
내장 메서드를 사용하면 요청 핸들러가 자바스크립트 객체 또는 배열을 반환할 때 자동으로 JSON으로 직렬화됩니다. 그러나 자바스크립트 기본 타입(예: string, number, boolean)을 반환하면 Nest는 직렬화를 시도하지 않고 값만 보냅니다. 이렇게 하면 응답처리가 간단해집니다. 값을 반환하기만 하면 Nest가 나머지 작업을 처리합니다.

또한 응답의 상태 코드는 201을 사용하는 POST 요청을 제외하고는 항상 기본적으로 200입니다. 핸들러 수준에서 @HttpCode(...) 데코레이터를 추가하여 이 동작을 쉽게 변경할 수 있습니다(참조: 상태 코드).

라메소드 핸들러 시그니처(예: findAll(@Res() response))에서 @Res() 데코레이터를 사용하여 삽입할 수 있는 라이브러리별(예: Express) 응답객체를 사용할 수 있습니다. 예를 들어 Express에서는 response.status(200).send()와 같은 코드를 사용하여 응답을 구성할 수 있습니다.
```
- 기본적으로 다 200 code, POST 만 201
- @HttpCode(204) 를 이용해 (예시) code 변경 가능 
- @Header() 를 이용해 커스텀 응답헤더 지정 

### Request object
- @Req() 데코레이터를 추가하여 요청객체에 액세스 가능, 대부분의 경우 안에 있는 속성도 데코레이터로 가져올 수 있음 (@Body(), @Query() 등)
- @Param() params 를 통해 :id 접근 가능 

### Asynchronicity
- NestJS 는 비동기 함수 지원, 모든 비동기 함수는 Promise 를 반환해야 함 

### Dto
- Class 로 지정하는 것이 좋음 (Interface 는 컴파일 중 제거되기 때문에 nest 런타임에서 참조 불가)


## Providers
- 