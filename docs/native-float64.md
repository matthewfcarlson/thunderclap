# 64-bit float fidelity (flt1, 2026-11-05)

The 32-bit Wine build replays play3 with no persistent divergence to the end of the recording (56,550;
[wine-float.md](wine-float.md) sections 15-16). The 64-bit builds (x86-64 SteamOS, arm64 macOS, arm64 Android) have no
x87, so every place where the Wine build's float results depend on the x87 has to be reproduced in another way. This
document picks the strategy for each such behaviour, with measurements, and records what is implemented.

**The reference is the Wine build, not the original.** The chain is original == Wine object (`equiv.py --wine`, the
replay) and Wine object == 64-bit object (this document, `equiv.py --x64`). The Wine build's game code is SSE2 code at
-O0 with `-ffp-eval-method=double -ffp-contract=off` and three IR passes ([wine-float.md](wine-float.md) section 13):
x87-keep (the 268 functions that compute with an 80-bit math result stay x87 code), retfix (every call declared `float`
is read as the double in st(0)) and castfix (`(float)i` inside an expression is not rounded). The 64-bit builds have to
compute what that code computes.

Scripts and raw outputs: `build/flt1/` (local; `RESUME.md`, `fp/`, `scripts/`).

## Decisions

| x87 behaviour the Wine build relies on | x86-64 (SSE2) | arm64 (NEON) | how it was checked |
|---|---|---|---|
| float expressions evaluated in double, rounded only at float stores | `-ffp-eval-method=double -ffp-contract=off` (already the native front end's flags) | the same; `-ffp-contract=off` is required (arm64 contracts to `fmadd` by default) | the kernel of wine-float.md section 6: hash 4db0c63c (MSVC 7.1 x87) on x86-64 and arm64, -O0 and -O2 |
| `hulk_freg` locals | `double` | `double` | as above: PC 53 x87 arithmetic is IEEE double arithmetic for game values |
| results returned in st(0): a `float` declaration of a `hulk_freg` (double) callee, a vftable slot declared `float` that a `hulk_freg` override fills | **retfix64**: float results travel as doubles between game functions | the same | without it an arm64 caller reads garbage (a `float` call of a double function returned 4.4e13 for 1/3); with it the value is the Wine build's |
| `(float)i` inside an expression is not rounded | **castfix** (the Wine build's pass) | the same | 252 sites in the tree |
| the 80-bit result of fsin/fcos/fptan/fpatan/... used by the next instruction | soft x87 for the functions (as before) plus **x87ext**: the consumer computes from the 80-bit value at 53 bits | the same | x86-64 hardware x87 as the reference: 0 mismatches in 2,000,000 per operation, the same hash on arm64 |
| float -> integer conversion | **fpcvt**: the Wine build's results for every input | the same | 37 edge values and 3,000 random ones, 12 conversions each: 0 differences from the i686 SSE object on both targets |
| comparisons | nothing to do | nothing to do | identical predicates on i686 SSE, i686 x87, x86-64 and arm64 for NaN, infinities and ties |
| transcendentals | `softx87` (integer only; native CRT table rows) | the same | same results on both targets (hash); `log10` against xemu's `fyl2x` at play3's 626,687 arguments (section "log10") |
| control word, denormals | nothing (SSE: MXCSR default, no FTZ/DAZ) | FPCR cleared by `entry_posix` (FZ/DN/AH off) | wine-float.md, native-android.md section 6 |

The four passes are in `tools/native_float.py`. The native compiles apply them in `native_mac.retarget()`, **by default
since flt2 (2026-11-06)**; `HULK_NATIVE_FPFIX=0` turns them off (the setting is part of the cache key: `VERSION` 2+fpfix1
with, 2 without, so caches built before the switch are rebuilt once). The
x87ext helpers are `src/platform/sdl/host/x87ext_native.cpp`, linked with the host glue. Over the whole tree (HEAD
77b9475d2, 2,659 TUs): castfix 252, fpcvt 384 conversions (the float-cast-overflow build of wine-float.md section 14
counted the same 384), x87ext 264 math calls with 203 consumers, retfix64 217 float definitions and 2,479 float calls;
every TU still compiles through the backend.

**On the macOS image** (HEAD 77b9475d2's tree and binding map, compiled and linked locally both ways): with
`HULK_NATIVE_FPFIX=1` the link binds 676 more names by address (13,723 -> 14,399: exactly unb1's "`float` result for a
`hulk_freg` definition" class, whose signatures now agree) and leaves 31,302 unbound instead of 31,958; ld64 rc 0 and no
CRT binding problems either way. The start-up stops at the same place with and without the pass (initializer 216,
HEAD's known stop), in the normal and the survey mode. Tests: `tests/native_host/native_float_test.py` (the three checks
of the next section, about 15 s); xdk_bind (3 targets), crt_bind (mac, linux-x64), shim (mac, linux-x64),
replay_native, entry and native_unbound pass with the changed link tools.

## Options considered

- **`long double` on x86-64.** Under the native front end (`x86_64-pc-windows-msvc`, the MS C++ ABI) `long double` is
  `double`, so the sources cannot ask for it; at IR level `x86_fp80` would work on x86-64 only (with the control word
  set to PC 53), while arm64 macOS has no wider type and arm64 Android's `long double` is binary128. It would split the
  targets. Rejected.
- **Soft float everywhere.** The arithmetic is already exact IEEE double on all three targets (the kernel above); only
  the 203 consumers of 80-bit values need more than double, and those use integer-only operations. Rejected for the
  rest (cost, nothing gained).
- **Flags only.** Necessary but not sufficient: measured below, the plain 64-bit code differs from the x87 code in the
  double result of 20-27% of the operations that consume an 80-bit value, and the conversions differ on arm64.
- **Source spellings.** The 676 `float` declarations of `hulk_freg` callees (unb1) can be spelled `hulk_freg` (a batch
  below), but 570 of the 702 `hulk_freg` definitions are virtual, so most of the problem is in vftable slots declared by
  stub classes all over the tree. The ABI rule (retfix64) covers both, the way the Wine build's retfix does.

## Measurements

**80-bit results consumed** (`build/flt1/fp/ext_consume.cpp`; the result of softx87's sin, cos, atan, atan2, exp over
the game's argument ranges, 1,000,000 each; reference: the x87 under Rosetta with control word 0x027F):

| consumer | plain 64-bit code (result rounded to double first) differs from x87, double result | after rounding to float | softx87 at PC 53 differs |
|---|---|---|---|
| `r * 57.29577951308232` | 230,294-257,478 (sin, cos, atan, atan2) | 0 | 0 |
| `r + k` (k a float value) | 26,870-63,280 | 0 | 0 |
| `r / k` | 229,884-266,734 | 0 | 0 |
| `(float)r` | - | 0 | 0 |
| `(long long)(r * 2^20)` | 0 | - | - |
| any, after `exp` (its last steps already round at 53 bits) | 0 | 0 | 0 |

So a consumer that rounds to float at once (92 of the 273 consumer sites in the x87-keep functions are `fptrunc`) is
already right; the ones that compute on in double are not. In the Wine build that difference was enough to move play3:
perf1 found the x87-keep list by bisecting a divergence at checkpoint 450 (camera, `atan2(...) * 57.29...`) and
gameplay RNG from 780.

**What the x87-keep functions do with the value** (`build/flt1/scripts/keep_uses.py`, 32-bit IR of HEAD): 112 of the
268 functions consume a math result directly: `fptrunc` 92, `fmul` 74, `store double` 58 (fstp m64: the double, exact
either way), `fadd` 18, `fdiv` 14, passed as an argument 7, `fsub` 5, `fpext` 2, returned 2, `fcmp` 1.

**x87ext** (`src/platform/sdl/host/x87ext_native.cpp`). Operations on the 80-bit value at 53 bits: softx87's fmul,
fadd, fsub and a 128-by-64-bit integer division, then the x87's store to double; `fptrunc` is softx87's store to float;
`fcmp` compares exactly. Checked against the x87 (x86-64 under Rosetta, control word 0x027F) on 2,000,000 values from
sin, atan2 and pow, with float and double second operands and zeros: mul, add, sub, reversed sub, div, reversed div, to
float and four predicates all 0 mismatches; the hash of 6,000,000 results is the same on x86-64 and arm64
(f260a9a9edc088ce). The pass (`x87ext_ir`): a call of sin, cos, tan, atan, atan2, exp, asin, acos, log, log10 or pow
writes the 80-bit value to a slot (`hulk_x87e_<fn>`) and gives the other uses its double; an `fmul`/`fadd`/`fsub`/
`fdiv`/`fptrunc`/`fcmp` that uses it before the next call or block boundary computes from the slot. That boundary is
where the x87 code at -O0 has already stored the value as a double (LLVM's x87 registers do not survive a call, and -O0
spills every value at block ends). Kernels compiled the way the tree is (`build/flt1/fp/x87e/`: `atan2(y,x)*57.29`,
`r*sin(a)+1`, `sin(a)*cos(b)`, `(float)sin(a)`, `sin(a) > t`, `1/cos(a)`, `b - pow(a, 0.75)`), 300,000 inputs each,
against hand-written x87 references: without the pass 59,059-70,090 mismatches per kernel (the float and compare
kernels 0); with it 0, and arm64 gives the same hash as x86-64.

Not covered by x87ext: an 80-bit value returned by a function (the Wine build's x87-keep fixpoint: 2 `ret` sites and 9
uses of such results in callers). Those need a second entry point that returns the slot; listed for the next step.

**Float -> integer** (`build/flt1/fp/conv/`; i686 objects run in Unicorn, x86-64 under Rosetta, arm64 native; 37 edge
values: NaN, infinities, +-0.5, +-1.5, the limits of every width, 2^31, 2^32, 2^63, 2^64, 1e30):

| conversion | i686 SSE (Wine build) vs x86-64 | vs arm64 | vs i686 x87 |
|---|---|---|---|
| `(int)` | 0 | 12 | 0 |
| `(unsigned)` | 15 | 21 | 15 |
| `(short)` / `(unsigned short)` | 0 / 0 | 10 / 14 | 25 / 0 |
| `(signed char)` / `(unsigned char)` | 0 / 0 | 10 / 13 | 5 / 5 |
| `(__int64)` / `(unsigned __int64)` | 0 / 6 | 8 / 16 | 0 / 0 |
| `(int)(__int64)` / `(unsigned)(__int64)` | 0 / 0 | 6 / 6 | 0 / 0 |
| `(int)` of a float | 0 | 13 | 0 |
| comparisons (6 predicates) | 0 | 0 | 0 |

arm64 saturates (`fcvtzs`), gives 0 for NaN and 0 for a negative value converted to an unsigned type (`(unsigned)-1.0`
is 0xffffffff on x86 and 0 on arm64). x86-64 differs from the Wine build only for `unsigned` and `unsigned __int64`
out of range. The fpcvt pass replaces each `fptosi`/`fptoui` with an IR helper that computes the i686 SSE result
(LLVM's own i686 lowerings, read from the object: `cvttsd2si`, and for `unsigned` `b | (cvtt(x - 2^31) & (b >> 31))`).
With the pass: 0 differences from the i686 SSE object on x86-64 and on arm64, for the edge values and for 3,000 random
values over 2^-3..2^70 (without it 1,585 and 2,257 of the 3,000 differ).

**Double evaluation** (wine-float.md section 6's kernel, `build/x87/hyp/`, rebuilt with the native flags): the faithful
spelling gives 4db0c63c, MSVC 7.1's x87 result, on x86-64 and arm64 at -O0 and -O2; the plain float spelling ca266a3f
and the all-double one d0b2e2e3 on both, as on i686.

**Wine build A/B for the 80-bit consumers** (`HULK_SOFT_X87=1` against `=2`, the latter storing each math result to a
double first, which is what plain 64-bit code does): jobs 63434 / 63436, one lineage on one build host, HEAD 77b9475d2,
play3 to 60,000. **The two are identical at all 2,011 common checkpoints (0-60,300).** So on play3 the 80-bit
consumption changes no checkpoint once the math functions are soft x87; x87ext keeps the 64-bit builds bit-exact with
the Wine build's x87-keep code anyway (cheap: 203 sites), but it is not what decides the replay.

**What does decide it: soft x87 against the x87 instructions.** Both soft runs diverge from the recording persistently
from **frame 8,850** (1,593 of 2,011 checkpoints DIVERGED), while the default Wine build of the same HEAD on the same
host (job 63381, the x87 instructions under Rosetta for sin, cos, tan, atan, atan2, exp and msvcrt for asin, acos, log,
log10, pow, fmod) matches the recording everywhere but the known transients (5880, 5910, 34260, 52620, 52650); the
default and the soft run differ at 1,716 of 2,011 common checkpoints, first at 8,850. (soft-x87.md's "no checkpoint
change in 30,000 frames" was measured against a control that had already left the recording at 3,900.) The 64-bit
builds bind the math rows to soft x87 (native_crt_table.h), so **they would leave play3 at 8,850 whatever the float
passes do** (flt2: resolved, the cause was leaked x87 registers in the Wine build, section "log10"): the transcendental implementation, not the precision model, is the first native fidelity item.

**The culprit is `log10`.** A per-function switch (`HULK_SOFT_X87_HW=f,...`: under `HULK_SOFT_X87=1` the listed
functions keep the default build's version, the x87 instruction for sin cos tan atan atan2 exp, msvcrt for asin acos
log log10 pow fmod; patch `build/flt1/patch-soft-x87-hw.diff`, not committed: a Wine build input, measurement only),
play3 to 12,000 or 60,000, HEAD 50dd6fb59 workspace, one lineage:

| soft (everything else as the default build) | first divergence from the recording |
|---|---|
| sin cos tan atan atan2 exp (64110) | none to 12,000 |
| asin acos log log10 pow fmod (64111) | 8,850 |
| asin acos log (64249) | none to 12,150 |
| log10 pow fmod (64250) | 8,910 |
| pow (64281) | none to 12,060 |
| log10 fmod (64282) | 6,090 |
| log10 (64284) | 6,090 |
| fmod (64285) | none to 12,150 |
| **everything but log10 (64289)** | **none to 60,180** (only the known transients) |
| everything, log10 correctly rounded (64286; `hulk_x87_log10_cr`, one rounding from the ~120-bit value) | 19,200 |
| log10 correctly rounded only (64288) | 6,090 |

So every soft x87 routine except `log10` reproduces the recording to its end. `log10` (`fldlg2; fxch; fyl2x` in soft
x87, 64-bit result) and a correctly rounded `log10` both move play3; Wine's msvcrt `log10` (the default Wine build) does
not. The game's `log10` feeds the 3D sound's dB conversion (`ToDb`, FUN_00258f90 -> FUN_00262270, wine-float.md
section 14). (flt2: the cause is not the value but a side effect of msvcrt's `log10` on leaked x87 registers; next section.) Locally (`build/flt1/fp/fm*.cpp`): soft
fyl2x `log10` differs from macOS libm in 769 of 2,000,000 arguments, the correctly rounded one in 608 (macOS libm is
not correctly rounded there; the correctly rounded variant was exact against a decimal reference on all 300 sampled
disagreements). What the original computes there: the next section.

## log10 (flt2, 2026-11-06)

**There is no library `log10` in the original's path.** Both call sites inline MSVC 7.1's intrinsic (the game's own code,
read in `tools/packet.py show`): FUN_00258f90+0x388 (`ToDb`) is `fld dword [esp+0x10]; fldlg2; fxch st(1); fyl2x; fmul
dword [0x3fef48]; fstp dword` and FUN_0033b900 is `fldlg2; fxch st(1); fyl2x; fstp dword`. The constant at 0x3fef48 is
10.0f, so `ToDb(v)` is `10*log10(v)` (a power ratio), not 20. The reference is therefore what the emulated CPU's
`FLDLG2`/`FYL2X` return (play3 was recorded in xemu with no game function patched), followed by the game's own `fmul` at
53-bit precision and the float store. No CRT code is involved, and none was read.

**How the reference data was obtained** (black box only): `tools/xemu_log10_probe.py`, an xemu queue job on the Mac
Studio (`--needs xemu --host studio`, `-snapshot`, run from `~/hulk-tr1`; no watchpoints, no disk writes). It boots the
hybrid image paused, stops at the game's `main` (0x8ee30) with a breakpoint, writes a loop under the stack (`cli; fninit;
fldcw CW`; per argument `fld qword; fldlg2; fxch; fyl2x; fnstsw`, the 80-bit result stored with `fstp tbyte`, the result
stored as a float, and the result times `[0x3fef48]` stored as a float), continues to a breakpoint after the loop and
reads the results over the GDB stub, 64 arguments per chunk, at control words 0x027F (the game's) and 0x037F. Arguments:
edge cases (zeros, infinities, NaN, negatives, denormals, every power of two from 2^-149 to 2^127, powers of ten, 4,096
floats next to 1.0 and 512 doubles next to 1.0, the integers 1-4,096), 40,000 random floats in (0, 1] (the dB conversion's
domain), 10,000 random positive floats and 10,000 random doubles (job 64560, 69,059 arguments, 11 s), and 159,975 floats
chosen to lie within 0.004 ULP of a rounding tie of the exact result (job 64567; found with a local scan of 20,000,000
random floats in (0, 1]). Raw outputs stay local (`build/flt2/probe/`, not tracked); the argument set of play3 itself
comes from a Wine-build trace (job 65002, below).

**Observations.**

- Precision control does not apply: every 80-bit result is the same at 0x027F and 0x037F (Intel documents this for the
  transcendental instructions).
- The 80-bit result is `FLDLG2 * log2(x)` (FLDLG2 = 0x3ffd:9a209a84fbcff799, log10(2) rounded to nearest) rounded once to
  64 bits, nearest even, in 69,050 of the 69,052 finite arguments of the first set, the 2 others within 0.0008 ULP of a
  tie. A correctly rounded `log10(x)` agrees in only 32,785 (the constant's own rounding moves the last bit), a double
  `log10` in 51. Special cases: the x87's (zero -> -inf, negative and -inf -> the negative default NaN, NaN quieted,
  1 -> +0, +inf -> +inf).
- Near ties xemu's FYL2X is not exact: in the tie set 620 of 158,532 results are one 64-bit ULP from the correctly
  rounded value, both ways (334 up, 286 down). The needed error, expressed as an absolute error of log2(x), is below about
  2^-71.5 and scales with the size of the series term after the leading one (s^3 for s = (m-1)/(m+1), m in
  [sqrt(1/2), sqrt(2))): xemu evidently computes part of log2 in 64-bit arithmetic. Not reproduced (rounding that tail term
  to 64 bits does not give xemu's results), and not needed: see the next point.
- **What the game sees agrees everywhere.** The float stored by FUN_0033b900 and the `10.0f` product stored by ToDb,
  computed from the model's 80-bit value, are identical to xemu's in all 227,583 probed arguments at control word 0x027F
  (and all 455,166 records at both control words), including the 620 near-tie ones: a one-ULP change of the 80-bit value
  only shows after rounding to float if the value is also within 2^-40 of a float tie.

**play3's own arguments.** A measurement-only Wine build (job 65002; `build/flt2/wt2`, not committed: the tree's `log10`
bound to a wrapper that calls msvcrt's and logs each new argument with msvcrt's and softx87's 80-bit results) replayed
play3 to 60,180 on the recording like the control: 3,589,048 calls, 626,687 distinct arguments. All of them probed in
xemu (job 65007, mac2): the game-visible floats from softx87's value equal xemu's in 626,687 of 626,687 (both control
words); the 80-bit value differs in about 84 near-tie arguments per control word. msvcrt's `log10` returns double
results (the low 11 mantissa bits zero) whose game-visible floats are also identical to softx87's at every finite
argument, with or without a store to double in between.

**What really moved play3: leaked x87 registers.** So the values were never the problem, and two more Wine builds showed
what was: a wrapper that calls msvcrt's `log10` but returns softx87's value replays clean (job 65012), and one that also
records the x87 environment around the call (job 65013, `fnstenv` before and after) finds the tag word **non-empty at
entry** in 35 of the 64 distinct environments it saw (from the 317,094th call on; a cdecl call should find the x87 stack
empty) and **all empty afterwards** every time, control and status words unchanged. msvcrt's `log10` frees registers
that the Wine build's x87 code leaves behind; without that, the leaks pile up until some push overflows (the masked
response is the default NaN) and play3 leaves the recording (6,090-6,150 and from 12,060 with softx87 alone: job 65010;
8,850 with all of soft x87: job 65011). In the original the dB conversion never meets a NaN: an xemu log of
FUN_00262270's argument during play3 frames 5,907-6,403 (job 65006, `rl4p.py --fn 0x262270:10`, the checkpoints
matching the recording) has 105,154 calls from the seven ToDb sites, 4,027 distinct values, none NaN. The leaks were
found later (x87leak, next section) and fixed at their source; the Wine build's `log10` freed the registers the way
msvcrt's did until x87b took that out (section "Checking for x87 leaks").

## The x87 leaks themselves (x87leak, 2026-11-07)

**How they were found.** A measurement-only Wine build (committed since as `HULK_X87CHK=1`, next section: `tools/wine_link.py` with an entry check in front of
each of the 27,635 game functions and XDK stand-ins, every reference pointed at it the way the trace probes are; the
check compares the x87 TOP (`fnstsw`) with the thread's last value and runs `fxam` on st(0), which must be empty at a
cdecl/thiscall entry, and logs the function, its caller and the function entered before; a later version also saved
`ebp` at each entry to print the returned frames). A cdecl call starts with an empty x87 stack, so the first entry
after the stack goes wrong brackets the code that did it. Four type errors in equivalent/ sources, all in one of two
shapes:

| source | declared | the original | in the Wine build |
|---|---|---|---|
| equivalent/0x000c72e0 (and 0x0030c440, not on play3's path) | `void` V3::FUN_0022d110() (normalize) | 0x0022d110 returns the length in st(0); the caller pops it (`fstp st(0)` after the call) | clang never pops: one register leaked per call (TOP -1; about 90,000 times in play3) |
| equivalent/0x001b05a0, 0x001d8350 | `float` FUN_0022d180() (normalize in place) | 0x0022d180 returns nothing; the callers pop nothing | clang's `fstp st(0)` pops an empty register: stack underflow (IE+SF set, a NaN stored and popped, TOP +1) |
| equivalent/0x001050d0 CPathAgent::vfunc_4 | `float`, and the behaviour's vfunc_4 it tail-returns `float` | it returns the behaviour's bool (CAvoidBehaviour::vfunc_4 0x00109c00 is `_N`) in al, and its caller COccupationAgent::vfunc_4 0x00103c30 ignores it | `fstps` of an empty st(0) (underflow) then `flds` of the "result", which the void-declared caller never pops: TOP unchanged, st(0) left full, from frame 6,018 on. This is the register flt2's job 65013 saw at log10's entry from call 317,094 (tag word fffe, status 0x0061) |

The first and third leave a register full; the second only moves TOP. Fixed by the declarations (`float` / `void` / `bool`); the MSVC objects
of matches/ are untouched, and the four equivalents re-pass `equiv.py` (3,000 inputs; 0x000c72e0 runs out of time budget
at 1,032 / 742 with `--wine`, equivalent; 0x001050d0's `--wine` run faults at input 0 (`Invalid_instruction`) before and
after the change alike, a harness gap, its default run is EQUIVALENT at 3,022). `equiv.py` passed all of them before the
fix: a callee's x87 return is modelled from the source's own declaration, so a wrong declaration on both sides agrees
with itself (a checker gap: comparing the x87 stack depth after each call with the original's would catch it).

**Proof** (base b4ff21f77 + HEAD's build_tree.py/clang_probe.py, `--gfx`, play3, data from that commit's own data_gen,
all on the Mac Studio, one lineage): control 65245; fix with `emms` in log10 (65271), fix without it (65272), soft x87
without it (65273, `HULK_SOFT_X87=1`): `ckpt_gate.py` GATE ok for all three, only the known transients 5880 5910 34260
52620 52650, prng hashes identical at every common frame. Before the fix the same build without the `emms` failed (65259:
6,090-6,150 and from 12,060, as flt2's) and soft x87 without it too (65260: from 37,140). The measurement build with the
fixes and no `emms` (65274) found no entry with a wrong TOP or a full st(0) through 60,360, and `log10` saw an empty tag
word at all of its 3.67 million entries.

**Implementation.** softx87's `hulk_x87_log10_ext` (`src/platform/sdl/crt/softx87.cpp`: fyl2x with FLDLG2, integer
arithmetic only) already computes the model; an independent implementation written for this (192-bit fixed-point atanh
series, kept local as `build/flt2/fp/softx87_lg2.cpp`) agreed with it bit for bit on all 853,000 probed arguments, so the
tree keeps the one routine. It is used by:

- the native builds, as before: the native CRT table's `log10` row (`hulk_ncrt_log10` -> `hulk_x87_log10`) and the x87ext
  slot (`hulk_x87e_log10`); they have no x87 stack, so nothing leaks there;
- the Wine build **by default** (it used msvcrt's until now): `tools/wine_host.py` binds the tree's `log10` to
  `hulk_crt_log10_x87` (crt_glue.cpp: softx87's 80-bit value in st(0), the way the inlined `fyl2x` leaves it, the rest of
  the x87 stack untouched); `HULK_WINE_LOG10=msvcrt` binds msvcrt's again. Until x87b it began with an `emms` (tag word
  all empty, control and status words kept), the way msvcrt's `log10` freed the registers the leaks left; with the leaks
  fixed at their source it is gone (the original has no such cleanup), proof in "Checking for x87 leaks" below.

Test: `tests/native_host/native_float_test.py` check `log10` (powers of two against exact integer arithmetic, random and
special arguments against the documented rounding in decimal arithmetic, x86-64 == arm64, and, when the local probe
files are present, the game-visible floats against xemu's; that part is skipped otherwise).

**Proof** (HEAD 3234e788e + this change, `--gfx`, play3, data from HEAD's own data_gen, control and proof on the Mac
Studio, one lineage): control 64977, proof 65014: `tools/ckpt_gate.py` GATE ok, the checkpoints identical at all 2,002
common frames (0-60,030), prng hashes identical, only the known transients 5880/5910/34260/52620/52650, 1,314 unbound in
both, x87-keep 268 in both. **Soft x87 with this `log10`** (`HULK_SOFT_X87=1`, every math routine soft, job 65016, same lineage): **no divergence to 60,330** beyond the known transients, the checkpoints identical to
the control's at all 2,002 common frames (GATE ok) (before: 8,850 with all soft, 6,090 with `log10` alone). So the 64-bit
builds' math table (all soft x87) is no longer expected to leave play3 for this reason.
(A first control built from the laptop's `build/data/src`, generated before reg3's commit, hung at the audio start-up
on both studio and mac2 with no checkpoint; with `--data-src` from HEAD's own data_gen it ran clean.)


## Checking for x87 leaks (HULK_X87CHK, x87b, 2026-11-07)

x87leak's measurement build is an off-by-default switch of the Wine link. With `HULK_X87CHK=1` in the build's environment
`tools/wine_link.py` (`x87chk_asm`) puts an entry stub in front of every game function and XDK stand-in (27,635 on
play3's tree; not the host CRT or the library code), outside every other wrapper, and points every reference at it
the way the trace probes are. The stub calls `_hulk_xc_chk`, which keeps every register and flag but the x87's: a
cdecl or thiscall entry finds the x87 stack empty, so TOP must be the thread's last value and `fxam` must call st(0)
empty. A difference calls `hulk_xc_event` (`src/platform/sdl/xdk/startup.cpp`, compiled only with `-DHULK_X87CHK=1`,
which `platform_shim` adds), which writes trace lines:

```
x87chk armed: 27635 entry checks                    (at start-up: the checks are in the image)
x87chk N f=FRAME tid=T sw=SW top A->B fn=XBE site=RET caller=XBE+OFF prev=XBE prevsite=RET prevcaller=XBE+OFF
x87chain N XBE+OFF x6                               (full st(0) only: the frames the previous entry has returned from)
```

`fn` is the function entered, `caller` the one its return address is in (by the link's table `_hulk_xc_tab`), `prev`
the function entered before on that thread and its caller: the code between the two entries left the stack wrong.
`sw` bit 31 marks a full st(0) (then the low half is the status word: IE+SF, 0x0041, set after an underflow); without it TOP moved
(`top A->B`) and B is the new reference. A full st(0) is freed after the event (each leak logged once), so a
measurement replay can drift from the recording; it is a diagnostic, never a proof image. The first 6,000 events are
logged, then every 10,000th.

```sh
J=build/venv/bin/python
id=$($J tools/x87chk.py submit --host studio --lineage ME-x87chk [--workspace DIR --data-src DIR/src])   # play3 to 60000, --gfx
$J tools/wine_build_job.py wait $id
$J tools/x87chk.py check $id --frames 60000      # X87CHK ok: armed, no event, replay reached the frame (exit 1 otherwise)
```

`submit` is `wine_build_job.py submit` with `--env HULK_X87CHK=1` and the defaults `--name x87chk --gfx --replay play3
--frames 60000`. On its own lineage it costs a fresh build; after a proof on the proof's lineage it reuses the build state
and relinks (about 7.5 minutes on the Mac Studio, the replay 230 s: 68257 below). Run it after a batch that changes float returns or
the declarations of float callees: `equiv.py` cannot see a wrong x87 return declared the same way on both sides.

**The stand-in pass after the wrappers (fixed with this).** native9's stand-in bodies (`wine_link.standin_bodies`) treat
a `local_code` symbol that is not the tree's definition of an address as a stand-in and alias it to that address's
definition. They ran after the wrappers were installed and looked only at `by_addr_def`'s values, where a wrapper has
replaced the definition it wraps: a wrapped definition listed in `local_code` (its verified calls go to its own
address) was aliased to its own wrapper, whose `jmp` to the definition then jumped to itself (x87leak's first
measurement build hung at start-up, job 65246). The pass now also counts the definitions from before the wrappers and
every wrapped one as the tree's (`tests/jobq/test_wrap_rebind.py` `Standin`); `HULK_TRACE_FUNCS` / `HULK_TRACE_EXIT`
probes and the hooks could hit it the same way. The link report counts what the old rule would have taken
(`stand-in pass: wrapped definitions kept as themselves (x87b)`): 0 in the default build (its few wrappers wrap no
`local_code` symbol, so it links as before), 125 in the HULK_X87CHK build.

**Proof** (HEAD edaf49b8e, `--gfx`, play3 to 60,000, data from HEAD's own data_gen, all on the Mac Studio): control
65298 (HEAD as it was, log10 with the `emms`), proof 68255 (no `emms`, the stand-in fix, the switch off;
`--state seed:65298`): `ckpt_gate.py` GATE ok, the checkpoint hashes identical at all 2,003 common frames, prng hashes
identical, only the known transients 5880 5910 34260 52620 52650. Soft x87 on the proof tree (68261,
`HULK_SOFT_X87=1`): GATE ok, checkpoints identical at all 2,003 common frames (its replay takes about 370 s, more than
wine_build_job's default `--replay-timeout` of 300: 68256 stopped at 48,480, ok to there). The measurement build
(68257, `tools/x87chk.py submit` on the proof's lineage): 27,635 entry checks armed, **0 events** to frame 60,030, and
its checkpoints still GATE ok against the control (`tools/x87chk.py check 68257 --frames 60000`: X87CHK ok).

## The `float` callers of `hulk_freg` functions (unb1's 676 names)

`build/flt1/scripts/freg_callers.py`: 702 sources define a function returning `hulk_freg`; 750 declarations in 439
sources (23 matches/, 416 equivalent/) declare such a callee `float`. The batch spells them `hulk_freg` (the same type
under MSVC 7.1, so the matches/ objects are unchanged). On the 64-bit builds it makes the declarations agree with the
definitions without retfix64; on the Wine build it changes the code (the -O0 temporaries) but not the values, since
retfix already reads those calls as doubles. Gates and proof: below.

**Classification** (`equiv64.py batch`, HEAD versions of the 416 equivalent/ sources; the 23 matches/ sources are
byte-matched): 341 equivalent, 53 fail (float 15, untyped 15, layout 8, crash64 6, int 4, call 3, ptrtrunc 1,
intwidth 1: per-function 64-bit differences unrelated to the declarations, since the checker's stubs return the same
value on both sides), 11 unsupported, 11 inconclusive. The cross-function problem itself (a `float` read of a double
result) is invisible to a per-source check; on the macOS image it is the 676 names retfix64 binds.

**The batch** (373 sources: 23 matches/, 350 equivalent/). Left out of the 439: 3 that no longer compile with clang
(0x001cf690, 0x001cfb20, 0x001d4830: a member-function pointer typed with a `float` result), 2 whose `--x64` run
newly fails or is inconclusive (0x000835a0, 0x0001c430), and every source whose 3,000-input or `--wine` run is not
`equivalent` after the change (5 and 59, mostly the same at HEAD). Gates: 23/23 MATCH + verify_relocs ok; 350/350
equivalent at 3,000 inputs and at 600 with `--wine`; `--x64` before -> after: 295 equivalent -> equivalent, 2 fail ->
equivalent, none newly failing. Proof (HEAD 50dd6fb59 + the batch) 64109 against control 64287, same host, `--gfx`,
play3: `tools/ckpt_gate.py` GATE ok, the checkpoints identical at all 2,003 common frames (0-60,060), prng hashes
identical, only the known transients 5880/5910/34260/52620/52650, strict link 0 errors, 1,318 unbound in both; the
images differ (the -O0 temporaries).

## The x86-64 Linux replay

**Built.** `tools/native_linux_sdl.py` cross-builds a static headless SDL3 for x86-64 Linux against the glibc sysroot
(no video, dummy audio, evdev joystick; 27 s). With it, `tools/native_elf.py link --target linux-x64 --ld` links the
same shim configuration as the macOS image: the SDL3 backends, the replay layer (`replay_native.cpp`, the recording
reader) and the hook plan applied (10 of the 14 ready rows, the same as macOS: GameClock::Update's entry hook and its
clock site, sound-rng x3, sound `rand`, seq-rng x2, RandInt x2). Movies: FFmpeg from `HULK_LINUX_FFMPEG` (a prefix with
include/ and lib/, e.g. the box's `/usr` after installing the libavformat development package), else
`src/platform/sdl/host/movie_none.c` (every movie fails to open, as an unreadable file does; a headless replay that
skips the intro needs none). On unb4's batch-c objects (the HEAD tree) with that map: lld rc 0, 31,770 code and 4,410
data stubs, a 41 MB PIE needing glibc 2.29 or later (libm, librt, libpthread, libdl, libstdc++, libgcc_s).

**Not runnable to a checkpoint yet, on any 64-bit target.** The replay layer hooks GameClock::Update, which only runs
once the game has started; the start-up still stops in the static initializers (macOS: initializer 216, reg1's
frontier). The same image on Linux will stop at the same place, so the first Linux run checks the platform layer
(low-4 GB reservation, glibc, the varargs glue, the SDL3 build), not float. A native float comparison starts when the
start-up reaches the game loop.

**Steps on the box** (once it has the repo, `isos/extracted` and the recording; see the host setup below):

```sh
# on the build Mac: the image (HEAD's tree: a Wine build's clang-probe snapshot and binding map of the same tree)
PY=build/venv/bin/python
$PY tools/native_linux_sdl.py                                   # once: build/third_party/out/sdl-linux-x64
HULK_NATIVE_FPFIX=1 HULK_CLANG_PROBE_DIR=<dir with snap/> HULK_NATIVE_ELF_DIR=build/nl $PY tools/native_elf.py compile --target linux-x64 --jobs 4
HULK_NATIVE_CRT_TABLE=src/platform/sdl/crt/native_crt_table.h HULK_CLANG_PROBE_DIR=<dir with snap/> HULK_NATIVE_ELF_DIR=build/nl \
    $PY tools/native_elf.py link --target linux-x64 --ld --bindings <bindings.json of the same tree>
scp build/nl/link/hulk-linux build/rp1/play3.hrp tools/native_linux_replay.sh BOX:hulk-native/
# a Wine reference: the checkpoints of a Wine build replay of the same HEAD (wine_build_job.py ... --replay play3)
scp build/jobs/out/<wine job>/nb-out/<checkpoint file> BOX:hulk-native/wine-ckpt.txt

# on the box
cd ~/hulk-native && sh native_linux_replay.sh ./hulk-linux ./play3.hrp ~/hulk-permute/isos/extracted out-1 wine-ckpt.txt
cat out-1/result.txt         # rc, checkpoints written, the stop (missing name / crash / init N), and the comparison
HULK_NATIVE_MISSING=continue sh native_linux_replay.sh ./hulk-linux ./play3.hrp ~/hulk-permute/isos/extracted out-2   # survey of stops
```

As a queue job once the box is registered with the `linux-x64` capability (`tools/jobq_host_setup_linux.sh`):

```sh
$PY tools/jobq.py submit --name ME --needs linux-x64 --slots 2 --limit 3600 \
    --files build/nl/link/hulk-linux=job/hulk-linux build/rp1/play3.hrp=job/play3.hrp tools/native_linux_replay.sh=job/run.sh \
            <wine ckpt>=job/wine-ckpt.txt --out job/out/result.txt job/out/ckpt.txt job/out/trace.txt \
    -- sh job/run.sh job/hulk-linux job/play3.hrp "$HOME/hulk-permute/isos/extracted" job/out job/wine-ckpt.txt
```

(`linux-x64` is a new capability: `tools/jobq.py` accepts it as `--needs`; the daemon matches it against host caps by name, so no restart is needed for jobs to wait for such a host.)

## Host setup for a Linux queue host

`tools/jobq_host_setup_linux.sh` (draft, not run against any host): the Linux counterpart of `tools/jobq_host_setup.sh`,
run on the box itself from a checkout. `--check` (default) reports the platform, packages, sshd, Wine with 32-bit
support, the Python 3.12 venv with the pinned packages (capstone 5.0.9, unicorn 2.1.4, clang 21.1.7), LLVM 22.1.8 in
`~/llvm` (clang, lld, lld-link, llvm-nm, llvm-undname, libclang), MSVC under wibo, the queue runner, disk space, the
game data and a `compare.py` smoke test, and exits 1 if something required is missing. `--install` installs with apt or
dnf (i386 Wine: `dpkg --add-architecture i386` + `wine32`, or `wine-core.i686`), the venv, LLVM's release tarball (its
sha256 printed, to pin), wibo, MSVC through `tools/pull_compiler.py`. `--data SRC` rsyncs the player's `isos/extracted`
and `build/{functions.csv,rtti.json}` from a checkout given on the command line. `--register NAME` prints the hosts
entry (caps `equiv msvc clang wine linux-x64`) and the command to merge it on the controller. Open points: the LLVM and
wibo checksums are not pinned yet; the distro's Wine (8-10) differs from Whisky's 7.7 and a Linux wibo from
`wibo-macos`, so the box's lineages are its own and its first Wine replay has to be compared with a Mac's.

## Next

1. (done, flt2) `HULK_NATIVE_FPFIX=1` is the default of the native compiles.
2. x87ext for 80-bit values returned through functions (the 2 + 9 sites above).
3. `equiv.py --x64` with the passes on its 64-bit side, so the per-function check covers them.
4. The first Linux run (platform layer), then a float comparison once the start-up reaches the game loop.
