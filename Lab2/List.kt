data class Node(val data: Double){
    var next: Node? = null
}

fun isEmpty(head: Node?): Boolean{
    return head == null
}

fun insertNode(head: Node?, index: Int, x: Double): Node?{
    val insert = Node(x)
    if (index < 0){
        println("Please input a positive position!")
        return head
    }
    if (index == 0){
        insert.next = head
        return insert
    }
    var present = head
    for (i in 1 until index){
        if (present == null){
            println("Index $index out of range!")
            return head
        }
        present = present.next
    }
    insert.next = present?.next
    present?.next = insert
    return head
}

fun findNode(head: Node?, x: Double): Int{
    if (isEmpty(head))
        return 0
    var phead = head
    var pos = 1
    while (phead != null){
        if (phead.data == x)
            return pos
        phead = phead.next
        pos++
    }
    return 0
}

fun deleteNode(head: Node?, x: Double): Node?{
    if (isEmpty(head))
        return head
    var pos = 1
    var present = head
    var next = present?.next
    if (present?.data == x)
        return next
    while (present?.next != null){
        pos++
        if (present.next?.data == x){
            present.next = present.next?.next
            return head
        }
        present = present.next
    }
    return head
}

fun displayList(head: Node?){
    if (isEmpty(head)){
        println("The list is empty.")
        return
    }
    var phead = head
    print("${head?.data}")
    phead = phead?.next
    while (phead != null){
        print("->${phead.data}")
        phead = phead.next
    }
    println()
}