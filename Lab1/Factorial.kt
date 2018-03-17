import java.util.*

fun factorial(n: Int): Long{
    if (n > 1)
        return factorial(n - 1) * n
    return 1
}

fun main(args: Array<String>){
    val input = Scanner(System.`in`)
    var number: Int
    while (true){
        print("Enter a positive number: ")
        number = input.nextInt()
        if (number > 0)
            break
        println("Please enter a positive number!");
    }
    println("The factorial of $number is ${factorial(number)}")
}
