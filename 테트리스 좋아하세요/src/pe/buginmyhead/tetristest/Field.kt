package pe.buginmyhead.tetristest

class Field(
  val width: Int, val height: Int
) {
  private val array = IntArray(width)
  val ar get() = array.asList()

  fun pileUp(blockCreation: BlockCreation) {

  }

  private class Column(
    height: Int
  ) {
    private val array = BooleanArray(height)
    val height get() = array.size
    var highestBlockPosition = 0

    fun draw(position: Int) {
      if (array[position]) {
        throw NoSuchElementException()
      }
      array[position] = true
      if (position > highestBlockPosition) {
        highestBlockPosition = position
      }
    }
  }
}