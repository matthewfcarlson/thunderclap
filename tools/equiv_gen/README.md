# Equivalence source generators

Scripts the Sonnet equivalence batches wrote for families of near-identical functions. Each one turns
a function's packet (`tools/packet.py show ADDR`) into an equivalence source; run `tools/equiv.py` on the
output as usual. They're kept here because many files in `equivalent/` were produced by them; they are
rough, single-purpose scripts, not maintained tools. Run them from the repo root.

| Script | Family | Usage |
|---|---|---|
| `param_table_spec.py` + `param_table.py` | Param-registration tables (Name/Script/IntConstRange/FloatConstRange/Vector/EnumConstList/Bool/String/Branch/NameConstList params, ctors at 0x2348e0–0x235170) | `param_table_spec.py 0xADDR > spec.json; param_table.py spec.json` (writes `build/farm/bench/claude-equiv/work/0xADDR.cpp`) |
| `closure.py` | Script-binding registrations: `Closure0<T,R>`, `Function0<R>`, `Function1<R,A>` (templates of 0x00087d50 / 0x00087a90 / 0x00087b40) | `closure.py 0xADDR...` (writes next to the script under `out/`) |
| `inlined_regs.py` + `templates/*.in` | Manager constructors/`Register` functions with N script-binding registrations inlined (`Method<n>`/`Closure<n>` constructors expanded, out-of-line `Entry` constructors, `Registry::FUN_xxx(name, owner, fn)` calls). Reads every registration in order from the disassembly (vftables, type DATs, method pointers, names) and fills `@@DECLS@@`/`@@REGS@@` in a hand-written template (the class and the members set before and after). Proved 0x001e7470 (CSPManager, 66), 0x0009dd20 (CCameraManager, 62), 0x00200c10, 0x0007f950, 0x000d75c0, 0x000436f0, 0x001eebc0, 0x00047890, 0x00106e90, 0x001b6440 | `inlined_regs.py 0xADDR templates/0xADDR.in [OUT]` |
| `reg_helper.py` | The 65-83 byte `Registry::Register*(name, owner, fn)` helpers, 128 proved (new block, out-of-line ctor, optional inline Closure vptr + owner, `FUN_001d3b70`); wiring is recovered by tracking the stack offset | `reg_helper.py 0xADDR... [-o DIR]` |
| `props_reader.py` + `templates/0x000464c0.in` | Property-reader functions (`this->f = DEFAULT; props->GetFloat("Name", &this->f)` x ~90, 0x000464c0): expands the regular blocks from the disassembly into a hand-written template (`@@GEN from to@@`, `//@field`, `@@FIELDS@@`). The template keeps the original's stack offsets for out-parameter locals in a `Frame` struct, which the checker needs | `props_reader.py 0xADDR TEMPLATE [OUT]` |
| `call_table.py` | Fight-track factory tables (`FUN_xxx(r, "name")` runs and `TrackFactoryCasterTemplate<T>` locals registered with `FUN_002367c0(FUN_00236ac0(name, &local))`), 0x00073700 | `call_table.py 0xADDR [OUT]` |
| `read_xbe.py` | Helper: dump `N` bytes at a virtual address from the XBE (jump tables past a truncated packet) | `read_xbe.py 0xVA N` |

`inlined_regs.py` details: the registrations of one function are read in order; `G<n>` = inline `Method<n>`/`Closure<n>` constructors, `E` = out-of-line constructor on the new block, `M` = out-of-line `Method` ctor plus inline Closure vptr/owner (needs an explicit `Closure<n><...>` specialisation, emitted automatically), `O` = `registry->FUN_xxx(name, owner, fn)`. Run time: a constructor that touches a large object (0x001e7470, 126 KB) costs ~19 s per input, so `equiv.py --inputs 3000` completes only ~21 inputs there; call `equiv.verify(src, addr, n_inputs=3000, max_steps=1000000, time_budget=450)` instead (55 inputs, 102/102 branches).

Same-shape copies of an already proven function don't need a generator: `tools/clone_equivalent.py`.
