# Equivalence verifier (`tools/equiv.py`)

Proves that a function we wrote behaves like the original, without needing byte-identical codegen. It is the
level 1–3 verifier of [task 09](tasks/09-equivalent-decomp.md).

```sh
build/venv/bin/python tools/equiv.py SRC 0xADDR                 # human-readable report
build/venv/bin/python tools/equiv.py SRC 0xADDR --json          # one-line JSON (for the farm)
build/venv/bin/python tools/equiv.py SRC 0xADDR --map map.json  # bind our symbols to original addresses
build/venv/bin/python tools/equiv.py SRC 0xADDR -- /Oy-         # extra cl flags
```

Library: `equiv.verify(src, addr, symbol=None, flags=(), n_inputs=64, mapping=None, ...)` returns the report
dict. Exit status is 0 only for `equivalent`.

## Levels

| Level | Check | Fails on |
|---|---|---|
| 1 | compiles with MSVC 7.1 (`compare.py` flags; `--clang` adds a host-clang syntax check, warning only) | compile errors |
| 2 | same references: callees, globals, vftables, strings, float constants, address immediates | a missing/extra callee or global, a string the original never uses, an unresolvable symbol |
| 3 | differential execution in Unicorn on fuzzed inputs | any difference in calls, memory writes, return value, callee-saved registers, stack balance |

`status` is `equivalent` (levels 1–3 pass), `fail`, `unsupported` (level 3 could not run any input to
completion), `compile_error` or `no_function`. `level` is the highest level passed.

## Binding our symbols to original addresses

Our object names things; the original has addresses. Each symbol our function references is bound in this
order (the report's `level2.mapping` says which rule fired):

1. **explicit**: `--map` JSON, or a `// equiv-map: ?Foo@@YAXXZ = 0x00123456` comment in the source;
2. **content**: string literals (bytes equal to a string the original references), `__real@` float constants
   (same bits), vftables (`??_7Class@@6B@` by RTTI class name);
3. **name**: an address in the name (`FUN_00123456`, `DAT_004dd6e4`, `g_00491234`, ...), a unique
   `Class::method` name from `build/functions.csv`, an XDK symbol, or a fixed CRT helper (`__ftol2`, `__chkstk`);
4. **paired**: instruction alignment with the original (the operand at the same spot of the matching
   instruction); when the code is byte-identical this is exact and overrides wrong name claims, which are
   reported in `level2.conflicts`;
5. **ordered**: leftover symbols matched to leftover original targets of the same kind in first-use order.

Rules 4 and 5 trust the original, so for invented names level 2 checks shape and consistency, and level 3
checks the behaviour that results. Names that carry addresses make level 2 a real check.

## Level 3 design

Both the original bytes and our linked object run in a fresh 32-bit Unicorn instance per input:

- **Memory** is a pure function of `(seed, epoch, address)` and is mapped lazily on first touch, so both runs
  see identical memory wherever they read, and no address faults. XBE image pages hold the original
  sections (`.bss` zero); referenced `.data` globals get fuzzed values (except in input 0). Everything else
  (heap, wild pointers) is filled from a pool of structured pages: zeros, small ints, `-1`, flags, floats
  and pointers into a heap region; some inputs plant "dictionary" values (the input's own pointers and the
  constants the original compares against) so search loops hit. `0..0xFFFF` reads as zero (null derefs).
- **Our object** is laid out at `0x60000000`; relocations to bound symbols point at original addresses, so a
  call goes to the same address in both runs and a stored vftable pointer has the same value.
- **Inputs:** `this`, arguments and registers from the mangled signature (pointers, ints, floats, doubles,
  hidden struct-return pointer); 16 extra stack words; callee-saved registers get unique values.
  Seeds rotate between wide/near pointers, "tame" (small-number) memory and dictionary memory.
- **Callees** are never executed (except `_ftol`/`_chkstk`, which are pure). At every `call`, and at a `jmp`
  that leaves the function (tail call), a stub records the target, the argument words, the registers, and
  the first 32 bytes of every stack local passed by pointer. It returns a deterministic `eax`/`edx` (and a
  float on the x87 stack if the code after the call consumes `st0`), writes the first word of each local
  passed by pointer (an out-parameter), and pops the callee's argument bytes. The pop count comes from the
  callee's own `ret N` (following tail jumps) when the target is a known function, from the caller's
  `add esp, N` for cdecl, and otherwise from tracked argument pushes.
- **Callee side effects:** after each stub the memory epoch advances: every non-code page is rewritten
  with fresh deterministic contents. That models "the callee may change anything" and catches code that
  caches a value across a call that the original re-reads.
- **Compared per input:** call trace (targets in order, argument words, the callee's register inputs, i.e.
  `ecx`/`edx`/`eax` when the callee reads them before writing (so `this`), contents of locals passed by pointer),
  memory writes per call segment (final byte values that differ from the segment's initial state;
  stack excluded), return value by type (`al`/`ax`/`eax`/`edx:eax`/`st0`), x87 stack depth,
  `ebx/esi/edi/ebp` and `esp` after return. Values that point into the stack compare as "a stack
  address". Floats stored by `fst`/`fstp` and float arguments compare with relative tolerance 1e-5.
- **Inputs run:** 64 by default; then more (up to 256) while branch coverage of the original keeps growing;
  then up to 96 **directed** inputs: every `cmp`/`test` the original executes is recorded with the
  address each operand was loaded from, and for a branch side never taken the input that reached it is
  re-run with that memory (or stack argument) patched to the value on the other side (input-to-state).
  Some seeds make every stub return 0 or 1, so loops over callee results terminate. An input on which the
  original doesn't return (step limit 50k, page limit) is inconclusive; one where the original faults is
  compared up to the fault but not counted as a pass.
- **Return type** comes from our mangled name. If ours returns `void` but the original's direct callers read
  `eax` (or `st0`) after the call, the return value is compared anyway and `return_note` says so.
- **Coverage:** taken/not-taken for every conditional branch, 0/1 for every `setcc`, and every jump-table
  case of the original.
  `level3.coverage.complete` is false when some edge never ran; the uncovered edges are listed.

## Report (JSON)

```jsonc
{
  "addr": "0x001b77e0", "src": "...", "target": "FUN_001b77e0", "symbol": "?Run@Target@@QAEXXZ",
  "status": "equivalent", "level": 3, "byte_identical": true, "time": 6.0,
  "level1": {"ok": true},
  "level2": {"ok": true, "issues": [],                       // missing_call, extra_data_ref, ...
             "mapping": {"?Fn@Mgr@@QAEXXZ": {"addr": "0x002088a0", "how": "paired"}},
             "conflicts": []},
  "signature": {"cc": "thiscall", "this": true, "ret": "void", "params": []},
  "level3": {"ok": true, "inputs_run": 68, "inputs_inconclusive": 0, "inputs_faulted": 0, "inputs_failed": 0,
             "statuses": {"ret": 68},
             "coverage": {"edges_total": 16, "edges_covered": 16, "complete": true, "uncovered": []},
             "mismatches": [{"input": 4, "diffs": ["call #3 went to 0x00232660 instead of 0x0008d690"]}]}
}
```

Mismatch strings are written for a model to act on, e.g. `write to this+0x40 before call #2 was 0x3f000000
(0.5f), expected 0x3f800000 (1f)`, `call #3 to 0x0008d690: argument 1 is 0x25, expected 0x24`,
`missing call #2 to 0x00232660`, `returned 0x0, expected 0x1`.

## Validation

See the journal entry of 2026-10-10 for the numbers. Harnesses:

- `tests/equiv/selftest.py`: a size-stratified sample of 300 matches must be `equivalent` against itself;
  `--flags /Oy-` or `--flags /O1` recompiles the same sources with other options (different bytes, same
  behaviour), which must also pass.
- `tests/equiv/mutate.py`: per function, one mutant per operator (swap non-commutative operands, change a
  literal, drop a call, shift a field offset, flip a comparison) must `fail`; a commutative swap must
  pass. Mutants that don't compile or give identical bytes are excluded. Symbols are bound with the
  unmutated match's mapping.
- `tests/equiv/test_equiv.py`: quick unit and end-to-end tests.

## Limits

- **Coverage, not proof.** A pass means no difference on the inputs run; check `coverage.complete`. Code
  behind conditions the fuzzer can't satisfy (magic values, deep pointer chains, specific globals) stays
  unverified; the uncovered edges are listed so a caller can add inputs.
- **Branch coverage is not path coverage.** A difference that needs a particular combination of
  conditions (e.g. a magic value and a sign) can survive full branch coverage.
- **Callees are opaque.** A stub writes only the first word of a local passed by pointer, and compares only
  the first 32 bytes (up to the next pointer argument) of each such local. Equivalent code with a
  different local layout can fail there when a small local has different neighbours; declaring locals in
  the original's order avoids it.
- **Argument counts** for calls through unknown pointers (virtual calls on fuzzed objects, kernel imports)
  come from tracked pushes. Nested calls whose arguments interleave with an outer call's pushes can be
  misattributed; both sides use the same rule, so this can cause false failures, not passes.
- **Inline-vs-call differences** fail: the original calling a small function that we inlined (or vice versa)
  is a different call trace.
- **Calling conventions** come from our mangled name. C-linkage functions without a decorated name get the
  return type from Ghidra's decompile when available, otherwise `eax` is compared.
- **Not modelled:** exceptions (SEH frames work, but nothing throws), threads, timing, hardware/MMIO,
  self-modifying code, `in`/`out`. LTCG register-argument functions work when registers carry the
  arguments (all registers start as valid pointers), but only by accident of the fuzzing.
- **x87:** float results compare with tolerance; integer results of `fistp` compare exactly.
