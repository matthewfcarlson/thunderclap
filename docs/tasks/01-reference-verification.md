# 01: Reference verification (relocation targets)

## Goal
Upgrade a "match" from *same code shape* to *same program*. Today `tools/compare.py` masks every byte covered by a relocation in our object, so a call to the wrong function or a load from the wrong global still "matches". Make compare check that each relocation resolves to the **same target** as the original instruction.

## Context
- The XBE has no relocation table. Original targets must come from analysis: Ghidra references (`ReferenceManager`), or from decoding the instruction itself (rel32 call/jmp targets, absolute `[addr]` operands, `push imm32` pointers).
- Our side: COFF relocations in the compiled `.obj` name symbols (`?Foo@Bar@@...`, `__real@...` float constants, `??_7Class@@6B@` vftables, `??_C@...` string literals). `tools/compare.py` already parses relocations (`Coff`), but only uses their offsets as a mask.
- The farm writes TUs with invented names, so name equality is the wrong test. What we need is a **consistent mapping**: within one function, each of our symbols maps to exactly one original address, and that address is plausible for the symbol's kind (function start, vftable, string with the same contents, float constant with the same value).

## Deliverables
1. `tools/ghidra_scripts/ExportRefs.java` → `build/refs.jsonl`: for each game function, its outgoing references (instruction offset, operand byte offset, target VA, ref type). Validate against capstone decoding for a sample.
2. `compare.py --verify-relocs` (or a separate `tools/verify_relocs.py`) reporting per relocation: our symbol → original target, with checks:
   - string literal: same bytes as the C string at the target;
   - float/double constant: same value;
   - vftable: target is that class's vftable (from `build/rtti.json`);
   - function call: a consistent mapping (the same symbol always maps to the same target). Record the mapping so stage 3 can name things.
3. A sweep over `matches/` producing `build/reloc-report.jsonl` and a summary: how many matches pass, and the failure categories.

## Done when
- Known-good hand matches in `experiments/first-matches/` pass.
- A deliberately wrong TU (e.g. a changed string literal or float) fails.
- The summary across `matches/` is in `docs/journal.md`. Failing matches are listed, not deleted. The farm will be pointed at them later.

## Notes
- Masked bytes in `tools/compare.py`: see `Coff.function()` and `diff()`; relocation records are `(vaddr, symidx, type)`.
- Propagated matches (`// Same code shape as …`) reuse another function's TU. Their relocation *mapping* differs per address, which is expected; check each address independently.
