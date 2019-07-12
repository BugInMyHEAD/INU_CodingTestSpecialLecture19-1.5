package pe.buginmyhead.tetristest

enum class Block(
  m00: Boolean, m01: Boolean, m02: Boolean, m03: Boolean,
  m10: Boolean, m11: Boolean, m12: Boolean, m13: Boolean
) : Iterable<AbstractColumn> {
  A(
    true,  true,  true,  true,
    false, false, false, false
  ),
  B(
    true,  true,  true,  false,
    false, true,  false, false
  ),
  C(
    true,  true,  false, false,
    true,  true,  false, false
  ),
  D(
    true,  true,  false, false,
    false, true,  true,  false
  ),
  E(
    false, true,  true,  false,
    true,  true,  false, false
  ),
  F(
    true,  true,  true,  false,
    false, false, true,  false
  ),
  G(
    false, false, true,  false,
    true,  true,  true,  false
  );

  private val array =
    arrayOf(
      Column(m00, m10), Column(m01, m11), Column(m02, m12), Column(m03, m13)
    ).shrink()

  val size
    get() = array.size

  override fun iterator() = array.iterator()

  /**
   * Have the array shrink if the last Columns don't have a block piece
   */
  private fun Array<out AbstractColumn>.shrink(): Array<out AbstractColumn> {
    return sliceArray(0 .. indexOfLast { it.height > 0 })
  }

  private class Column(m0: Boolean, m1: Boolean) : AbstractColumn(2) {
    init {
      array[0] = m0
      array[1] = m1
      height = array.lastIndexOf(true) + 1
    }
  }
}