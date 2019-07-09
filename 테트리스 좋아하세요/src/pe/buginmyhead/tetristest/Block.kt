package pe.buginmyhead.tetristest

enum class Block(
  m00: Boolean, m01: Boolean, m02: Boolean, m03: Boolean,
  m10: Boolean, m11: Boolean, m12: Boolean, m13: Boolean
  ) {
  A(
    true, true, true, true,
    false, true, false, false
  ),
  B(
    true, true, true, false,
    false, true, false, false

  ),
  C(
    true, true, false, false,
    true, true, false, false

  ),
  D(
    true, true, false, false,
    false, true, true, false

  ),
  E(
    false, true, true, false,
    true, true, false, false

  ),
  F(
    true, true, true, false,
    false, false, true, false

  ),
  G(
    false, false, true, false,
    true, true, true, false
  )
}