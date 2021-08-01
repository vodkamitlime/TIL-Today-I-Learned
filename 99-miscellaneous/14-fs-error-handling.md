# ENOTEMPTY, ENOENT 에러

## 에러 내용
- 비어 있지 않은 폴더 경로 (디렉토리) 를 사용하고자 할 때 fs.rmdirSync 메서드를 사용했는데, 이 때 제목과 같은 에러가 발생하곤 했다.
- 에러의 내용은 각각 directory is not empty 또는 directory is not a file 을 의미하는 에러였으며, 메서드에 recursive 옵션을 부여해도 동일한 에러가 발생했다 (알고보니 해당 옵션은 deprecated 되었다고 한다.)

## 원인
- 말 그대로 폴더가 파일이 아니거나 비어 있지 않아서 발생하는 에러였다. fs.rmdirSync 의 옵션을 더욱 세세하게 주거나 다른 fs 메서드를 활용할 수 있었다.

## 해결책
- fs.rmdirSync(recursive, force, maxretries) 등의 옵션도 함께 줄 수 있다.
- 또는 반복문을 활용해 fs.unlink 메서드와 함께 폴더 내의 파일들은 먼저 전부 비울 수 있다. 
