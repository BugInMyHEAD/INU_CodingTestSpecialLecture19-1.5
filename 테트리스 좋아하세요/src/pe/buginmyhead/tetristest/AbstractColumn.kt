package pe.buginmyhead.tetristest

abstract class AbstractColumn {
  abstract val height: Int

  var highestBlockPosition = 0
    protected set
}