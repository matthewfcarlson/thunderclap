# 09: Equivalent decomp for large functions

## Status (2026-10-10)
- **Deliverables 1 and 2 are done.** `tools/equiv.py SRC 0xADDR` covers levels 1–3; see
  [docs/equivalence.md](../equivalence.md) for usage, design and limits. It's usable as a library
  (`equiv.verify(...)` returns the JSON report) and as a CLI.
- Validated on ground truth: `tests/equiv/selftest.py` (300 matches against themselves, plus the same
  sources recompiled with `/O1` and `/Oy-`) and `tests/equiv/mutate.py` (mutation suite). Numbers are
  in the journal entry of 2026-10-10.
- **Open:** deliverables 3–4 (`submit_equiv` in the farm, a tier file, the A/B, `equivalent/` and the
  README row). Captured xemu snapshots as level-3 inputs aren't done yet either.

## Goal
Give every large game function compilable C++ that behaves like the original, without requiring byte-identical codegen. Build a verifier that proves "same behaviour" automatically, then a farm mode that uses it as its feedback loop.

## Why
- Byte-matching hit rates collapse with size: about 28% per attempt under 64 B, about 10% at 160–400 B with Sonnet ($0.40–0.70 per match), and 0 of 51 over 400 B. Functions over 160 B hold most of the remaining 2 MB.
- The port ([roadmap](../roadmap.md)) needs correct source, not matching source. Most of a large function's byte diff is register allocation and instruction scheduling, which don't change behaviour.
- What we lose without a byte-match is the free correctness proof. This task replaces it.

## Verification ladder
A candidate passes the highest level it can reach. Each level is cheaper than the next, so failures are caught early.

1. **Compiles** with MSVC 7.1 against the shared headers ([task 02](02-rtti-headers.md)), and also with host clang (`-m32`) to catch MSVC-only code early.
2. **Same references.** `verify_relocs.py` already resolves every relocation to a symbol. Require that the candidate calls the same functions, reads and writes the same globals, uses the same vtable slots and the same float/string constants as the original. Compare these as sets, plus call order along each path where it's cheap. This alone rejects most wrong decompiles, and costs nothing to run.
3. **Differential execution (the core of this task).** Run the original function's bytes and our compiled function side by side in an x86-32 emulator ([Unicorn](https://www.unicorn-engine.org/)), from the same starting state:
   - **Memory:** map the XBE's sections at their original addresses, so globals and constants resolve for both versions. Load our object at a scratch address and link its externals to original addresses (the same table the hybrid build uses).
   - **Callees:** stub every call out of the function under test. A stub records the callee address and its arguments, and returns a recorded or fuzzed value. Both runs must make the same calls, in the same order, with the same arguments.
   - **Inputs:** `this`, the arguments and the memory they point to. Start with fuzzed inputs shaped by the class layout from the shared headers. Later, use real snapshots captured in xemu (GDB stub, breakpoint at the function entry, dump the registers plus the pages the function touches).
   - **Compare:** the return value, every memory write (address and value), the call trace, and floating-point results within a small tolerance (x87 precision can differ with code order).
   - **Pass:** identical over N inputs (start with 64 fuzzed plus every captured snapshot), with branch coverage reported so a pass that never ran half the function is visible.
4. **Hybrid build** ([task 06](06-hybrid-patch-build.md)): patched into the XBE and exercised in xemu, with recorded input replays compared against the original. This catches what the per-function harness can't, such as timing and initialization order.

Level 3 is the bar for **equivalent**. Below it, a function is a **draft**.

## Farm mode
- A second tool alongside `submit_cpp`: `submit_equiv` runs levels 1–3 and replies with a compact *behaviour* diff. Examples: "call #3 went to 0x1234 instead of 0x5678", "write to this+0x40 was 1.0, expected 0.5", "branch at +0x6a never taken; add an input that reaches it". This is the feedback that makes a model converge, the same way the asm diff does for matching.
- The tier ladder is unchanged, but turns are worth more on big functions: higher `maxOutput` (tiers can set it now), more attempts, and the shared headers in the packet.
- Output: `equivalent/<addr>.cpp` with a header comment giving the level reached, the input count and the coverage. Never overwrite a matched function.
- Priority queue from the [subsystem map](07-subsystem-map.md): the platform seams (`pddi`, controller, audio, movie), the game loop, camera and HUD first.
- A later matching pass can still upgrade an equivalent function, with the permuter seeded from its source.

## Deliverables
1. `tools/equiv.py SRC 0xADDR`: the level 1–3 verifier, with a JSON report (level, mismatches, coverage).
2. Validation on known ground truth: every function in `matches/` must pass level 3 against itself, with no false failures. Mutated copies, such as a swapped operand, a dropped call or an off-by-one offset, must fail, with no false passes.
3. `submit_equiv` in the farm, with a tier file for equivalent mode, and an A/B on about 40 large functions versus matching mode: pass rate and $/function.
4. `equivalent/` plus progress reporting: the README status table gets an "equivalent" row and a combined coverage figure in bytes.

## Done when
- The verifier has no false passes on the mutation set, and no false failures on the existing matches.
- The farm produces level-3 equivalent functions for large functions at a measured cost per function that we can plan the remaining 2 MB around.
