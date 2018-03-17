import java.text.DecimalFormat

data class Stack(val size: Int){
    val maxTop = size - 1
    val values = arrayOfNulls<Double>(maxTop)
    var top = -1
}

fun isEmpty(stack: Stack): Boolean{
    return stack.top == -1
}

fun isFull(stack: Stack): Boolean{
    return stack.top >= stack.maxTop
}

fun top(stack: Stack): Double?{
    if (isEmpty(stack)){
        println("The stack is empty!")
        return null
    }
    return stack.values[stack.top]
}

fun push(stack: Stack, x: Double): Boolean{
    if (isFull(stack)){
        println("The stack is full, push failed.")
        return false
    }
    stack.values[++stack.top] = x
    return true
}

fun pop(stack: Stack): Boolean{
    if (isEmpty(stack)){
        println("The stack is empty, pop failed.")
        return false
    }
    stack.top--
    return true
}

fun displayStack(stack: Stack){
    val df: DecimalFormat = DecimalFormat("#.##")
    print("Top --> ")
    if (isEmpty(stack)){
        println("|---------------|")
        return
    }
    System.out.printf("%-7s%-9s|\n", "|", df.format(stack.values[stack.top]))
    for (i in (stack.top - 1) downTo 0)
        System.out.printf("%8s%-7s%-9s|\n", "", "|", df.format(stack.values[i]))
    System.out.printf("%9s---------------|\n", "|")
}

fun destroyStack(stack: Stack){
    for (i in stack.values.indices){
        stack.values[i] = null
    }
}