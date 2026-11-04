# Moved

This document is now [docs/wine-build.md](wine-build.md). The 32-bit clang image run under Wine is called the "Wine build" ("native" is reserved for the future 64-bit builds); this stub keeps old links working.

## x86-64 Linux (SteamOS): the native build on ELF (elf1, 2026-11-03)

The 64-bit native builds are documented in [native-mac.md](native-mac.md) (arm64 macOS) and
[native-android.md](native-android.md) section 13 (the ELF targets). x86-64 Linux shares `tools/native_elf.py` with
arm64 Android:

1. The front end for `x86_64-pc-windows-msvc` (MS C++ ABI, LLP64).
2. `native_mac.retarget()`.
3. The ELF steps: `m:e` datalayout, COMDATs kept as `any`, `win64cc` on game variadics, and `@` -> `#` in MS names.
4. The backend for `x86_64-unknown-linux-gnu` with `-fPIC`.
5. lld into a PIE.

The toolchain is the tree's LLVM (22.1.8) with lld. The sysroot is Debian 11's glibc 2.31 and GCC 10's libstdc++,
the base of Steam Runtime 3 "sniper". `tools/linux_sysroot.py` builds it from pinned, SHA-256-checked packages
(about 70 MB, under build/).

```sh
PY=build/venv/bin/python; export HULK_CLANG_PROBE_DIR=<dir with snap/>
$PY tools/linux_sysroot.py                                   # build/elf1/sysroot-x64 (HULK_LINUX_SYSROOT elsewhere)
$PY tools/native_elf.py compile --target linux-x64 --jobs 4  # build/native-linux-x64/ (HULK_NATIVE_ELF_DIR)
$PY tools/native_elf.py link --target linux-x64 --ld         # link/hulk-linux, link-report.json, unbound.txt
sh tests/linux/host_link.sh                                  # the host-layer tests, linked for glibc
```

**Status (snapshot of clean1's proof build 42504):**
- Tree TUs: 2,655 / 2,658 compile. The 3 failures are the same as on macOS.
- Data TUs: 1,078 / 1,078.
- Unbound: 46,369. That is macOS's 46,370 without Darwin's `bzero`; `floor` moves to the host-libm rows.
- lld links with every unbound name stubbed (rc 0). The image is a 41 MB PIE for `/lib64/ld-linux-x86-64.so.2`.
- **Link only:** there is no Linux machine yet, so neither the image nor the host tests have run on Linux.

On the first run, check:
- the start-up trace's `low-4gb reserved` line (about 4,095 MB; the reservation is on by default on Linux);
- the game-`va_list` glue on glibc (it ran as x86-64 macOS under Rosetta: the same System V convention);
- `tests/native_host/*`.
