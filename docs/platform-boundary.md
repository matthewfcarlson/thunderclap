# Platform boundary (roadmap step 1)

What game code calls outside itself: XDK (D3D8, XGraphics, DirectSound, XInput/XPP), XAPI, the
Xbox kernel, LIBCMT and Bink. This is the port's shim surface. Regenerate with:

```sh
# once per Ghidra project change (read-only, ~1 min):
build/tools/ghidra_12.0.3_PUBLIC/support/analyzeHeadless build/ghidra hulk -process default.xbe -noanalysis -readOnly \
  -scriptPath tools/ghidra_scripts -postScript ExportRefs.java build/port/refs.tsv
build/venv/bin/python tools/platform_map.py --summary --priority   # ~20 s
```

Outputs (all under `build/`, not in git): `build/port/platform_calls.json` (every target with its
callers and call counts, the seams, the leaks, the priority list with match status),
`build/port/labels.json` (Ghidra labels, applied by `ApplyPortLabels.java`),
`build/farm/priority.txt`. The priority list is also committed as `docs/port-priority.txt`.

## Summary

- **182 distinct platform functions** are called from game code, plus **69 portable CRT / C++
  runtime functions** (string, stdio, math helpers, `_ftol`, RTTI casts, `/GS` cookie checks).
  Game code also writes **93 words of D3D's own state** (`D3D__RenderState`, `D3D__TextureState`,
  `D3D__DirtyFlags`) directly, through `d3d8.h` inline functions.
- **The seams hold.** Every graphics, audio, movie, input, file, save, thread and kernel call
  comes from one of four engine seams. Only **8 game functions** outside them touch the platform,
  all trivial (a DVD check, launch info, language, memory status, a timer).
- **No direct hardware access**: no NV2A MMIO, no APU MMIO, no port I/O, no `rdtsc`, no push-buffer
  writes outside XDK code. **No Xbox Live / networking.** The kernel is called directly only for
  `RtlEnter/Leave/InitializeCriticalSection`.
- Things the port has to know about (details below): NV2A method numbers inline in game code,
  a hard-coded 733 MHz performance-counter frequency, fibers, `/GS` stack cookies, custom
  soundtracks, HD video modes already supported, 30 fps frame pacing in gameplay.

| Subsystem | Functions | Call sites | Port replacement | Difficulty |
|---|---|---|---|---|
| graphics (D3D8 + XGraphics) | 86 (+93 D3D state words) | 622 (+434 state refs) | pddi backend on Vulkan/Metal (SDL_gpu or bgfx) | **hard**: vertex shaders are NV2A microcode, pixel shaders are register-combiner programs |
| audio (DirectSound + soundtracks) | 24 | 27 | miniaudio / SDL3 audio; reimplement the radsound HAL voice | medium: I3DL2 reverb, HRTF 3D, mix bins and the DSP effects image (sample decode, incl. Radical ADPCM, is already game code) |
| movies (Bink) | 12 | 16 | modern Bink decoder (libbink/ffmpeg `binkvideo`) or transcode at asset-prep time | easy-medium |
| input (XInput / XPP) | 7 | 12 | SDL3 gamepad (rumble via `SDL_RumbleGamepad`) | easy |
| file I/O | 10 | 52 | `std::fstream`/POSIX; map `D:\`/`T:\`/`U:\` and `.rcf` paths | easy |
| saves / storage | 12 | 26 | files in the user data dir; drop signatures and MU mounting | easy-medium (save signing is HMAC over the title key: just skip) |
| threads / sync | 16 | 34 | `std::thread`, `std::mutex`, semaphores; fibers need ucontext / a thread-per-fiber | medium (fibers) |
| timing | 3 | 12 | `SDL_GetPerformanceCounter` / `std::chrono::steady_clock` | easy (but see the 733 MHz constant below) |
| memory | 5 | 7 | `malloc`; XAPI heap → a plain allocator | easy |
| process / system settings | 6 | 30 | config file / CLI flags; `XLaunchNewImage` → quit | easy |
| debug | 1 | 4 | `fputs(stderr)` | trivial |
| portable CRT / C++ runtime | 69 | 2,207 | the host libc / libc++ | none (but see `_ftol`) |

## Where library code lives

The XBE's `.text` (`0x11000`–`0x364840`) is not all game code. Three library spans are linked into it;
`tools/packet.py` currently counts them as game code because their unnamed functions are `FUN_`:

| Span | Contents | Evidence |
|---|---|---|
| `0x208b9c`–`0x212bb0` | XAPILIB (files, threads, heap, MU, launch, signatures) and `xboxkrnl` jump stubs | XbSymbolDatabase names, unaligned `/O1 /Oy-` code, `call [kernel thunk]` |
| `0x3440e0`–`0x356bf0` | LIBCMT plus more XAPILIB (fibers, save games, soundtracks, `XGetVideoFlags`) | same |
| `0x35a7b0`–`0x35be88` | LIBCMT EH runtime, `itoa`, 64-bit helpers | Ghidra FID names |

`0x356bf0`–`0x35a7b0` is aligned `/O2` math and collision code called only from game code
(spherical coordinates, triangle tests): a Radical library linked after the CRT, so **game**.
`0x35be88`–`0x364840` is `.text$yc`/`.text$yd` (dynamic initializers and `atexit` thunks of game
translation units): also game. Everything after `.text` (BINK*, D3D, XGRPH, DSOUND, XPP) is library.

The three library spans hold 753 functions (106 KB) that the farm queue treats as game code; 47 of
them are already matched. They are replaced, never decompiled, so they can be dropped from the
queue (a change to `tools/packet.py` `is_game`, left to the owner of that tool).

The kernel thunk table is at `0x3f2be0` (159 imports; the XBE header's address XOR the retail key).
Names come from the ghidra-xbe loader's ordinal table, read out of its jar at run time.

### Library functions named by hand

XbSymbolDatabase leaves most of LIBCMT and part of XAPILIB unnamed, and Ghidra's FID mislabels some
(`_strncpy` at `0x345650` is a memcpy-shaped copy; `FID_conflict:_fwprintf` is `fprintf`). Game
code calls 74 such functions; `IDENTIFIED` in `tools/platform_map.py` names them from their kernel
imports, constants and strings. The ones that matter:

| Address | Name | Evidence |
|---|---|---|
| `0x344e74` | `__RTDynamicCast` | 5 arguments incl. two RTTI type descriptors, throws `bad_cast`; 758 call sites |
| `0x34483c` | `_ftol` | `fistp qword` with control-word juggling; 367 call sites |
| `0x354ce2` | `QueryPerformanceFrequency` | writes the constant `0x2bb5c755` = **733,333,333 Hz** |
| `0x356667` | `XGetVideoFlags` | `ExQueryNonVolatileSetting(8)` `>> 16 & 0x5f` |
| `0x354c8f` / `0x209f50` | `XGetAudioFlags` / `XGetLanguage` | NV settings 9 / 7 |
| `0x2109f1`, `0x20ff8d`, `0x21007a`, `0x2101d4`, `0x2109b6`, `0x20bbc2` | `CreateFileA`, `ReadFile`, `WriteFile`, `SetFilePointer`, `GetFileSize`, `CloseHandle` | `NtCreateFile`, `NtReadFile`, … |
| `0x35618d`, `0x3564c0`, `0x3565ca`, `0x356611` | `XCreateSaveGame`, `XFindFirst/NextSaveGame`, `XFindClose` | `"\SaveMeta.xbx"`, UDATA paths |
| `0x355ab5`, `0x355791`, `0x3559b9` | `XFindFirstSoundtrack`, `XFindNextSoundtrack`, `XOpenSoundtrackSong` | `"…\TDATA\FFFE0000\MUSIC\"`, `"%s%04x\%08x.WMA"` |
| `0x20e1a1`, `0x20c79c`, `0x20c731`, `0x20d7ff` | `HeapAlloc`, `HeapFree`, `HeapCreate`, `HeapSize` | `RtlAllocateHeap` etc. |
| `0x37d8e0` | `D3D_SetPushBufferSize` | XbSymbolDatabase put this name on `0x244c0`, which is game code |

## The seams

Pure3D, radcore and radsound keep each library's translation units together, so each seam is an
address range. The ranges were checked against the RTTI owners of the functions inside them.

| Seam | Range | Classes (RTTI) | Functions in range | Calling the platform | Distinct platform APIs |
|---|---|---|---|---|---|
| **render**: Pure3D pddi D3D8 backend | `0x31ac80`–`0x3338e0` | `pure3d::d3dDisplay` (vt `0x43242c`), `d3dDevice` (`0x4324e4`), `d3dContext` (`0x433164`, 111 slots), `d3dTexture` (`0x4333ac`), `d3dPrimBuffer` (`0x4334b4`), `d3dPrimBufferStream` (`0x4334f4`), `d3dShader` + 14 shader subclasses (`0x43386c`…`0x433f74`), `d3dExt*` (9 extensions, `0x43307c`…`0x433324`), plus the platform-neutral `pddi*` bases | 662 | 149 | 86 functions + all 93 D3D state words |
| **core-platform**: radcore Xbox layer | `0x267000`–`0x27ab50` | `core::ControllerSystemXBox` (`0x42b2a4`), `ControllerXBox` (`0x42b14c`), `ControllerInputPointXBox` (`0x42b24c`), `ControllerOutputPointXBox` (`0x42b228`), `ControllerBuffer`, `Timer`/`TimerList`, `MemoryDlAllocator`/`MemoryTwoWayAllocator`/`MemoryPool`, `DebugConsole`, `Platform`, `XboxDrive` (`0x42b52c`), `XboxSaveDrive` (`0x42c064`), `Drive`, `DriveThread`, `File`, the `*Request` classes, `CementLibrary` (RCF), `InstanceDrive` | 856 | 71 | 59 |
| **audio-hal**: radsound Xbox HAL | `0x240c00`–`0x241400`, `0x258e00`–`0x259c80` | no RTTI (plain functions next to `audio::Mix`/`MixBuss`); `audio::ListenerEffectXBox` (`0x4294a8`) holds the I3DL2 parameters | 18 | 15 | 25 |
| **movie**: Bink player | `0x3338e0`–`0x335200` | `movie::PlayerBink` (`0x4340bc`), `RenderStrategyBink` (`0x4342c4`), `BinkCallback` (`0x4342e8`/`0x4342fc`) | 53 | 10 | 12 (all of Bink) |

What each seam calls:

- **render**: device creation and modes (`Direct3D_CreateDevice`, `D3DDevice_Reset`,
  `XGetVideoFlags`, `D3D_SetPushBufferSize`, `SetVerticalBlankCallback`), presentation
  (`BlockUntilVerticalBlank`, `Swap`, `D3D_KickOffAndWaitForIdle`), resources (textures, palettes,
  vertex/index buffers, surfaces, `XGSwizzleRect/Box`), fixed-function and programmable state
  (render/texture-stage states, `SetVertexShaderConstant*`, pixel shaders, lights, transforms),
  draws (`DrawVertices[UP]`, `DrawIndexedVertices`), visibility tests, gamma, and
  `XGAssembleShader` (shaders assembled at run time from text).
- **core-platform**: XInput (open/close/poll/rumble, hot-plug via `XGetDeviceChanges`), XAPI files
  (the `.rcf` archives go through `CreateFile`/`ReadFile` in a `DriveThread`), save games and MUs
  (`XCreateSaveGame`, `XFindFirstSaveGame`, `XMountMUA`, `XCalculateSignature*`, free space),
  custom soundtracks, threads, semaphores, critical sections, **fibers**
  (`ConvertThreadToFiber`/`CreateFiber`/`SwitchToFiber`), `Sleep`, QPC timers, `GetLocalTime`.
- **audio-hal**: `DirectSoundCreate`, `DownloadEffectsImage` (DSP image), `SetI3DL2Listener`,
  `DirectSoundUseFullHRTF`, `DirectSoundDoWork`, one `IDirectSoundBuffer` per voice
  (`SetBufferData`, `Play`, `Stop`, `SetFrequency`, `SetMixBinVolumes`, `SetHeadroom`,
  position/status), plus an XAPI heap for sample memory and `XGetAudioFlags` (stereo/surround).
- **movie**: twelve Bink entry points (open, frame decode/advance, copy-to-surface, sound track,
  close); none are named by XbSymbolDatabase. `RenderStrategyBink` draws the frames through pddi,
  so it uses the render seam rather than D3D.

### Leaks

Game functions outside the seams that call the platform (`build/port/platform_calls.json` → `leaks`):

| Function | Owner (nearest class) | Calls | Port fix |
|---|---|---|---|
| `0x88020` | `CGame::Init` | `XGetDiskSectorSizeA("D:\")`: 2048 means running from DVD | pick a mode by config |
| `0x88fe0` | near `CSimDb` | `XGetDiskSectorSizeA` (same DVD check) | same |
| `0x8c680` | near `CMemoryCardManager` | `XLaunchNewImageA` (reboot to dashboard) | quit to desktop |
| `0x8d480` | near `CPlatformManager` | `GlobalMemoryStatus` | report a fixed budget |
| `0x8ed60` | near `CPlatformManager` | `XGetLaunchInfo` | none |
| `0xbc7c0` | near `CFESoundManager` | `XGetLanguage` | OS locale / config |
| `0x2924e0` | Pure3D timer | `QueryPerformanceFrequency` | host timer |
| `0x292500` | Pure3D timer | `QueryPerformanceCounter` | host timer |

So: **reimplementing the four seams (149 + 71 + 15 + 10 = 245 platform-calling functions, inside
1,589 seam-range functions) plus these 8 leaves no platform call anywhere else in game code.** The other
1,167 game functions that call out only use the portable CRT/C++ runtime.

Callbacks go the other way and must be honoured by the shims: the vertical-blank callback
(`0x31acc0`, counts vblanks for frame pacing), thread and fiber start routines, Bink I/O callbacks
(`movie::BinkCallback`), and `atexit`.

## Things the port has to know

- **NV2A method numbers in game code.** `D3DDevice_SetRenderState(…)` and
  `SetTextureStageState(…)` are inline in the XDK headers: they write `D3D__RenderState[i]` /
  `D3D__TextureState[stage][i]`, OR bits into `D3D__DirtyFlags`, and call
  `D3DDevice_SetRenderState_Simple(method, value)` with an NV2A push-buffer method as an immediate
  (`0x40300` = alpha-test enable, `0x40304`, `0x40350`, …; 56 call sites). 51 functions do this, all
  in the render seam. The port's D3D shim must accept NV2A method numbers (a lookup table back to
  `D3DRS_*`), or the d3d backend gets rewritten against the new API, which it has to be anyway.
- **Shaders.** `d3dShader` subclasses set vertex-shader constants (112 `SetVertexShaderConstant1`
  sites) and assemble shaders with `XGAssembleShader`; the vertex shaders are NV2A microcode and the
  pixel shaders are register-combiner programs (`D3DDevice_CreatePixelShader`). Each of the ~15
  shader classes needs a hand-written GLSL/MSL equivalent. This is the biggest single port task.
- **733 MHz.** `QueryPerformanceFrequency` is a constant 733,333,333 Hz. Any host counter works as
  long as frequency and counter come from the same source.
- **`_ftol` everywhere** (367 sites): MSVC float→int with truncation. x87 precision and rounding
  differ from SSE; the port compiles to SSE/NEON, so physics replays may drift (roadmap step 6).
- **`/GS` stack cookies** (`__security_check_cookie`, 491 sites in 297 functions): drop them.
- **`__RTDynamicCast`** (758 sites): `dynamic_cast` throughout content loading; needs real RTTI in
  the port (the `include/gen/` headers have it).
- **Fibers.** radcore's thread layer uses fibers (`0x26d990`, `0x26db70`, `0x26dc00`, `0x26dd10`).
- **Custom soundtracks** (`XFindFirstSoundtrack` …) and **save signatures**
  (`XCalculateSignature*`) have no host equivalent; stub them.
- **Xbox Live / network:** none. **Direct hardware access:** none found (scan of all game code for
  `in`/`out`/`rdtsc`/`cpuid`/`wbinvd` and immediates in the NV2A/APU/USB MMIO ranges).

## Prior art for the backends: jsrf-recomp (reviewed 2026-10-12)

[andeecollard/jsrf-recomp](https://github.com/andeecollard/jsrf-recomp) is a Jet Set Radio Future port
built on [sp00nznet/xboxrecomp](https://github.com/sp00nznet/xboxrecomp). It statically recompiles the
XBE to C, then runs it on a kernel/XAPI replacement layer and an xemu-derived NV2A/APU model. As of
2026-09-26 it was playable into chapter 2 at 60 fps on Apple Silicon. It is the closest public project
to our port, but it solves a different problem. The recompiled game still runs Microsoft's D3D8 library,
which writes push buffers that the project observes and redraws. Our decomp replaces the pure3d D3D
backend with source, so we never produce push buffers.

| Our seam | Use | What |
|---|---|---|
| Input | Adapt | `src/input/xinput_device.c`: SDL2 GameController backend with rumble (MIT). Works on SteamOS and macOS. |
| Audio | Adapt | SDL2 output pattern (`src/apu/apu_sdl2.c`) and the DirectSound-call semantics (`dsound_host*.c`). We only need the DSOUND surface the game calls, not the APU/DSP emulator. |
| pure3d D3D backend | Reference | Register-combiner and vertex-shader-microcode translators (`src/nv2a/nv2a_vsh_hlsl.c`, `d3d8_combiners.c`), texture unswizzle and format decode, and their per-draw check of the D3D lift against the NV2A model (a way to verify our renderer later). The renderer itself is Metal-only (D3D11 on Windows) and tied to XDK 4134; we're on 5849 and need SteamOS too, so it stays ours to write. |
| radcore platform layer | Reference | `src/kernel/` HLE is built around the recompiled register model. |
| Bink | — | No Bink player; their movie playback is Media Foundation (Windows-only). |

**License:** MIT (© sp00nz), except for the xemu-derived files listed in its `NOTICE`, which are
LGPL-2.1 (`src/apu/apu_*`, `src/nv2a/nv2a_regs.h`, `nv2a_core.c`, `nv2a_state.h`). The swizzle and
combiner headers are MIT but credited as derived from xemu algorithms. Reuse MIT parts with their
notice, and treat the LGPL and xemu-derived files as reference only. **This repo has no license yet; pick one
before importing any code.** No leaked XDK or Microsoft source was found; its headers are self-written
from public documentation (xboxdevwiki, xemu, Cxbx-Reloaded).

## Full call inventory

Generated from `build/port/platform_calls.json`. "Called from" counts calling functions per seam;
`LEAK` is a game function outside the seams. "Library" is where the callee lives (`XAPI`,
`LIBC+XAPI` and `LIBC` are the spans inside `.text`).

#### graphics (86 functions, 622 call sites)

| Function | Library | Sites | Callers | Called from |
|---|---|---|---|---|
| `D3DDevice_SetVertexShaderConstant1` | D3D | 112 | 19 | render 19 |
| `D3DDevice_SetRenderState_Simple` | D3D | 56 | 26 | render 26 |
| `D3DDevice_SetTexture` | D3D | 55 | 17 | render 17 |
| `D3DDevice_SetPalette` | D3D | 44 | 14 | render 14 |
| `D3DResource_Release` | D3D | 36 | 24 | render 24 |
| `D3DDevice_GetTransform` | D3D | 30 | 11 | render 11 |
| `D3D_CheckDeviceFormat` | D3D | 28 | 1 | render 1 |
| `D3DDevice_SetVertexShaderConstant4` | D3D | 24 | 11 | render 11 |
| `D3DDevice_GetLight` | D3D | 21 | 10 | render 10 |
| `D3DDevice_SetTextureState_TexCoordIndex` | D3D | 14 | 12 | render 12 |
| `D3DDevice_CreateTexture2` | D3D | 10 | 8 | render 8 |
| `D3DDevice_SetPixelShaderConstant` | D3D | 10 | 3 | render 3 |
| `D3DDevice_GetBackBuffer2` | D3D | 8 | 8 | render 8 |
| `D3DDevice_SetPixelShader` | D3D | 8 | 6 | render 6 |
| `D3DSurface_GetDesc` | D3D | 7 | 7 | render 7 |
| `Get2DSurfaceDesc` | D3D | 7 | 5 | render 5 |
| `D3DDevice_SetRenderState_CullMode` | D3D | 6 | 5 | render 5 |
| `D3DDevice_SetRenderState_TextureFactor` | D3D | 6 | 6 | render 6 |
| `D3DDevice_SetVertexShader` | D3D | 6 | 5 | render 5 |
| `D3DDevice_GetRenderTarget2` | D3D | 5 | 5 | render 5 |
| `D3DDevice_SetRenderState_TwoSidedLighting` | D3D | 5 | 3 | render 3 |
| `D3DDevice_SetTransform` | D3D | 5 | 3 | render 3 |
| `D3DTexture_GetSurfaceLevel2` | D3D | 5 | 4 | render 4 |
| `D3DDevice_SetRenderState_ZEnable` | D3D | 4 | 3 | render 3 |
| `D3DDevice_SetTextureState_BumpEnv` | D3D | 4 | 1 | render 1 |
| `D3DTexture_LockRect` | D3D | 4 | 4 | render 4 |
| `XGIsSwizzledFormat` | XGRPH | 4 | 2 | render 2 |
| `D3DDevice_CopyRects` | D3D | 3 | 3 | render 3 |
| `D3DDevice_CreatePixelShader` | D3D | 3 | 3 | render 3 |
| `D3DDevice_DrawVerticesUP` | D3D | 3 | 2 | render 2 |
| `D3DDevice_SetRenderState_FillMode` | D3D | 3 | 2 | render 2 |
| `D3DDevice_SetRenderState_StencilEnable` | D3D | 3 | 2 | render 2 |
| `D3DDevice_SetRenderTarget` | D3D | 3 | 2 | render 2 |
| `D3DDevice_SetStreamSource` | D3D | 3 | 2 | render 2 |
| `D3DDevice_SetViewport` | D3D | 3 | 3 | render 3 |
| `D3DResource_AddRef` | D3D | 3 | 3 | render 3 |
| `D3DVertexBuffer_Lock2` | D3D | 3 | 3 | render 3 |
| `D3D GetSurfaceDesc helper` | D3D | 2 | 2 | render 2 |
| `D3DDevice_BlockUntilVerticalBlank` | D3D | 2 | 1 | render 1 |
| `D3DDevice_CreatePalette2` | D3D | 2 | 2 | render 2 |
| `D3DDevice_CreateVertexBuffer2` | D3D | 2 | 2 | render 2 |
| `D3DDevice_DeletePixelShader` | D3D | 2 | 1 | render 1 |
| `D3DDevice_DrawVertices` | D3D | 2 | 2 | render 2 |
| `D3DDevice_GetPixelShader` | D3D | 2 | 2 | render 2 |
| `D3DDevice_GetVertexShader` | D3D | 2 | 2 | render 2 |
| `D3DDevice_GetViewport` | D3D | 2 | 2 | render 2 |
| `D3DDevice_Release` | D3D | 2 | 2 | render 2 |
| `D3DDevice_Reset` | D3D | 2 | 1 | render 1 |
| `D3DDevice_SetVertexShaderConstantNotInline` | D3D | 2 | 2 | render 2 |
| `D3DDevice_Swap` | D3D | 2 | 2 | render 2 |
| `D3DPalette_Lock2` | D3D | 2 | 2 | render 2 |
| `D3D_KickOffAndWaitForIdle` | D3D | 2 | 1 | render 1 |
| `Direct3D_CreateDevice` | D3D | 2 | 1 | render 1 |
| `XGAssembleShader` | XGRPH | 2 | 2 | render 2 |
| `XGBuffer_GetBufferPointer` | XGRPH | 2 | 2 | render 2 |
| `XGBuffer_Release` | XGRPH | 2 | 2 | render 2 |
| `D3DDevice_BeginVisibilityTest` | D3D | 1 | 1 | render 1 |
| `D3DDevice_Clear` | D3D | 1 | 1 | render 1 |
| `D3DDevice_CreateImageSurface/RenderTarget` | D3D | 1 | 1 | render 1 |
| `D3DDevice_CreateIndexBuffer2` | D3D | 1 | 1 | render 1 |
| `D3DDevice_CreateVertexShader` | D3D | 1 | 1 | render 1 |
| `D3DDevice_DrawIndexedVertices` | D3D | 1 | 1 | render 1 |
| `D3DDevice_EndVisibilityTest` | D3D | 1 | 1 | render 1 |
| `D3DDevice_GetCreationParameters` | D3D | 1 | 1 | render 1 |
| `D3DDevice_GetDepthStencilSurface2` | D3D | 1 | 1 | render 1 |
| `D3DDevice_GetGammaRamp` | D3D | 1 | 1 | render 1 |
| `D3DDevice_GetVisibilityTestResult` | D3D | 1 | 1 | render 1 |
| `D3DDevice_LightEnable` | D3D | 1 | 1 | render 1 |
| `D3DDevice_SetBackMaterial` | D3D | 1 | 1 | render 1 |
| `D3DDevice_SetGammaRamp` | D3D | 1 | 1 | render 1 |
| `D3DDevice_SetIndices` | D3D | 1 | 1 | render 1 |
| `D3DDevice_SetLight` | D3D | 1 | 1 | render 1 |
| `D3DDevice_SetMaterial` | D3D | 1 | 1 | render 1 |
| `D3DDevice_SetRenderState_FogColor` | D3D | 1 | 1 | render 1 |
| `D3DDevice_SetRenderState_MultiSampleAntiAlias` | D3D | 1 | 1 | render 1 |
| `D3DDevice_SetRenderState_MultiSampleMask` | D3D | 1 | 1 | render 1 |
| `D3DDevice_SetRenderState_NormalizeNormals` | D3D | 1 | 1 | render 1 |
| `D3DDevice_SetRenderState_StencilFail` | D3D | 1 | 1 | render 1 |
| `D3DDevice_SetVerticalBlankCallback` | D3D | 1 | 1 | render 1 |
| `D3DSurface_LockRect` | D3D | 1 | 1 | render 1 |
| `D3D_GetDeviceCaps` | D3D | 1 | 1 | render 1 |
| `D3D_SetPushBufferSize` | D3D | 1 | 1 | render 1 |
| `Direct3D_AddRef/Release stub` | D3D | 1 | 1 | render 1 |
| `Lock3DSurface` | D3D | 1 | 1 | render 1 |
| `XGSwizzleBox` | XGRPH | 1 | 1 | render 1 |
| `XGSwizzleRect` | XGRPH | 1 | 1 | render 1 |

#### audio (24 functions, 27 call sites)

| Function | Library | Sites | Callers | Called from |
|---|---|---|---|---|
| `IDirectSoundBuffer_GetCurrentPosition` | DSOUND | 2 | 2 | audio-hal 2 |
| `IDirectSoundBuffer_SetCurrentPosition` | DSOUND | 2 | 2 | audio-hal 2 |
| `IDirectSound_SetI3DL2Listener` | DSOUND | 2 | 2 | audio-hal 2 |
| `DirectSoundCreate` | DSOUND | 1 | 1 | audio-hal 1 |
| `DirectSoundDoWork` | DSOUND | 1 | 1 | audio-hal 1 |
| `DirectSoundUseFullHRTF` | DSOUND | 1 | 1 | audio-hal 1 |
| `IDirectSoundBuffer_GetStatus` | DSOUND | 1 | 1 | audio-hal 1 |
| `IDirectSoundBuffer_Play` | DSOUND | 1 | 1 | audio-hal 1 |
| `IDirectSoundBuffer_Release` | DSOUND | 1 | 1 | audio-hal 1 |
| `IDirectSoundBuffer_SetBufferData` | DSOUND | 1 | 1 | audio-hal 1 |
| `IDirectSoundBuffer_SetFrequency` | DSOUND | 1 | 1 | audio-hal 1 |
| `IDirectSoundBuffer_SetHeadroom` | DSOUND | 1 | 1 | audio-hal 1 |
| `IDirectSoundBuffer_SetMixBinVolumes_8` | DSOUND | 1 | 1 | audio-hal 1 |
| `IDirectSoundBuffer_Stop` | DSOUND | 1 | 1 | audio-hal 1 |
| `IDirectSound_CommitDeferredSettings` | DSOUND | 1 | 1 | audio-hal 1 |
| `IDirectSound_CreateSoundBuffer` | DSOUND | 1 | 1 | audio-hal 1 |
| `IDirectSound_DownloadEffectsImage` | DSOUND | 1 | 1 | audio-hal 1 |
| `IDirectSound_Release` | DSOUND | 1 | 1 | audio-hal 1 |
| `XFindFirstSoundtrack` | LIBC+XAPI | 1 | 1 | core-platform 1 |
| `XFindNextSoundtrack` | LIBC+XAPI | 1 | 1 | core-platform 1 |
| `XFindNextSoundtrack (dir)` | LIBC+XAPI | 1 | 1 | core-platform 1 |
| `XOpenSoundtrackSong` | LIBC+XAPI | 1 | 1 | core-platform 1 |
| `XapiSoundtrack create` | LIBC+XAPI | 1 | 1 | core-platform 1 |
| `XapiSoundtrack set-info` | LIBC+XAPI | 1 | 1 | core-platform 1 |

#### movies (12 functions, 16 call sites)

| Function | Library | Sites | Callers | Called from |
|---|---|---|---|---|
| `BINK!FUN_00366b40` | BINK | 3 | 3 | movie 3 |
| `BINK!FUN_00368530` | BINK | 2 | 2 | movie 2 |
| `BINK!FUN_00368660` | BINK | 2 | 2 | movie 2 |
| `BINK!FUN_00364da0` | BINK | 1 | 1 | movie 1 |
| `BINK!FUN_00364dc0` | BINK | 1 | 1 | movie 1 |
| `BINK!FUN_00364fe0` | BINK | 1 | 1 | movie 1 |
| `BINK!FUN_00365f30` | BINK | 1 | 1 | movie 1 |
| `BINK!FUN_00366940` | BINK | 1 | 1 | movie 1 |
| `BINK!FUN_00367610` | BINK | 1 | 1 | movie 1 |
| `BINK!FUN_00367660` | BINK | 1 | 1 | movie 1 |
| `BINK!FUN_00367bc0` | BINK | 1 | 1 | movie 1 |
| `BINK!FUN_003681d0` | BINK | 1 | 1 | movie 1 |

#### input (7 functions, 12 call sites)

| Function | Library | Sites | Callers | Called from |
|---|---|---|---|---|
| `XInputClose` | XPP | 3 | 3 | core-platform 3 |
| `XGetDeviceChanges` | XPP | 2 | 2 | core-platform 2 |
| `XInitDevices` | XPP | 2 | 2 | core-platform 2 |
| `XInputGetState` | XPP | 2 | 2 | core-platform 2 |
| `XGetDevices` | XPP | 1 | 1 | core-platform 1 |
| `XInputOpen` | XPP | 1 | 1 | core-platform 1 |
| `XInputSetState` | XPP | 1 | 1 | core-platform 1 |

#### file I/O (10 functions, 52 call sites)

| Function | Library | Sites | Callers | Called from |
|---|---|---|---|---|
| `CloseHandle` | XAPI | 13 | 7 | core-platform 7 |
| `SetFilePointer` | XAPI | 9 | 6 | core-platform 6 |
| `GetFileSize` | XAPI | 8 | 8 | core-platform 8 |
| `WriteFile` | XAPI | 5 | 4 | core-platform 4 |
| `CreateFileA` | XAPI | 4 | 2 | core-platform 2 |
| `GetDiskFreeSpaceExA` | XAPI | 4 | 4 | LEAK 2, core-platform 2 |
| `GetDiskFreeSpaceExA (MU)` | XAPI | 3 | 3 | core-platform 3 |
| `SetEndOfFile` | XAPI | 3 | 2 | core-platform 2 |
| `ReadFile` | XAPI | 2 | 2 | core-platform 2 |
| `XapiOpenDirectory (NtOpenFile dir)` | XAPI | 1 | 1 | core-platform 1 |

#### saves/storage (12 functions, 26 call sites)

| Function | Library | Sites | Callers | Called from |
|---|---|---|---|---|
| `XCalculateSignatureBegin` | XAPI | 4 | 3 | core-platform 3 |
| `XCalculateSignatureEnd` | XAPI | 4 | 3 | core-platform 3 |
| `XCalculateSignatureUpdate` | XAPI | 4 | 3 | core-platform 3 |
| `XFindClose` | LIBC+XAPI | 3 | 3 | core-platform 3 |
| `XCreateSaveGame` | LIBC+XAPI | 2 | 1 | core-platform 1 |
| `XDeleteSaveGame / XFindFirstSaveGame` | LIBC+XAPI | 2 | 2 | core-platform 2 |
| `XUnmountMU` | XPP | 2 | 1 | core-platform 1 |
| `XFindFirstSaveGame` | LIBC+XAPI | 1 | 1 | core-platform 1 |
| `XFindNextSaveGame` | LIBC+XAPI | 1 | 1 | core-platform 1 |
| `XFormatUtilityDrive` | XAPI | 1 | 1 | core-platform 1 |
| `XMUNameFromDriveLetter` | XAPI | 1 | 1 | core-platform 1 |
| `XMountMUA` | XPP | 1 | 1 | core-platform 1 |

#### threads/sync (16 functions, 34 call sites)

| Function | Library | Sites | Callers | Called from |
|---|---|---|---|---|
| `xboxkrnl!RtlLeaveCriticalSection` | kernel | 8 | 5 | core-platform 5 |
| `xboxkrnl!RtlEnterCriticalSection` | kernel | 5 | 5 | core-platform 5 |
| `GetCurrentThreadId` | XAPI | 3 | 3 | core-platform 3 |
| `ConvertThreadToFiber` | LIBC+XAPI | 2 | 2 | core-platform 2 |
| `SetThreadPriority` | XAPI | 2 | 2 | core-platform 2 |
| `Sleep` | XAPI | 2 | 2 | core-platform 2 |
| `WaitForSingleObject` | XAPI | 2 | 2 | core-platform 2 |
| `xboxkrnl!RtlInitializeCriticalSection` | kernel | 2 | 2 | core-platform 2 |
| `CreateFiber` | LIBC+XAPI | 1 | 1 | core-platform 1 |
| `CreateSemaphoreA` | XAPI | 1 | 1 | core-platform 1 |
| `CreateThread` | XAPI | 1 | 1 | core-platform 1 |
| `DeleteFiber` | LIBC+XAPI | 1 | 1 | core-platform 1 |
| `ExitThread` | XAPI | 1 | 1 | core-platform 1 |
| `ReleaseSemaphore` | XAPI | 1 | 1 | core-platform 1 |
| `ResumeThread` | XAPI | 1 | 1 | core-platform 1 |
| `SwitchToFiber` | LIBC+XAPI | 1 | 1 | core-platform 1 |

#### timing (3 functions, 12 call sites)

| Function | Library | Sites | Callers | Called from |
|---|---|---|---|---|
| `QueryPerformanceCounter` | LIBC+XAPI | 8 | 8 | core-platform 5, render 2, LEAK 1 |
| `QueryPerformanceFrequency` | LIBC+XAPI | 3 | 3 | core-platform 1, LEAK 1, render 1 |
| `GetLocalTime` | LIBC+XAPI | 1 | 1 | core-platform 1 |

#### memory (5 functions, 7 call sites)

| Function | Library | Sites | Callers | Called from |
|---|---|---|---|---|
| `GlobalMemoryStatus` | XAPI | 2 | 2 | LEAK 1, core-platform 1 |
| `HeapSize` | XAPI | 2 | 2 | audio-hal 2 |
| `HeapAlloc` | XAPI | 1 | 1 | audio-hal 1 |
| `HeapCreate` | XAPI | 1 | 1 | audio-hal 1 |
| `HeapFree` | XAPI | 1 | 1 | audio-hal 1 |

#### process/system (6 functions, 30 call sites)

| Function | Library | Sites | Callers | Called from |
|---|---|---|---|---|
| `GetLastError` | XAPI | 24 | 19 | core-platform 19 |
| `XGetVideoFlags` | LIBC+XAPI | 2 | 2 | render 2 |
| `XGetAudioFlags` | LIBC+XAPI | 1 | 1 | audio-hal 1 |
| `XGetLanguage` | XAPI | 1 | 1 | LEAK 1 |
| `XGetLaunchInfo` | XAPI | 1 | 1 | LEAK 1 |
| `XLaunchNewImageA` | XAPI | 1 | 1 | LEAK 1 |

#### debug/exceptions (1 functions, 4 call sites)

| Function | Library | Sites | Callers | Called from |
|---|---|---|---|---|
| `OutputDebugStringA` | LIBC+XAPI | 4 | 2 | core-platform 1, render 1 |

#### Portable runtime (CRT / C++ runtime)

| Group | Functions (call sites) |
|---|---|
| C++ runtime | `__RTDynamicCast` (758), `__security_check_cookie` (491), `_atexit` (30), `_chkstk` (12), `type_info::operator==` (11), `_errno` (3), `_exit` (3), `strerror` (3), `__RTtypeid` (2), `__setjmp3` (2), `_longjmp` (2), `_fcloseall` (1), `type_info::name (undname)` (1) |
| CRT: heap/stdio | `FID_conflict:_fwprintf` (10), `free` (6), `_malloc` (5), `FID_conflict:_getc` (4), `_fclose` (4), `_nh_malloc` (4), `fopen` (2), `calloc` (1) |
| CRT: string/memory | `_strncpy` (85), `_strchr` (29), `_isdigit` (24), `_strncmp` (14), `toupper` (12), `_isspace` (10), `_memmove` (10), `_strncat` (5), `_qsort` (4), `_isalnum` (3), `_isalpha` (3), `_strstr` (3), `__stricmp` (2), `_bsearch` (2), `_iscntrl` (2), `_islower` (2), `_strrchr` (2), `strcmp` (2), `tolower` (2), `_ispunct` (1), `_isupper` (1), `_isxdigit` (1), `_memchr` (1), `_strcspn` (1), `_strupr` (1), `_ungetc` (1), `strtod` (1) |
| CRT: formatting | `_sprintf` (87), `_atol` (34), `atof` (20), `sscanf` (15), `__vsnprintf` (5), `puts` (3), `sprintf (vsprintf wrapper)` (1) |
| CRT: math | `_ftol` (367), `_CIpow` (29), `__floor_default` (20), `__isnan` (19), `_CIfmod` (9), `__allmul` (7), `_CIlog-class 1-arg x87 helper` (2), `_CIsqrt-class 1-arg x87 helper` (2), `__aulldiv` (2), `__aulldvrm` (2), `_CIexp` (1), `__aullshr` (1), `__ceil_default` (1), `_rand` (1) |

#### Library data referenced directly by game code

| Symbol | Words | References | Functions |
|---|---|---|---|
| `D3D__TextureState` | 42 | 162 | 27 |
| `D3D__DirtyFlags` | 1 | 153 | 34 |
| `D3D__RenderState` | 50 | 119 | 35 |
| `DSOUND!DAT_003d5e68` | 1 | 2 | 1 |
| `g_DeviceType_Gamepad` | 1 | 2 | 1 |
| `g_DeviceType_MU` | 1 | 2 | 2 |
| `D3D!DAT_0039db04` | 1 | 1 | 1 |
| `DSOUND!DAT_003d5e6c` | 1 | 1 | 1 |
