# MongoDB Atlas 에 모델이 바로 생성되지 않는 이유

## 고민 지점:
- Mongoose.model() 을 사용해 collection 을 여러개 만들었는데 서버 실행 시 mongoDB Atlas 에 몇 개의 컬렉션만 자동 생성됨
- 문제가 있는건가 살펴봤지만 생성되지 않는 collection 의 스키마에는 문제가 없었고, 시드를 넣을 때에야 비로소 collection 이 생성되는 것을 확인

## 원인
- mongoDB Atlas 에는 index 값 (unique 설정된 key) 가 있는 컬렉션만 자동 생성함 (DB 에서 index 설정은 미리 해두어야 하기 때문에 그런 것으로 보임)
- model 필드 설정만 해주면 모든 모델의 열을 생성해놓는 mysql 과는 다름. 이는 필드가 변경 불가능한 mysql 과 변경 가능한 nosql 의 특징 차이임 
- 이후 seed 넣을 때에서야 비로소 index 를 제외한 컬렉션의 나머지 key 값들이 생성되며, 이전에 index 가 없었던 모델도 이 때 생성됨