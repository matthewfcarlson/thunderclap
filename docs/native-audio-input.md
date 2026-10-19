# Native audio and controller input (sa1)

The native image ([native-build.md](native-build.md)) replaces the XDK's DirectSound (18 imports), user soundtracks
(3) and XPP (7) with our own implementations on SDL3. Like the graphics backend
([graphics-backend.md](graphics-backend.md)) this follows [platform-boundary.md](platform-boundary.md#rules-for-library-and-platform-code-decided-2026-10-18):
interfaces only, no Microsoft or RAD code, shapes and constants taken from the game's own call sites and data.

```sh
PY=build/venv/bin/python
$PY tools/native_sdl.py build              # pinned upstream SDL3: host static lib (CMake) + i686 SDL3.dll
$PY tools/native_sdl.py test               # host: tests/native_audio, tests/native_input (typed backend API)
$PY tools/native_sdl.py wine-test          # i686 under Wine: the same tests through the hulk_xdk_* stand-ins
$PY tools/native_sdl.py backends --target win32   # hulk_sdl.lib for the native link (build/sa1/for-native9.md)
```

## Plan

**Layers.** `src/platform/sdl/audio/` and `src/platform/sdl/input/` are typed, platform-neutral backends on SDL3
(pointer-sized handles, `hulk_audio_*` / `hulk_input_*`). The XDK-shaped stand-ins in `src/platform/sdl/xdk/`
(`audio_dsound.cpp`, `audio_soundtracks.cpp`, `input_xpp.cpp`) only translate the game's 32-bit arguments into
calls on them. When `include/seams/` replaces the XDK layer (platform-boundary rule 4), the radsound HAL and the
radcore controller code call the backends directly and the shim files drop out.

**What the game asks for** (read from the verified sources of the radsound HAL `0x240c00-0x241400`,
`0x258e00-0x259c80`, and the radcore controller code):

| call | site | use |
|---|---|---|
| `DirectSoundCreate(0, &ds, 0)` | 0x241390 | once, sound init |
| `DownloadEffectsImage(ds, img, size, &loc{0,1}, &desc)` | 0x2411b0 | `img\dspimage.bin`: accepted and ignored (no DSP) |
| `CreateSoundBuffer(ds, desc, &buf, 0)` | 0x259610 | one mono buffer per sample channel; `desc` 24 bytes: size, flags 0x400a0, 0, format, mix bins, 0 |
| `SetBufferData(buf, ptr, bytes)` | 0x259610 | the buffer plays the game's memory (not copied) |
| `SetHeadroom(buf, 0)`, `SetCurrentPosition(buf, 0)` | 0x259610 | |
| `SetMixBinVolumes(buf, {count, pairs})` | 0x258f90 | per update: 7 outputs: bins 0 FL, 1 FR, 4 BL, 5 BR, 2 C, 3 LFE, 10 I3DL2 send; volumes in mB |
| `SetFrequency(buf, hz)` | 0x258f90 | pitch |
| `Play(buf, 0, 0, loop)`, `Stop`, `GetStatus` (bit 0 playing) | 0x259be0, 0x258e50, 0x258f40 | |
| `Get/SetCurrentPosition` (bytes per channel buffer) | 0x258e50/f00/ea0 | pause/resume, stream progress |
| `SetI3DL2Listener(ds, 12 words, 1)`, `CommitDeferredSettings`, `DirectSoundDoWork` | 0x241280, 0x240f50 | per update |

Formats: the HAL builds wave formats for two codec modes only: mode 0 PCM (8/16 bit) and mode 3 Xbox ADPCM (tag
0x69, 36-byte blocks). The game's codec table (0x4cc24c: PCM, VAG, PCMB, XADP, RADP, AT3+) and the data say what
reaches it: **every one of the 5,126 `.rsd` files in sound.rcf / sound_en.rcf is `RSD6` `RADP`** (Radical ADPCM,
1/2/4 channels, 12-48 kHz), which game code decodes; DirectSound sees PCM16. Xbox ADPCM is implemented and tested
anyway (it is the HAL's only other mode).

**Audio backend.** Our own mixer: voices = buffers reading the game's memory; PCM8/PCM16/Xbox ADPCM (decoder
written from the IMA ADPCM algorithm: 4-byte block header + 32 bytes of nibbles); linear-interpolation resampling to
48 kHz from a 32.32 fixed-point cursor; per-bin gains (mB -> 10^(mB/2000), headroom subtracted); bins folded to
stereo (FL+BL -> L, FR+BR -> R, C and LFE to both at -3 dB); bin 10 feeds a small software reverb (our own
Schroeder/FDN-style network driven by the I3DL2 room, reverb, decay time and HF ratio) as a documented
approximation of the Xbox's I3DL2 DSP image. No HRTF (DirectSoundUseFullHRTF: no-op), no DSP image.
One mutex guards all state; every game-visible value (status, position) is read under it, so a buffer that
reports "stopped" also reports its final position. Clock modes (`HULK_AUDIO_CLOCK`):

- `device` (default): SDL's audio device pulls; voices advance in real time (as on the Xbox).
- `frame[:N]`: deterministic for replays: each `DirectSoundDoWork` renders N frames (default 800 = 1/60 s at
  48 kHz) and queues them to the device; play positions depend only on the game's update count.
- no device (SDL audio failed to open): `DirectSoundDoWork` advances by wall time, so sounds still end.

`HULK_AUDIO_CAPTURE=path.wav` writes everything the mixer renders (tests check frequency, levels, pan from it).

**Input backend.** One interface, `HulkInputSource` (connected mask, read port, rumble), two sources:
SDL3 gamepads (default) and, later, a recorded stream (design below). The XPP stand-ins keep the Xbox semantics the
game depends on: `XGetDeviceChanges` reports pads present at start as insertions on the first call (the game opens
pads only from it, 0x2691f0), MU queries report none, `XInputGetState` fills the 22-byte state whose layout the
game's own table at 0x4cd6a8 spells out (buttons word: DPadUp 1, Down 2, Left 4, Right 8, Start 0x10, Back 0x20,
LeftThumb 0x40, RightThumb 0x80; analog bytes A, B, X, Y, Black, White, LeftTrigger, RightTrigger; thumbs LX, LY,
RX, RY), `XInputSetState` takes the motors at +0x42 of the feedback block and completes at once (status word 0:
the game skips rumble while it reads ERROR_IO_PENDING).

Mapping from SDL: A/B/X/Y = south/east/west/north (0 or 255), White = left shoulder, Black = right shoulder,
triggers 0..32767 -> 0..255, thumbs as SDL gives them except Y, which SDL reports positive-down and XInput
positive-up (a convention change, not an invert). **No axis is inverted.** About the right stick X feeling inverted
in xemu: the game negates the camera X input itself unless its "invert X" option is set (0x000a2100:
`if (!DAT_004dd83a) x = -x`; the option is the selector `camera_invert_x_selector`, saved with the profile,
command line `-caminvertx`), and inverts Y only when the option is set. That is the game's default, on hardware too;
the backend reports the stick as the pad does and leaves it to the in-game option.

**Recorded input (built by rp1; see [native-replay.md](native-replay.md)).** A `HulkInputSource` for native replays reads the hybrid recordings
(`tools/hybrid_test.py`'s JSON, keyed by the poll counter that `hybrid/hooks.cpp`'s vpad counts per
`ControllerXBox::vfunc_17` read): one virtual pad in port 0, inserted at the first device check, every read
succeeds, state = the recording's 18-byte gamepad for that poll, rumble ignored. Selected with
`HULK_INPUT_SOURCE=replay:<file>`; it needs the native image to count polls exactly as the hybrid hook does (the
same call site), and `HULK_AUDIO_CLOCK=frame` so audio-driven game events (a line of dialogue ending) land on the
same update.

**Build.** `tools/native_sdl.py` mirrors `tools/native_gfx.py`: a pinned upstream tarball (SDL `release-3.4.18`,
zlib licence, sha256 in the tool) under `build/third_party/` (never committed). Host: SDL's CMake build, static.
i686 Windows: SDL's own Windows configuration and source list compiled with clang against mingw-w64's headers into
**SDL3.dll** + import library: the image imports only `SDL_*` names, SDL's own msvcrt/Win32 imports stay inside the
DLL (the tree binds plain CRT names to game code, see graphics-backend.md 8). Import libraries for the DLL come from
.def files built from the names SDL needs and Wine's i386 DLL export tables.

## Status (2026-10-19)

**Built.** `tools/native_sdl.py build`: host libSDL3.a (CMake, 38 s) and i686 **SDL3.dll** (260 units, 17 s, 1.6 MB):
SDL's Windows configuration without a C runtime (`HAVE_LIBC` off: SDL's own stdlib and libm, `SDL_mslibc.c` for
`_chkstk` and 64-bit division, its own DLL entry), camera/GPU/render disabled, stb_image off. Imports: Win32 DLLs only
plus 9 math/string names from msvcrt.dll. One local patch (`PATCHES`: a static constant moved out of a naked
function, which clang rejects). `backends --target win32`: `hulk_sdl.lib` (4 objects) for the image; the xdk
stand-ins compile with the image's own flags (`native_host.compile_dir`) plus `-DHULK_NATIVE_SDL=1`.

**Proven** (`test` on the host through the typed API, `wine-test` i686 under Wine through the hulk_xdk_* stand-ins
with game-shaped structures; SDL's dummy audio driver, no sound to the speakers):

| check | host | i686 / Wine |
|---|---|---|
| audio | 34 / 34 | 58 / 58 |
| input | 29 / 29 | 31 / 31 |

Audio, measured on the mixer's output (identical on both): 1 kHz PCM16 tone -> 1000.00 Hz, RMS 0.3535 (0.3536
expected) both sides; pan with the right bin at -600 mB -> R/L 0.5012 (10^-0.3 = 0.5012); headroom 600 -> 0.1772;
centre bin -> 0.2500 per side (-3 dB); -10000 mB -> exactly 0; `SetFrequency(24000)` on a 48 kHz buffer -> 500.00 Hz;
a 22,050 Hz buffer with 441 Hz -> 441.00 Hz; PCM8 750 Hz -> 750.00 Hz at the right level; Xbox ADPCM: three
hand-worked IMA vectors (the step sequence 0, 11, 41, 104, 240, 533, 1164, 2521, 5431; saturation both ways;
the stereo nibble layout) exact, an encode/decode round trip at 46.0 dB SNR, an ADPCM voice at 500.00 Hz with
the block-granular byte position; one-shot status/position (playing at 4800 bytes half way, stopped at 0 at the
end, silent after), pause/resume through Stop/GetCurrentPosition/SetCurrentPosition, looping wrap; reverb off ->
exactly 0, a 1 s room -> a tail falling 25.7 dB over 0.4 s; the capture WAV equals the rendered frames bit for bit
(136,681 frames); frame clock: 10 DoWork -> exactly 8,000 frames / 16,000 bytes; device clock on SDL's dummy
device -> ~46,800 frames/s. The i686 run adds the HAL's own sequence (effects image, HRTF, the 0x3d5e68 listener
words, a channel whose mix-bin descriptor points into itself, volumes written in place, Play, GetStatus each 1/60 s
update): 1200.0 Hz, R/L 0.2512 for -1200 mB, the 0.05 s one-shot ends in the 3rd update.

Input (SDL virtual gamepads): no pads -> no changes; plug -> inserted bit 0 once; every button, the analog
buttons (A/Y/Black 255, others 0), triggers (127 / 255), thumbs (32767, 32767 up, -12345, -1000) as the game's layout
wants; the packet number moves only on change; rumble 0x8000/0x4000 reaches the pad's low/high motors, feedback
status 0; a second pad -> port 1; unplug -> removed, the old handle reads ERROR_DEVICE_NOT_CONNECTED (1167); replug
-> inserted, a new handle reads; unplug+replug between two checks -> removed and inserted; memory units: none; the
gamepad type also recognized by its XBE address (0x3ea774).

**In the game image: not linked yet.** The link and run changes are native9's (build/sa1/for-native9.md: the
`HULK_NATIVE_SDL` switch, hulk_sdl.lib + SDL3.lib, SDL3.dll next to the exe, `SDL_AUDIO_DRIVER=dummy` by default).
Until then the image keeps the old stand-ins (the switch is off). `audio_soundtracks.cpp` changed for every link:
its three stand-ins now fail the way the callers expect (INVALID_HANDLE_VALUE / FALSE; 0x355ab5 is in fact the
drive's find-first-file, see the request).

**Stubbed / approximate:** no HRTF, no DSP effects image (accepted, ignored), I3DL2 as our own small reverb (levels,
decay time, HF ratio, delays, diffusion; not room HF, rolloff, density), crosstalk and FX-send bins (6-9, 11+)
not mixed (logged once), LFE folded into both sides at -3 dB, a stereo buffer sends bin i from channel i % 2,
`SetBufferData` with a desc byte count and no data (the game never does this) plays nothing, the end-of-buffer
position reads 0, user soundtracks none, memory units none, XInputSetState completes synchronously (status 0,
returns 0), SDL rumble renewed every 30 s for a held rumble (SDL caps one call at 65 s), the recorded-input
source (design above).
