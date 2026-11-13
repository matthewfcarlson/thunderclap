# The x86-64 Linux image in a local VM (linux1, 2026-11-13)

The x86-64 Linux build (`tools/native_elf.py --target linux-x64`, image `hulk-linux`) is the SteamOS target. Until
now it was linked but never run: there was no x86-64 Linux machine, VM or container here (native-android.md 16.4).
This page sets up a free, scriptable Linux VM on an Apple Silicon Mac that runs the image, and records where it stops.

## Verdict

**The x86-64 Linux image runs**, in an arm64 Debian VM through Rosetta for Linux (Lima, free, headless), and after one
fix it stops where macOS and Android stop:

| | arm64 Android (and1, same snapshot) | x86-64 Linux, first run | x86-64 Linux, fixed |
|---|---|---|---|
| link | lld rc 0 | lld rc 0 (18,891 unbound names, metric as native_elf reports) | the same |
| initializers | 457 run, 9 skipped | 457 / 9 | 457 / 9 |
| stop (normal) | `missing ??0ParticleAllocator@pure3d@fn_002ac4a0@@QEAA@XZ`, 56 imports | `missing ?FUN_002674f0@fn_f6ff0ab7@@YA_NPEBD0@Z` from FUN_002771b0, 10 imports | as Android |
| stop (survey) | 4 missing names, SIGSEGV in `?run@C_265210@fn_00265210` +0x28 | that miss, then SIGSEGV in FUN_0008fca0 (args.txt not opened) | as Android: the same 4 names, the same crash |

Input: and1's snapshot (x64t7's proof 72321, HEAD 96cba7a7c, binding map `maps/p3`), compiled on the queue (72409;
77425 for the fixed objects, 2,675 / 2,675 tree TUs and 1,097 / 1,097 data TUs) and linked locally.

With the fix, the Linux trace equals Android's line for line (addresses normalised), except for:
- the floating-point line (`mxcsr 0x1f80 -> 0x1f80` on x86-64, `fpcr 0x0 -> 0x0` on arm64);
- `low-4gb reserved 4095 MB` (Android reserves nothing; native-mac.md section 1 expected about 4,095 MB on Linux: confirmed);
- the second thread's timing (the order of `WaitForSingleObject` / `ReleaseSemaphore` / `Sleep`, where the first
  `CloseHandle` falls, and the poll counts);
- the crash and missing reports' frames (below).

**No Linux-specific failure is left in the start-up.** The next stop is the game's 64-bit code: ParticleSystemLoader's
allocator 0x002ac4a0, already fixed on main by x64t8 (native-build.md "The loaders' records"), so the next run on a
current snapshot goes further.

### The fix: a 2-byte item read as 3 (all native targets, latent)

The first Linux run stopped in `FUN_002771b0` (src/engine/core/CementLibrary.cpp), the drive-name check, called with
`"D:X"`: none of its prefixes matched, so it called the wildcard matcher `FUN_002674f0` (unbound natively: its
callers declare it `bool`, its definition is `extern "C" char`). The name came from `FUN_00277190`, which copies the
default drive name into `DAT_0052a10c`: two bytes from `DAT_0042b50c` (`"D:"`, a 2-byte `short` in the data
inventory) and the terminator from the next byte. In the XBE that byte is the next item, `s_empty_0042b50e` (the
original's relocation names it), but the source read it as `DAT_0042b50c + 2`. Natively the data items are separate
objects in link order, so the byte after the 2-byte item is whatever the linker put there: 0 in the Android and macOS
links, `'X'` in this one. The source now reads `DAT_0042b50e` (still MATCH, relocations ok, and the reference now hits
the right symbol). Found with gdb under qemu-user (below): a breakpoint on FUN_002771b0, then a software watchpoint.

### x86-64 versus arm64

- **Frame pointers.** The x86-64 Windows front end omits them (Win64 unwinds by tables; its IR has no
  `"frame-pointer"` attribute), and the ELF backend then emits frameless code even at -O0. entry_posix.cpp walks
  `rbp`, so every crash and missing-name report stopped at frame 0. `tools/native_elf.py` now passes
  `-fno-omit-frame-pointer` to the linux-x64 front end (arm64's front ends already keep them: `"reserved"`). The reports
  now show the whole chain (e.g. ParticleAllocatorTemplate <- ParticleSystemLoader <- FUN_00291dc0 <- ... <- main).
  The crash report's `lr=` field is empty on x86-64 (no link register); the frames carry the information.
- **Calling convention.** Game functions use the IR's default convention, so SysV on x86-64 Linux and AAPCS64 on
  arm64, the same as the host glue on each; variadics are `win64cc` on both (native_elf.py). `long` stays 32-bit
  (the MS front end's LLP64) on every target.
- **Floating point.** The image has no x87 instruction at all (the game's float code is SSE2 scalar on x86-64, as
  it is NEON scalar on arm64; `long double` is `double` in the MS front end). The only AVX code is SDL3's
  cpuid-dispatched AVX2 blitters, which the headless runs never call. MXCSR starts and stays at 0x1f80 (round to
  nearest, all exceptions masked).
- **Page size.** The guest's kernel uses 4 KB pages, as SteamOS / the Steam Deck do (macOS arm64 is 16 KB, Android
  4 KB or 16 KB).
- **Alignment.** No difference seen: the image ran no faulting unaligned access on either.
- **Rosetta.** It translates SSE exactly; it is a translation layer, so timing-sensitive comparisons belong on real
  x86-64 hardware. Its debug server (`ROSETTA_DEBUGSERVER_PORT`) segfaults at start in this guest (even for a
  trivial binary), hence qemu-user for gdb.

### The host layer's tests

`tests/linux/host_link.sh` links the host layer's tests (CRT, Win32 shim, entry, MS-ABI RTTI) for x86-64 Linux;
until now they were linked, never run. `sh tests/linux/vm_run.sh host-tests build/elf1/linux-host` runs them in the
VM with tests/android/host_tests.sh's checks (tests/linux/host_run.sh): all pass (10 / 10, incl. the four endings
of entry_test and `low-4gb reserved 4095 MB`).

## The VM

| | |
|---|---|
| tool | [Lima](https://lima-vm.io) 2.x from Homebrew (`brew install lima`; Apache 2.0, free) |
| backend | `vmType: vz` (Apple's Virtualization.framework), `mountType: virtiofs` |
| guest | Debian 12 (bookworm) arm64 cloud image, kernel 6.1, 4 KB pages |
| x86-64 | Rosetta for Linux (`vmOpts.vz.rosetta: {enabled, binfmt}`): the guest's binfmt_misc hands every x86-64 ELF to Rosetta; Debian's amd64 multiarch packages give the loader and libraries (`libc6:amd64`, `libstdc++6:amd64`, `libgcc-s1:amd64`) |
| size | 4 CPUs, 8 GiB memory, a 20 GiB sparse disk (about 1.4 GB used after setup); Lima's image cache about 1.6 GB |
| where | `~/.lima/hulk-linux` (the instance), `~/Library/Caches/lima` (the downloaded image) |

**Why Debian.** SteamOS 3 is Arch-based, but a Steam game does not run against SteamOS's own libraries: it runs in
the Steam Linux Runtime container, and runtime 3 "sniper" is Debian 11. The sysroot the image links against
(`tools/linux_sysroot.py`) is that Debian 11 (glibc 2.31, GCC 10's libstdc++). The guest has to be arm64 (Rosetta
runs x86-64 *processes* in an arm64 VM; a full x86-64 VM would be qemu emulation, many times slower), and the x86-64
user space comes from multiarch packages, which Debian has and Arch Linux ARM does not (Lima's Arch template for
aarch64 is a third-party image from 2022). Debian 11 itself is out of LTS since August 2026, so the guest is
Debian 12: glibc 2.36 runs what was linked against 2.31. Debian 13 would do as well.

**What the guest sees of the Mac.** Lima's default home-directory mount is not used. The guest gets two read-only
virtiofs mounts and nothing else:

- `/mnt/hulk/bin`: the share directory (`build/linux-vm/share` by default; `SHARE=` at setup), where the script
  copies the image;
- `/mnt/hulk/data`: the player's own extracted disc (`isos/extracted`), read in place: it is never copied into the
  VM or anywhere else.

Writes go to the guest's `/tmp/hulk-run` (trace, stdout, save / tdata / udata), copied back with `limactl cp` and
deleted after each run. Port forwarding is off in both directions (`portForwards` ignores every guest port); the only
listener is Lima's own ssh on 127.0.0.1. No ssh keys from `~/.ssh`, no agent or X11 forwarding. The guest's network
is Lima's user-mode NAT (outbound only: apt during setup).

## Commands

```sh
brew install lima                                    # once
sh tests/linux/vm_run.sh setup                       # once: creates and starts hulk-linux (about 2 minutes)
sh tests/linux/vm_run.sh status | start | stop | shell
sh tests/linux/vm_run.sh host-tests [DIR]            # tests/linux/host_link.sh's executables, checked in the VM
sh tests/linux/vm_run.sh run IMAGE OUT [continue]    # the image's start-up (REC=<.hrp> for a replay)
sh tests/linux/vm_run.sh delete                      # removes the VM and its disk
limactl prune                                        # removes Lima's cached downloads (setup fetches them again)
```

Needs Rosetta on the Mac (`softwareupdate --install-rosetta --agree-to-license`; `setup` checks for it). A stopped
VM uses no CPU or memory, only its disk.

## Building and running the image

The queue compiles; the link is local (the sysroot and SDL3 are here), as in native-android.md 16.3. The link's
inventory step takes about 55 minutes on the laptop.

```sh
PY=build/venv/bin/python
$PY tools/linux_sysroot.py; $PY tools/native_linux_sdl.py        # once: the Debian 11 sysroot, the headless SDL3
# the objects: a clang-probe snapshot (snap/) compiled on the queue, e.g. build/x64t7/scripts/elfjob.sh as job/elfjob.sh:
$PY tools/jobq.py submit --name ME --needs clang --slots 4 --limit 3600 --files SNAP.tgz=job/snap.tgz \
    build/x64t7/scripts/elfjob.sh=job/elfjob.sh src/platform/sdl/crt/native_crt_table.h=job/native_crt_table.h \
    --out job/out.tgz job/compile.log -- sh job/elfjob.sh linux-x64           # (+ --files for uncommitted tools/)
tar xzf build/jobs/out/ID/job/out.tgz -C $NE/..                               # $NE/cache, $NE/report.json
HULK_NATIVE_CRT_TABLE=src/platform/sdl/crt/native_crt_table.h HULK_CLANG_PROBE_DIR=<dir with snap/> HULK_NATIVE_ELF_DIR=$NE \
    $PY tools/native_elf.py link --target linux-x64 --ld --bindings <bindings.json>   # $NE/link/hulk-linux
sh tests/linux/vm_run.sh run $NE/link/hulk-linux build/ME/run              # normal: the first stop
sh tests/linux/vm_run.sh run $NE/link/hulk-linux build/ME/run-c continue   # survey
```

`run` prints the stop as tests/android/libmain_run.sh does: a missing name (exit 3), a crash (exit 4), the end of
main. The environment is the other targets': `HULK_DATA_DIR` (the read-only disc mount), `HULK_SAVE_DIR`,
`HULK_TDATA_DIR`, `HULK_UDATA_DIR` and `HULK_TRACE_FILE` under the guest's `/tmp/hulk-run`, SDL's dummy audio and
video drivers, `HULK_HANG`, and `HULK_NATIVE_MISSING=continue` for `continue`. `REC=<.hrp>` adds the replay settings
of tools/native_linux_replay.sh. Movies: the image links `host/movie_none.c` unless `HULK_LINUX_FFMPEG` names an
x86-64 FFmpeg prefix at link time (none is built for Linux yet; `FFMPEG=` then copies its libraries into the VM).

**Debugging** (`vm_run.sh gdb IMAGE CMDS.gdb [continue]`): the start-up under qemu-user's gdb stub with gdb-multiarch
attached in batch mode; output in `gdb.txt` next to the command file. Symbols are the image's, so breakpoints go by
name (`break FUN_002771b0`, `break ?FUN_0008ee30#fn_f7b5f211##YAHXZ`: the ELF spelling of MS names has `#` for `@`).

## As a queue host later (not registered)

Possible only for `linux-x64` jobs (native replays of x86-64 images, tools/native_linux_replay.sh). The guest is
arm64, so tools/jobq_host_setup_linux.sh's checks fail as written (it expects x86-64: LLVM, MSVC through wibo, Wine);
Rosetta for Linux runs 64-bit x86 code only, so the 32-bit MSVC and Wine capabilities are out. Registering it would
also put queue work on the laptop, which takes only `wine-gfx` today (docs/compute.md), and Lima's ssh is on a
random localhost port (`limactl show-ssh`). A dedicated x86-64 SteamOS / Linux box remains the better `linux-x64` host;
the VM is the local check before one exists.

## Removing it

`sh tests/linux/vm_run.sh delete` (the VM and its disk, about 1.6 GB after setup and the debugging packages), then
`limactl prune` (Lima's download cache, about 1.6 GB) and `brew uninstall lima` if wanted. The share directory
(`build/linux-vm/share` or the one given at setup) holds only copies of images.
