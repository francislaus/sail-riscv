#include "sail.h"
#include "rts.h"
#include "riscv_sail.h"
#include "riscv_softfloat.h"
#include "softfloat.h"

static uint_fast8_t uint8_of_rm(mach_bits rm) {
  // TODO.
  return (uint_fast8_t)rm;
}

#define SOFTFLOAT_PRELUDE(rm)                           \
  softfloat_exceptionFlags = 0;                         \
  softfloat_roundingMode = (uint_fast8_t) rm

#define SOFTFLOAT_POSTLUDE(res)                         \
  zfloat_result = res.v;                                \
  zfloat_fflags = (mach_bits) softfloat_exceptionFlags

unit softfloat_f32add(mach_bits rm, mach_bits v1, mach_bits v2) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t a, b, res;
  a.v = v1;
  b.v = v2;
  res = f32_add(a, b);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f32sub(mach_bits rm, mach_bits v1, mach_bits v2) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t a, b, res;
  a.v = v1;
  b.v = v2;
  res = f32_sub(a, b);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f32mul(mach_bits rm, mach_bits v1, mach_bits v2) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t a, b, res;
  a.v = v1;
  b.v = v2;
  res = f32_mul(a, b);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f32div(mach_bits rm, mach_bits v1, mach_bits v2) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t a, b, res;
  a.v = v1;
  b.v = v2;
  res = f32_div(a, b);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f64add(mach_bits rm, mach_bits v1, mach_bits v2) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t a, b, res;
  a.v = v1;
  b.v = v2;
  res = f64_add(a, b);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f64sub(mach_bits rm, mach_bits v1, mach_bits v2) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t a, b, res;
  a.v = v1;
  b.v = v2;
  res = f64_sub(a, b);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f64mul(mach_bits rm, mach_bits v1, mach_bits v2) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t a, b, res;
  a.v = v1;
  b.v = v2;
  res = f64_mul(a, b);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f64div(mach_bits rm, mach_bits v1, mach_bits v2) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t a, b, res;
  a.v = v1;
  b.v = v2;
  res = f64_div(a, b);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f32muladd(mach_bits rm, mach_bits v1, mach_bits v2, mach_bits v3) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t a, b, c, res;
  a.v = v1;
  b.v = v2;
  c.v = v3;
  res = f32_mulAdd(a, b, c);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f64muladd(mach_bits rm, mach_bits v1, mach_bits v2, mach_bits v3) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t a, b, c, res;
  a.v = v1;
  b.v = v2;
  c.v = v3;
  res = f64_mulAdd(a, b, c);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f32sqrt(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t a, res;
  a.v = v;
  res = f32_sqrt(a);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f64sqrt(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t a, res;
  a.v = v;
  res = f64_sqrt(a);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

// The boolean 'true' argument in the conversion calls below selects
// 'exact' conversion, which sets the Inexact exception flag if
// needed.
unit softfloat_f32toi32(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t a, res;
  uint_fast8_t rm8 = uint8_of_rm(rm);
  a.v = v;
  res.v = f32_to_i32(a, rm8, true);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f32toui32(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t a, res;
  uint_fast8_t rm8 = uint8_of_rm(rm);
  a.v = v;
  res.v = f32_to_ui32(a, rm8, true);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f32toi64(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t a;
  float64_t res;
  uint_fast8_t rm8 = uint8_of_rm(rm);
  a.v = v;
  res.v = f32_to_i64(a, rm8, true);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f32toui64(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t a;
  float64_t res;
  uint_fast8_t rm8 = uint8_of_rm(rm);
  a.v = v;
  res.v = f32_to_ui64(a, rm8, true);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f64toi32(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t a;
  float32_t res;
  uint_fast8_t rm8 = uint8_of_rm(rm);
  a.v = v;
  res.v = f64_to_i32(a, rm8, true);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f64toui32(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t a;
  float32_t res;
  uint_fast8_t rm8 = uint8_of_rm(rm);
  a.v = v;
  res.v = f64_to_ui32(a, rm8, true);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f64toi64(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t a, res;
  uint_fast8_t rm8 = uint8_of_rm(rm);
  a.v = v;
  res.v = f64_to_i64(a, rm8, true);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_f64toui64(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t a, res;
  uint_fast8_t rm8 = uint8_of_rm(rm);
  a.v = v;
  res.v = f64_to_ui64(a, rm8, true);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_i32tof32(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t res;
  res = i32_to_f32((int32_t)v);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_ui32tof32(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t res;
  res = ui32_to_f32((uint32_t)v);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_i64tof32(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t res;
  res = i64_to_f32(v);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_ui64tof32(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float32_t res;
  res = ui64_to_f32(v);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_i32tof64(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t res;
  res = i32_to_f64((int32_t)v);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_ui32tof64(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t res;
  res = ui32_to_f64((uint32_t)v);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_i64tof64(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t res;
  res = i64_to_f64(v);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}

unit softfloat_ui64tof64(mach_bits rm, mach_bits v) {
  SOFTFLOAT_PRELUDE(rm);

  float64_t res;
  res = ui64_to_f64(v);

  SOFTFLOAT_POSTLUDE(res);

  return UNIT;
}
