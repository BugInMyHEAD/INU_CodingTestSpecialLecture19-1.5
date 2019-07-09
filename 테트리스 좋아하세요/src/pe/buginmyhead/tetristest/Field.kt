package pe.buginmyhead.tetristest

class Field(
  val width: Int, val height: Int
) {
  private val arr = IntArray(width)
  val ar
    get() = arr.asList()

  fun pileUp(blockCreation: BlockCreation) {

  }
}