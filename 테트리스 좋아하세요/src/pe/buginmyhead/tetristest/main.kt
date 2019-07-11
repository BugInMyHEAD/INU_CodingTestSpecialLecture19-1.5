package pe.buginmyhead.tetristest

fun main() {
  val field = Field(8, 12)
  readLine()!!
    .split(' ')
    .map { BlockCreation(Block.valueOf(it[0].toString()), it[1] - '0') }
    .forEach {
      println(it.toString())
      field.forcePileUp(it)
    }
}