package pe.buginmyhead.tetristest

/**
 * A wrapper for BooleanArray to make immutable
 */
abstract class AbstractColumn(
  height: Int
) {
  protected val array = BooleanArray(height)

  /**
   * The maximum height
   */
  val size: Int
    get() = array.size

  /**
   * The lowest position you can pile up a block piece
   */
  var height = 0
    protected set

  operator fun get(index: Int) = array[index]
}