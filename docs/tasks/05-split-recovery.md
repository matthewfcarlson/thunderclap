# 05: Translation-unit / split recovery

## Goal
Recover the original source-file (`.obj`) boundaries of `.text`, `.rdata` and `.data`, and set up per-object matching with csplit + objdiff, as the Halo decomp does (roadmap stage 4).

## Context
- Reference implementation: github.com/punpckhdq/halo. See `configure.py`, `tools/project_x86.py`, `config/{splits,symbols,relocs,contribs}.json`, csplit (github.com/punpckhdq/csplit), objdiff v3.x and wibo. Halo had a PDB (`contribs.json` = PDB section contributions); **we don't**, so boundaries must be inferred.
- Signals for boundaries:
  - MSVC emits functions of one `.obj` contiguously, in source order, and the linker places objects in link order. So gaps, alignment padding (`CC` runs) and changes of class or namespace in function names (from RTTI) cluster by file.
  - `.rdata` string literals and float pools (`__real@`) are grouped per object near that object's vtables and RTTI. Cross-reference which functions use which constants.
  - Assert or error strings with file names (e.g. `objectdefinition.hpp`, `datadefinition.hpp`) and `__FILE__`-style paths.
  - COMDAT functions (inline and template instantiations) are deduplicated and placed by the linker, often away from their "home" file. Treat them separately.
- `build/functions.csv` has every function's address, size and name. `build/rtti.json` has vtable addresses (vtables live in `.rdata` near their object's data).

## Deliverables
1. `tools/infer_splits.py` → `config/splits.json` (proposed object ranges for `.text`/`.rdata`/`.data`, with a confidence and evidence per boundary), plus a human-readable `docs/splits.md` summary (estimated object count, largest objects, uncertain regions).
2. Symbols and relocs export in Halo's format (`config/symbols.json`, `config/relocs.json`), built from Ghidra (coordinate with task 01's `build/refs.jsonl`).
3. A configure/ninja prototype that csplits the original into per-object COFF files and runs objdiff against objects built from a handful of `matches/` TUs placed into one recovered object.

## Done when
- csplit + objdiff run end to end on at least one recovered object containing matched functions, and objdiff reports their functions as matching.
- `docs/splits.md` documents the method and its known weak spots.

## Notes
- Keep inferred configs under `config/` (committed). They contain addresses and names only, no game bytes.
- XDK, CRT and Bink regions are library objects. Mark them as such rather than trying to split them as game sources.
