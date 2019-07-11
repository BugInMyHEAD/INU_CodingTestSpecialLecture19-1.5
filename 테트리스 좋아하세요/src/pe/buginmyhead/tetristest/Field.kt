package pe.buginmyhead.tetristest

class Field(
  width: Int,
  val height: Int
) {
  private val array = Array(width) { Column(height) }
  val width get() = array.size
  val ar
    get() = array.asList()

  fun forcePileUp(blockCreation: BlockCreation): Boolean {
    val subarray = array.slice(blockCreation.position until blockCreation.position + 4)
    return false
  }

  class Column(
    height: Int
  ) : AbstractColumn() {
    private val array = BooleanArray(height)
    override val height
      get() = array.size

    private fun draw(position: Int) {
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