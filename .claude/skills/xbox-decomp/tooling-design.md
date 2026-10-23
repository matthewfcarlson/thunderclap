# Tooling worth building (what each piece does and why)

The capabilities a full Xbox decomp-and-port project ends up needing, roughly in the order you need them. If the
repo has a this-repo.md, it maps each to that project's implementation.

## 1. Function list and packets

- A function list from the disassembler, then a deterministic fixer that walks each function's real control-flow
  graph (fall-through, jumps, jump tables; not calls) to correct truncated sizes, fold fragments into parents, and
  classify code in the gaps between listed functions (referenced code, jump/index tables, padding, unreferenced
  COMDAT copies). Log every change with its evidence and re-check affected verified sources at the new sizes.
  *Why: truncated entries can never match, and fragments matched as functions are wrong.*
- A per-function **packet**: symbolized assembly, a decompiler hint, referenced data (string text, float values,
  vftable names), RTTI class and slot, caller/callee names. It is the unit of work for every agent and model.
- An **RTTI walker** (type descriptors, complete object locators, hierarchies, vtables) and a small MSVC
  demangler; the disassembler's own RTTI support may not handle XBEs.
- **RTTI-derived class headers** (bases, virtuals in vtable order, destructor slots, parameter counts from `ret N`)
  generated once and shared, plus a layout probe that compiles them with the original compiler and compares the
  emitted vftables and `sizeof` with the binary. *Why: sources stop inventing per-file placeholder classes.*
- **Object split inference** from link order (matching.md section 3), written as addresses and names only.

## 2. Byte-match compare and relocation verifier

- **Compare**: compile one self-contained TU with the original compiler (MSVC 7.1 runs on macOS/Linux under a small
  PE loader such as wibo, or Wine), extract the function from the COFF, mask relocated bytes, print an LCS-aligned
  instruction diff (differs / missing / extra) and a score. Per-file flag comments with a whitelist. JSON output for
  tools.
- **Relocation verifier**: every relocation in our object must resolve to the symbol at the address the original
  references: strings by content, float constants by bits, vftables, function starts, data in data, one symbol per
  target, address-carrying names consistent, global initializers compared with the original's bytes.
  *Why: masked relocations hide wrong callees and wrong constants; propagated copies are the main source.*
- **Formatter** that keeps a reformatted file only if it compiles to the same object.
- **Permuter**, **shape dedup/propagation**, **cloner**, family **generators** and a **hand-matching workbench**:
  matching.md sections 8-9.

## 3. Equivalence checker (differential execution)

Proves "behaves like the original" without identical bytes.

- **Level 1**: compiles. **Level 2**: same references (callees, globals, vtables, strings, float constants,
  initializers), with our symbols bound to original addresses in a fixed order: explicit map comments, content
  (strings, float bits, vtables by RTTI name), names carrying addresses, instruction pairing, first-use order.
  CRT routines are recognised in the executable by behaviour (run candidates against test vectors) and run for real
  on both sides.
- **Level 3**: run the original bytes and our object side by side in an x86 emulator library (e.g. Unicorn) on
  fuzzed inputs. Memory is a pure function of (seed, epoch, address), so both runs see the same bytes wherever they
  read. Every outgoing call is a stub that records arguments and returns the same fuzzed value to both sides;
  compare call sequence, arguments, memory writes between calls, return value, callee-saved registers, stack
  balance, and x87 results exactly.
- **Argument counts come from the callee** (its `ret N` and which stack slots it reads), not from the caller's
  pushes: size-optimised code defers and merges stack cleanup.
- **Inputs that reach code**: argument types from the mangled signature; seed modes (wide pointers, iterator ranges,
  small numbers, dictionaries planting the original's compare constants, boundary ints, stubs returning 0/1); loop
  repair (patch a runaway loop's bound); walk sentinels for lists and trees; directed inputs for uncovered branches.
- **Verdicts**: equivalent / fail / inconclusive / unsupported, plus a separate **promotable** flag that applies the
  promotion bar (no reference conflicts, coverage and completed-input minimums, few wild inputs).
- **Annotations** in source comments: map a symbol to an address; declare register conventions MSVC can't express.
- **Second-compiler mode**: compile the same source with clang as the port build does and run the same comparison,
  so a source is port-ready only if both compilers' objects behave like the original.
- **Process**: checker changes come in numbered rounds, each rule switchable off, each with regression cases (real
  functions plus known-wrong mutants that must keep failing) and an old-vs-new sample run. *Why: a checker that
  silently passes wrong code poisons everything downstream.*
- Document the blind spots instead of papering over them: callees are opaque, coverage is branch not path,
  data-dependent differences can survive full coverage, writable globals are seeded with initial values.

## 4. Trace capture and replay checker

Fuzzing can't reach some paths and its stubs return invented values. Record real game states once; replay every
proven function against them on every change.

- Run the original executable (plus deterministic test hooks only) in xemu under its gdb stub. At a target's entry,
  co-simulate: run the original bytes in the emulator library with registers and touched pages read from the paused
  game; at each callee, let the real game run it and record its results (return registers, `st0`, bytes it changed).
  Store per-call records locally (they are game memory: never commit them).
- **Gate recorder**: patch every target's entry to count calls in a guest table and stop at one shared gate only when
  the host wants that call. One permanent breakpoint instead of hundreds (emulator speed drops roughly linearly
  with armed breakpoints); it also yields a census of what ran when.
- Replay compares our function against the recorded call (same callee results), giving a confidence tier per
  function. Recorder bugs are common (stack addresses stored in frames, temporary breakpoints re-hit in loops,
  by-value structs overwriting return slots): when replay disagrees, suspect the recorder before the source.
- Shard captures across hosts/instances; never-returning or boot-time polling functions get their own session.

## 5. Hybrid build

Patch compiled functions into the original executable (a new section, 5-byte jumps at the originals), run it in
xemu with determinism hooks (fixed frame time, constant seed, skip intro, pinned date and RNG, input polls as the
clock), and compare against the hooks-only build on the same recorded input; bisect failures by function tiers
(identical first, then equivalent). It finds behaviour bugs no byte diff sees, and it produces the recordings and
checkpoint hashes every later build replays.

## 6. The clang (pre-native) build

Generate one source tree from the verified functions (merged translation units, shared headers), compile with clang
i686 x87 (`-ffp-eval-method=double -ffp-contract=off`), bind unresolved symbols to the original layout, link with
the player's data and a platform layer (input, audio, graphics behind the game's renderer interface, a runtime-loaded
video decoder, XDK-shaped shims reimplemented from interfaces), run under Wine or on Windows, replay a recording,
and compare checkpoint hashes (a cheap hash over RNG state, boot step, camera, game clock every N frames). Headless
with a null renderer, so it runs on any queue host. Keep per-host incremental build state; make images reproducible.

## 7. Shared job queue

One queue, many hosts, many agents.

- **submit / wait / result / status / cancel** from any agent; a small database queue and a scheduler daemon that
  starts on submit and exits when idle. Jobs carry needed capabilities (e.g. msvc, clang, wine, wine-gfx, emulator),
  slots, a wall-clock limit, attempts, priority, and output paths to fetch back.
- **Host model**: configured slots, capabilities and preference per host; usable slots shrink with load from
  outside the queue; prefer remote hosts and use the interactive machine last. Host config lives untracked (it holds
  user/host names) and reloads live, so slot edits need no restart.
- **Big jobs** reserve hosts, or a stream of 1-slot jobs starves them.
- **Workspaces**: each job runs in a copy-on-write clone of a per-host cached base tree (built from committed tools,
  keyed by content hash) plus the job's overlay files. Large shared inputs (compilers, venv, extracted disc) are
  symlinked to each host's own copies; game data never travels with a job.
- **States**: done, failed (command exit != 0: not retried), gave up (infrastructure failed N times or limit hit),
  cancelled. A daemon restart re-queues running jobs, but some end "gave up" and must be resubmitted.
- **Batch front-ends** that append results to a JSONL as they arrive and skip addresses already present (rerun to
  resume).
- **Safety checks at submit, dispatch and on the host**: emulator jobs must carry `-snapshot` and may not name disk
  backup/mirror commands or the emulator's settings folder.

## 8. Model farm (optional)

A lane runner that feeds packets to cloud or local models with tiers of attempts, records every attempt in a
durable store (crash-resumable), auto-verifies (compare + relocation verifier, or the equivalence checker) and
installs results. Prompting and benchmarking: matching.md section 10. Stop lanes that rewrite sources while other
agents do structural work on the same files.

## 9. Progress and debt reporting

Generated, never hand-edited: a status table (functions and bytes by state, excluding library and dead code), a
treemap of functions by size and state, and a tech-debt table of proven-but-ugly sources.
