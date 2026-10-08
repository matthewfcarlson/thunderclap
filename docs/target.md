# Target binary: Xbox `default.xbe` (USA/Asia)

Extract with `xdvdfs unpack <iso> isos/extracted` (`cargo install xdvdfs-cli`). Dump header with `tools/xbeinfo.py`.

| | |
|---|---|
| MD5 | `5ed84ae5d79eee84d04f1535daf2bbc1` |
| SHA1 | `d5e7da38af1c3acbf6babe2b11a3e4c849a33362` |
| Size | 5,197,824 bytes |
| Title ID | `56550039` ("The Incredible Hulk:Ultimate Destruction") |
| Build timestamp | 2005-06-15 01:41:29 UTC |
| Base / entry (retail) | `0x10000` / `0x20A016` |
| Debug path | `c:\HC3-Link\hulk2\cd\xbox\default.exe` |
| PDB path (string in image) | `c:\HC3-Link\hulk2\cd\xbox\hulk2f.pdb` (not shipped) |
| XDK libs | XAPILIB, XBOXKRNL, LIBCMT, D3D8, XGRAPHC, DSOUND — all **5849** (final XDK, VS.NET 2003 / MSVC 7.1-era `cl` 13.10) |

Internal project name is `hulk2` (sequel to Hulk 2003). `f` suffix on the PDB is likely the "final" build config.

## Sections

| Section | VA | Size | Notes |
|---|---|---|---|
| `.text` | `0x11000` | `0x353834` (~3.3 MB) | game + Pure3D/radcore engine + statically-linked CRT |
| `BINK*` (16 sections) | `0x364840`… | small | Bink video codec — third-party, skip |
| `D3D`, `XGRPH`, `DSOUND`, `XPP` | `0x37D240`… | ~0x75000 | XDK libraries — identify with XbSymbolDatabase, skip |
| `.rdata` | `0x3F2BE0` | `0x99E88` | vtables, RTTI, strings |
| `.data` | `0x48CA80` | `0xE2E60` (0x4F56C on disk; rest is BSS) | |
| `BINKDATA`, `DOLBY` | | | third-party |

## Big wins already visible

- **RTTI is enabled**: ~4,200 `.?AV`/`.?AU` type descriptors. Through RTTI + vtables we recover class names, namespaces, inheritance, and every virtual method slot for free.
- Namespaces seen: `pure3d` (251 types), `audio`, `core`, `fight`, `physics`, `choreo2`, `content`, `hulkfight`, `om`, plus many `VC*Manager` game singletons (`VCActorManager`, `VCCameraManager`, `VCWorldStreamManager`, …).
- Engine is **Radical's Pure3D / radcore**: confirmed by namespaces and RCF archive magic `ATG CORE CEMENT LIBRARY` (radcore "Cement" archives, same family as Simpsons: Hit & Run).

## Disc layout

- `default.xbe`: the game
- `*.rcf` (13 files, ~2.3 GB): Cement archives (art, districts, rooms, sound, movies, nis, misc)
- `rcfs.txt`: mount order for the RCFs; `args.txt`: command line (`-fmvvol 0.9`)
- `img/*.bin`: DSP images for DirectSound (`dsstdfx.bin`, `rsdeffects.bin`, …)
