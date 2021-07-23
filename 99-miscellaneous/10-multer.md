# multer

## multer 란?
- 파일 업로드를 위해 사용되는 multipart/form-data 를 다루기 위한 nodejs 미들웨어이다. 
- body 객체와 한 개 이상의 files 객체를 request 객체에 추가한다.
- 기본 사용 방법:
```js
var express = require('express')
var multer  = require('multer')
var upload = multer({ dest: 'uploads/' })

var app = express()

app.post('/profile', upload.single('avatar'), function (req, res, next) {
  // req.file 은 `avatar` 라는 필드의 파일 정보입니다.
  // 텍스트 필드가 있는 경우, req.body가 이를 포함할 것입니다.
})

app.post('/photos/upload', upload.array('photos', 12), function (req, res, next) {
  // req.files 는 `photos` 라는 파일정보를 배열로 가지고 있습니다.
  // 텍스트 필드가 있는 경우, req.body가 이를 포함할 것입니다.
})

var cpUpload = upload.fields([{ name: 'avatar', maxCount: 1 }, { name: 'gallery', maxCount: 8 }])
app.post('/cool-profile', cpUpload, function (req, res, next) {
  // req.files는 (String -> Array) 형태의 객체 입니다.
  // 필드명은 객체의 key에, 파일 정보는 배열로 value에 저장됩니다.
  //
  // e.g.
  //  req.files['avatar'][0] -> File
  //  req.files['gallery'] -> Array
  //
  // 텍스트 필드가 있는 경우, req.body가 이를 포함할 것입니다.
})
```

## Parameters
- `.single(fieldname)`
fieldname 인자에 명시된 이름의 단수 파일을 전달 받고, req.file 에 저장한다.
- `.array(fieldname[, maxCount])`
fieldname 인자에 명시된 이름의 파일 전부를 배열 형태로 전달 받는다.
- `.fields(fields)`
fields 인자에 명시된 여러 파일을 전달 받는다.

### 참고 자료 
- [공식문서](https://github.com/expressjs/multer/blob/master/doc/README-ko.md)