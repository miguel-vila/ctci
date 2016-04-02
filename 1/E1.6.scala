def rotate(matrix: Array[ Array[ Short ] ]): Unit = {
  val n = matrix.length
  for( i <- 0 to n -1 ) {
    assert(matrix(i).length == n)
    for( j <- 0 to i ) {
      val nw = matrix(     i      )(     j     )
      val sw = matrix( n - 1 - i  )(     j     )
      val se = matrix( n - 1 - i  )( n - 1 - j )
      val ne = matrix(     i      )( n - 1 - j )
      matrix(     i      )(     j     ) = ne
      matrix( n - 1 - i  )(     j     ) = nw
      matrix( n - 1 - i  )( n - 1 - j ) = sw
      matrix(     i      )( n - 1 - j ) = se
    }
  }
}

val m: Array[Array[Short]] = Array( Array(1,2,3), 
                                    Array(4,5,6), 
                                    Array(7,8,9) )
val e: Array[Array[Short]] = Array( Array(3,6,9), 
                                    Array(2,5,8), 
                                    Array(1,4,7) )