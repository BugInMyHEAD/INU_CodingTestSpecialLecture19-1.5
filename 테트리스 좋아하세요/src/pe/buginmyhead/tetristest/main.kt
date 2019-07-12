package pe.buginmyhead.tetristest

fun main() {
  val field = Field(8, 12)
  readLine()!!
    .split(' ')
    .map { BlockCreation(Block.valueOf(it[0].toString()), it[1] - '0') }
    .forEach { blockCreation ->
      println(blockCreation.toString())
      field.forcePileUp(blockCreation)
      for (i1 in field.height - 1 downTo 0) {
        field.columns.forEach { abstractColumn ->
          print(if (abstractColumn[i1]) 'x' else '.')
        }
        println()
      }
    }
}