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
| transcendentals | `softx87` (integer only; native CRT table rows) | the same | same results on both targets (hash) |
| control word, denormals | nothing (SSE: MXCSR default, no FTZ/DAZ) | FPCR cleared by `entry_posix` (FZ/DN/AH off) | wine-float.md, native-android.md section 6 |

The four passes are in `tools/native_float.py`. The native compiles apply them in `native_mac.retarget()` when
`HULK_NATIVE_FPFIX=1` (off by default; the setting is part of the cache key, so the default objects are unchanged). The
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
double first, which is what plain 64-bit code does): jobs 63434 / 63436, one lineage on one build host. RESULT PENDING.

## The `float` callers of `hulk_freg` functions (unb1's 676 names)

`build/flt1/scripts/freg_callers.py`: 702 sources define a function returning `hulk_freg`; 750 declarations in 439
sources (23 matches/, 416 equivalent/) declare such a callee `float`. The batch spells them `hulk_freg` (the same type
under MSVC 7.1, so the matches/ objects are unchanged). On the 64-bit builds it makes the declarations agree with the
definitions without retfix64; on the Wine build it changes the code (the -O0 temporaries) but not the values, since
retfix already reads those calls as doubles. Gates and proof: below.

GATES PENDING.

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

1. Make `HULK_NATIVE_FPFIX=1` the default of the native compiles (a decision: it changes every native object; the
   start-up stop is unchanged with it, above).
2. x87ext for 80-bit values returned through functions (the 2 + 9 sites above).
3. `equiv.py --x64` with the passes on its 64-bit side, so the per-function check covers them.
4. The first Linux run (platform layer), then a float comparison once the start-up reaches the game loop.
