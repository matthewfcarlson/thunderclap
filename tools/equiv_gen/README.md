# Equivalence source generators

Scripts the Sonnet equivalence batches wrote for families of near-identical functions. Each one turns
a function's packet (`tools/packet.py show ADDR`) into an equivalence source; run `tools/equiv.py` on the
output as usual. They're kept here because many files in `equivalent/` were produced by them; they are
rough, single-purpose scripts, not maintained tools. Run them from the repo root.

| Script | Family | Usage |
|---|---|---|
| `param_table_spec.py` + `param_table.py` | Param-registration tables (Name/Script/IntConstRange/FloatConstRange/Vector/EnumConstList/Bool/String/Branch/NameConstList params, ctors at 0x2348e0–0x235170) | `param_table_spec.py 0xADDR > spec.json; param_table.py spec.json` (writes `build/farm/bench/claude-equiv/work/0xADDR.cpp`) |
| `closure.py` | Script-binding registrations: `Closure0<T,R>`, `Function0<R>`, `Function1<R,A>` (templates of 0x00087d50 / 0x00087a90 / 0x00087b40) | `closure.py 0xADDR...` (writes next to the script under `out/`) |
| `read_xbe.py` | Helper: dump `N` bytes at a virtual address from the XBE (jump tables past a truncated packet) | `read_xbe.py 0xVA N` |

Same-shape copies of an already proven function don't need a generator: `tools/clone_equivalent.py`.
