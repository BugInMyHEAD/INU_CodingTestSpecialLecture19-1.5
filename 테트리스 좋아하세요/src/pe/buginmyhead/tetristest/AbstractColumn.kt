package pe.buginmyhead.tetristest

abstract class AbstractColumn(
  height: Int
) {
  protected val array = BooleanArray(height)
  val size: Int
    get() = array.size
  var height = 0
    protected set
  operator fun get(index: Int) = array[index]
}