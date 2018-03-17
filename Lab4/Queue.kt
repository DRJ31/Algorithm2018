import java.text.DecimalFormat

data class Queue(val maxSize: Int){
    val values = arrayOfNulls<Double>(maxSize)
    var front = 0
    var rear = -1
    var counter = 0
}

fun createQueue(size: Int): Queue?{
    if (size <= 0){
        println("Please use valid size which is bigger than 0")
        return null
    }
    return Queue(size)
}

fun isEmpty(queue: Queue): Boolean{
    return queue.counter == 0
}

fun isFull(queue: Queue): Boolean {
    return queue.counter >= queue.maxSize
}

fun enqueue(queue: Queue, x: Double): Boolean{
    if (isFull(queue)){
        println("Error: The queue is full, enqueue failed.")
        return false
    }
    queue.rear = (queue.rear + 1) % queue.maxSize
    queue.values[queue.rear] = x
    queue.counter++
    return true
}

fun dequeue(queue: Queue): Double?{
    if (isEmpty(queue)){
        println("Error: The queue is empty, dequeue failed.")
        return queue.values[queue.front]
    }
    queue.front = (queue.front + 1) % queue.maxSize
    queue.counter--
    when (queue.front == 0){
        true -> return queue.values[queue.maxSize - 1]
        false -> return queue.values[queue.front - 1]
    }
}

fun displayQueue(queue: Queue){
    val df: DecimalFormat = DecimalFormat("#.##")//Format Decimal numbers
    System.out.printf("front -->%8s\n", df.format(queue.values[queue.front]))
    if (queue.front > queue.rear){
        for (i in (queue.front + 1) until queue.maxSize){
            System.out.printf("%17s\n", df.format(queue.values[i]))
        }
        for (i in 0 until queue.rear){
            System.out.printf("%17s\n", df.format(queue.values[i]))
        }
    }
    else{
        for (i in (queue.front + 1) until queue.rear){
            System.out.printf("%17s\n", df.format(queue.values[i]))
        }
    }
    System.out.printf("%17s%17s\n", df.format(queue.values[queue.rear]), "<-- rear")
}

fun destroyQueue(queue: Queue){
    for (i in queue.values.indices){
        queue.values[i] = null
    }
}