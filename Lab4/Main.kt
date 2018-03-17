fun main(args: Array<String>){
    val value: Double?
    val queue: Queue = createQueue(5) ?: return
    println("Enqueue 5 items.")
    for (i in 0 until 5)
        enqueue(queue, i.toDouble())
    println("Now attempting to enqueue again...")
    enqueue(queue, 5.0)
    displayQueue(queue)
    value = dequeue(queue)
    println("Retrieved element = $value")
    displayQueue(queue)
    enqueue(queue, 7.0)
    displayQueue(queue)
    destroyQueue(queue)
}
