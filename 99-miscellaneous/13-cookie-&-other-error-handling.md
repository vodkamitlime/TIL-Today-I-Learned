params.나 query 숫자면 꼭 타입 변환

debouncing 

localstorage (client)

clearCookie
처음 쿠키 세팅값과 같아야 함 

Clears the cookie specified by name. For details about the options object, see res.cookie().

Web browsers and other compliant clients will only clear the cookie if the given options is identical to those given to res.cookie(), excluding expires and maxAge.

res.cookie('name', 'tobi', { path: '/admin' })
res.clearCookie('name', { path: '/admin' })


fs 모듈 맥에서는 잘 되는데 우분투에서는 안됨 
왜 ? 
-> npm, node 문제였다 maybe?
