package pe.buginmyhead.tetristest

class Field(
  width: Int,
  val height: Int
) {
  private val array = Array(width) { Column() }
  val width
    get() = array.size
  val columns: List<AbstractColumn>
    get() = array.asList()

  fun forcePileUp(blockCreation: BlockCreation): Boolean {
    try {
      val zipped =
        array
          .copyOfRange(blockCreation.position, blockCreation.position + blockCreation.block.size)
          .zip(blockCreation.block)
      val positionToPile =
        zipped
          .map { it.first.height + it.second.height }
          .max()!! - 1
      zipped
        .forEach {
          it.first.pileUp(positionToPile, it.second)
        }
    } catch (exc: IndexOutOfBoundsException) {
      return false
    }
    return true
  }

  private inner class Column : AbstractColumn(height) {
    fun pileUp(position: Int) {
      if (position < height) {
        throw NoSuchElementException()
      }
      array[position] = true
      height = position + 1
    }

    fun pileUp(position: Int, abstractColumn: AbstractColumn) {
      for (i1 in abstractColumn.size - 1 downTo 0) {
        if (abstractColumn[i1]) {
          pileUp(position - i1)
        }
      }
    }
  }
}