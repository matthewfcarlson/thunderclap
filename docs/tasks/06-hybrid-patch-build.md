# 06: Hybrid patch build in xemu

## Goal
Build a modified `default.xbe` where selected original functions are redirected to our compiled code, and boot it in xemu. This lets us (a) play-test matched functions for behaviour the byte diff can't see, and (b) ship QoL patches (widescreen, FOV, 60 fps) long before a full relink.

## Context
- Prior art: github.com/halo-re/halo builds reimplemented functions with Clang or MSVC and patches the original XBE so originals jump to them. Read how it lays out the new section, resolves references to original globals and functions, and patches entry points.
- XBE structure: `tools/xbe.py` and `tools/xbeinfo.py`; xboxdevwiki.net/Xbe (headers, section headers, the certificate, and the requirement that sections are page-aligned and listed in the header). Retail XBEs are not signature-checked by xemu.
- Our matched TUs (`matches/`) compile to COFF with unresolved externals (calls into the game, globals, vftables, `__real@` constants). Externals must resolve to **original addresses**. Task 01's relocation mapping is exactly that table. Until it lands, start with leaf functions that have no relocations.
- xemu: needs the user's own BIOS/MCPX/HDD images. Don't download or commit any. Document what the user must provide and where.

## Deliverables
1. `tools/patch_xbe.py`: input the original XBE and a set of `(original address → our object/function)` pairs, output a new XBE with:
   - a new executable section holding our code, linked (resolving externals to original VAs);
   - a `jmp` written at each original function entry to our version;
   - corrected header, section table and image size. Output goes to `build/` only.
2. A smoke test: patch a handful of matched leaf functions (byte-identical, so behaviour can't change), boot in xemu to the main menu, and document the steps in `docs/hybrid-build.md`.
3. A first deliberate behaviour change behind a flag, e.g. one QoL tweak from task 07, to prove the path for mods.

## Done when
- A patched XBE with ≥10 redirected functions boots and plays in xemu.
- The process is documented and reproducible from a clean checkout plus the user's own game and xemu files.
