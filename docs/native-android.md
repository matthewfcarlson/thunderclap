# Native build: arm64 Android handhelds (android1, 2026-11-02)

Investigation, no code changed. Question: what does it take to add arm64 Android handhelds (Retroid Pocket 4 Pro / 5 /
Mini, AYN Odin 2, AYANEO Pocket) as a supported target next to x86-64 SteamOS and arm64 macOS? Basis: the repo
([native-mac.md](native-mac.md), [wine-float.md](wine-float.md) sections 12-14 and "Long term, 64-bit",
[graphics-backend.md](graphics-backend.md), [remaster.md](remaster.md), [wine-movies.md](wine-movies.md),
[wine-files-saves.md](wine-files-saves.md), `src/platform/sdl/`), SDL3's Android README and Android's tagged-pointer
page (both fetched, the only two vendor pages read in depth), and my own knowledge of the NDK, marked **(unverified)**
where I did not check it. No NDK is installed on this machine (no `adb`, `sdkmanager` or `~/Library/Android`), so no
compile experiment was run: every toolchain statement below is reasoning, and milestone A0 exists to test it.

## Verdict

**Feasible, and cheaper than it looks, because Android arm64 is "Linux aarch64 plus a Java shell".** The macOS work
(MS-ABI front end, retarget, `rtti_msabi.cpp`, soft x87, native CRT glue, bgfx sink, SDL3 layer) carries over. The
SteamOS x86-64 work (ELF retarget, non-Apple varargs, `entry_posix` Linux branches) is the half that Android shares and
that is not finished yet; **Android should be sequenced behind the first Linux/ELF native link**, with `aarch64` as the
second ELF architecture. entry_posix.cpp already has `__linux__ && __aarch64__` branches.

Biggest risks, in order:

1. **Variadic calling convention in the retarget (ELF/AAPCS64 `va_list` is a 32-byte struct; the Windows-triple front end
   emits a `char*` `va_list`).** macOS escapes this (Darwin arm64 `va_list` is also `char*`); Linux aarch64 and
   Android do not. native-mac.md section 5 already records the x86-64 System V form of this problem. It is a retarget
   problem for any variadic function the game defines (not only the host glue), and the fix has to be found in the
   LLVM IR/backend (see 1.3). Shared with SteamOS x86-64; Android arm64 is a second instance.
2. **Time to the first native link at all** (x64-6 name unification, the 56k unbound symbols in native-mac.md section 11):
   Android adds nothing here but cannot start before it.
3. **Performance at -O0**: the Wine build is -O0 today; the handheld budget needs -O1/-O2 game code, which is
   unproven for the float-order work (wine-float.md sections 4, 13). Needs the replay at the chosen level.
4. **Data install UX** (scoped storage, multi-GB extraction) and APK packaging: ordinary but a lot of Java/Gradle surface
   that nothing else in the project has.
5. Device fragmentation (GPU drivers, button layouts); mitigated by a small supported-device list.

## 1. Toolchain

### 1.1 What carries over

The pipeline is: front end for `aarch64-pc-windows-msvc` (LLP64, MS C++ ABI) to LLVM IR, then `retarget()` to the
platform triple and an ordinary backend ([native-mac.md](native-mac.md) section 1). For Android the second step targets
`aarch64-linux-android<API>` using the NDK's clang (same LLVM family; the retargeter must run on IR that the NDK's
LLVM version can read, so pin the front end to the NDK's LLVM or the other way round; mixed versions are the usual IR
break) and lld. The NDK is a full clang/lld/llvm-ar toolchain, so nothing needs Apple's tools.

### 1.2 Changes from the macOS retarget

| item | macOS (done) | Android (to do) |
|---|---|---|
| object format | Mach-O, ld64 `-alias_list` | ELF, lld (`--defsym`/linker script for aliases; lld has `--defsym`, and `--wrap`). The Linux x86-64 port needs the same work: share it |
| datalayout | `m:w` -> `m:o` | `m:w` -> `m:e` |
| COMDATs | dropped (ld64 coalesces `linkonce_odr`) | ELF supports COMDAT groups: keep them, but MS comdat kinds (`largest`, `noduplicate`, `samesize`) and `$`-names need converting to `any` |
| vftable/RTTI | named `<vftable>$rtti` + alias; 32-bit image-relative RTTI fields become offsets from the holding record | same rewrite (ELF has `R_AARCH64_PREL32` for `sym - place` but still no `sym - undefined_sym`, so keep the record-relative form). `rtti_msabi.cpp` is plain Itanium C++ host code: builds with the NDK unchanged |
| initializers | `llvm.global_ctors` -> `hulk_game_initializers[]` | same: take the TU initializers out of `.init_array`, run the XBE's table from `entry_posix` |
| `dllimport/export`, Windows linker options | dropped | dropped |
| TLS | Mach-O TLV | ELF TLS in the game's `.so` (initial-exec is not allowed for a `dlopen`ed lib on old Android; use the default model or `-ftls-model=local-dynamic`). Check how many sources use `thread_local`/`__declspec(thread)` first **(unverified count)** |
| x18 | macOS reserves it | Windows arm64 and Android both treat x18 as reserved/platform: consistent |
| unwind tables | none needed | none needed (below) |

### 1.3 Varargs (the real new item)

The Windows arm64 front end expands `va_arg` itself (pointer bump over a spill area) and calls `llvm.va_start/end/copy`
on a `char*`-sized `va_list`. The AArch64 backend picks the `va_start` lowering from the target triple: Darwin and
Windows use the `char*` forms; ELF Linux/Android use the AAPCS64 struct (`__stack`, `__gr_top`, `__vr_top`, offsets).
Retargeting that IR to `aarch64-linux-android` would write a 32-byte struct into an 8-byte slot. The other half is
the call side: Windows arm64 variadic calls pass floating-point arguments in integer registers; AAPCS64 passes them in
v0-v7. Options, to be tested at A0:

1. Mark every variadic function and call with LLVM's `win64cc` calling convention in the retarget. I believe the AArch64
   backend gives `win64cc` the Windows varargs lowering regardless of OS **(unverified; the fastest experiment)**.
2. Recompile variadic definitions with the real Android front end where the source allows (few functions; the sources
   are MSVC code and call `va_start` through the MSVC macros, which clang maps to builtins either way).
3. Wrap: game-side variadics are almost all `printf`-like debug/Lua glue that the platform layer already replaces
   (`_snprintf`, `_vsnprintf` in crt_posix.cpp). Count the remaining game-defined variadics first (a one-off scan of
   `llvm.va_start` in the IR); if it is a handful, rewrite them to take `va_list` explicitly, MSVC-neutral.

The count and option 1 are the first concrete experiment; the answer also unblocks SteamOS x86-64 (where the SysV
`va_list` is a struct as well).

### 1.4 C++ runtime, exceptions, RTTI

- **Exceptions**: not needed. The tree has one try/catch in an unreachable funclet (matches/0x0035be90, native-mac.md
  section 7); `__CxxFrameHandler3`/`_CxxThrowException` report and exit. No SEH. Compile with `-fno-exceptions`
  semantics as on macOS; no unwinder is required for game code.
- **RTTI**: the MS-ABI `__RTDynamicCast`/`typeid` live in our `rtti_msabi.cpp`; the game never touches libc++abi's
  `type_info`. The platform layer (SDL, bgfx, FFmpeg wrapper) is Itanium C++ and uses the NDK's libc++.
- **libc++**: link `c++_static` into the single `libmain.so` (SDL3's Android template requires the game library to be
  a shared library named `main`): one APK-local `.so`, no `libc++_shared.so` packaging, no ODR mix with FFmpeg (C).
  If the bgfx/SDL parts ever need to share libc++ with another `.so`, switch to `c++_shared`.
- **bionic vs the host CRT glue**: the glue (crt_posix.cpp, win32_posix.cpp) is POSIX and already builds on Linux.
  Android-specific checks: no `pthread_cancel`, `ucontext`-free fibers (the project has its own assembly context
  switch: good), `mmap` stacks fine, `dladdr` present, `backtrace()` absent (the crash report walks frame pointers:
  build with `-fno-omit-frame-pointer`), `/proc/sys/vm/mmap_min_addr` may be unreadable under SELinux (code must
  tolerate that). Android 15+ devices may use 16 KB pages: link with `-Wl,-z,max-page-size=16384` and do not hard-code
  4096 in the fiber/guard-page code.

## 2. Address space

- **Nothing in the build needs low-4 GB placement.** On macOS every pointer is above 4 GB (page zero), the build links
  and runs the pointer-width work already; the Linux `low_4gb_reserve` constructor in entry_posix.cpp is a *trap* so
  a 32-bit truncation faults loudly, not a requirement. The same holds for replay pins (`replay_hooks.cpp` is
  32-bit Wine-build only; native uses `hulk_uptr`/`HULK_OFS`).
- **Do not reserve the low 4 GB on Android.** ART on 64-bit places its heaps and images in the low 4 GB (compressed
  32-bit references **(unverified detail, but standard ART behaviour)**) and the zygote-forked process already maps parts
  of it; a `PROT_NONE` reservation of "every free range" could starve ART's later low-4 GB requests (heap growth, new
  dex/oat maps). Default `HULK_LOW_4GB=0` on Android; keep truncation hunting on macOS/SteamOS builds. `MAP_FIXED_NOREPLACE`
  exists on kernels >= 4.17 (Android 12+ devices ship 5.4/5.10), so it would work technically; the reason to skip it is ART.
- **Tagged pointers.** Per Android's page: on Android 11+, 64-bit processes on kernels with ARM Top-Byte-Ignore get an
  implementation-dependent tag in the top byte of native heap pointers for apps with targetSdk >= 30; checked on free.
  Consequences for this code base: (a) a pointer kept in a 32-bit field is already fatal; (b) a pointer cast to
  `hulk_intptr` and compared, hashed, sorted or masked behaves differently from an untagged one (a `malloc` pointer
  and a pointer to static data differ in the top byte; sorting by pointer value changes); (c) anything that shifts or
  masks a pointer (the data_ptrs "pointer-holding items" use whole words, fine). Replay checkpoints hash game state,
  not addresses (they would break under ASLR on macOS otherwise). The manifest opt-out is
  `android:allowNativeHeapPointerTagging="false"` on `<application>`; Android says the escape hatch is temporary and not a fix.
  Recommendation: opt out for the faithful build (identical pointer shapes on all three targets), and run one tagged
  configuration in CI to see whether any site breaks. MTE (Armv9 / some Pixels) is not on the listed handhelds.
- **VA size**: 39-bit or 48-bit depending on kernel config; both are above 4 GB, so no issue. `RLIMIT_AS` is not
  normally set for apps.

## 3. Platform layer

- **SDL3**: minimum API 21, builds need Android SDK 36+ and NDK r28c+ (SDL's README). `SDLActivity.java` loads the game
  library, which must be a shared library named `main`; the existing `main` in entry_posix.cpp becomes `SDL_main`
  (`SDL_main.h`) on Android. The Java glue and a Gradle project come from SDL's `android-project` template; Gradle
  runs on the build host and the NDK compiles the native part, so the APK build is a separate stage after the native
  link (our tree is one prebuilt `libmain.so`, not CMake sources: the template needs a prebuilt-libs variant).
- **Entry/crash handling**: the alt-stack SIGSEGV report works but Android's debuggerd also catches; send the report to
  logcat (`__android_log_print`) and a file in the app dir (`HULK_TRACE_FILE`), not only stderr. Replace `HULK_HANG`
  thread-state sampling (Mach-only) with a `tgkill` + signal backtrace if needed.
- **Storage and the player's data.** SDL3's README: relative paths go to internal storage then APK assets; helpers
  `SDL_GetAndroidInternalStoragePath()`, `SDL_GetAndroidExternalStoragePath()`, `SDL_GetAndroidCachePath()`. It does not
  cover permissions or `content://` access (I did not verify SDL's handling of SAF URIs). Plan:
  - saves and config: `SDL_GetPrefPath("Thunderclap","HulkUD")` (internal) already used by hulk_fs; also offer the
    external app dir for easy backup;
  - game data (`HULK_DATA_DIR`): never in the APK. First-run flow: the player points at their own ISO/XISO or
    already-extracted folder; the app verifies the XBE hash and extracts into the app's external files dir
    (`Android/data/<pkg>/files`, no permission needed; reachable through USB/MTP on most devices; Android 11+ hides
    `Android/data` from file managers without a workaround, so also allow an app-private internal dir). The roadmap's "extract
    locally" step is the same code. Picker: Storage Access Framework (Java side, `ACTION_OPEN_DOCUMENT`, then a file
    descriptor handed to native code), or for sideloaded builds the "all files access" permission
    (`MANAGE_EXTERNAL_STORAGE`) so a plain `/storage/emulated/0/...` path works, which is what emulator users expect.
    Space: movies alone are 1.2 GB (wine-movies.md); budget several GB. Decision for the user (below).
  - `hulk_crt_host_path`/`hulk_fs_map_path` map `D:\` etc. to `HULK_DATA_DIR`: unchanged; the loose-file `mods/` override
    layer maps to the external dir.
- **Input.** SDL3 maps Android game controllers (including a handheld's built-in controls, which Android exposes as an
  `InputDevice` with gamepad sources) to its gamepad API; hulk_input.cpp is on SDL gamepads already. Items to verify on
  a device: A/B/X/Y position swap (Retroid has a Nintendo-style layout option in its launcher), analog vs digital
  triggers (the RP5 reportedly has analog triggers; others digital: map to 0/255), the Mini and Odin Mini form factors'
  missing second stick clicks, rumble (`SDL_RumbleGamepad` -> vibrator), and SDL's noted limitation that joystick button
  count is hard-coded to 36 (irrelevant for the gamepad API). A touch overlay is optional (menus only).
- **Audio.** SDL3 audio on Android goes through its Android backend (AAudio with OpenSL ES fallback **(unverified for
  3.x)**); the game mixer (`hulk_audio.cpp`, xadpcm, reverb) produces PCM at 48 kHz and SDL pulls it. Needs a buffer-size
  choice for latency, and the CPU cost of the reverb/ADPCM on the little cores counted in section 5.
- **Movies.** Bink 1 via FFmpeg shared libs plus the `hulkmovie` wrapper, `dlopen`ed (wine-movies.md section 6). On
  Android: cross-compile the same minimal FFmpeg with the NDK for arm64-v8a (NEON on), ship the `.so` files inside the APK
  under `lib/arm64-v8a/` and `dlopen` them by soname. Android 10+ blocks executing code from app-writable directories
  for targetSdk >= 29, so a download-on-first-run FFmpeg is not an option; bundling is fine under the LGPL (dynamic
  link, notices as on desktop, `LICENSES-FFMPEG.txt`). The game still works without them (movies skipped).
- **Lifecycle (Android-only work).** App pause/resume (surface destroyed and recreated, GPU context loss), back button,
  keeping the screen on, sustained-performance mode, the game's loop vs `SDL_EVENT_WILL_ENTER_BACKGROUND` (suspend audio,
  stop the simulation without desyncing the replay clock). This is new code with no desktop analogue.

## 4. Graphics

### 4.1 Faithful backend (bgfx)

bgfx has Vulkan and OpenGL ES backends and builds with the NDK; the shader pipeline already emits SPIR-V and ESSL 300
for every program ([graphics-backend.md](graphics-backend.md) sections 3, 7). **Use Vulkan on Android**, not GLES:
graphics-backend.md notes bgfx's desktop GL path needs GL 4.3 features (`glCopyImageSubData`) and that "an
OpenGL/WebGL2 run" is not done; the Vulkan path is the one the project has exercised (under Wine). Expect device
work: the quad-copy fallback instead of blits, 548 self-test probes run on the device with `HULK_GFX_SCALE`, and
driver quirks around the generated combiner programs (100 combiner keys; shader compile at first use causes hitching on
mobile drivers: persist a pipeline cache under the cache dir, `SDL_GetAndroidCachePath()`).

### 4.2 Remaster renderer

remaster.md picks a native Vulkan 1.3 + Metal 3 RHI with inline ray queries. Handheld reality **(device facts from
news/spec pages, partly unverified)**: Retroid Pocket 5 and Mini use the Snapdragon 865 (Adreno 650, Vulkan 1.1/1.2 class
and **no** `VK_KHR_ray_query`); Pocket 4 Pro is a Dimensity 1100 (Mali-G77, Vulkan 1.1/1.2, no RT); Odin 2 uses a
Snapdragon 8 Gen 2 (Adreno 740, Vulkan 1.3, and I believe ray query only in newer drivers). So on Android the remaster
must be raster-only: R1-R3 features (resolution, PBR, SSAO, draw distance) behind capability gates, R4 ray tracing
off. The RHI's Vulkan backend must therefore not require 1.3 or ray query at device creation; design the capability
tiers now. The Vulkan backend is the same code as SteamOS and Windows-less Linux, plus `VK_KHR_android_surface` via SDL.
Freedreno/Turnip (Mesa's open Adreno driver) works through KGSL on some rooted/community setups and the Winlator/GameHub
world uses it; it is not something an APK can rely on, so assume the vendor driver and measure cold shader-compile hitching.

### 4.3 Resolution and aspect

Game is 640x480 literal with scaling/aspect handling in the backend (HULK_GFX_SCALE; widescreen is roadmap step 7).
Retroid Pocket 5: 5.5" 1920x1080 16:9; Pocket Mini: reported as 3.7" 1280x960 4:3 (the task text says 3.92"; spec
pages disagree, check the device in hand); Pocket 4 Pro 4.7" 1334x750; Odin 2 6" 1080p; AYANEO Pocket models 1080p-class
**(the last three unverified)**. 4:3 panels fit the original aspect perfectly; 16:9 needs the widescreen work
or pillarbox. Render at a fixed internal scale (e.g. 1x-2x, not native 1080p) for the faithful build.

## 5. Performance budget

Measured numbers exist only for x86 hosts under Rosetta and arm64 macOS: gameplay was 13.8 ms/frame with x87 -O0 and
2.2 ms/frame with the SSE -O0 image on an arm64 Mac (wine-float.md section 13, play3 headless). Game simulation was 66 percent of a frame and the game's own render
traversal 31 percent; pddi front end, bgfx submission, audio were small. The original ran on a 733 MHz Pentium III-class
CPU at 30 fps (33 ms), so an Xbox-era budget is generous in principle.

- An Apple M-series performance core is several times faster per clock than the A77/A78-class cores in a Snapdragon
  865 / Dimensity 1100 (rough ratio 2-3x single-thread, **my estimate, unmeasured**). Applying 2-3x to 2.2 ms gives
  roughly 5-7 ms of simulation at -O0, still inside 33 ms or even 16.6 ms. Level load measured 2.5 s on the Mac; expect
  roughly 5-10 s.
- The -O0 caveat: the Wine build is -O0 and the replay checkpoints were proven there; -O1 and above changed results in
  the x87 era (wine-float.md section 4, "-O1 crash"), and the SSE path compiles at -O0 by design. For a handheld, -O0 code
  is the simplest to keep bit-faithful and appears sufficient for simulation, but battery/thermals prefer -O1/-O2.
  Plan: ship -O0 first, measure on a device, then qualify -O1 with the full play3 replay.
- GPU: the faithful renderer is Xbox-era (low polygon counts; the cost is state changes, framebuffer effects, bloom
  passes, refraction). An Adreno 650 or Mali-G77 should hold 30-60 fps at 1x-2x internal resolution; the risk is
  per-draw CPU overhead through bgfx and the generated shaders, not fill rate. The remaster (PBR, SSAO, higher
  resolution) is a stretch on 865-class parts and fine on 8 Gen 2.
- Thermals/battery: mobile SoCs throttle under sustained load; the game should run at a locked 30 (the original rate)
  or 60 only where proven, use Android's sustained-performance hint, and the audio/movie decode on little cores.
  Movies are Bink 1 at 640x480 with software FFmpeg (NEON): trivial.
- Memory: handhelds have 6-12 GB RAM; the Xbox had 64 MB. Not a concern.

## 6. Determinism

Same flags as arm64 macOS: `-ffp-eval-method=double -ffp-contract=off`, SSE-order spellings, soft transcendentals
(`softx87.cpp`, integer/double-only, identical everywhere), the float-to-int spelling rule of wine-float.md section 14.
Android-specific points:

- **libm**: bionic's libm is not used for the 28 math rows (they go to soft x87); remaining `sqrt`, `fabs`, `floor`
  are exact IEEE. Do not let the NDK's `-ffast-math`-adjacent defaults in (`-ffp-model` untouched; the NDK default is
  precise). `fmaf` contraction off is the important flag; arm64 has FMA, so `-ffp-contract=off` is mandatory on every
  TU including the platform layer's math-sensitive parts.
- **FPCR**: entry_posix already clears FZ/DN/AH and sets round-to-nearest on arm64 (lines 315-322); Android app
  threads start with the default FPCR (FZ=0) on current bionic, but **every thread the game or SDL creates must set it**
  (the existing code sets it in `main` only: audit thread starts, `win32_posix.cpp` `CreateThread`, FFmpeg threads
  do not run game math). Some vendor kernels/ROMs and the Java VM may flush denormals on a JIT thread, not on ours.
- **NaN handling and conversions**: arm64 `fcvtzs` saturates and gives 0 for NaN; arm64 macOS and Android arm64 are the
  same ISA, so the two agree bit for bit; the open items (the one `FUN_00262270` spelling, ~2^63 cases) are shared.
- **Big/little cores and threading**: single-threaded simulation; scheduling does not change results.
- Conclusion: if arm64 macOS reaches checkpoint equality with the Wine build, arm64 Android should too, subject to the
  varargs and TLS retarget being correct. This is what makes Android useful for cross-platform rollback co-op: the same
  instruction semantics as the Mac, no Rosetta in the middle.

## 7. Distribution and legality

- **Sideloaded APK**, no Play Store needed. Recommended: `targetSdk >= 30` set deliberately (so tagged pointers are a
  known quantity, with the manifest opt-out), `arm64-v8a` only. Android 14+ blocks installs of targetSdk < 23. Play Store
  is a different project: game-asset policy, a decompilation of a commercial game, and notarization-like review; not planned.
- **User supplies**: their own disc image or extracted files (XBE hash checked), as on every other target. The APK
  contains code, shaders compiled from our sources, FFmpeg libs (LGPL notices) and no game bytes. Same Hard rules:
  nothing derived from the disc is committed; no leaked source, no XDK/Bink code (movies via FFmpeg).
- Updating: an in-app "check for updates" is optional; side-loaders will use their own flow.
- Public binary distribution carries the same open questions as the other targets.

## 8. Verification (joining the proof chain)

Chain today: Xbox (xemu, hybrid) -> Wine build (32-bit clang) -> 64-bit builds (macOS arm64, SteamOS x86-64).
Android arm64 joins as one more 64-bit build compared against the Wine build's golden checkpoints (play3, frontier
17310+ at 60000 frames per the memory note).

1. **No device needed for the first proof.** Build the same arm64 objects for `aarch64-linux-android` and run the
   *headless replay* (null audio, no graphics, `noop` bgfx) on Linux aarch64: Android's userland is not required for the
   simulation. A Linux aarch64 container or VM on Apple Silicon (arm64 Linux VM via Virtualization.framework/UTM) is
   native speed, so it proves "ELF + AAPCS + non-Apple retarget + soft float" bit-exactly. Honest limit: it uses glibc,
   not bionic.
2. **Android emulator (arm64 system image on Apple Silicon)** runs with hardware virtualization, so it is native arm64
   with bionic, SELinux, the real loader, scoped storage and the real SDLActivity lifecycle. Use it as the CI device for
   bionic/loader/lifecycle issues and for the replay-to-checkpoint run (`adb push` the `.hrp` and the player's data,
   `adb shell` run a `--replay` entry, `adb pull` the checkpoint file, compare). GPU: its Vulkan is
   SwiftShader/gfxstream-over-Metal, fine for functional graphics (the replay is headless anyway), not for performance.
3. **Real devices** for performance, thermals, input mapping and driver behaviour; connect over `adb` (USB or
   Wi-Fi); add a small `tools/android_replay.py` mirroring `wine_replay_job.py`. Host queue note: jobs here carry
   `--needs`; an `android` capability on a box with a connected device or emulator fits the existing queue model.
4. Compare function: reuse the checkpoint comparator (`wine_build_job.py compare`) unchanged; the Android trace file lines
   (`low-4gb`, `fpcr`) are the same format.

## 9. Proposed architecture

```
one tree  ->  MS-ABI IR (aarch64-pc-windows-msvc)  ->  retarget(os)  ->  object
                                                          macos-arm64   Mach-O   ld64   (done)
                                                          linux-x64     ELF      lld    (SteamOS; next)
                                                          android-arm64 ELF      lld    (NDK clang; this doc)
platform layer (src/platform/sdl): SDL3 + bgfx(Vulkan) / remaster RHI(Vulkan, raster-only gate) + FFmpeg (.so in APK)
packaging: libmain.so (+ libSDL3.so, libavcodec... , libhulkmovie.so) + SDLActivity (Java) -> hulk.apk (arm64-v8a)
android-only: first-run data installer (SAF or all-files), lifecycle, tagged-pointer opt-out, immersive mode
```

Keep the Android-specific code in `src/platform/sdl/android/` (Java activity subclass, data-install glue, storage paths,
logcat sink) and in the retarget (`os == "android"` branch); no change to game sources.

## 10. Staged plan

- **A0 (1-2 days, needs an NDK + a Linux/arm64 box)**: install the NDK locally (not system-wide), then (a) test the
  varargs question with a 30-line MS-ABI prototype: variadic definition + call with a double, front end for the Windows
  triple, retarget to `aarch64-linux-android`, run in the emulator/VM (try `win64cc`); (b) build `rtti_msabi.cpp`,
  `crt_posix.cpp`, `win32_posix.cpp` with the NDK and run `tests/native_host/*` on the emulator via adb; (c) count
  `thread_local` in the tree and variadic game definitions. Output: go/no-go on section 1.3. **Done 2026-11-03: go,
  with two new A1 items (section 12).**
- **A1 (depends on the first Linux ELF native link)**: ELF branch of `native_mac.py`'s retarget (generalise to
  `native_elf.py` shared by SteamOS and Android), alias/initializer handling for ELF, `entry_posix` as `SDL_main`,
  link `libmain.so` with stubs as macOS did in its section 9 stage. **Done 2026-11-03 (elf1, section 13), with the
  x86-64 Linux link alongside.**
- **A2**: headless replay of play3 on the arm64 Linux VM then in the Android emulator; checkpoints equal to the Wine build
  to the current frontier. This is the proof-chain milestone, and needs no GUI.
- **A3**: SDL3 Android shell: Gradle project, `SDLActivity` subclass, manifest (pointer tagging opt-out, landscape,
  gamepad), a "hello pddi" scene (`pddi/smoke`, selftest_scene) on a real device with bgfx Vulkan.
- **A4**: data installer (ISO/folder pick, hash check, extraction), saves path, FFmpeg for Android, audio.
- **A5**: playable on device: input mapping per supported handheld, pause/resume, performance pass at -O0, then -O1
  qualification, shader cache, sustained-performance mode.
- **A6**: remaster renderer capability gating for non-RT Vulkan; widescreen on 16:9 panels; release APK.

## 11. Risks and open questions for the user

**Decisions (2026-11-03).** The user accepted the suggested answers below:
- **Devices:** Snapdragon 865 class (Retroid Pocket 5 / Mini) is the floor and the Odin 2 the comfortable target. The
  test device is a Retroid Pocket 6 (12 GB).
- **Remaster:** raster-only on Android.
- **Data install:** the Storage Access Framework picker, with the ISO extracted on the device.
- **Pointer tagging:** opt out in the manifest, with one CI configuration that runs tagged.
- **Order:** run A0 now.
- **Performance:** a locked 30 fps at -O0 is acceptable for the first release.
- **Toolchain:** pinning the LLVM version needs a closer look before a decision.

The questions as they were put:


1. **Which devices are required?** Suggest a minimum of Snapdragon 865 (Retroid Pocket 5 / Mini) as the floor and the
   Odin 2 as the comfortable target; the Dimensity-based Pocket 4 Pro (Mali) is the likelier source of driver trouble. Do you
   own a device for testing, or is the emulator only for now?
2. **Raster-only remaster on Android** acceptable? (No ray tracing on 865/Dimensity-class GPUs.)
3. **Data install**: is "all files access" acceptable for a sideloaded build (simplest for users), or must it use the
   Storage Access Framework only? Do you want an in-app ISO extractor on the device or a desktop-side extract-then-copy?
4. **Pointer tagging**: opt out in the manifest (my recommendation) or run tagged?
5. **Order**: should Android wait for the Linux/ELF native link (my recommendation, it shares the hard parts), or
   do A0 in parallel now because it also de-risks SteamOS (the varargs question)?
6. **Performance target**: locked 30 fps faithful at -O0 acceptable for the first handheld release?
7. **Toolchain pin**: the front end and the NDK must use compatible LLVM (IR version); pinning to the NDK's clang for
   the whole 64-bit pipeline would simplify this but moves the macOS pipeline's compiler too.
8. Unchecked claims in this document: Retroid/Odin/AYANEO specs beyond the 865/screen facts; ART's low-4 GB use; the
   `win64cc` lowering; the TLS model on old Android; SDL3's SAF/content-URI support; AAudio as SDL3's default backend.
   All are cheap to check at A0/A3.

Sources read: SDL3 `docs/README-android.md` (libsdl-org/SDL, main), Android Open Source Project "Tagged pointers"
page, press spec pages for Retroid Pocket 5 / Mini (retrododo, notebookcheck, timeextension: treated as untrusted data).

## 12. A0 results (android2, 2026-11-03)

**Go on section 1.3.** `win64cc` on the variadic functions makes the retargeted MS-ABI IR correct on arm64 Android
(run on bionic, in the emulator). Two new findings must also be fixed before A1 links anything. Neither is Android-only:
the game sources spell `va_start` the x86 way, which breaks every 64-bit build including macOS, and MS-mangled names
collide under ELF symbol versioning.

**Toolchain (all under `build/android/`, nothing system-wide).**
- NDK r30 (30.0.16248370): clang/lld 21.0.0 (r574158c).
- The SDK's own cmdline-tools, platform-tools 37.0.1 and emulator 37.2.13, driven by Homebrew's JDK 21.
- System image `android-35;google_apis_ps16k;arm64-v8a`: Android 15, kernel 6.6, 16 KB pages, rootable. One AVD,
  headless, shut down after the runs.
- The tree's front end is Homebrew LLVM 22.1.8.
- Side effect: sdkmanager and adb created `~/.android/` (adbkey, analytics.settings). Nothing else outside the repo.
- Everything ran in the emulator, which runs native arm64 with bionic. No glibc VM was used. The x86-64 cross-check
  ran as x86-64 macOS under Rosetta (System V `va_list`, the same as SteamOS).

**(a) Varargs.** `tests/android/va_proto.sh` runs `va_game.cpp`, MS-ABI code with a variadic definition, ints and
doubles in and past the 8 registers, and `va_list` forwarding inside the game and to the host. It is retargeted by
`tests/android/va_retarget.py`, and `va_host.cpp` is the native caller.

| case | plain retarget | `--win64cc` |
|---|---|---|
| game -> game variadic, double among ints, 4 and 10 args | wrong values | ok |
| game `va_list` forwarding to a game consumer | SIGBUS | ok |
| game `va_list` to host `vsnprintf` | SIGBUS | ok |
| game -> bionic `snprintf` with a double | ok | ok (host names keep `ccc`) |
| host -> game variadic, plain prototype | wrong | wrong (expected) |
| host -> game variadic, prototype `__attribute__((ms_abi))` | wrong | ok |

- The same results hold at -O0, -O1 and -O2, with both backends (NDK 21, Homebrew 22).
- They also hold for x86-64 System V (`x86_64-pc-windows-msvc` IR retargeted to x86-64 macOS under Rosetta), so the
  same pass covers SteamOS.
- With `win64cc` the backend lowers `va_start`, the GPR save area and variadic calls the Windows way for any OS. On
  AArch64 it also saves and restores x18 in those functions. That is harmless on Android, where x18 is reserved or
  holds the shadow call stack.
- Host glue that receives the game's `va_list` (a `char*` over 8-byte slots) builds a native one with no copying. On
  AAPCS64 it is `{__stack = p, gr/vr_offs = 0}`; on System V it is `{gp_offset 48, fp_offset 176, overflow = p}`.
  The prototype is `hulk_host_vsnprintf_ms` in `va_host.cpp`, which crt_posix.cpp's `_vsnprintf` family needs on
  Linux and Android.
- Rule for A1:
  - `win64cc` goes on every game variadic definition, declaration and call.
  - Host C library variadics (`snprintf`, ...) stay `ccc`.
  - Host code that calls a game variadic declares it `ms_abi`.
  - One signature per address. A caller that declares a fixed-argument function variadic, or the reverse, passes
    doubles in the wrong registers. The consolidation's single declaration per function covers this.

**The x86 `va_start` in the game sources (new, all 64-bit targets).**
- 18 game functions build their `va_list` from the address of the last named parameter:
  - `(char*)&fmt + 4`: 0x000964a0, 0x000dfcc0, 0x0023fde0, 0x00245b00, 0x00246f50, 0x00267760, 0x00213470.
  - `&fmt + 1`: 0x00238bb0, 0x0021f800, 0x00232cc0.
  - `&c` or `(&c) + 1`, with the variadic part declared as named parameters (`(a, b, c)`): 0x000fc000, 0x000fc020,
    0x00216320, 0x0023fef0, 0x0025fba0, 0x00338e20, 0x00214a90, 0x0025fad0.
- Only 8 of the 18 are spelled with `...`. 258 other sources call them by their FUN_ name, and more call them
  through local aliases.
- Three game consumers walk the list in 4-byte slots: 0x002160c0 (Lua's pushvfstring), 0x000fbc00 and 0x000fbe00
  (wide vsprintf).
- On a 64-bit target the parameter is a spilled register copy, so `&fmt + 4` reads other stack data. In the emulator
  `"%d-%d", 11, 22` printed `22558-22558` with +4 and garbage with +8, with no crash.
- macOS arm64 has the same bug. No native build has run game code yet, which is why it hasn't been seen.
- Fix (A1, all 64-bit builds): give these sources real `...` signatures with `va_start`/`va_arg`, under the native
  configuration only, so the 32-bit match and equivalence stay. Turn the consumers' slot walks into `va_arg`.
- `tests/android/count_variadics.py` writes the candidate list to `build/android/counts/va_start_idiom.txt`. It has
  58 candidates; the other 40 use a parameter slot as scratch or as an out-argument and are not varargs.

**ELF symbol versioning breaks MS names (new, SteamOS and Android).**
- lld reads `@` in a symbol name as a version separator. In an executable it silently truncates `??_7D@@6BB@@@` and
  `??_7D@@6BC@@@` to `??_7D`, so both vftables became one address and `dynamic_cast` from a second base failed
  (rtti_game.cpp line 41).
- A shared library such as `libmain.so` fails to link with "symbol ... has undefined version".
- Fix: the ELF retarget escapes `@` to `#` in every global name (`va_retarget.py --escape-at`; MS mangling does not
  use `#`). Host code that names MS symbols (rtti_msabi.cpp's `HULK_ALIAS`, the link's generated tables, stub names)
  uses the same spelling on ELF.
- With the escape the RTTI test passes, both as an executable and with the game side in a `-Bsymbolic` shared
  library.
- `libmain.so` also needs `-fPIC` and `-Wl,-Bsymbolic` (or hidden visibility on game definitions). Otherwise lld
  rejects the RTTI records' `R_AARCH64_PREL32` against preemptible `linkonce_odr` symbols.

**LLVM pin (section 11 item 7).**
- Homebrew 22 IR fed to the NDK's 21 backend compiled at -O0. That covered 39 of 40 sampled tree TUs and the
  prototype; the 40th fails the front end on both compilers (a template-specialization error in
  ShaderVectorBroadcast.cpp).
- At -O1 it fails, because LLVM 22's `llvm.lifetime.start` dropped the size argument.
- The NDK's clang 21 works as the MS-ABI front end: the same 39/40, and every test above.
- Recommendation: one LLVM per build, front end and backend together. On Android that is the NDK's clang end to end;
  linking always uses the NDK's lld and sysroot.

**(b) Host-layer tests.** `tests/android/host_tests.sh` builds them with the NDK (API 29, `-static-libstdc++`) and
runs them over adb. All pass:
- crt_test, with softx87 and with libm.
- host_test: threads, fibers on mmap stacks, files, on 16 KB pages.
- rtti_test, including the bad_cast and bad_typeid exits.
- entry_test, all four endings.

Differences from macOS:
- bionic's `dladdr` sees only `.dynsym`, so the crash report cannot name static functions.
- `HULK_HANG` sampling is Mach-only: one `hang phase=` line.
- rtti_test.cpp's operator new/delete labels carry Mach-O's `_` prefix. The script patches copies, not the sources.
- The FPCR starts at 0.
- The low-4 GB reserve worked in a shell process (4,095 MB). It must stay off in the app; see below.

**(c) Counts** (lists in `build/android/counts/`):
- TLS: no `thread_local`, `__declspec(thread)` or `Tls*` in matches/, equivalent/ or include/. There are 8
  `thread_local` variables in the host glue: 4 in crt_posix.cpp (strtok, rand, the jmp table) and 4 in
  win32_posix.cpp (last error, thread id, thread object, fiber).
- Varargs: see above. 8 definitions are spelled `...` and 18 functions build a `va_list`. The tree also declares
  27 more variadic prototypes (CRT and aliases), with 1,772 call sites under those names.

**Section 11 item 8, checked here.**
- `win64cc` lowering: confirmed, as above.
- TLS model:
  - At API < 29 the NDK emits emulated TLS (`__emutls_get_address`).
  - At API >= 29 it emits ELF TLS with TLSDESC (general dynamic), not initial-exec. A `thread_local` in a
    `dlopen`ed `.so` worked across threads on API 35.
  - Use minSdk 29 or later.
- ART in the low 4 GB: confirmed. systemui's maps (as root) have 96 mappings below 4 GB, including the main heap
  `dalvik-main` at 0x14000000-0x20000000, the JIT caches and the boot images. So `HULK_LOW_4GB=0` is required in
  the app.
- `vm.mmap_min_addr` is 32768 on this image. Whether the app domain can read it is not checked here; that needs an
  APK.
- 16 KB pages: NDK r30 already links with 16 KB `LOAD` alignment by default.
- SDL3 3.4.18 (the project's pinned tarball):
  - AAudio comes first, with OpenSL ES as the fallback.
  - `SDL_IOFromFile` opens `content://` URIs through a file descriptor.
  - `SDL_ShowOpenFileDialog` uses `ACTION_OPEN_DOCUMENT`, so the SAF file picker for the ISO works as is.
  - The folder picker is `SDL_Unsupported()` on Android, so an extracted-folder install needs its own Java.
- Device specs were not checked.

**For A1.** Generalise `native_mac.retarget` to ELF:
- datalayout `m:e`, triple `aarch64-unknown-linux-android29` or `x86_64-unknown-linux-gnu`.
- the `@` escape.
- `win64cc` on game variadics, with a host-name list.
- `-fPIC` and `-Bsymbolic` for `libmain.so`.
- COMDATs per section 1.2.

Before the game links, also do these:
- Native-only `...` and `va_start` rewrites of the 18 functions and 3 consumers.
- A `_vsnprintf` glue that converts the game's `va_list`.
- Pin one LLVM.

## 13. A1 results (elf1, 2026-11-03): the ELF retarget and the first lld links

**Both ELF targets link.** The tree compiles and links for arm64 Android (`libmain.so`) and for x86-64 Linux (a PIE
executable), at the stage macOS reached in [native-mac.md](native-mac.md) section 9: every name the tree does not
define yet is stubbed. On Android the library starts in the emulator and runs the game's start-up up to the first
missing stub. Input: the clang-probe snapshot of clean1's proof build 42504, the same snapshot as macOS's 46,370.

| target | toolchain | tree TUs (front-end failures) | data TUs | unbound | link | image |
|---|---|---|---|---|---|---|
| arm64 macOS (control) | Homebrew LLVM 22.1.8, ld64 | 2,655 / 2,658 (3) | 1,078 / 1,078 | 46,370 | rc 0 | 29 MB executable |
| arm64 Android (API 29) | NDK r30 clang/lld 21, end to end | 2,655 / 2,658 (the same 3) | 1,078 / 1,078 | 46,369 | rc 0 | 42 MB `libmain.so` |
| x86-64 Linux (glibc 2.31) | Homebrew LLVM 22.1.8 + lld, Debian 11 sysroot | 2,655 / 2,658 (the same 3) | 1,078 / 1,078 | 46,369 | rc 0 | 41 MB PIE |

- "Unbound" means undefined names less the native CRT table's rows. It is the same metric as macOS's.
- The three unbound sets are macOS's set with one name changed:
  - Android lacks `bzero`. That is a Darwin artifact: Apple's backend lowers memset to `bzero`.
  - Linux also lacks `bzero`, and it has `floor` as a host-libm row. The x86-64 backend calls `floor` where AArch64
    has an instruction.
- The 3 front-end failures are the same TUs on all three targets: Track.cpp, CSoundSequence.GS.cpp and the
  held-back `_alloca` source. The 64-bit diagnostics are the same too: 454 truncations and 274 pointer/int casts.
- The compiles ran as queue jobs: 70 s for Linux and 88 s for Android, at 4 slots. The Android job ships the
  NDK's `clang-21`, thinned to arm64, with its resource headers. The links ran locally.

**Design: `tools/native_elf.py`.** It is a new tool, and `tools/native_mac.py` is unchanged. Its retarget calls
`native_mac.retarget()` itself, so the vftable, RTTI and initializer rewrites are shared and macOS's output cannot
change. It shields the COMDATs from the Mach-O step and then adds the ELF steps:

- **Triple and datalayout.** The triples are `aarch64-unknown-linux-android29` and `x86_64-unknown-linux-gnu`. The
  datalayout (`m:e`) comes from the backend clang itself.
- **COMDATs are kept.** MS `largest`, `samesize` and `exactmatch` become `any`, the kind ELF supports. Vftables are in
  clang's `largest` group, so one copy per class survives the link.
- **`win64cc` on game variadics.** It goes on definitions, declarations, direct calls and indirect calls with a
  variadic type. Host names keep the platform's convention: the native CRT table's tree names and targets, names
  that carry a row's XBE address, and the C library's variadics.
- **`@` is escaped to `#`** in every quoted global and COMDAT name. A single left-to-right scan does it, so a name's
  closing `@"` is never read as an opening one. The link reads names back with `#` -> `@`, so the inventory stays in
  MS spelling.
- **`-fPIC` objects.** `libmain.so` links with `-shared -Wl,-Bsymbolic -Wl,-z,defs` and libc++ static, and its soname
  is `libmain.so`. Linux links `-pie --export-dynamic`, so the crash report's `dladdr` names game functions.
- **Aliases and initializers.** These need no ELF-specific change. Vftable aliases are `linkonce_odr` ELF aliases.
  The TU initializers leave `llvm.global_ctors` (`.init_array`) and are run from the XBE-ordered table that `link`
  writes. `native_mac`'s link tables (`startup.s`, `rtti.s`) are converted to ELF assembly: no `_` prefix, `.data` and
  `.rodata`, and the `#` spelling.
- **The link.** It is `native_mac`'s inventory (name groups, type descriptors, vftables and RTTI records, the start-up
  table) with the ELF symbol reader and an lld step swapped in. It links:
  - the host glue: `entry_posix`, `crt_posix`, `win32_posix`, `rtti_msabi` and `softx87`;
  - a stub for every unbound name that the glue, libc, libm, libdl and the start files do not define.
- **Stubs.** A code stub calls `hulk_native_missing("name")`. A data stub is 64 zero bytes in `.bss`. Code and data
  are told apart by the demangled form: native_mac's `DATA_LIKE` pattern takes `?f@ns@@YA?AUPair@1@...` for data
  because of its `@1` back reference.
- **Shim hooks.** The ones the host glue calls but nothing links yet (`hulk_xdk_called`,
  `hulk_xdk_first_call_sink`) are null stubs. `hulk_game_main` is a reporting stub.

Host side:
- `rtti_msabi.cpp` spells its MS aliases through `HULK_MS(at, hash)`: `#` on ELF, `@` elsewhere. On macOS the
  object's symbols are unchanged.
- `entry_posix.cpp`:
  - On Android its entry is the exported `SDL_main`.
  - The low-4 GB reservation stays on by default on Linux and is off on Android unless `HULK_LOW_4GB=1`.
  - `hulk_native_missing` exits on re-entry (a stub reached from its own report).
- `crt_posix.cpp`:
  - `_vsnprintf` and `vsprintf` now take the game's `va_list`, a `char*` over 8-byte slots, and build the host's on
    ELF. On AAPCS64 that is `{stack, 0, 0, 0, 0}`. On System V it is `{48, 176, overflow, 0}`.
  - The table's `vsprintf` row became glue.
- TLS is ELF TLS. Our 8 `thread_local` variables use TLSDESC: there are 8 TLSDESC relocations and a `PT_TLS` segment.
  The one emulated-TLS variable in the image is libc++abi's own, from the NDK's static library.

Files:
- `tools/native_elf.py`.
- `tools/linux_sysroot.py`: the pinned Debian 11 sysroot, about 70 MB.
- `tests/android/libmain_loader.c` and `tests/android/libmain_smoke.sh`.
- `tests/linux/host_link.sh`.
- `host_tests.sh` and `va_proto.sh` now run the tree's retarget. `va_proto.sh` has an `elf` mode, which gives the
  same results as `win64cc`.

```sh
PY=build/venv/bin/python; export HULK_CLANG_PROBE_DIR=<dir with snap/>
$PY tools/native_elf.py compile --target android-arm64 --jobs 4     # or linux-x64; output build/native-<target>/
$PY tools/native_elf.py link --target android-arm64 --ld            # link-report.json, unbound.txt, link/libmain.so
sh tests/android/libmain_smoke.sh build/native-android-arm64/link/libmain.so   # adb device: start-up trace
sh tests/android/host_tests.sh; sh tests/android/va_proto.sh                   # host layer, varargs
$PY tools/linux_sysroot.py && sh tests/linux/host_link.sh                       # Linux: link only
```

**Emulator smoke tests.** The emulator was the same AVD as A0: Android 15, arm64, 16 KB pages.

- `host_tests.sh` passes:
  - `crt_test` with softx87 and with libm, including the new game-`va_list` cases on bionic;
  - `host_test`;
  - `rtti_test`, with the game side through `native_elf.py` and the real sources, not sed copies;
  - its `ref` and `typeid` exits;
  - `entry_test`, all four endings, through `SDL_main`.
- Low-4 GB: 0 MB by default, and 4,095 MB with `HULK_LOW_4GB=1`.
- `va_proto.sh`: `plain` fails as before, and `win64cc` and `elf` pass every case except the expected `hostcall`.
- `libmain_smoke.sh` on the game's `libmain.so` stands in for the activity: dlopen, then `dlsym("SDL_main")`.
  - The library loads, with every relocation resolved and `-z defs` clean.
  - The start-up trace runs, and initializer 0 (a library one) is skipped.
  - Initializer 1 (`FUN_0035c6e0`) calls the stub of `FUN_0027b020` and ends with
    `missing ?FUN_0027b020@fn_0035c6e0@@YA?AUPair_35c6e0@1@PEBD@Z ... phase=init 1 0x0035c6e0`, exit 3.
  - This is the first missing name. It is the same frontier any native target has today.

**Linux x86-64: link only.** No Linux machine was available, so nothing ran on Linux.
- `hulk-linux` is checked with llvm-readelf and llvm-nm:
  - it is an x86-64 `DYN` PIE with interpreter `/lib64/ld-linux-x86-64.so.2`;
  - it needs libpthread, libdl, libstdc++, libm, libgcc_s and libc;
  - `main` is exported, and no symbol name contains `@`.
- `tests/linux/host_link.sh` links the five host tests (crt, crt_libm, host, entry, rtti) for glibc. The build has no
  warnings.
- The System V `va_list` conversion in `crt_posix.cpp` ran as x86-64 macOS under Rosetta. That is the same convention
  but not glibc.

**macOS before and after.** `native_mac.py link --ld` on the same objects gives the same result before and after:
- undefined 46,744 and unbound 46,370, with the same 3 front-end failures;
- `link.out` and `unbound.txt` identical;
- `rtti.s`, `startup.s` and `stubs.s` identical;
- the `rtti_msabi.cpp` object's symbols identical;
- the 29 MB `hulk-mac` image byte-identical.

`native_mac.py` is untouched, so the macOS compile cannot change. `tests/native_host/rtti_test.sh` and
`entry_test.sh` pass on arm64 macOS. `crt_test` passes on arm64 macOS and on x86-64 macOS under Rosetta.

The Wine build is not affected. None of the changed files (`src/platform/sdl/host/*`, `crt/native_crt_table.h`,
the tools) are part of it.

**What A2 (the headless replay) needs.**
1. **The unbound names.** These are x64-6's name unification and the consolidation. The run stops at the first
   initializer that calls an undefined name.
2. **The native CRT table bound by name.** The 374 rows' tree names have to reach their glue targets: the host
   defines them, or the sources name them. Today, for example, the game's `atexit` would bind to libc's, not to the
   glue's list that `entry_posix` runs.
3. **The 18 x86-style `va_list` producers and the 3 consumers.** These are the native-only `...` rewrites from
   section 12, a later agent's work. `win64cc` and the glue are ready for them.
4. **The shim on native.** `hulk_xdk_*`, the file layer with `HULK_DATA_DIR` on the device (the extracted disc pushed
   to the emulator's app storage, never committed), SDL3 for Android (`libSDL3.so`), bgfx's null renderer, and the
   replay driver and checkpoint hashing. `replay_hooks.cpp` is a Wine-build bridge.
5. **A place to run x86-64 Linux.** This means a SteamOS/Linux box, or a Linux VM. On this Mac that would be arm64
   Linux plus Rosetta for x86-64 binaries.
