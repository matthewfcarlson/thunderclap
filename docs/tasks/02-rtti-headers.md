# 02: RTTI → class headers

## Goal
Generate a first set of shared C++ headers from recovered RTTI, so matched functions can eventually compile against one definition per class instead of per-file stubs (roadmap stage 3).

## Context
- `build/rtti.json` (from `tools/rtti.py`): 4,244 classes with mangled and demangled names, base classes (with `mdisp` offsets and attributes), and vtables (address, offset for secondary bases, slot function VAs).
- Function names in Ghidra/`build/functions.csv`: `Class::vfunc_N` (owner = class with the fewest bases using that slot); XDK functions keep XbSymbolDatabase names.
- `matches/*.cpp` are standalone TUs with invented member names. Field offsets used there are evidence for layouts.

## Deliverables
1. `tools/gen_headers.py` → `include/gen/` (committed, generated, with a "do not edit" header): one header per namespace (or per class family). It emits:
   - namespaces and forward declarations;
   - classes with base lists in the right order (single and multiple inheritance from base descriptors; virtual bases flagged);
   - virtual method declarations in vtable order (`virtual void vfunc_3();`, with inherited slots not redeclared), and a virtual destructor where the slot looks like a scalar deleting destructor (`push 1` / flag test patterns);
   - a `// vftable 0x...` comment per class.
2. A layout probe: for each generated class, `sizeof`/vtable-slot sanity compiled with `cl` 13.10 via wibo, e.g. a test TU per header that compiles cleanly.
3. A short report: classes with multiple or virtual inheritance, templates (`DynamicCaster<...>`, `Method1<...>`), and anything the generator can't express yet.

## Done when
- Every generated header compiles with `cl` 13.10 (`/c /O2 /GR /GX`).
- At least 3 hand matches in `experiments/first-matches/` are rewritten to include the generated headers and still `MATCH` with `tools/compare.py`.

## Notes
- Field layouts are out of scope beyond the vftable pointer. Add `char _pad[N]` only where a matched function proves an offset. A follow-up task can mine `matches/` for field offsets per class.
- Template classes: emit the template once with its instantiations noted. Don't emit every instantiation as a separate class.

## Status (2026-10-10): done
- `tools/gen_headers.py` generates `include/gen/` (17 namespace headers + `all.h`). Details, the probe results and known gaps are in [`docs/headers.md`](../headers.md).
- Layout probe (`--probe`): all 17 headers compile with `cl` 13.10 `/O2 /GR /GX`. For all 4,238 classes with a vftable, the vftable slot counts, all 27,439 slot implementers, the RTTI base descriptors and `sizeof` agree with the RTTI.
- `experiments/first-matches/{refcount,action,method}_gen.cpp`: 5 functions rewritten on the generated headers, all MATCH.
- Stretch: `--mine` mines field offsets and slot signatures from `matches/`, and `--swap-test` measures how many matches survive the swap to the headers (see `docs/headers.md`).
