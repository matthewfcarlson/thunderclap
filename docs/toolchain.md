# Toolchain

## Compiler: MSVC 7.1 (`cl` 13.10.3077)

- XDK 5849 (what the game links against) ships VC 7.1 `cl` **13.10.3077** / `link` 7.10.3077 (per community reports, e.g. projects built against "XDK 5849.17 + VC7.1 cl 13.10.3077"; not yet verified against a real XDK `bin/vc71`).
- The same version is the VS.NET 2003 RTM / free Visual C++ Toolkit 2003 compiler, and decomp.me hosts it as `win32/msvc7.1`. Verified file versions: `cl.exe`, `c1xx.dll`, `c2.dll` = 13.10.3077; `link.exe` = 7.10.3077.
- Fetch (no Docker needed):

  ```sh
  tools/pull_compiler.py win32/msvc7.1 build/compilers/msvc7.1
  # → build/compilers/msvc7.1/compilers/win32/msvc7.1/{Bin,Include,Lib}
  ```

- Xbox headers (`xtl.h`, Xbox D3D8) aren't included. Write our own minimal declarations (or use the GPL headers from ghidra-xbe / nxdk) for engine→XDK calls. Codegen doesn't depend on them.

## Running it on macOS: wibo

[wibo](https://github.com/decompals/wibo) 1.2.0 `wibo-macos` (x86_64, runs under Rosetta 2) runs `cl.exe` fine:

```sh
curl -L -o build/tools/wibo https://github.com/decompals/wibo/releases/download/1.2.0/wibo-macos && chmod +x build/tools/wibo
INCLUDE=build/compilers/msvc7.1/compilers/win32/msvc7.1/Include \
  build/tools/wibo build/compilers/msvc7.1/compilers/win32/msvc7.1/Bin/cl.exe /nologo /c /O2 /GR /GX t.cpp
```

Output is `coff-i386`, readable with `objdump -d --x86-asm-syntax=intel` and diffable with objdiff.
(The Halo decomp uses the [punpckhdq/wibo](https://github.com/punpckhdq/wibo) fork, tag `1.2.0-crypt`. Switch to it if upstream misses an API that the XDK tools need.)

## Ghidra

`tools/setup_ghidra.sh` installs Ghidra 12.0.3 and [ghidra-xbe](https://github.com/XboxDev/ghidra-xbe) (build-202602250354) into `build/tools/`, points it at Homebrew `openjdk@21`, and imports and analyzes `default.xbe` into `build/ghidra/hulk.gpr`.

- ghidra-xbe bundles only an x86_64 `XbSymbolDatabaseCLI` for macOS. The script copies it to `os/mac_arm_64` so Apple Silicon Ghidra finds it (it runs under Rosetta).
- Standalone run: `XbSymbolDatabaseCLI isos/extracted/default.xbe` finds **650** XDK symbols (D3D8, DSOUND, XAPILIB, …).
- First auto-analysis takes ~5 min. It found **17,481 functions**, 635 of them named (XDK). Ghidra's RTTI analyzer is PE-only, so it found **no** RTTI or vtables on the XBE (`ProjectStats`: vftables=3, rtti_symbols=0). We use our own RTTI recovery instead (below).
- **RTTI recovery**: `tools/rtti.py` parses TypeDescriptors, CompleteObjectLocators, ClassHierarchyDescriptors and vftables straight from the XBE into `build/rtti.json`. It uses its own demangler (`tools/msvc_demangle.py`) because `undname.exe` prints nothing under wibo. `ApplyRtti.java` applies it: class namespaces, `RTTI_*`/`vftable` labels, vtable pointer arrays, and `Class::vfunc_N` (`__thiscall`) for each virtual function. A function is owned by the class with the fewest bases that uses it, so inherited slots keep the base-class name. Results:
  - 4,244 type descriptors, 4,267 vtables, 27,440 slots → 13,006 distinct virtual functions. Demangle failures: 0.
  - ApplyRtti created 8,467 functions that auto-analysis had missed (reachable only through vtables). After re-analysis there are **25,426 functions, 13,225 named (52%)**.
  - Known limitation: vtable length is "until the next COL slot or a non-code pointer". A vtable directly followed by a function-pointer table would be over-counted.
- `DecompileFunction.java <addr|Ns::name>...`: dump decompiled C headlessly (handy for agents).
- GUI: `build/tools/ghidra_12.0.3_PUBLIC/ghidraRun`, then open `build/ghidra/hulk.gpr`.
- Scripts live in `tools/ghidra_scripts/` (e.g. `ProjectStats.java`).

## Preliminary codegen observations on `default.xbe` .text

Heuristic byte counts (not a disassembly):

| Signal | Count | Implication |
|---|---|---|
| `push ebp; mov ebp,esp` | 395 | Frame pointers are mostly **omitted**: likely `/O2` with FPO (`/Oy`), unlike Halo's `/Oy-` |
| SSE `movss` | 0 | x87 floating point only (no `/arch:SSE`) |
| `ret n` vs `ret` | 33.8k vs 25.5k | heavy `__thiscall`/`__stdcall` C++ |
| `CC CC` runs | 137k | int3 padding between functions |

Starting guess for flags: `/O2 /GR /GX /MT` (RTTI is on, which is confirmed by ~4.2k type descriptors).

## Matching loop (verified 2026-10-08)

```sh
build/venv/bin/python tools/disasm.py 'CAction::vfunc_5'          # target asm (bounds from build/functions.csv)
build/venv/bin/python tools/compare.py file.cpp <symbol> 0xADDR  # compile with cl 13.10 via wibo, diff vs XBE
```

- `build/functions.csv` comes from `ExportFunctions.java`, plus two post-passes. Don't re-export it from scratch without re-applying them. `build/venv` needs `pip install capstone`.
  - Size fixes: bodies Ghidra ended one instruction before the final `ret` are extended (see the journal, 2026-10-09).
  - Missing functions (2026-10-11): Ghidra never created functions that are reached only through pointers it didn't resolve (vtable slots, callback tables, element constructors passed to vector helpers). `CreateMissingFunctions.java` created them at the starts of uncovered code runs (two passes, about 17k). The 4,879 that are referenced (by a pointer in data, an immediate in code, or a direct call/jmp) were appended to `functions.csv`, with each size clamped to the next function start. The other 12,447 have no reference anywhere. They're listed in `build/farm/dead-code.txt` and left out of the function list and the progress denominator. The Ghidra project does contain them now, so a fresh `ExportFunctions` would include them.
  - Truncated bodies (2026-10-13, `tools/fix_truncated_sizes.py`): Ghidra ends a function at a call it believes never returns, and some of those beliefs were wrong (`FUN_00236d40`, a plain constructor). 658 functions were recorded only up to such a call. The pass extends each body that doesn't end in ret/jmp/int3 (and isn't followed by int3 padding, which a real noreturn call is) to its first ret or jmp that is followed by padding or the next listed function. Re-checking the verified ones afterwards: 21 equivalents still passed; 2 matches had only matched the cut-off start and were demoted.
- `compare.py` builds with `/nologo /c /O2 /GR /GX /Gy` (extra flags after `--`). It pulls the function out of the COFF object, masks bytes covered by relocations, and diffs instruction by instruction against the XBE.
- **First 5 functions matched byte-for-byte** (`experiments/first-matches/`): a refcount `Release`, a switch dispatcher, an x87 float getter with a relocated constant, and two script-binding member-function-pointer templates. This confirms **cl 13.10.3077 + `/O2`** with frame-pointer omission. (Those five had no EH state; later matches with EH frames did exercise `/GX`.)
- Matching quirks seen so far: `bool r = false; switch … break; return r;` rather than early returns, and copying a member-fn pointer to a local before calling it.
