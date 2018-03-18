import java.text.DecimalFormat

data class Node(val data: Double){
    var next: Node? = null
}

data class Stack(val size: Int){
    val maxTop = size - 1
    var head:Node? = null
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
    return stack.head?.data
}

fun push(stack: Stack, x: Double): Boolean{
    if (isFull(stack)){
        println("The stack is full, push failed.")
        return false
    }
    val newNode = Node(x)
    newNode.next = stack.head
    stack.head = newNode
    stack.top++
    return true
}

fun pop(stack: Stack): Boolean{
    if (isEmpty(stack)){
        println("The stack is empty, pop failed.")
        return false
    }
    stack.head = stack.head?.next
    stack.top--
    return true
}

fun displayStack(stack: Stack){
    val df = DecimalFormat("#.##")
    print("Top --> ")
    if (isEmpty(stack)){
        println("|---------------|")
        return
    }
    System.out.printf("%-7s%-9s|\n", "|", df.format(stack.head?.data))
    var next = stack.head?.next
    while (next != null) {
        System.out.printf("%8s%-7s%-9s|\n", "", "|", df.format(next.data))
        next = next.next
    }
    System.out.printf("%9s---------------|\n", "|")
}

fun destroyStack(stack: Stack){
    var next = stack.head?.next
    while (stack.head != null){
        stack.head = null
        stack.head = next
        next = stack.head?.next
    }
}