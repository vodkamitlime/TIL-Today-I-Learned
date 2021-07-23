# multer-2

## Multer 에서 파일명 지정하는 방법 
- multer middleware 의 storage 를 만들 때 filename 에서 업로드하는 파일명을 지정해줄 수 있다. 
- 이 때 업로드 되는 file 객체를 활용하면 다양한 방법으로 파일명을 수정해서 업로드할 수 있다. 
- file 객체 예시: 
```js
 {
    "fieldname": "image",
    "originalname": "profile.jpeg",
    "encoding": "7bit",
    "mimetype": "image/jpeg",
    "destination": "uploads/profile",
    "filename": "profile_49925.jpeg",
    "path": "uploads/profile/profile_49925.jpeg",
    "size": 529624
}
```
- `mimetype.slice('/')[1]` 를 활용하면 파일 확장자를 따로 Parsing 할 수 있다. 
- fieldname 을 활용하여 파일을 분류하여 저장할 수 있다. 
- file.filename 을 활용하면 원본 파일명 그대로 저장된다. 

## 주의할 점: 
- filename 을 따로 설정하지 않는다면 확장자가 포함되지 않은 이진 (binary) 파일이 저장된다. 
- 이 때, 파일명은 무작위로 부여된 값이 된다. 
