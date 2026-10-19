// Stand-ins for movies: Bink: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
// Movies: Bink for the native image. The game's movie player (movie::PlayerBink, src/platform/xbox/movie) calls 12
// Bink entry points; this file answers them on the native movie decoder (src/platform/sdl/movies/, FFmpeg's Bink
// decoder: docs/native-movies.md) and the audio mixer's streaming voices. The shapes (calling convention, argument
// bytes, what a result means, the handle's first four words, the 316-byte I/O block the game's own open callback
// fills) are read off the game's call sites, never from Bink's SDK or headers (docs/platform-boundary.md, rules 1-3):
//
//   0x364da0  BinkSetIO(open callback): stdcall (cb); cb = FUN_00334fa0 (state*, name*, flags) -> non-zero. The
//             game's streams (radfile, so the movie archives) sit behind it: it zeroes the 79-word block `state` and
//             fills words 0..5 with stdcall callbacks: 0 ReadHeader (state, offset, dst, bytes) -> bytes read
//             (synchronous, any offset or size), 1 ReadFrame / 2 GetBufferSize / 3 SetInfo / 4 Idle (Bink's
//             asynchronous read-ahead, which this implementation does not need), 5 Close (state); word 0x13 (+0x4c)
//             is its stream.
//   0x364dc0  BinkSetSoundTrack(count, ids*): stdcall; (0, 0) is "no sound"
//   0x364fe0  BinkOpen(name*, flags 0xa004000) -> handle (width at +0, height +4, frames +8, frame number +0xc;
//             0: failed). Opens paused (the game pauses it right after anyway)
//   0x367610  BinkSetVolume(handle, track id, volume): the game passes gain squared * 65536
//   0x367660  BinkSetMixBins(handle, track id, bins*, count): stdcall; the mixer bins (0 FL, 1 FR, 2 C, 3 LFE,
//             4 BL, 5 BR) the track plays through
//   0x366b40  BinkPause(handle, paused)
//   0x366940  BinkWait(handle) -> non-zero: not yet time for the frame
//   0x367bc0  BinkDoFrame(handle) -> 0: decoded (the game copies only then)
//   0x365f30  BinkCopyToBufferRect(handle, dst, pitch, dest height, dx, dy, sx, sy, sw, sh, flags 3) -> non-zero:
//             copied (the game treats 0 as a failed tile). A negative pitch: the lock's bottom-up layout (dst is the
//             lowest address; the image's top row lands at the highest)
//   0x3681d0  BinkNextFrame(handle)
//   0x368530  BinkClose(handle)
//   0x368660  a millisecond tick: cdecl () -> u32 (the I/O callbacks time their reads with it)
#include "imports.h"

// HULK_NATIVE_SDL: built with the SDL3 backends (tools/native_sdl.py, tools/native_ffmpeg.py; the native link once
// build/mv1/for-native9.md is in). Without it, the first skeleton's stand-ins: count the call, return 0.
#if defined(HULK_NATIVE_SDL)
#include "../movies/bink_player.h"

typedef __SIZE_TYPE__ hulk_uptr;

template <class T> static T* ptr(hulk_u32 a)
{
    return (T*)(hulk_uptr)a;
}

static hulk_u32 handle(void* p)
{
    return (hulk_u32)(hulk_uptr)p;
}

// ---- the game's I/O: a movie file read through the open callback's block
typedef hulk_u32(HULK_STDCALL* OpenCb)(hulk_u32 state, hulk_u32 name, hulk_u32 flags);
typedef hulk_u32(HULK_STDCALL* ReadCb)(hulk_u32 state, hulk_u32 offset, hulk_u32 dst, hulk_u32 bytes);
typedef hulk_u32(HULK_STDCALL* CloseCb)(hulk_u32 state);

static hulk_u32 g_open_cb;
enum { IO_BLOCK_BYTES = 512 };      // the game's block is 79 words; room to spare

static int guest_read(void* ctx, unsigned long long pos, void* buf, int n)
{
    hulk_u32* block = (hulk_u32*)ctx;
    ReadCb read = (ReadCb)(hulk_uptr)block[0];
    if (!read || pos > 0xffffffffull)
        return -1;
    return (int)read(handle(block), (hulk_u32)pos, handle(buf), (hulk_u32)n);
}

static void guest_close(void* ctx)
{
    hulk_u32* block = (hulk_u32*)ctx;
    CloseCb close = (CloseCb)(hulk_uptr)block[5];
    if (close)
        close(handle(block));
    hulk_bink_free(block);
}

extern "C" {

hulk_u32 HULK_STDCALL hulk_xdk_Bink_364da0(hulk_u32 cb)
{
    HULK_XDK_TRACE("Bink_364da0");
    g_open_cb = cb;
    return 1;
}

hulk_u32 HULK_STDCALL hulk_xdk_Bink_364dc0(hulk_u32 count, hulk_u32 ids)
{
    HULK_XDK_TRACE("Bink_364dc0");
    hulk_bink_set_tracks(ids ? ptr<const unsigned>(ids) : 0, ids ? count : 0);
    return 1;
}

hulk_u32 HULK_STDCALL hulk_xdk_Bink_364fe0(hulk_u32 name, hulk_u32 flags)
{
    HULK_XDK_TRACE("Bink_364fe0");
    if (!g_open_cb)
        return 0;
    hulk_u32* block = (hulk_u32*)hulk_bink_alloc(IO_BLOCK_BYTES);
    if (!block)
        return 0;
    if (!((OpenCb)(hulk_uptr)g_open_cb)(handle(block), name, flags)) {
        hulk_bink_free(block);
        return 0;
    }
    HulkMovieIO io = {};
    io.ctx = block;
    io.read = guest_read;
    io.close = guest_close;       // (runs on failure too)
    return handle(hulk_bink_open(&io, flags));
}

hulk_u32 HULK_STDCALL hulk_xdk_Bink_365f30(hulk_u32 h, hulk_u32 dst, hulk_u32 pitch, hulk_u32 dest_height, hulk_u32 dx,
                                           hulk_u32 dy, hulk_u32 sx, hulk_u32 sy, hulk_u32 sw, hulk_u32 sh,
                                           hulk_u32 flags)
{
    HULK_XDK_TRACE("Bink_365f30");
    return h ? (hulk_u32)hulk_bink_copy_rect(ptr<HulkBink>(h), ptr<void>(dst), (int)pitch, dest_height, (int)dx,
                                             (int)dy, (int)sx, (int)sy, (int)sw, (int)sh, flags)
             : 0;
}

hulk_u32 HULK_STDCALL hulk_xdk_Bink_366940(hulk_u32 h)
{
    HULK_XDK_TRACE("Bink_366940");
    return h ? (hulk_u32)hulk_bink_wait(ptr<HulkBink>(h)) : 1;
}

hulk_u32 HULK_STDCALL hulk_xdk_Bink_366b40(hulk_u32 h, hulk_u32 paused)
{
    HULK_XDK_TRACE("Bink_366b40");
    if (h)
        hulk_bink_pause(ptr<HulkBink>(h), (int)paused);
    return 0;
}

hulk_u32 HULK_STDCALL hulk_xdk_Bink_367bc0(hulk_u32 h)
{
    HULK_XDK_TRACE("Bink_367bc0");
    return h ? (hulk_u32)hulk_bink_do_frame(ptr<HulkBink>(h)) : 1;
}

hulk_u32 HULK_STDCALL hulk_xdk_Bink_3681d0(hulk_u32 h)
{
    HULK_XDK_TRACE("Bink_3681d0");
    if (h)
        hulk_bink_next_frame(ptr<HulkBink>(h));
    return 0;
}

hulk_u32 HULK_STDCALL hulk_xdk_Bink_368530(hulk_u32 h)
{
    HULK_XDK_TRACE("Bink_368530");
    hulk_bink_close(h ? ptr<HulkBink>(h) : 0);
    return 0;
}

hulk_u32 HULK_CDECL hulk_xdk_Bink_368660(void)
{
    HULK_XDK_TRACE("Bink_368660");
    return hulk_bink_ticks();
}

// library.h rows (src/platform/sdl/xdk/library.cpp holds count-only stand-ins until build/mv1/for-native9.md is in)
hulk_u32 HULK_STDCALL hulk_lib_Bink_367610(hulk_u32 h, hulk_u32 track, hulk_u32 volume)
{
    HULK_XDK_TRACE("lib:Bink_367610");
    if (h)
        hulk_bink_set_volume(ptr<HulkBink>(h), track, volume);
    return 0;
}

hulk_u32 HULK_STDCALL hulk_lib_Bink_367660(hulk_u32 h, hulk_u32 track, hulk_u32 bins, hulk_u32 count)
{
    HULK_XDK_TRACE("lib:Bink_367660");
    if (h && bins)
        hulk_bink_set_mix_bins(ptr<HulkBink>(h), track, ptr<const unsigned>(bins), count);
    return 0;
}

} // extern "C"

#else

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_364da0(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("Bink_364da0");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_364dc0(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("Bink_364dc0");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_364fe0(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("Bink_364fe0");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_365f30(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4, hulk_u32 a5, hulk_u32 a6, hulk_u32 a7, hulk_u32 a8, hulk_u32 a9, hulk_u32 a10) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; (void)a6; (void)a7; (void)a8; (void)a9; (void)a10;
    HULK_XDK_TRACE("Bink_365f30");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_366940(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("Bink_366940");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_366b40(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("Bink_366b40");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_367bc0(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("Bink_367bc0");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_3681d0(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("Bink_3681d0");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_368530(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("Bink_368530");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_Bink_368660(void) {
    HULK_XDK_TRACE("Bink_368660");
    return 0;
}

#endif // HULK_NATIVE_SDL
