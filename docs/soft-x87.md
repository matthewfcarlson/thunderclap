# Soft x87 intrinsics (soft-intrinsics, 2026-10-24)

The x87 transcendental and special instructions the game uses, as portable integer-only C++: `src/platform/sdl/crt/softx87.{h,cpp}`.
Why: [wine-float.md](wine-float.md) section 6 (2). The Wine image ran Rosetta's `fsin` or msvcrt's `sin` (and xemu's recordings carry
macOS libm results), the arm64/x86-64 builds have no x87. These routines compute what Intel x87 hardware returns, with no host FPU, libm
or `long double`, so every build computes the same bits.

## What is computed

- Operands and results are 80-bit extended (software `hulk_x87_ext`, 64-bit mantissa). Round to nearest even, exceptions masked.
- Precision control does not apply to the transcendental instructions on real hardware (only `fadd/fsub/fmul/fdiv/fsqrt` family):
  `fsin fcos fptan fpatan f2xm1 fyl2x fyl2xp1 fscale frndint` return the full 64-bit-mantissa value rounded once (nearest even). The
  wrappers that mimic compound CRT sequences (`exp`) round their `fmul/fsub/fadd` steps at 53 bits, the game's precision control.
- `fsin/fcos/fptan` reduce the argument with the FPU's **66-bit approximation of pi** (`0x3243f6a8885a308d3 * 2^-64`): the argument is
  reduced exactly (192-bit integer arithmetic) by multiples of pi66/2 to `|r| <= pi66/4`, then sin/cos of that residue is evaluated to
  ~120 bits and rounded once. Hence results for arguments near multiples of pi differ from a correctly rounded `sin`: for the double
  nearest pi the routine returns `1.2246063538223773e-16`, the value Intel hardware is documented to return (the true sin is
  `1.2246467991473532e-16`). |x| >= 2^63: C2 set, operand unchanged. |x| < pi/4: no reduction.
- `fpatan` (all quadrants and the manual's zero/infinity table), `f2xm1`, `fyl2x`, `fyl2xp1`: ~120-bit evaluation (128-bit software
  float, series; `atan` by an eighth-table plus a short series, logarithms by the atanh series, `2^x-1` by an expm1 series with
  squaring), rounded once to 64 bits. `fscale`, `frndint`, `fprem`, `fprem1` (partial reductions, C2, quotient bits), `fsqrt` and
  `fmul/fadd/fsub` at PC 24/53/64 are exact.
- Double-level functions (`hulk_x87_sin cos tan atan atan2 exp log log10 pow asin acos fmod sqrt`) = the 80-bit result stored to
  a double. `_ext` variants return the 80-bit value.
- Not claimed: bit-exactness of the *last 64-bit digit* with a given CPU. Intel documents < 1 ulp (64-bit) for these instructions,
  not correct rounding; the routines are correctly rounded to 64 bits. After the game's 53-bit rounding a 1-ulp(64) difference shows in
  about 1 call in 2,000, after rounding to `float` in about 1 in 500 million. `pow`, `asin`, `acos` are built from the instructions'
  building blocks; the CRT's own sequences (`_CIpow`, `_CIasin`, `_CIacos`) are not known (no decompiling of library code), so they
  are correctly rounded values, unverified against the original.

## Using it

- Header API: `src/platform/sdl/crt/softx87.h` (build/soft-intrinsics/notes.md has the same list). On arm64/x86-64 compile the .cpp as plain C++14.
- Wine build: `HULK_SOFT_X87=1` in the environment of the build job (`tools/wine_build_job.py submit --env HULK_SOFT_X87=1`) compiles
  `crt_glue.cpp` with `-DHULK_SOFT_X87=1`: `sin cos tan atan atan2 exp` (already glue functions) and `asin acos log log10 pow fmod _CIpow
  _CIfmod _CIacos _CIasin` (rebound from msvcrt by `SOFT_X87_REMAP` in tools/wine_host.py) call the soft routines. On i386 the result is
  loaded into st(0) as the 80-bit value (`fldt`), which is what the original's code finds after `fsin`; `HULK_SOFT_X87=2` stores it to a
  double first (A/B). `HULK_SOFT_X87_STATS=1` additionally appends the argument ranges the game really uses to `softx87-stats.txt`
  (or `$HULK_SOFTX87_STATS`). Off by default: nothing changes without the variable.
- MSVC byte matches are untouched (no source changed): the switch only changes what the clang image links for `sin()` etc.

## Validation

`build/soft-intrinsics/oracle.py`, `test_all.py`, `test_special.py` (local, not tracked): exact math with mpmath at 800 bits, the 66-bit-pi
reduction for the trig instructions, rounded to nearest-even at 64 (or 53/24) bits; inputs are doubles and full-mantissa extended values over the
game's ranges plus tiny, huge and near-multiples-of-pi/2 arguments. See the tables in `build/soft-intrinsics/notes.md`.
