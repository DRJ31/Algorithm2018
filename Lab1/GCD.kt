import java.util.*

fun compare(x: Int, y: Int, judge: Boolean): Int{//Return bigger number if true else smaller number
    if (judge)
        return if (x >= y) x else y
    return if (x <= y) x else y
}

fun GCD(x: Int, y: Int): Int{
    if (compare(x, y, false) == 0)
        return compare(x, y, true)
    return GCD(compare(x, y, false), compare(x, y, true) % compare(x, y, false))
}

fun main(args: Array<String>){
    val input = Scanner(System.`in`)
    var x: Int
    var y: Int
    while (true){
        print("Enter number x: ")
        x = input.nextInt()
        if (x >= 0)
            break
        println("Please input a natural number!")
    }
    while (true){
        print("Enter number y: ")
        y = input.nextInt()
        if (y >= 0)
            break
        println("Please input a natural number!")
    }
    println("The greatest common divisor of $x and $y is ${GCD(x, y)}")
}
