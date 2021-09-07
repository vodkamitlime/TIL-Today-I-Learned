// 15. Node 에서의 this 

// Nodejs 파일 실행하면 this는 빈 객체임 {} 
// window 와 document 는 Node 에 없는 객체이기 때문
console.log(this)

// Nodejs 파일 안에서의 this 는 module.exports 임. 
// module.exports 는 파일을 모듈로 사용할 수 있도록 해주는 빈 객체임 
console.log(this, module.exports, exports);
console.log(this === module.exports);
console.log(this === exports);
console.log(module.exports === exports);

// 그러나 nodejs 파일의 this 와 global 은 다름. 
console.log(this === global)

// 지역 변수 안에서의 this 는 module.exports 와는 다름
// 지역 변수 안에서의 this 는 global 과 같음
function a() {
    console.log('a function')
    console.log(this)
    console.log(module.exports)
    console.log(global)
}
a()

// Node 의 전역 객체는 즉 global 이 맞음
// 파일 안에서 this 가 빈 객체가 되는 이유는, 해당 코드 역시 하나의 함수 안에서 실행되기 때문임  
// 즉 하나의 모듈이기 때문에 Local scope를 갖게 됨...
// node --inspect-brk 실행 후, 크롬 개발자 도구에서 node 열기
// 보면 이 코드 전체가 하나의 function () { // 여기 안에 들어가있음}
// 그리고 해당 function 의 전달인자로 exports, require, module, __filename, __dirname 이 들어옴

// 출처: https://www.zerocho.com/category/NodeJS/post/5b67e8607bbbd3001b43fd7b
// 출처: https://youtu.be/jWllMubtfPQ