import scala.collection.mutable.Queue

def compress(str: String): String = {
    val counts = Queue.empty[(Char,Int)]
    var lastChar = str(0)
    var charCount = 1
    var i = 1
    var allCountsAreOne = true
    while( i < str.length ) {
        var c = str(i)
        if(c == lastChar) {
            charCount = charCount + 1
            allCountsAreOne = false
        } else {
            counts.enqueue(lastChar -> charCount)
            lastChar = c
            charCount = 1
        }
        i = i+1
    }
    counts.enqueue(lastChar -> charCount)
    if(allCountsAreOne) {
        str
    } else {
        val sb = new StringBuilder()
        while(!counts.isEmpty){
            val (char,count) = counts.dequeue
            sb.append(s"$char$count")
        }
        sb.toString
    }
}

def test(initial: String, expected: String) = {
    assert(compress(initial) == expected)
    println("OK")
}

test("aabcccccaaa", "a2b1c5a3")
test("abcd", "abcd")
test("abcdd", "a1b1c1d2")
test("aaaaabcdd", "a5b1c1d2")