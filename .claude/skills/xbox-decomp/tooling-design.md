# Tooling worth recreating (what each piece does and why)

The Hulk project built these; another Xbox decomp would want the same capabilities. Names in parentheses are this
repo's implementations (see this-repo.md).

## 1. Function list and packets

- A function list from Ghidra, then a deterministic fixer that walks each function's real control-flow graph
  (fall-through, jumps, jump tables; not calls) to correct truncated sizes, fold fragments into parents, and find
  unlisted code in gaps. *Why: truncated entries can never match, and fragments matched as functions are wrong.*
- A per-function "packet": assembly, a decompiler hint, referenced data, RTTI class names, caller/callee names.
  It is the unit of work for every agent and model. (`tools/packet.py`)
- RTTI-derived class headers (vtables, slot counts, inheritance) generated once and shared, so sources stop
  inventing per-file placeholder classes. (`include/gen/`)

## 2. Byte-match compare

- Compile one self-contained translation unit with the original compiler (MSVC 7.1 runs on macOS/Linux through a
  small PE loader such as wibo), diff the target function's bytes against the executable with relocations masked,
  print an aligned instruction diff. Per-file flag comments (`// cl-flags: /Oy- /O1 /GS`) with a whitelist.
  (`tools/compare.py`)
- A relocation verifier: every relocated reference in our object must resolve to the symbol at the address the
  original references; float constants compared by bits; global initializers compared with the original's bytes.
  *Why: masked relocations hide wrong callees and wrong constants.* (`tools/verify_relocs.py`)

## 3. Equivalence checker (differential execution)

Proves "behaves like the original" without identical bytes. (`tools/equiv.py`, design in docs/equivalence.md)

- **Level 1**: compiles. **Level 2**: same references (callees, globals, vtables, strings, float constants,
  initializers), with symbols bound to original addresses in a fixed order: explicit map comments, content (strings,
  float bits, vtables by RTTI name), names carrying addresses, instruction pairing (exact when bytes are identical),
  first-use order. CRT routines are recognised in the executable by behaviour and run for real on both sides.
- **Level 3**: run the original bytes and our object side by side in Unicorn on fuzzed inputs. Memory is a pure
  function of (seed, epoch, address), so both runs see the same bytes wherever they read. Every outgoing call is a
  stub that records arguments and returns the same fuzzed value to both sides; compare call sequence, arguments,
  memory writes between calls, return value, callee-saved registers, stack balance, x87 results exactly.
- **Input generation that reaches code**: argument types from the mangled signature; seed modes (wide pointers,
  iterator ranges, small numbers, dictionaries planting the original's compare constants, narrow memory, boundary
  ints, stubs returning 0/1); loop repair (patch a runaway loop's bound after discovering it); walk sentinels for
  list/tree walks; small-count planting; directed inputs for uncovered branches.
- **Verdicts**: equivalent / fail / inconclusive (too few completed inputs or coverage under 25%) / unsupported.
  A separate **promotable** flag adds the promotion bar: no level-2 conflicts, >= 75% branch coverage, >= 50
  completed inputs (run with 3,000), at most 10% wild inputs. Status keeps its meaning; tools read `promotable`.
- **Annotations** in source comments: map a symbol to an address; declare register conventions MSVC can't express.
- **Wine mode**: compile the same source with clang as the Wine build does and run the same comparison, so a
  source is port-ready only if both compilers' objects behave like the original.
- **Process**: checker changes come in numbered rounds, each rule switchable off by environment variable, each with
  regression cases (real functions plus deliberately wrong mutants that must keep failing) and an old-vs-new sample
  run. *Why: a checker that silently passes wrong code poisons everything downstream.*
- Known blind spots to document, not paper over: callees are opaque, coverage is branch not path, data-dependent
  differences can survive full coverage, writable globals are seeded with initial values.

## 4. Trace capture and replay checker

Fuzzing can't reach some paths and its stubs return invented values. Record real game states once; replay every
proven function against them on every change. (`tools/trace_gate.py`, `tools/trace_capture.py`, `tools/equiv_replay.py`)

- Run the original executable (plus deterministic test hooks only) in xemu under gdb. At a target's entry, start a
  co-simulation: run the original bytes in Unicorn with registers and touched memory pages read from the paused
  game; at each callee, let the real game run the callee and record its results (eax/edx/ecx, ST0, bytes it changed).
  Store per-call records in a database (game memory: never commit).
- Gate recorder: patch every target's entry to count calls in a guest table and stop at one shared gate only when
  the host wants that call. One permanent breakpoint instead of hundreds; also yields a census of what ran when.
- Replay compares our function against the recorded call (same callee results), giving a confidence tier per
  function. Recorder bugs (stack addresses stored in frames, temp breakpoints re-hit in loops, by-value structs
  overwriting return slots) are common: when replay disagrees, suspect the recorder before the source.
- Sharding: run captures on several hosts/instances; never-returning or boot-time polling functions get their own
  session.

## 5. Hybrid build

Patch compiled functions into the original executable in a new section with 5-byte jumps, run it in xemu with
determinism hooks (fixed frame time, constant seed, skip intro, pinned date and RNG, polls as the input clock), and
compare against the hooks-only build on the same recorded input; bisect failures by function tiers (identical first,
then equivalent). It finds behaviour bugs no byte diff sees, and it produces the input recordings and checkpoint
hashes that the Wine build replays. (`tools/patch_xbe.py`, `tools/hybrid_run.py`, `tools/hybrid_test.py`)

## 6. Wine build

Generate one source tree from the verified functions (merged translation units, shared headers), compile with clang
i686 x87 `-O0 -ffp-eval-method=double -ffp-contract=off`, bind unresolved symbols to the original layout, link with
the player's data and a platform layer (SDL3 input/audio, bgfx graphics behind the game's renderer interface,
FFmpeg for video, XDK-shaped shims reimplemented from interfaces), run under Wine, replay a recording, compare
checkpoint hashes (FNV over RNG state, boot step, camera position, game clock, every 30 frames). Headless with a null
renderer, so it runs on any queue host. A per-host build "lineage" keeps incremental state; images must be
reproducible across hosts. (`tools/wine_*.py`, `tools/build_tree.py`, `tools/wine_build_job.py`)

## 7. Shared job queue

One queue, many hosts, many agents. (`tools/jobq.py`, docs/compute.md)

- **Submit/wait/result/status/cancel** from any agent; a SQLite queue and a scheduler daemon that starts on submit
  and exits when idle. Jobs have `--needs` capabilities (equiv, msvc, clang, wine, wine-gfx, xemu), slots, a
  wall-clock limit, attempts, priority, output paths to fetch back.
- **Host model**: each host has configured slots, capabilities and a preference; the daemon reads each host's load
  and shrinks its usable slots by load from outside the queue, prefers remote hosts and uses the laptop only when
  they're full. Host config (untracked, it holds user/host names) reloads live: no restart for slot/cap edits.
- **Big jobs** (>= 4 slots) reserve hosts they could run on, or a stream of 1-slot jobs starves them.
- **Workspaces**: each job runs in a copy-on-write clone of a per-host cached base tree (`git archive HEAD` of the
  tool directories, keyed by content hash) plus the job's overlay files (uncommitted tools/sources it ships).
  Large shared inputs (compilers, venv, extracted disc) are symlinked to the host's own copies; game data never
  travels with a job.
- **States**: done, failed (command exit != 0: not retried), gave up (infrastructure failed N times: ssh drop, limit),
  cancelled. A daemon restart re-queues running jobs, but some end "gave up" and must be resubmitted.
- **Batch front-ends**: an equivalence batch submitter that appends results to a JSONL as they arrive and skips
  addresses already present (rerun to resume); sharded regression runs.
- **Safety at submit, dispatch and on the host**: emulator jobs must carry `-snapshot` and may not name disk
  backup/mirror commands or the emulator's settings folder.

## 8. Model farm (optional)

A lane runner that feeds packets to local or subscription models with tiers of attempts, records every attempt,
auto-verifies and commits matches. Small functions (< 100 bytes) suit fine-tuned local models; larger ones need
frontier models; equivalence needs the strongest. Benchmark a new model on a fixed held-out set before giving it a
lane, and stop lanes that rewrite sources under agents doing structural work. (`farm/`)

## 9. Progress and debt reporting

Generated, never hand-edited: a README status table and a treemap of functions by size and state
(`tools/progress.py`), and a tech-debt table of proven-but-ugly sources (`tools/tech_debt.py`). Formatters that keep a
reformatted file only if it compiles to the same object (`tools/format_matches.py`, `tools/format_equivalents.py`).
