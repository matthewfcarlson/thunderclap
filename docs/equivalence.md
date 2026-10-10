# Equivalence verifier (`tools/equiv.py`)

Proves that a function we wrote behaves like the original, without byte-identical codegen. It is the level
1–3 verifier of [task 09](tasks/09-equivalent-decomp.md).

```sh
build/venv/bin/python tools/equiv.py SRC 0xADDR                 # human-readable report
build/venv/bin/python tools/equiv.py SRC 0xADDR --json          # one-line JSON (for the farm)
build/venv/bin/python tools/equiv.py SRC 0xADDR --map map.json  # bind our symbols to original addresses
build/venv/bin/python tools/equiv.py SRC 0xADDR -- /Oy-         # extra cl flags
```

Library: `equiv.verify(src, addr, symbol=None, flags=(), n_inputs=64, mapping=None, use_names=True, ...)`
returns the report dict. The exit status is 0 only for `equivalent`. A typical function takes 1–5 s
(compile included); loops that run long on fuzzed inputs can take up to the 120 s level-3 budget.

## Levels

| Level | Check | Fails on |
|---|---|---|
| 1 | compiles with MSVC 7.1 (`compare.py` flags; `--clang` adds a host-clang syntax check, warning only) | compile errors |
| 2 | same references: callees, globals, vftables, strings | a missing or extra callee or global, an unresolvable symbol |
| 3 | differential execution in Unicorn on fuzzed inputs | any difference in calls, memory writes, return value, callee-saved registers or stack balance |

`status` is `equivalent` (levels 1–3 pass), `fail`, `unsupported` (level 3 could not run any input to
completion), `compile_error` or `no_function`. `level` is the highest level passed.

Level 2 also lists **warnings**: differences that equivalent code can legitimately have. Examples are an
immediate that only looks like an address, a float constant loaded another way (`fld1`, or a double
instead of a float), a string or global read in pieces, and CRT calls the original inlined. Level 3
still checks the behaviour behind them.

## Binding our symbols to original addresses

Our object names things; the original has addresses. Each symbol our code references is bound in this
order. The report's `level2.mapping` says which rule fired.

1. **explicit**: `--map` JSON, or a `// equiv-map: ?Foo@@YAXXZ = 0x00123456` comment in the source.
2. **content**: string literals (same bytes as a string the original references), `__real@` float
   constants (same bits), and vftables (`??_7Class@@6B@` by RTTI class name).
3. **name**:
   - an exact `build/functions.csv` name (`Class::vfunc_3`, `thunk_FUN_…`);
   - an address in the name (`FUN_00123456`, `DAT_004dd6e4`, `g_00491234`, …);
   - an XDK symbol;
   - a fixed CRT helper (`__ftol2`, `__chkstk`);
   - a CRT routine found in the XBE by behaviour (below).
4. **paired**: instruction alignment with the original; the operand at the same spot of the matching
   instruction. When the code is byte-identical, this is exact and overrides wrong name claims, which are
   reported in `level2.conflicts`.
5. **ordered**: leftover symbols matched to leftover original targets of the same kind, in first-use order.

Rules 4 and 5 trust the original. With invented names, level 2 checks shape and consistency, and level 3
checks the resulting behaviour. Names that carry addresses make level 2 a real check.

Two kinds of symbol are never paired:

- **Functions defined in our own object.** These are code the original inlined, for example an inline
  constructor that this compile didn't inline. They run in place, as if inlined, and their references count
  at level 2.
- **CRT routines** (`memcpy`, `strcmp`, `sin`, …). The XBE's own copies are found once by behaviour. Every
  function in the CRT region is probed against memcpy/strcmp/floor/… test vectors, and the results are
  cached in `build/equiv/crt.json`. The routines found run for real on both sides. A routine the XBE
  doesn't have out of line (e.g. `memset`, inlined everywhere) runs semantically in Python. Either way,
  inlining one side and calling on the other makes no difference.

## Level 3 design

Each input runs the original bytes and our linked object, each in a fresh 32-bit Unicorn instance.

**Memory**
- Memory is a pure function of `(seed, epoch, address)`, mapped lazily on first touch. Both runs see the
  same bytes wherever they read, and no address faults except a small poison range for unresolved symbols.
- XBE image pages hold the original sections, with `.bss` zero. Referenced `.data` globals get fuzzed
  values, except in input 0.
- Other memory (heap, wild pointers) comes from a pool of structured pages: zeros, small ints, `-1`,
  flags, floats, and pointers into a heap region. `0..0xFFFF` reads as zero, so null dereferences work.
- Our object is laid out at `0x60000000` and mapped in both runs. Bound symbols point at original
  addresses, so a call goes to the same address in both runs and a stored vftable pointer has the same value.

**Inputs**
- `this`, the arguments and the registers come from the mangled signature: pointers, ints, floats, doubles,
  and the hidden struct-return pointer. 16 extra stack words follow, and callee-saved registers get unique
  values.
- Seeds rotate between several modes:
  - wide or near/ascending pointers;
  - "tame" small-number memory;
  - dictionary memory: planted copies of the input's pointers, `this+4/8/12` (object graphs) and the
    constants the original compares against;
  - narrow memory: every heap pointer folded into 512 bytes, so `end - begin` ranges stay short;
  - noise memory: random bytes on half the pages, so copies and byte loads see distinct values;
  - boundary constants as int arguments;
  - stubs that always return 0 or 1.
- 64 random inputs, then more (up to 256) while branch coverage of the original keeps growing.
- Then up to 96 **directed** inputs (input-to-state). Every `cmp`/`test` the original executes is
  recorded, with the address each operand was loaded from. When a branch side (or `setcc` outcome) was
  never taken, or was taken by fewer than 4 inputs, the input that reached it is re-run with that memory
  or stack argument patched to the value on the other side.

**Callees**
- Callees are never executed, except `_ftol`/`_chkstk` and the CRT routines above. At every `call`, and at
  a `jmp` that leaves the function (a tail call), a stub:
  - records the target, the argument words, the registers, and every stack local passed by pointer;
  - returns a deterministic `eax`/`edx`, plus a float on the x87 stack if the code after the call consumes
    `st0`;
  - writes the first word of each local passed by pointer (an out-parameter);
  - pops the callee's argument bytes.
- The pop count comes from the callee's own `ret N` (following tail jumps) when the call site names a real
  function. For cdecl, it comes from the caller's `add esp, N` or `pop ecx` cleanup, including one
  deferred over several calls. Otherwise it comes from tracked argument pushes. For indirect calls, our
  k-th call reuses the count the original's k-th call used on the same input.
- The number of argument words compared is what the callee actually reads (a stack-depth scan of the
  callee). Unused or dead arguments don't count.
- Callee side effects: after each stub the memory epoch advances, and every non-code page is remapped with
  fresh deterministic contents. That models "the callee may change anything", and it catches code that
  caches a value across a call when the original re-reads it.

**Compared per input**
- The call trace: targets in order; the argument words; and the callee's register inputs, i.e.
  `ecx`/`edx`/`eax` when the callee reads them before writing (so `this`, and `ecx` for every virtual
  call).
- Locals passed by pointer: `sizeof(*param)` bytes, taken from our callee declaration (a `sizeof` probe
  compile for class types), 4 bytes when unknown. Only bytes the function wrote count, so an
  uninitialised out-parameter is not compared.
- Memory writes per call segment: the final byte values that differ from the segment's initial state.
  The stack is excluded.
- The return value by type: `al`, `ax`, `eax`, `edx:eax` or `st0`.
- The x87 stack depth, `ebx/esi/edi/ebp` and `esp` after return.
- Values that point into the stack compare as "a stack address". Floats stored by `fst`/`fstp` and float
  arguments compare with relative tolerance 1e-5.

An input on which the original doesn't return (step limit 50k, or the 1000-page limit) is inconclusive.
One where the original faults is compared up to the fault, but not counted as a pass.

**Return type** comes from our mangled name. For a C name it is inferred from the original's call sites.
If ours returns `void` but the original's direct callers read `eax` (or `st0`) after the call, the return
value is compared anyway, and `return_note` says so.

**Coverage** counts taken/not-taken for every conditional branch, 0/1 for every `setcc`, and every
jump-table case of the original. It comes only from inputs that ran to completion. `level3.coverage.complete` is false when some edge never ran, and the
uncovered edges are listed.

## Report (JSON)

```jsonc
{
  "addr": "0x001b77e0", "src": "...", "target": "FUN_001b77e0", "symbol": "?Run@Target@@QAEXXZ",
  "status": "equivalent", "level": 3, "byte_identical": true, "time": 6.0,
  "level1": {"ok": true},
  "level2": {"ok": true, "issues": [], "warnings": [],       // missing_call, extra_data_ref, ...
             "mapping": {"?Fn@Mgr@@QAEXXZ": {"addr": "0x002088a0", "how": "paired"}},
             "conflicts": []},
  "signature": {"cc": "thiscall", "this": true, "ret": "void", "params": [], "param_types": []},
  "level3": {"ok": true, "inputs_run": 68, "inputs_inconclusive": 0, "inputs_faulted": 0, "inputs_failed": 0,
             "inputs_directed": 4, "statuses": {"ret": 68},
             "coverage": {"edges_total": 16, "edges_covered": 16, "complete": true, "uncovered": []},
             "mismatches": [{"input": 4, "diffs": ["call #3 went to 0x00232660 instead of 0x0008d690"]}]}
}
```

Mismatch strings are written for a model to act on. Examples:

- `write to this+0x40 before call #2 was 0x3f000000 (0.5f), expected 0x3f800000 (1f)`
- `call #3 to 0x0008d690: argument 1 is 0x25, expected 0x24`
- `call #1 to 0x00337700: the local passed as argument 1 differs at +0x8`
- `missing call #2 to 0x00232660`
- `returned 0x0, expected 0x1`

## Validation

Numbers are in the journal (2026-10-10). The harnesses:

- `tests/equiv/selftest.py`: a size-stratified sample of 300 matches must be `equivalent` against itself.
  `--flags /O1` or `--flags /Oy-` recompiles the same sources with other options: different bytes (other
  register allocation, frames, inlining and CRT calls), same behaviour. Those must pass too. Symbols are
  bound with the exact match's ground truth.
- `tests/equiv/mutate.py`: for each function, one mutant per operator must `fail`. The operators swap
  non-commutative operands, change a literal, drop a call, shift a field offset, and flip a comparison. A
  commutative swap must pass. Mutants that don't compile, or that give identical bytes, are excluded.
  Hand-checked semantically equivalent mutants are listed in `EQUIVALENT_MUTANTS`. Symbols are bound
  with the unmutated match's mapping.
- `tests/equiv/test_equiv.py`: quick unit and end-to-end tests.

## Limits

- **Coverage, not proof.** A pass means no difference on the inputs run, so check `coverage.complete`.
  Code behind conditions the fuzzer can't satisfy (deep pointer chains, specific global state, values
  computed from several loads) stays unverified. Branch coverage is also not path coverage: a difference
  that needs a combination of conditions can survive full branch coverage.
- **Callees are opaque.** A stub writes only the first word of an out-parameter. A local passed to a
  virtual call (unknown declaration) is compared over 4 bytes only.
- **Argument counts** for calls through fuzzed pointers come from tracked pushes in the original, and are
  reused by our run call by call. A rare mix of cdecl and thiscall indirect calls sharing one deferred
  cleanup can still be miscounted. That shows up as a false failure, not a pass.
- **Data-dependent loops:** a difference that only shows with particular data, such as a byte copy whose
  source and destination happen to hold equal bytes, can pass even with full branch coverage. Two of the
  final mutants are like this.
- **Inline-vs-call differences** of game functions fail. If the original calls `FUN_x`, our code must
  call it too: declare it `extern` rather than defining a body. Only CRT routines are exempt.
- **Unspecified evaluation order:** MSVC may evaluate call arguments in a different order under other
  flags (seen once with `/O1`). The call order differs, so it fails; arguably correctly, since the binary
  differs.
- **Not modelled:** exceptions (SEH frames work, but nothing throws), threads, timing, hardware/MMIO,
  self-modifying code, `in`/`out`. LTCG register-argument functions work when registers carry the
  arguments, because all registers start as valid pointers. Callee-saved registers are never compared as
  callee inputs.
- **x87:** float results compare with tolerance, and integer results of `fistp` compare exactly.
