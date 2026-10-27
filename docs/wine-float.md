# Wine build float: x87 precision, the original's model and ours (x87, 2026-10-20)

Why does the Wine image's play3 replay differ from the hybrid recording by 1-14 ULP in camera y at checkpoints
450/540/600/660/690 ([wine-build.md](wine-build.md) native14), and what makes float results reproducible,
on 32-bit now and on 64-bit later? Tools: `tools/x87_scan.py` (tracked); experiment scripts and outputs in
`build/x87/` (local, `build/x87/RESUME.md`).

Since perf1 (2026-10-26, section 13) the Wine build's game code is SSE2 by default (`HULK_WINE_FLOAT=x87`: the x87 build these
sections describe), with results identical to the x87 build.

Outcome (native16, 2026-10-21): the float flags were adopted (`-ffp-eval-method=double -ffp-contract=off`, `hulk_freg` returns
bound at link; sections 8-9), and the play3 replay now matches checkpoints 0-420 and 480-840 (answer 3's "everything through 690
except 450" is older). Later checkpoints are in [wine-replay.md](wine-replay.md).

## Answers in short

1. **The original runs the x87 at 53-bit precision** (control word 0x027F: round to nearest, all exceptions
   masked). XAPI's `_cinit` (0x0020ba10) calls the CRT's `_fpmath(1)` (0x003441d9) through the `_FPinit` pointer
   (0x004d98e0), which calls `_setdefaultprecision` (0x003487ac) = `_controlfp(_PC_53, _MCW_PC)`. No game code
   writes the control word (a sweep of every code section finds `fldcw` only in the CRT's math helpers, which save
   and restore it; D3D/DSOUND/XGRPH/XPP have none). MSVC 7.1 /O2 keeps float values in x87 registers (53 bits)
   across statements and rounds only when a value goes to `float` memory (table below).
2. **Our image runs at 53-bit precision too** (Wine starts threads with 0x027F; measured), and Rosetta 2 honours
   the precision-control bits (measured: 1/3 has a 53-, 64- or 24-bit mantissa under PC 53/64/24). The difference
   is codegen: clang -O0 rounds every named `float` local at every assignment (store + reload); MSVC kept many of
   them in registers. clang -O1 on x87 reproduces MSVC's model closely (LLVM keeps `float` SSA values in 80-bit
   registers and rounds only at stores and spills), with its own deviations. `-ffp-eval-method=extended` makes
   -O0 worse (more stores); long double is double under the MS ABI.
3. **Measurements** (play3, table below): -O0 matches checkpoints 0-420, 480, 510, 570, 630 (camera y off by 1, 7,
   -14, -4, -1 ULP at 450-690). An image that compiles only the 172 TUs holding the scanner's candidate functions
   with register codegen (MSVC's model) and the rest at -O0 matches **everything through 690 except 450** (1 ULP).
   Whole-image register builds crash before 450 on non-float source bugs that -O0 hides (item 4).
4. **The -O1 crash after frame 0** is a callee-pops mismatch: `equivalent/0x00248670.cpp` declares
   `FUN_0025d740` (and `FUN_0025d780`) as `thiscall (unsigned ticks)`, popping 4 bytes; the definition
   (`matches/0x0025d740.cpp`, `Owner_25d740::Run()`) takes no argument and returns with plain `ret`. At -O0 clang
   addresses locals through ebp and leaves with `mov esp, ebp` (or re-adjusts with `sub esp, 4` after the call),
   so the 4 bytes are absorbed; at -O1 (no frame pointer, esp-relative frame) the caller's `ret` pops a wrong
   address and jumps to the heap. Check 7 (`wine_conv_check.py --pops`) lists this one among 26 such symbols.
   A prototype that gives every function a dynamic alloca (ebp frame, `lea esp,[ebp-N]` epilogue) runs -O1 past
   frame 0 and through checkpoint 420; the next crash (heap free in an audio `Sequence`, before 450) appears with
   only mem2reg + O1 codegen as well; bisected to `equivalent/0x00256d40.cpp`, which calls a two-word pool release
   with one argument and relies on the stack word the previous call left (fix proposed, EQUIVALENT).
5. **Recommendation**: keep -O0 for now (adding `-ffp-eval-method=double -ffp-contract=off` once measured); fix float sites in the sources by spelling what MSVC did
   ("temporaries and kept locals as `double`, `float` only where the original stores to float memory"), driven by
   the scanner's list; build 64-bit with `-ffp-eval-method=double -ffp-contract=off`, which then gives the *same
   bits* as the 32-bit x87 build for the same source (verified below); pin the transcendental functions to one
   software implementation in both the hybrid and the Wine build. Details at the end.

## 1. The original: precision control and MSVC 7.1's x87 model

**Control word.** Evidence (addresses in the XBE):

| what | where |
|---|---|
| `_cinit` reads `_FPinit` and calls it with 1 | XAPILIB::_cinit 0x0020ba10: `mov eax, [0x4d98e0]` |
| `_FPinit` = `_fpmath`: `_cfltcvt_init`, then if arg: `_setdefaultprecision`, `fnclex` | 0x003441d9 |
| `_setdefaultprecision`: `_controlfp(0x10000 /*_PC_53*/, 0x30000 /*_MCW_PC*/)` | 0x003487ac -> 0x00352612 |
| `_fpreset`-style handler: `fninit` + `_setdefaultprecision` | 0x0035243b |
| CRT math fast paths compare the control word with 0x027F and otherwise load 0x7f plus the current PC bits (`cw & 0x300`) | `_CIpow` 0x00346694, helper 0x003489f5 |
| `fldcw` anywhere else: none (linear sweep of every executable section; one hit at 0x003029f0 is a jump table) | |

The Xbox kernel's own initial control word for new threads is not read here (we don't decompile the kernel); the
main thread's word is set by `_cinit` before `main`. Precision control matters for *every* arithmetic result:
with PC=53 a register value has a 53-bit mantissa, so a store to a `double` is exact and only a store to a 32-bit
`float` rounds.

**Where MSVC 7.1 rounds.** A probe compiled with the project's MSVC 7.1 (`/O2`, listing in
`build/x87/msvc/probe.asm`), against clang:

| construct | MSVC 7.1 /O2 | clang -O0 (x87) | clang -O1 (x87) |
|---|---|---|---|
| `float t = a*b; float u = t*c; return u + t;` | t, u in registers, no rounding | rounds t and u (store/reload) | registers |
| `double d = (double)a*b; float f = (float)d; return f*c;` | the `(float)` cast is dropped: no rounding | rounds at the cast | folded: no rounding |
| `return a*b;` | unrounded st(0) | unrounded (one `return`); rounded if the function has several `return`s | unrounded |
| caller `g(x,y) + z` | uses st(0) unrounded | same | same |
| `float t = a*b; ext(); return t*c;` | recomputes `a*b` after the call: no rounding | rounds t across the call | spills t as float: rounds |
| `V v; v.x = a*b; ...; return v.x+v.y+v.z;` (local struct) | scalarised, registers | rounds each field | registers (SROA) |
| `if (a*b > c)` | compares the unrounded product | same | same |
| `p->x = a*b; return p->x * c;` | stores a rounded copy, **reuses the unrounded register** | reloads p->x (rounded) | forwards the store: unrounded, as MSVC |
| `float f = (float)i; return f*c;` | `fild` + `fmul`: the int is not rounded to 24 bits | rounds f | `fimul`: not rounded |
| `x.f = a-b; x.u &= 0x7fffffff; return x.f <= c;` (union fabs) | rounds through memory | rounds | **folds to `fabs` on the register: no rounding** (differs from MSVC) |
| a `float` live across a call, or under register pressure | spilled as `float` (rounded) | always in memory | spilled as `float` (rounded) |

So the MSVC rule is: float values live in 53-bit registers; they are rounded to 24 bits only when they are
written to `float` memory (a member, a pointer target, a spill slot across a call or under register pressure,
a struct whose address escapes, a union/bit trick) — and even after such a store MSVC may keep using the unrounded
register copy. Explicit `(float)` casts and int-to-float conversions are not rounding points.

The scanner (section 5) counts the original's rounding round trips: 6,530 in 645 functions (2,298 of them spills
across a call).

## 2. Our image: compiler and host

**Compiler.** The tree is compiled by `tools/clang_probe.py`'s `msvc` configuration: clang 22,
`--target=i686-pc-windows-msvc -O0 -mno-sse -mfpmath=387` (x87 so that the `volatile` rounding pins and the
replay checkpoints mean what they mean on the original). What the options do:

| option | effect on x87 code |
|---|---|
| -O0 | every local is an alloca: each assignment to a `float` local stores and reloads (rounds); fast regalloc spills every value live across a basic block as its type (rounds, e.g. `?:`) |
| -O1 / -O2 | locals in registers; `float` values unrounded until a store or a spill (LLVM's x87 backend never rounds a `float` register value); explicit `double->float` truncations are rounded through memory, but instcombine folds many of them away |
| `-ffp-eval-method=double` | float expressions evaluated in double, truncated at assignments and casts (C's FLT_EVAL_METHOD 1). On x87 at -O0 the results change only at `return` of a float expression (C rounds there, MSVC returns st(0) unrounded); at -O1 it is what makes a `float` local round at all (LLVM's x87 backend otherwise keeps it unrounded in a register, kernel experiment below). On SSE/NEON it is required to match x87 |
| `-ffp-eval-method=extended` | with the MS ABI's 64-bit long double: stores temporaries as well at -O0; no help |
| `-fexcess-precision=standard` / `fast` | accepted, no change (it governs `_Float16`/`__bf16`; `none` is rejected) |
| `/arch:IA32` (clang-cl) | = `-mno-sse` (x87 math); already the case |
| `-mfpmath=387` + `-mno-sse` | required together (clang refuses 387 math while SSE is enabled) |
| `-ffp-contract=off` | no FMA on i686 x87 anyway; **required on arm64** (clang contracts `a*b+c` to `fmadd` by default: measured) and on x86-64 with `-march=x86-64-v3` (`vfmadd213ss`) |
| `-ffloat-store` | not implemented by clang |
| fast-math | off (default); must stay off |
| long double | 64-bit under the MS ABI (`__LDBL_MANT_DIG__` 53); the game has none |

**Host.** `build/x87/cw/cw.c` under Whisky's Wine 7.7 on Apple silicon (Rosetta 2):

| test | result |
|---|---|
| initial control word of the process | **0x027F** (= the original after `_cinit`) |
| 1/3 to 80 bits under PC 53 / 64 / 24 | `3ffdaaaaaaaaaaaaa800` / `...aaab` / `3ffdaaaaab0000000000`: Rosetta honours precision control |
| `fsin`/`fcos`/`fpatan` (Rosetta) vs Wine msvcrt `sin`/`cos`/`atan2`, 400 arguments in [-7.3, 7.5] | differ by 1 ULP in 9 / 16 / 35 cases |
| either vs macOS libm (the host xemu runs on) | Wine sin/cos/atan2 differ in 18/25/35; Rosetta fsin/fcos differ in 17/19; Rosetta `fpatan` = macOS `atan2` in all 400 |
| macOS libm sin/cos vs correctly rounded (decimal reference), 5,000 arguments | not correctly rounded in 217 / 201 cases (errors up to ~0.77 ULP) |

So the control word needs no change (a pin + log is proposed as `build/x87/patch-x87-control-word.diff`), but
**transcendentals are host-dependent on both sides**: QEMU's x87 `fsin`/`fcos`/`fptan` helpers (xemu) convert
st(0) to double and call the *host's* libm, so the golden recordings carry macOS libm results, while the native
image calls Wine's msvcrt (game sources call `sin()`/`cos()` where MSVC inlined `fsin`/`fcos`). These are 1-ULP
differences in a few percent of calls.

## 3. Measurements (play3 replay, native14's image + flag sets)

Workspaces `$S/wx87-*` are copies of native14's `wsn13` image (HEAD 4ffd8334 + native14's fixes through stop 39)
with only the compiler changed (`build/x87/x87cc.py`, a clang++ stand-in for clang_probe; `build/x87/link.sh`,
`build/x87/rrun.sh`). 25 checkpoints from 0 to 720.

| image (compiler) | checkpoints 0-720 matched | camera y at the diverged ones (`ckall.py`) | end |
|---|---|---|---|
| -O0 (current; = native14) | 0-420, 480, 510, 570, 630 (19 of 25) | 450 +1, 540 +7, 600 -14, 660 -4, 690 -1 ULP; 720+ more than camera | runs on (hang at the T limit) |
| -O1 (native14's `wsO1`) | none | | crash right after frame 0 (section 4) |
| o1dyn (-O1 + dynamic alloca: robust frames) | 0-420 (15) | | crash before 450: dlmalloc `free` from an audio `Sequence` release |
| sroadyn (no IR optimisation but SROA; O1 codegen) | 0-420 (15) | | the same crash |
| m2rdyn (mem2reg only; O1 codegen) | 0-270 (10) | | the same crash, earlier |
| o1dyn + the 0x256d40 fix | 0-420 (15) | | crash before 450 (`Obj_1f4b60::second`) |
| **mixed: the 173 TUs holding the scanner's "image rounds more" functions at o1dyn (+ 0x256d40 fix), the rest -O0** | **0-420, 480-600 (20 of 21)** | 450 -1 ULP | crash before 630 (`FUN_00201e00`, CWorldCollisionManager) |
| **mixed, minus CWorldCollisionManager.cpp (172 TUs)** | **0-690 except 450 (23 of 24)** | 450 -1 ULP; 720 camera x -1, y -26 ULP | crash after frame 1350 (`FUN_001bc5b0`) |
| o0evd (-O0 + `-ffp-eval-method=double -ffp-contract=off`) | not run: 3 TUs fail to compile (below) | | |

So: keeping the float code's locals in registers (MSVC's model) fixes 540, 600, 660 and 690 — the checkpoints
native14 saw differ by 1-14 ULP — and leaves 450 at 1 ULP (now the other sign) and 720. That confirms the
precision class as the cause of those divergences, and the scanner's list as the right place to look: 172 TUs
with ~350 functions. The whole-image register builds don't get past the level load because of the non-float
source bugs of section 4. `-ffp-eval-method=double` breaks 3 TUs in C++ overload resolution:
`FUN_0004af40` is declared both `(int, float, float)` (include/common.h) and `(float, float, float)`; with the
float literal `-180.0f` evaluated as double the call becomes ambiguous (unk_06b300.cpp, CSoundVoiceManager*.cpp).
The fix is the header (one declaration), a consolidation item anyway.

## 4. The -O1 crash

MSVC 7.1 doesn't care how many bytes a callee pops when the declaration is wrong but the byte-matched or proven
equivalent caller happens to push the same words: the original caller's stack is rebalanced by its own frame. Natively the
declaration *is* the convention. Check 7 compares each bound symbol's declared callee-pops count with the original
callee's `ret N`: 26 symbols left (`build/x87/conv-pops.txt`), among them the crash's
`?FUN_0025d740@ThisNote_0025d740@...@QAEXI@Z` (declared `thiscall (unsigned)`, callee `ret`). Why -O0 survives:

```
-O0  call FUN_0025d740 ; sub esp, 4      (re-reserve what the callee "popped")  ...  mov esp, ebp ; pop ebp ; ret
-O1  call FUN_0025d740 ; add esp, 0x14   (frame size minus the 4 bytes it thinks were popped) ; pop esi/edi/ebx ; ret
```

With the 4 bytes not popped, -O1's epilogue pops callee-saved registers and the return address 4 bytes off. -O0
is not immune either: functions with a `double` local get a realigned frame and esp-relative locals (seen in the
`double r` rewrite of 0x350c0), and some -O0 epilogues are `add esp, N; pop ebp`.

Prototype `x87cc-o1dyn` (`build/x87/x87cc.py`): after the IR pipeline, a 64-byte alloca of opaque size in every
function forces an ebp frame, ebp-relative locals and a `lea esp, [ebp-N]` epilogue (plus a stack probe call; for
experiments only). That image passes frame 0 and matches 0-420. The next crash (before 450, a dlmalloc `free` of a
garbage pointer under an audio `Sequence` release) was bisected over TUs (`build/x87/bisect_loop.sh`, 11 steps,
mem2reg-only images) to `src/engine/audio/Sequence.cpp`, i.e. `equivalent/0x00256d40.cpp`: it declares the pool
release `FUN_00247550(void*)` with **one** argument and calls `FUN_00247550(FUN_00262030(track))`. The original
pushes `track` for `FUN_00262030`, pushes its result, and cleans both with one `add esp, 8`, so the release (a
two-word `(pool, item)` function, as all 40 other declarations say) receives `track` as its second word. -O0's
outgoing-argument area happens to still hold `track` there; with registers it holds something else. The same
"argument left on the stack for the next call" class as native10's stop 35 (and equiv.py can't see it: both sides
get the same stack words). Fix (`build/x87/patch-0x00256d40.diff`): declare two parameters and pass `track`;
equiv.py: EQUIVALENT, promotable (69 inputs, 8/8 edges). With it the o1dyn image gets past the audio release
and stops at a third crash (`Obj_1f4b60::second`, a null+0x78 read, before 450), not chased.

So an optimised build has (at least) these source-bug classes to clear, none of them float: callee-pops
mismatches (check 7), arguments left on the stack for the next call (one more found here), and whatever the
remaining crashes are (`Obj_1f4b60::second`; `FUN_00201e00` in CWorldCollisionManager and `FUN_001bc5b0` writing
through a float-valued pointer, both seen in the mixed images below).

For a shipping optimised build the callee-pops class has to be zero (check 7 plus the "caller symbols in another
convention than their definition" counts of the same check), and the second crash's class found and checked.

## 5. The scanner: `tools/x87_scan.py`

```
build/venv/bin/python tools/x87_scan.py --wine <Wine link dir> [--out build/x87/scan] [--addr 0x350c0 ...]
```

For each game function with x87 code and a definition in the image it simulates the x87 stack over the original
(XBE) and over our compiled code (image + map + bindings.json), linear sweep, and counts **consuming round trips**:
an "excess" value (an arithmetic result, `fild`, a double load) stored to a 32-bit stack slot, read back, and the
read value used by arithmetic, a compare, an integer conversion, a double store or the return in st(0). A value
only copied on to float memory doesn't count (MSVC would have stored it anyway). Integer copies of a rounded
slot keep it rounded (struct copies, mask tricks). It is a heuristic (indirect jumps, esp tracking across stdcall
callees, chunked functions), meant to rank functions, not to prove them.

| image | functions with x87 code | counts agree | image rounds more (sites) | image rounds less (sites) |
|---|---|---|---|---|
| -O0 (current) | 3,050 | 2,416 | 355 (+1,694): 67 in matches/, 288 in equivalent/ | 279 (-1,222): 10 matches/, 269 equivalent/ |
| o1dyn | 3,050 | 2,457 | 121 (+496): 17 / 104 | 472 (-3,062): 24 / 448 |

Reading: at -O0 about **630 functions** (≈ 2,900 sites) round differently from the original; 77 of them are
byte-matched sources (the source is right, clang -O0 is not MSVC), the rest are equivalents whose spelling lost
the original's register/memory split (equiv.py compares floats with a tolerance, so it accepts both). At -O1 the
"rounds more" side shrinks to 121 functions, but the other side grows: LLVM keeps values MSVC spilled (it
rematerialises, folds bit tricks to `fabs`, and the equivalents' extra locals now live in registers).

Examples: 0x000350c0 (`float r` kept by MSVC across the store `p[1] = r`), 0x000a38c0 Cam::Update (+15),
0x00293450 CameraAnimationController (+20), 0x00102550 (`fabsf` in the source where MSVC rounds through a union:
the image rounds *less*). Lists: `build/x87/scan-o0.txt`, `scan-o1dyn.txt` (+ `.json` per function with the
site addresses).

## 6. Options considered (coordinator's list)

**The working hypothesis** ("with PC=53, `double` temporaries and `float` stores reproduce x87 on SSE2/NEON")
is **right, with one correction**: the 64-bit build also needs `-ffp-eval-method=double`, because the original
evaluates *float* sub-expressions inside one statement in 53 bits as well (`float t = a*b + c` rounds once on x87,
twice in SSE/NEON float arithmetic), and `-ffp-contract=off` (arm64 contracts to `fmadd` by default). Experiment
(`build/x87/hyp/`): one loop kernel over 200,000 float triples (`t = a*b+c; u = t/(a-c+0.5f); v = u*u-t*b;
w = sqrt|v|`, stores v and `w + t*u`), hashed:

| build | hash |
|---|---|
| **MSVC 7.1 /O2, x87 (the original's compiler; it spills `t` to a float slot, keeps u, v, w in registers)** | **4db0c63c** |
| clang -O0 x87, the faithful spelling (`float t`, `double u, v, w`, float stores) | **4db0c63c** |
| arm64, the faithful spelling, `-ffp-eval-method=double -ffp-contract=off` | **4db0c63c** |
| clang -O2 i686 SSE2 / arm64, faithful spelling, without `-ffp-eval-method=double` | db9a29a1 |
| arm64 faithful spelling, contraction on (default) | eb5a3da7 |
| "all double" (t too), any target | d0b2e2e3 |
| the plain float source: clang -O0 x87 = arm64 with `-ffp-eval-method=double` | ca266a3f |
| the plain float source: clang -O1 x87 | 2d405e43 |
| the faithful spelling, clang **-O1** x87 without `-ffp-eval-method=double` (the `float t` stays unrounded) | d0b2e2e3 |
| the faithful spelling, clang -O1 and -O0 x87 **with** `-ffp-eval-method=double` | **4db0c63c** |
| the plain float source, clang -O0/-O1 x87 with `-ffp-eval-method=double` | ca266a3f |
| the plain float source: arm64 float evaluation | a8ab06bf |

So `-ffp-eval-method=double -ffp-contract=off` is the one flag set for *every* target, i686 x87 included: with it
-O0, -O1, x86-64 and arm64 all compute the same bits for the same source. x87 at PC=53 *is* IEEE double arithmetic for these values (the extended exponent range only matters beyond
double's range; float-derived values don't get there), and one source spelling gives the same bits on i686 x87
(any -O), x86-64 SSE2 and arm64 NEON. Note `t`: even in this tiny loop MSVC rounded one local (register
pressure), so the spelling must follow the original's code, not a blanket rule.

**(1) Soft-float for everything.** Buys nothing over hardware double: the arithmetic the original does *is*
IEEE double (above), which SSE2/NEON do natively and exactly; what is hard is knowing *where* the original rounded
to float, and soft-float needs exactly the same site list. Cost: the game has float code in 3,050 functions
(physics, animation, camera, particles, audio DSP); a software double is tens of times slower per operation. Not
recommended except for the few operations below.

**(2) Soft intrinsics.** Recommended. What the original actually uses (game code only, `build/x87/intrinsics.py`;
"ran" = functions seen in the trace census `build/reach1/census.json`, 2,372 functions, a lower bound):

| instruction / helper | sites | functions | ran |
|---|---|---|---|
| `call _ftol` (float->int, truncating) | 391 | 193 | 62 |
| `fsqrt` | 339 | 238 | 79 |
| `fcos` | 92 | 50 | 19 |
| `fsin` | 80 | 46 | 15 |
| `call _CIpow` | 29 | 8 | 4 |
| `fpatan` (atan2/atan) | 28 | 19 | 10 |
| `call atof` | 23 | 9 | 3 |
| `call floor` | 20 | 13 | 2 |
| `fptan` | 14 | 12 | 2 |
| `frndint`, `f2xm1`, `fscale` (inline exp/pow) | 10 each | 8 each | 2 each |
| `fyl2x` (log) | 9 | 3 | 0 |
| `call _CIfmod` / `_CIacos` / `_CIasin` | 9 / 4 / 4 | 5 / 3 / 3 | 2 / 1 / 2 |
| `ceil`, `frexp`, `ldexp` | 1 each | | 0 |
| `fistp` / `fprem` outside the CRT | 0 | | |

`fsqrt`, `_ftol`, `floor`/`ceil`, `frndint` and `fscale` are exact or correctly rounded by definition: any
correct implementation gives the same bits (SSE `sqrtsd`, `cvttsd2si`, NEON `fsqrt`, `fcvtzs` for in-range
values). `fmod` is exact too. The transcendental ones (`fsin`, `fcos`, `fptan`, `fpatan`, `f2xm1`, `fyl2x`, `pow`,
`acos`/`asin`) differ between implementations by an ULP in a few percent of arguments (measured above), and the
golden recordings carry *xemu-on-macOS* results (QEMU calls the host libm for `fsin`/`fcos`/`fptan`), which no
clean-room Wine build can reproduce. Plan: one deterministic implementation written with plain double
arithmetic (our own, or a permissively licensed upstream such as FreeBSD msun/fdlibm, or CORE-MATH's
correctly-rounded functions; never Bochs/QEMU code), used (a) natively on every target as `hulk_sin` etc. in place
of msvcrt's, and (b) in the hybrid build by hooking the original's call sites/inline `fsin` sequences, so new golden
recordings carry the same results. That removes host libm from both sides; old recordings stay as they are (the
replay just diverges a little earlier where those functions run).

**(3) `-fsanitize=float-cast-overflow`.** Worth one test build. clang i686 compiles it in trap mode without a
runtime (`-fsanitize=float-cast-overflow -fsanitize-trap=float-cast-overflow`: a compare + trap before each
conversion; checked). The x87 (`fistp`, the game's `_ftol`) and SSE (`cvttss2si`) give 0x80000000 for
out-of-range values, arm64 `fcvtzs` saturates, and `(unsigned)` of a negative float wraps on x86 (`_ftol`/clang
both go through a 64-bit `fistp`) but gives 0 with arm64 `fcvtzu`. 391 `_ftol` call sites; a replay with the trap
build lists the ones that actually overflow, each to be spelled explicitly (`(int)(unsigned)` / clamp) so arm64
matches.

**(4) `-Wconversion` family as a finder.** Measured over the tree (`build/x87/wfloat.py`, attributed to functions
by the snapshot's `// 0xADDR` markers): `-Wdouble-promotion` 3,828 warnings in 518 functions,
`-Wimplicit-float-conversion` 392 in 84, `-Wimplicit-int-float-conversion` 95 in 48, `-Wfloat-conversion` 0;
together 4,315 warnings in 550 functions. Against the scanner's 634 functions whose rounding differs at -O0 they
hit 307 (recall 48%, precision 56%). They flag spellings (`float * double` promotions, which are usually the
literal `0.5` in an equivalent), not the original's register/memory split, which is what decides the result.
Noise for this purpose; the scanner list is the work list. (The same pass also printed 5 `-Warray-bounds` and 2
`-Wreturn-type` sites, unrelated to floats but worth a look for an optimised build.)

**(5) All floats to double.** Refuted by the kernel experiment: "all double" (d0b2e2e3) differs from the original
(4db0c63c) because the original rounds every value that goes through float memory (members, spills across calls:
6,530 consuming round trips in 645 functions, 2,298 of them spills across calls); struct fields and on-disk data
must stay float anyway. Doubles only where the original kept a register.

## 7. Recommendation

**32-bit, short term (the replay work now).**

1. Keep -O0 and x87 (`-mno-sse -mfpmath=387`); the control word needs no change (0x027F on both sides; the
   proposed pin + log `build/x87/patch-x87-control-word.diff` makes it explicit and visible in the trace).
2. Fix float sites in the sources, in the order the replay meets them, using the scanner as the work list: for a
   diverging checkpoint, the functions on the path (camera, Hulk's position, physics) that `x87_scan.py` ranks are
   the candidates; rewrite the kept-in-register locals and temporaries as `double` (0x350c0's `double r` is the
   pattern), and where the image rounds *less* than the original (the scanner's "fewer" side, e.g. `fabsf` where
   MSVC rounds through a union) make the rounding explicit (`float` local, store). A byte-matched source keeps
   matching with such spellings (0x350c0 does); for equivalents equiv.py's float tolerance accepts both, so the
   proof is unchanged. No `volatile` pins needed for this (they force stores, i.e. the opposite).
3. Add `-ffp-eval-method=double -ffp-contract=off` to the i686 flags together with the first source fixes (no
   change to the kernel's -O0 result; it makes later -O1 and 64-bit builds agree with -O0). The one -O0 behaviour
   it changes is `return expr;` in a `float` function: rounded to float (C semantics, and unavoidable on 64-bit,
   where a float return travels in xmm0/s0 as a float). The original returns st(0) unrounded: the scanner finds 237
   functions whose `ret` leaves an unrounded arithmetic result (double-returning ones included); those whose
   callers compute with the result need a `double` return (or the caller-side computation inlined) in the faithful
   spelling. Measure with a replay before switching (prototype mode `x87cc-o0evd`; it first needs the duplicate
   `FUN_0004af40` declaration fixed, section 3; proposed flag diff `build/x87/patch-fp-flags.diff`).
   Don't switch to -O1 for precision: plain -O1
   fixes the "rounds more" side wholesale (355 -> 121 functions) but introduces its own deviations (472 functions
   round less than the original: rematerialised spills, bit tricks folded to `fabs`, `float` locals never
   rounded), and it needs the callee-pops class and the second crash class fixed first. It is the right thing for
   *shipping* performance later, once the sources say their float semantics explicitly; with
   `-ffp-eval-method=double` -O1 then gives the same bits as -O0.
4. Use the mixed build as a locator (prototype `build/x87/bisect.sh` with a TU list and `ON=o1dyn`): bisecting the
   172 TUs between "fixes 540/600/660/690" and "doesn't" names the functions whose spelling matters for the
   replay, which are then rewritten by hand (and the mixed build retired). It is diagnostic only: per-TU
   optimisation levels are not a shipping configuration.
5. Replace msvcrt's `sin`/`cos`/`tan`/`atan2`/`pow`/`exp`/`log`/`acos`/`asin` with our own deterministic
   implementations (soft intrinsics) and hook the same into the hybrid build before recording new golden replays.

**Long term, 64-bit (x86-64 SSE2, arm64 NEON).** Exact replay determinism against the *original* is not possible
in general (transcendentals depend on the recording host's libm through xemu; the original's spill decisions are
only reproduced where the sources spell them). But it is possible against *our own 32-bit build*, and that is
what to aim for:

- Flags: `-ffp-eval-method=double -ffp-contract=off`, no fast-math, no `-march` that enables FMA without
  `-ffp-contract=off`. With the faithful spellings the 64-bit image computes the same bits as the 32-bit x87 image
  (kernel experiment above: same hash on i686 x87, arm64 NEON); the remaining differences are the transcendentals
  (fixed by the soft intrinsics, which are plain double arithmetic and therefore identical everywhere) and
  float->int conversions out of range (fixed per site, found by the float-cast-overflow trap build).
- Replays: keep the hybrid recordings as the reference for the 32-bit build; record **native golden replays** from
  the 32-bit image (same pins, same `.hrp` format, checkpoints from the Wine image) and require the 64-bit
  images to match those bit for bit. Where they can't yet (sites not rewritten), compare the checkpoint regions
  with tolerances per region instead of the single hash: integer state (RNG, game state, counters) exact; camera,
  positions and velocities within N ULP or an absolute epsilon, with N recorded per region and tightened as sites
  are fixed. The hash stays the gate for the 32-bit image.
- Deterministic soft-float for the whole of gameplay is not needed: double arithmetic is already exact on all
  three targets; only the functions listed under (2) need software implementations.

**Effort estimate.** The scanner lists ~630 functions (-O0 image) whose rounding differs from the original
(≈1,700 extra and ≈1,200 missing round trips), 77 of them byte-matched sources and the rest equivalents. Not all
matter (rounding a value that is later only stored is harmless; the scanner already ignores those) and not all
run; the replay decides the order. A mixture is the plan: compiler flags for what flags can do (x87 PC53 on
32-bit, `-ffp-eval-method=double -ffp-contract=off` on 64-bit), source spellings for the rounding points, soft
intrinsics for the transcendentals.

## 8. Status (native15, 2026-10-20)

- Applied: the control-word pin + log (startup.cpp: `x87 control word 0x027f -> 0x027f` in the trace), the
  0x00256d40 two-word release, the FUN_0004af40 / FUN_00247890 declaration fixes (every TU now compiles with
  `-ffp-eval-method=double -ffp-contract=off`). The flags themselves are **not** switched on: the replay is
  identical through 750 but the image rounds 159 more returns than the original (list:
  `build/native15/flags-ret-lost.txt`); they need `double` returns first, and a `double` return type changes the
  callers' symbol (a binding rule in wine_link is the prerequisite).
- Source spelling: `hulk_freg` (include/compat/ptr.h) for locals the original keeps in registers (`float` under
  MSVC 7.1, so byte-matched sources keep matching; `double` elsewhere); volatile reads where MSVC would reuse a
  register but the original reloads the rounded store; sums in the listing's order (MSVC 7.1 reassociates them).
  49 byte-matched and 9 equivalent sources rewritten (docs/wine-build.md "native15").
- Transcendentals: sin, cos, tan, atan, atan2 and exp now run the original's x87 instructions natively
  (crt_glue.cpp); no checkpoint changed by it alone through 870.
- Replay: 0-420 and 480-780 match (the 540/600/660/690/720/750/780 differences were the precision class: the
  mixed-build locator named `physics/unk_2fa6b0.cpp`, `unknown/unk_22baf0.cpp` and `CChaseCamera.cpp`); 450
  is still -1 ULP (no candidate TU of the mixed build changes it: a function outside the scanner's "rounds more"
  list, or a transcendental); 810 differs in RNG and camera.
- cl5's round 17 makes equiv.py exact, so it now finds MSVC-side precision differences (99 flips, build/cl5/flips.txt);
  native14's natcheck (equiv.py on the clang object) finds the clang-side ones for leaf functions. The scanner's
  counts are a heuristic (volatile copies and unions inflate them); the locator plus natcheck are the reliable pair.

## 9. Status (native16, 2026-10-21)

- **Flags adopted**: `-ffp-eval-method=double -ffp-contract=off` are in tools/clang_probe.py's x87 flags. The
  prerequisite from section 8 is in place: 277 functions whose listing returns a computed st0 now return
  `hulk_freg` (151 of native15's 159 "lost" returns; the other 8 are members declared in shared headers), and
  tools/wine_link.py binds a caller's `float` reference (`...M...`) to the `double` definition (`...N...`) that
  differs only in the return code (x87-only: in st0 both come back alike; listed in wine-build.md "Bridges to
  remove"). The flags image gives the same checkpoint hashes as the image without them at every checkpoint both
  reached (0-6,000); strict link 0 errors with and without `--gfx`.
- **Replay**: 0-420 and 480-840 match. The physics divergences behind 810 and 840 were all this document's classes:
  register-kept locals and returns (`hulk_freg`), and two sums MSVC 7.1 reassociates (0x0022d180 normalize,
  0x0022c2b0 Mat::Transform's x row: `v1*m4 + v2*m8 + v0*m0 + m12`). The second kind is invisible to random-input
  checks (two summation orders at 53 bits almost always round to the same float), so neither `equiv.py` nor
  `--native` flags it; a listing-vs-source order check for fadd chains in byte-matched sources is the tool to build.
- **Transcendentals**: the 769 box-matrix difference was first suspected to be `fsin`/`fcos` (QEMU uses the host
  libm, Rosetta its own); the input to them already differed, so no transcendental divergence has been seen on the
  replay path yet. The software-implementation plan of section 3 stands for 64-bit.
- **`equiv.py --native` sweep** (cl6's round 18, 300 inputs, all 2,779 functions with x87 code): 2,374 equivalent,
  403 fail (57 ULP-sized, 35 NaN-payload sign after `x * -1.0f` (clang flips the sign bit, x87 `fmul` keeps the
  NaN's sign: harmless for real values), 12 unrounded returns of header virtuals, 296 other). 15 fixed by the
  greedy `autofix.py` (float/`hulk_freg` toggles until native-mode agrees), more by hand on the replay path.

## 10. float-cast-overflow build (ubsan1, 2026-10-21)

`HULK_WINE_SANITIZE=float-cast` (tools/clang_probe.py `SANITIZE`, `msvc` objects = the game's TUs only; unset = unchanged)
compiles every float -> integer conversion with `-fsanitize=float-cast-overflow`. wine_link.py then builds
src/platform/sdl/xdk/startup.cpp with `HULK_UBSAN_FLOAT=1`, which defines `__ubsan_handle_float_cast_overflow`: it logs one
`ubsan float-cast` trace line per site at its 1st, 2nd, 4th ... hit (return address, source file:line:col, types, frame,
value) and returns, so one replay lists every site (no UBSan runtime needed under Wine; the conversion then gives what the
Wine image always gave). `HULK_WINE_SANITIZE=float-cast-trap` adds `-fsanitize-trap` (a ud2, no handler; not run).
`tools/ubsan_sites.py TRACE --map hulk-strict.map` folds the log into `sites.jsonl` (function, XBE address, source line,
hits, first frame, sample value). Run the replay with tools/wine_replay_job.py as usual.

Result on play3 (whole recording, then to frame 100,200): one site, `FUN_003078a0` (CollisionObjectLoader.cpp:820), a NaN
into the `(__int64)` step of the already-faithful `(int)(__int64)` spelling (0 on x86 and arm64 alike). No direct
`int`/`unsigned` conversion overflowed. Limits: the path diverges from the recording at ~frame 1,020 and needed four
workspace-only crash guards after frame 3,900; see build/ubsan1/notes.md.

## 11. What xemu's fsin/fcos/fptan/fpatan really compute (cap1, 2026-10-21)

Measured, not read from source: `tools/xemu_x87_probe.py` boots the hybrid image in xemu 0.8.136 (`-S -snapshot`, muted),
stops at the first call of an early game function, writes `fninit; fldcw 0x37f; fld tbyte [..]; OP` under the stack and
single-steps it over the GDB stub, then reads all 80 bits of ST(0) from the `g` packet (offset 100, 10 bytes per register).
Inputs are exact 80-bit values with full 64-bit mantissas (126 for fsin/fcos/fptan: magnitudes 1e-6 to 1e10 plus 2^40 and
2^62; 40 pairs for fpatan). Reference: mpmath at 400 bits, rounded to nearest at 64 bits.

| op | result |
|---|---|
| `fsin`, `fcos`, `fptan` (42 each) | **the host double libm**: every result has its low 11 mantissa bits zero (42/42) and equals `sin`/`cos`/`tan` of the input *rounded to double*, computed in double and widened, bit for bit (42/42 each). Errors against the exact value reach thousands of 64-bit ULPs (an input rounded to 53 bits, then libm). `fptan` pushes exactly 1.0 |
| `fpatan` (40) | **correct 80-bit arithmetic**: bit-identical to the correctly rounded 64-bit-mantissa value in 40/40, no zero low bits (softfloat, not libm) |

So xemu's three trig helpers are the double path (as Unicorn 2.1.4's are, cl6 / equivalence.md round 18); `fpatan` is not.
Real hardware computes all four in extended precision (an `fsin` result has a full 64-bit mantissa, within about 1 ULP of the
64-bit value for arguments below 2^63; I could not run hardware here, so that part is Intel's documented behaviour).
Consequences for the soft intrinsics:
- **Follow real hardware, not xemu**, for `fsin`/`fcos`/`fptan`: compute in extended or at least double-double and round
  once. A float-returning game function then agrees with the original to the last bit of the float in nearly every
  case, while xemu's own results differ from hardware by up to ~2^-53 relative (a double ULP).
- **`fpatan`**: xemu already equals the correctly rounded value, so a correct implementation matches both xemu and
  hardware (to within hardware's ~1 ULP).
- The recordings made under xemu (all traces) carry the double-libm `fsin`/`fcos`/`fptan` results of the macOS host's libm:
  replay of recorded callee results is unaffected, but golden outputs of the *native* image compared with them can differ
  in the last double bit wherever the result is kept as a double. Where the hybrid build must reproduce xemu bit for bit
  (xemu A/B tests only), a `sin(double)` through host libm is what matches.
- Raw results: `build/cap1/x87-probe.json` (local, not tracked); scorer `build/cap1/x87_score.py`.

## 12. Soft intrinsics (soft-intrinsics, 2026-10-24)

Section 6 (2) is implemented: [soft-x87.md](soft-x87.md), `src/platform/sdl/crt/softx87.{h,cpp}` (integer-only 80-bit x87 `fsin fcos fptan fpatan
f2xm1 fyl2x fyl2xp1 fscale frndint fprem fprem1 fsqrt` with the FPU's 66-bit pi reduction, plus the double-level `sin cos tan atan atan2
exp log log10 pow asin acos fmod`). Switch: `HULK_SOFT_X87=1` in the environment of a Wine build job (off by default). On play3 the switch changes no
checkpoint hash in 30,000 frames (1,001 checkpoints, identical to the control, which diverges from the recording at 3900 for other reasons); the game calls
`sin` more than 1,000,000 times in the first 3,000 frames.

## 13. SSE2 float, the default (perf1, 2026-10-26)

**Why.** A headless play3 replay spent 72-75% of its main-thread samples on x87 instructions (an in-process sampler,
mac2 and the laptop; `fstp`/`fld m32` alone 44%). Rosetta 2 emulates x87 in software: the game's 4x4 matrix multiply
(FUN_0022ca90) takes 2.75 us per call as x87 code at any optimisation level and 43 ns as SSE2 code (arm64: 19 ns).
Game simulation and the game's own render traversal were 66% and 31% of a frame; the pddi front end 0.6%, bgfx
(noop) and the draw sink under 0.2%, audio 2.7%, waits 0.4%.

**What.** The game's TUs (clang_probe's `msvc` configuration, and equiv.py `--wine`) are compiled with
`-msse2 -mfpmath=sse -ffp-eval-method=double -ffp-contract=off` at -O0 unless `HULK_WINE_FLOAT=x87` (the x87 build of
the sections above, unchanged: same flags, cache keys and objects). `clang_probe.sse_compile` compiles to IR, runs
three passes and compiles the IR to the object. They cover the one mechanism by which the two differ here: x87
code computes on with a call's st(0) result unrounded, SSE code must store it first.

| pass | what | found by |
|---|---|---|
| x87-keep (`sse_x87fn_ir`) | Functions that call an 80-bit math shim (sin cos tan atan atan2 exp asin acos log log10 pow return the x87 result in st(0), as the original's inlined `fpatan` leaves it) and, to a fixpoint, functions that use the float/double result of a call to such a function, stay x87 code (a function attribute group with `-sse,-sse2`; byte-identical to the x87 build's code). 268 functions (109 seeds). | play3 differed at 450 (camera y +1 ULP, CChaseCamera FUN_000a04c0: `atan2(...)*57.29...`) and from 780 (gameplay RNG); the closure: 0x000fce60 uses 0x00224ea0 (`Angle`, returns atan2's st(0)) |
| retfix (`sse_retfix_ir`) | A call declared `float` is read as `double` (`call double` + `fptrunc`; both return in st(0) on i686) and the caller's `fpext` uses the double: MSVC 7.1 never rounds a returned st(0), so callees return wider values than their callers declare (`hulk_freg`); x87 code keeps them, SSE code would round to float. | from 870: ImpulseBasedCollisionSolver FUN_002f8300, the virtual `v4()` |
| castfix (`sse_castfix_ir`) | `fpext(sitofp/uitofp ... to float)` becomes a direct conversion to double: x87 (`fild`) and MSVC never round `(float)i` inside an expression; SSE (`cvtsi2ss`) does. | changes no play3 checkpoint; checker parity (0x00320330) |

The x87-keep list is computed by the probe after the snapshot (`compute_x87_keep`, one IR scan per TU, cached; written
to `build/clang-probe/x87_keep.txt`, `tools/x87_keep.py` prints it). Callees are identified by address through
wine_link's binding map (`bindings.json`: the symbol a caller names -> address; definitions: address -> symbol; a
`hulk_freg` function's clang name differs from the verification build's in the return type letter, N for M), which
`wine_link.py --no-inventory --no-link` makes from the verification build alone: `wine_build_run.py` runs that before
the probe when the map is not reused (stage `map`), and the link reuses it. Each object's cache key carries the
x87-keep functions its TU defines. Indirect calls are not followed (no virtual function returns such a value). A local
build (`clang_probe.py` by hand) needs the map first, `wine_link.py --no-inventory --no-link`; without it the probe says
"no binding map: callees by FUN_ name" and the closure misses callees with other names (0x00224ea0's `Angle`).
equiv.py `--wine` checks the same code (`sse_compile`; `--float sse|x87`, `--x87-keep FILE`) and binds clang's
`__xmm@`/`__ymm@` constant-pool symbols (negation's sign mask) as the object's own read-only data.

**How it was found.** Bisected with mixed images (the TUs of a list SSE, the rest x87; within a TU, functions switched
with `#pragma clang attribute push(__attribute__((target("sse2"))), apply_to = function)` around their lines), each
step a link-only build on one lineage and a replay to 1050 compared with the x87 control (`build/perf1/bis/`).
Stack-layout source bugs show up too: 0x001bc530 (a three-float write into a two-float local, fixed in 5d0b43182)
crashed the SSE image at 1350.

**Result.** play3, mac2, HEAD: x87 control against SSE, checkpoints identical at all common frames (286, 0-8550;
also with the rng/camera/clock region lines). Gameplay 13.8 -> 2.2 ms/frame (6.3x), the level load (420-480) 9.3 ->
2.5 s, a replay to 8500 frames 122 -> 22 s. The HEAD builds (x87 control and default SSE, one lineage): 2,571 of 2,571
TUs compile in both, strict link rc 0, 1,329 symbols unbound in both.

**Checker.** `equiv.py --wine --inputs 60` over all 5,140 equivalent/ sources, `--float x87` against `--float sse`:
x87 5,014 equivalent / 118 fail / 5 inconclusive / 3 unsupported; SSE 5,010 / 122 / 5 / 3. Changed: 0x00309520 passes
under SSE only; 0x000ffc40 and 0x001065b0 failed on a signalling NaN that the SSE conversions quiet (the original copies
the bits): a new rule, `nanquiet`, counts such an input inconclusive, as `nansign` does a NaN's sign (both pass then).
Open: 0x000e14b0 and 0x000e8790 (the same shape: a float from a call through the function pointer DAT_004de948 times
`(reverse == 0) * 2 - 1`, then a virtual call; under SSE three patched inputs report `this` of that call) and
0x001bea80 (a byte argument of call #19); neither changes a play3 checkpoint. `tests/equiv/regress.py`: 387/387 with
SSE the default; three cases about x87-only artefacts are pinned to x87 with the per-case `float` option
(nan_sign_off: SSE negates with a sign-mask xor, as fchs does; lstatic_off; f0e60 vsplit_wrong, whose first
difference changes).

## Files

- `tools/x87_scan.py`: the scanner (tracked).
- `tools/x87_keep.py`: section 13's x87-keep list (tracked); `build/perf1/` (local): the profiler, bisect scripts and runs.
- `tools/xemu_x87_probe.py`: the xemu x87 probe of section 11 (tracked; mac2 only).
- `build/x87/` (local): `x87cc.py` (compiler stand-in: modes o0, o1, o1dyn, sroadyn, m2rdyn, o0sroa, bis*),
  `mkws.sh`, `link.sh`, `rrun.sh`, `bisect.sh`, `bisect_loop.sh`, `scan-*.{txt,json}`, `intrinsics.{py,json}`,
  `wfloat.py`, `conv-pops.{txt,json}`, `patch-x87-control-word.diff`, `RESUME.md`; the probes `cw/` (host control word,
  transcendentals; `crcheck.py`), `msvc/` (MSVC 7.1 construct probe + listing), `hyp/` (the kernel experiment).
