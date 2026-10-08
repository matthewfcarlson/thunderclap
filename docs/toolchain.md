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
- First auto-analysis takes ~5 min. It found **17,481 functions**, 635 of them named (XDK). Ghidra's RTTI analyzer is PE-only, so it found **no** RTTI or vtables on the XBE (`ProjectStats`: vftables=3, rtti_symbols=0). We need our own RTTI recovery script.
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

Starting guess for flags: `/O2 /GR /GX /MT` (RTTI is on, which is confirmed by ~4.2k type descriptors). Check against first matched functions.
