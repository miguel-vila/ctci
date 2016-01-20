
import scala.collection.mutable.Queue

def replace(str: Array[Char]): Unit = {
    val q = Queue.empty[Char]
    var i = 0
    val length = str.length
    while(i < length) {
        if(q.size > 0) {
            q.enqueue( str(i) )
            str(i) = q.dequeue
        }
        val c = str(i)
        if(c == ' ') {
            str(i) = '%'
            q.enqueue( str(i+1) )
            str(i+1) = '2'
            q.enqueue( str(i+2) )
            str(i+2) = '0'
            i = i + 3
        } else {
            i = i + 1
        }  
    }
}

def test(initial: Array[Char], expected: Array[Char]): Unit = {
    replace(initial)
    assert(initial.deep == expected.deep)
    println("OK")
}

test("H   ".toArray,        "H%20".toArray)
test("A B     ".toArray,    "A%20B%20".toArray)
test("A BC     ".toArray,   "A%20BC%20".toArray)
test("A BC  ".toArray,      "A%20BC".toArray)
test("ABC".toArray,         "ABC".toArray)
test(" ABC  ".toArray,      "%20ABC".toArray)