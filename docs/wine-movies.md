# Movies for the Wine build (mv1)

The game's cut scenes, intro logos and "movie of the game" clips are **Bink 1** files. The Wine build plays them with
**FFmpeg's Bink decoder as shared libraries** (decision (a) below), behind a Bink-shaped player that answers the ten
Bink calls the game makes (plus two more that the library table lists), writes video into the game's own lock buffers
and sends audio through the native mixer. Nothing from RAD is used or needed; no movie is converted, copied or
committed.

Status 2026-10-21: proven outside the game image, host (macOS arm64) and i686 under Wine, and run by the game: the
Wine image's normal run plays the five boot movies through this player (wine-build.md, native11). Replays pin
`no-fmv` and skip movies. See [Open items](#open-items).

Contents: [1 What ships](#1-what-the-game-ships) - [2 What the game calls](#2-what-the-game-calls) -
[3 Decision](#3-decision-ffmpeg-libraries-or-a-transcode) - [4 Implementation](#4-implementation) -
[5 Proof](#5-proof) - [6 Web and install implications](#6-web-and-install-implications) - [7 Running it](#7-running-it) -
[Open items](#open-items)

## 1 What the game ships

28 movies in five archives (`movies1.rcf`, `movies2.rcf`, `mog_mov1.rcf` .. `mog_mov3.rcf`; the radcore cement archive of
[formats/rcf.md](formats/rcf.md), listed with `tools/rcf.py list`). The files are named `*.rmv` but are plain Bink 1
files: the magic is `BIKi`, FFmpeg's `bink` demuxer opens them as they are. 69,095 frames, 38.4 minutes, 1,226 MB in
the archives. `tools/wine_ffmpeg.py inventory` reads every header; the table is the
result (counts only; the files themselves are the player's).

| movies | count | size | frame rate | audio | what |
| --- | --- | --- | --- | --- | --- |
| `1A_anim` .. `8E_anim`, `dintro`, `transformation` | 15 | 640 x 336 | 29.97 | 6 tracks (ids 0-5), mono, 48 kHz | the `*_anim` scenes, `dintro`, `transformation` |
| `attract`, `radical` | 2 | 640 x 480 | 29.97 | 6 mono tracks, 48 kHz | |
| `dolby` | 1 | 640 x 480 | 29.97 (36000/1201) | 6 mono tracks, 48 kHz | 4 seconds |
| `marvel`, `sierra` | 2 | 640 x 480 | 30 | 1 track, stereo, 44.1 kHz | 13 s each |
| `mog1` .. `mog8` | 8 | 640 x 480 | 29.97 | 1 track, stereo, 48 kHz | the longest (`mog4`: 6,799 frames, 3.8 minutes); in `mog_mov1-3.rcf` |

The six mono tracks look like a 5.1 mix (one mono track per speaker): the game routes each track to mixer bins by
`0x367660`, and the mixer folds the speaker bins to stereo. None of the files has an alpha
plane. Every file decodes to 4:2:0 planar video; all the video codecs are Bink 1 (`binkvideo`), the audio is Bink Audio
(all 118 audio tracks are the DCT variant, `binkaudio_dct`; the build also carries the RDFT variant for completeness).

## 2 What the game calls

The movie code is `movie::PlayerBink` (vftable `0x4340bc`, `0x333cb0`-`0x334010`), `movie::RenderStrategyBink`
(`0x4342c4`, `0x334130`-`0x334540`) and the I/O callbacks `0x334960`-`0x335010`. The Bink library behind them (ten
imports plus `0x367610`/`0x367660` that [library.h](../src/platform/sdl/xdk/library.h) lists) is
[library code](platform-boundary.md#rules-for-library-and-platform-code): never decompiled. Every shape below is read off
the game's call sites (pushes, cleanup, use of the result); nothing from RAD's SDK or documentation.

| address | call | arguments (stdcall) | result, as the game uses it |
| --- | --- | --- | --- |
| `0x364da0` | set I/O | open callback | - (called before every open: `vfunc_5`) |
| `0x364dc0` | set sound tracks | count, ids* (the file's track ids); `(0, 0)` = no sound | - |
| `0x364fe0` | open | name*, flags `0xa004000` | handle or 0 (then the game skips the movie: state 0); width / height / frames / frame number are the handle's first four words |
| `0x366b40` | pause | handle, paused | - (the game pauses right after the open and unpauses to start: `vfunc_8`) |
| `0x367660` | set mix bins | handle, track id, bins*, count | - (once per track, `0x333970`) |
| `0x367610` | set volume | handle, track id, volume | - (gain squared x 65536, `0x3339b0`) |
| `0x366940` | wait | handle | non-zero: not yet time (the game returns and tries next frame) |
| `0x367bc0` | do frame | handle | 0: decoded; the game copies only then |
| `0x365f30` | copy to buffer rect | handle, dst, pitch, dest height, dx, dy, sx, sy, sw, sh, flags `3` | non-zero: copied (0 marks the movie failed); called per tile with the bits and stride of the tile texture's lock; a negative stride is the engine's bottom-up lock, the game passes the lowest address |
| `0x3681d0` | next frame | handle | - (not called on the frame numbered frames - 1, after which the game ends the movie) |
| `0x368530` | close | handle | - (`~PlayerBink`) |
| `0x368660` | tick | - (cdecl) | milliseconds (the I/O callbacks time their reads) |

**The game's own I/O sits behind the open call.** `0x364da0` registers `FUN_00334fa0` (verified, equivalent): given a
79-word block and the movie name it opens the file through the game's stream layer (radfile, so a movie inside an RCF
archive resolves like any other file) and fills the block's first six words with callbacks `0x334960` (read at an
offset: synchronous, any offset and size, aligned reads against the device), `0x334c70`, `0x334ef0`, `0x334f10`,
`0x334c00` (Bink's asynchronous read-ahead ring) and `0x334f60` (close). The native player uses the synchronous one for
everything and the close callback when the movie closes; the ring is not needed (the decoder reads ahead by itself).

Video: `RenderStrategyBink` makes 32-bit linear pddi textures (at most 1024 x 1024 per tile, so a 640 x 480 movie is one
tile), locks them, and the player copies the decoded frame into the lock. [graphics-backend.md](graphics-backend.md)
section 10 has the draw side: the backend needs nothing movie-specific.

## 3 Decision: FFmpeg libraries or a transcode

**Chosen: (a) FFmpeg's `libavcodec` Bink decoder, dynamic libraries only, built from pinned upstream source.**

Options weighed:

* **(a) Decode the original files with FFmpeg's `bink` demuxer and the `bink` / `binkaudio_dct` / `binkaudio_rdft`
  decoders.** Upstream FFmpeg n8.0 (`tools/wine_ffmpeg.py`, sha256-pinned tarball), configured with
  `--disable-everything` and only those components: LGPL 2.1+ (configure prints the licence; no GPL or nonfree part),
  `libavutil` + `libavcodec` + `libavformat` only (no swscale, swresample, avfilter, network, programs). Used as
  shared libraries (DLLs on Windows) that the player loads at run time, so the game image never links FFmpeg and a
  user can replace the libraries (LGPL 6). Notice written by the tool to `build/third_party/out/LICENSES-FFMPEG.txt`.
  No install step: the player's own extracted data is read in place. Decoding is bit-exact against the original
  decoder's output (section 5) and 36x real time on one core.
* **(b) Transcode once at install or first run** (e.g. to VP9/Opus or H.264/AAC in WebM/MP4, with FFmpeg or a system
  encoder on the user's machine). Needs an encoder at install (not just the decoder), 1.2 GB of extra disk and minutes
  of CPU, loses quality (a second lossy generation), and then still needs a decoder at run time: the platform's
  (`AVFoundation` / Media Foundation / `<video>`) for which each of the three platforms and the web needs its own
  seam, or FFmpeg again. Its one real advantage is the browser: no wasm decoder to ship. See [6](#6-web-and-install-implications).
* **(c) A clean-room Bink decoder** (the web-port.md option 4): FFmpeg's is already an independent, patent-free
  reimplementation under the LGPL; there is nothing to gain.

(a) wins on fidelity (the original streams, played as shipped), on the install step (none), on licence hygiene (an
upstream library, replaceable) and on effort. Costs: the libraries must sit next to the game (4 DLLs, 1.1 MB on
Windows; `dylib` / `so` elsewhere) and the player must tolerate their absence (it does: `BinkOpen` then returns 0 and
the game skips the movie, as it does when a movie file is missing).

Rules kept (platform-boundary.md): no RAD code or SDK in the tree, no leaked material; FFmpeg's decoder is explicitly
allowed reading; FFmpeg and SDL come from upstream, with their notices; the movies themselves are never converted or
shipped.

## 4 Implementation

```
game code (PlayerBink)                          src/platform/sdl/xdk/movies_bink.cpp    32-bit stand-ins for the 12 calls
   |  Bink calls (u32 handles, stdcall)            + game I/O: the open callback's block, ReadHeader, Close
   v
src/platform/sdl/movies/bink_player.{h,cpp}     the Bink-shaped player: pause / wait / do frame / copy rect /
   |                                            next frame, the clock, per-track voices, mix bins, volume
   |   (audio) src/platform/sdl/audio/hulk_audio.h: streaming voices (new) on the mixer
   v
src/platform/sdl/movies/movie.{h,c}              the decoder wrapper (a separate library in the image)
   |  FFmpeg API (libavformat bink demuxer, libavcodec bink + binkaudio)
   v
libavformat / libavcodec / libavutil             shared libraries, tools/wine_ffmpeg.py
```

* `movie.c` (plain C, built as `hulkmovie.dll` / linked statically in the host tests): opens a movie over a
  `HulkMovieIO` (offset reads; the game's callback in the image, a file in tests), demuxes forward, decodes video on
  demand and the selected audio tracks into per-track 16-bit PCM queues, converts a frame rectangle YUV -> B, G, R, A
  (BT.601, bilinear chroma). Video packets met while reading ahead for audio are kept (up to 128).
* `bink_player.cpp` loads that library with `SDL_LoadObject` on the first open (so the image carries no FFmpeg); host
  tests define `HULK_MOVIE_STATIC`. The handle's first four words are width, height, frames, frame number.
  *Frame number is 0-based*: the game ends the movie when it equals frames - 1 after decoding and never advances past
  it (`0x333de0`), which only makes sense if the first frame is number 0.
* Clock: frame n is due at n x 1000 x den / num ms. With sound the clock is the audio's play position (what Bink
  syncs to), with the ticks (`SDL_GetTicks`, or the test's clock) as fallback when the device stalls (> 750 ms behind) or
  the audio has ended; without sound the ticks. The movie opens paused; the clock and audio start at the unpause.
* Audio goes through **streaming voices** added to the mixer ([wine-audio-input.md](wine-audio-input.md);
  `hulk_audio_stream_create` / `_write` / `_queued` / `_played` / `_flush`): a voice with a ring of 16-bit PCM (2 s) that
  the player tops up (400 ms ahead) and the mixer consumes, silence and a held position on underrun, any source rate
  (44.1 kHz resampled linearly like every voice). One voice per selected track; the game's mix bins (`0x367660`) and
  volume (`0x367610`: 65536 = unity, converted to millibels) apply to it, so the 5.1 tracks reach the front / centre
  / LFE / back bins and fold down in the mixer. Sound tracks come from `0x364dc0`.
* Video: `BinkCopyToBufferRect` converts the requested rectangle straight into the game's lock (BGRA bytes, the
  texture's `A8R8G8B8`). A negative pitch puts the image's top row at the highest address of a buffer whose lowest
  address the game passes, which is the engine's bottom-up lock (the same rows `bgfxTexture::writeFrame` would write).
* `xdk/movies_bink.cpp` is the 32-bit shim: real behind `HULK_NATIVE_SDL` (the count-only stand-ins otherwise, so the
  current Wine image is unchanged until `build/mv1/for-native9.md` is applied). It also defines the two `library.h`
  rows (`0x367610`, `0x367660`).

Files: `src/platform/sdl/movies/{movie.h, movie.c, bink_player.h, bink_player.cpp, ffcompat_win32.c}`,
`src/platform/sdl/xdk/movies_bink.cpp`, `src/platform/sdl/audio/hulk_audio.{h,cpp}` (streaming voices; the existing API
is unchanged), `tools/wine_ffmpeg.py`, `tests/native_movies/{movies_test.cpp, movies_dump.cpp}`.

### The FFmpeg build

`tools/wine_ffmpeg.py` (outputs under `build/third_party/out/`, ignored by git; nothing is installed):

* `fetch`: the n8.0 tarball from GitHub, sha256 `dd4030db...c7b9e`, unpacked to `build/third_party/src/ffmpeg`.
* `build` (host): FFmpeg's own `configure && make` with the options above (37 s). `build --target win32`: FFmpeg's
  `configure` run as a cross build with clang for `i686-pc-windows-msvc` and the mingw-w64 *headers* the SDL build
  uses (no mingw-w64 code or library), a link wrapper that answers configure's link tests with `lld-link` against
  import libraries made from Wine's export tables (so each feature test sees the classic `msvcrt.dll`: no `sinf`,
  `lrint`, `isatty` ...), then our own `lld-link` step per library (`avutil-60.dll`, `avcodec-62.dll`,
  `avformat-62.dll`, `av*` exported). `src/platform/sdl/movies/ffcompat_win32.c` supplies what the mingw-w64 headers
  send to libmingwex (about ten small functions over msvcrt). No assembly (generic C), so the DLLs are small and the
  video is bit-exact; the audio floats can differ from an arm64 build by a last bit.
* `build --target wasm`: the same libraries and `movie.c` with emscripten (`hulkmovie.wasm`, 549 KB): feasibility only.

## 5 Proof

All of it is `tools/wine_ffmpeg.py`; references are decoded by the **ffmpeg command line** (Homebrew's build, an
independent build of the same decoders), never by our code.

1. **Every shipped movie, whole** (`inventory`, host): 28 files, 69,095 video frames, 38.4 minutes. For each, the
   Adler-32 of every decoded planar frame equals the command line's (69,095 / 69,095), and every sample of every audio
   track equals the command line's decoded floats rounded the way `movie.c` rounds (118 audio tracks, 0 mismatches). Our decode of all 28 takes 62 s on one core (about 1,100 frames per second, audio included). Results in
   `build/mv1/inventory.json` (header facts and verdicts only).
2. **`test` (host, 578 checks)**, on a six-track movie (`1A_anim`, 640 x 336) and a stereo one (`mog1`, 640 x 480), 60
   frames each, through the typed API: YUV planes identical to the command line's for every frame; the BGRA
   conversion against ffmpeg's own swscale conversion, PSNR 52.8 dB (min) / 66.0 dB (mean) and 51.2 / 52.9 dB (the
   difference is chroma interpolation, not decoding); audio bit-identical; then through the Bink-shaped player on the
   mixer's manual clock: `DoFrame` + `CopyToBufferRect` into a negative-pitch (flipped) buffer, same PSNR; a
   sub-rectangle copy into an offset equals the same rectangle of the whole copy and writes nothing outside its
   rectangle; a rectangle past the buffer fails; frames appear 15-17 ms after their due time on the audio clock (the
   mixer steps 16.7 ms); the mixer's capture of the track (WAV) is sample-exact to the reference (peak, rms equal; 1.983 s
   of sound for a last frame due at 1.969 s); the capture file's header and length agree. Also: the streaming voices
   (ring wrap, underrun holds the position and continues, full ring, flush, stopped, 24 kHz resampling, stereo
   routing) and a file that is not a movie (open fails, I/O closed once). Last, a **whole movie as the game plays it**
   (`dolby`, 120 frames): six tracks routed to the six speaker bins by `BinkSetMixBins`, the LFE at half volume through
   `BinkSetVolume`, the game's own end test (frame number = frames - 1 ends the movie): all 120 frames shown, the last at
   its due time, and the mixer's stereo output equals the fold of the six decoded tracks (front and back pairs to their side,
   centre and LFE at -3 dB to both) within 2 LSB over the whole 3.98 s.
3. **`wine-test` (i686 under Wine, 581 checks)**: the same test through the `hulk_xdk_Bink_*` stand-ins with 32-bit
   handles, against the i686 FFmpeg DLLs, `hulkmovie.dll` loaded by the player at run time, and **the game's own I/O
   callbacks compiled in from the verified sources** (`equivalent/0x00334960.cpp` ReadHeader, `matches/0x00334f60.cpp`
   Close, the two alignment helpers) over a stand-in stream that enforces the device's 1 KB read alignment: 1.2 MB read in
   1,217 aligned reads for the first movie, 0 unaligned. Video identical, audio within 1 LSB of the reference (3 and 158
   samples out of 130,560 are not bit-identical: float rounding of the i686 build), the mixer capture within 1 LSB.
4. The audio and input tests of sa1 still pass (`tools/wine_sdl.py test` and `wine-test`: 34 + 29 host, 58 + 31 under
   Wine).

## 6 Web and install implications

* **Desktop**: no install step. Ship `avutil`, `avcodec`, `avformat` and `hulkmovie` beside the executable with
  `LICENSES-FFMPEG.txt` and the LGPL text; the game works without them (movies skipped).
* **Web port** ([web-port.md](web-port.md), which asks "do `.rmv` movies use Bink 1?": **yes**, `BIKi`, and "what would a
  transcode path cost?": above). The same minimal FFmpeg builds with emscripten (static libraries + the wrapper link to a
  549 KB `hulkmovie.wasm`, not run yet), so the web port can carry the same decoder: output the BGRA frames into a
  texture and the PCM into an `AudioWorklet`. That keeps one code path and the original data. If a smaller download or
  hardware decode matters more, option (b) is the web's: transcode once on the user's machine (WebCodecs / `<video>`) or
  skip movies as OpenCE does. This is a decision for the web port; nothing here blocks either.
* **Other desktops**: the same sources build natively (the host build is Apple clang on arm64; Linux is the same
  `configure` with a shared library).

## 7 Running it

```
build/venv/bin/python tools/wine_ffmpeg.py fetch
build/venv/bin/python tools/wine_ffmpeg.py build                 # host libraries
build/venv/bin/python tools/wine_ffmpeg.py build --target win32  # the i686 DLLs
build/venv/bin/python tools/wine_ffmpeg.py test                  # tests/native_movies, host
build/venv/bin/python tools/wine_ffmpeg.py wine-test             # the same, i686 under Wine
build/venv/bin/python tools/wine_ffmpeg.py inventory             # every shipped movie, whole, against the ffmpeg CLI
build/venv/bin/python tools/wine_ffmpeg.py movies                # what the image links / runs with (paths, imports)
```

The reference decode needs the ffmpeg command line (`brew install ffmpeg`). Movies are read in place from
`isos/extracted/*.rcf`.

## Open items

* **Written before the game ran it** (the first boot-movie run came with native11, see [wine-build.md](wine-build.md)):
  the proof below is the player against the game's own I/O callbacks and the engine's lock conventions as the code
  shows them. The list that follows was what only a running game could confirm; the boot movies play, but the details
  have not been re-checked one by one: that the stream
  behind the open callback serves the synchronous reads at the movie's offsets inside an archive (the callback's reads
  are 1 KB device reads; fine for a host-file stream, to be seen on the native drive layer); that
  `BinkCopyToBufferRect`'s non-zero-means-copied and `BinkDoFrame`'s zero-means-decoded are as read off `0x333de0`; the
  0-based frame number; and which movies the game plays in which order (the shipped scripts decide). Link steps: `build/mv1/for-native9.md`.
* The asynchronous read-ahead callbacks (`0x334c70` and the others) are never called; the original used them for
  streaming from DVD. The player reads ahead by itself (a 64 KB buffer, 400 ms of audio).
* The copy `flags` are ignored (the game passes 3, a 32-bit surface); no other surface formats exist in the game.
* End of file: FFmpeg's reads are clipped to the movie's size (taken from its header), but the game's read callback
  rounds each request up to the device block, as the original's ring reads do, so the stream must serve the few hundred
  bytes of padding after a movie (inside the archive they exist; the Wine test's stand-in stream reads the archive
  itself). A stream that clamps at the logical end would fail the last block.
* The audio device stalls fall back to the tick clock after 750 ms; a movie that is paused for longer than the audio
  ring (2 s) just resumes (the voices are stopped while paused).
