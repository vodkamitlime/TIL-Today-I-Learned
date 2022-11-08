fun main() {
    var x: Int = 3 // Can be reassigned
    x = 4
    println("THe value of x is $x")

    val y: Int = 3 // val Cannot be reassigned
    val long = 3L // Long 타입
    val double = 3.333 // takes more memory, but also precise
    val float = 3.33f

    val bool = true
    val string = "str" // 쌍따옴표만 사용 가능

    val nullable: String? = null // nullable 처리
//    nullable!!.toInt() // !! 을 쓰면 null 이 아닐 것임을 명시하는 것
    nullable?.toInt() // ? 을 사용하면 null 이 아닌 경우에만 toInt 실행

    val one = nullable ?: 1 // ?: 는 앞이 null 이라면, 뒤를 할당
    val two = 2

    println(3/4) // 소수점 버림
    println(3f/4f) // 소수점 출력

    if(x == 2) {
        println("x is two")
    } else if(x == 3) {
        println("x is three")
    } else {
        println("It is neither")
    }

    val shopList = listOf<String>("iPad", "Pencil", "Shoes") // immutable list, element 추가하거나 삭제 불가
    println(shopList[0])

    val shopList2 = mutableListOf("macbook", "shampoo") // mutable list, element 추가, 삭제 가능
    shopList2.add("test2")
    shopList.add("test") // Unresolved reference: add
}