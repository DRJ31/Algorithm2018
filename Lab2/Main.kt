fun main(args: Array<String>){
    var head: Node? = null
    for (i in 0 until 5)
        head = insertNode(head, i, i.toDouble())
    displayList(head)
    for (i in 0 until 5)
        head = insertNode(head, 0, i.toDouble())
    displayList(head)
    for (i in 0..7 step 2){
        val idx: Int = findNode(head, i.toDouble())
        when(idx > 0){
            true -> println("$i is in position $idx.")
            false -> println("$i is not in the list.")
        }
    }
    head = deleteNode(head, 0.0)
    displayList(head)
}
