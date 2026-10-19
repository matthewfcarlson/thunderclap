// Audio: DirectSound (Xbox) for the native image, on our mixer (src/platform/sdl/audio/hulk_audio.h,
// docs/native-audio-input.md). Each stand-in counts its calls (xdk_shim.h) and translates the game's 32-bit
// arguments; the shapes (calling convention, argument bytes, structure layouts) are read off the radsound HAL's
// call sites, never from SDK headers (docs/platform-boundary.md, rules 1-3):
//
//   0x259610  CreateSoundBuffer(ds, desc, &buf, 0): desc = {size 24, flags, bytes, format*, mixbins*, 0};
//             format = {u16 tag (1 PCM, 0x69 Xbox ADPCM), u16 channels, u32 rate, u32 bytes/s, u16 block align,
//             u16 bits, ...}; mixbins = {u32 count, pairs*}, pair = {u32 bin, s32 volume (mB)}
//   0x258f90  SetMixBinVolumes(buf, mixbins*), SetFrequency(buf, hz)
//   0x259be0  Play(buf, 0, 0, loop): the last word's bit 0 loops; < 0 is a failure
//   0x258f40  GetStatus(buf, &status): bit 0 playing
//   0x258e50 / 0x258f00 / 0x258ea0  Get/SetCurrentPosition (bytes)
//   0x241280 / 0x240f50  SetI3DL2Listener(ds, 12 words, apply), CommitDeferredSettings, DirectSoundDoWork
//   0x2411b0  DownloadEffectsImage(ds, image, size, &loc, &desc_out), DirectSoundUseFullHRTF()
//
// Handles are our objects' addresses (the image is 32-bit); the game only passes them back.
#include "imports.h"

// HULK_NATIVE_SDL: built with the SDL3 backends (tools/native_sdl.py; the native link once build/sa1/for-native9.md
// is in). Without it, the first skeleton's stand-ins: count the call, return 0.
#if defined(HULK_NATIVE_SDL)
#include "../audio/hulk_audio.h"

typedef __SIZE_TYPE__ hulk_uptr;

#define DS_OK 0u
#define DSERR_INVALIDPARAM 0x80070057u
#define DSERR_OUTOFMEMORY 0x8007000eu

template <class T> static T* ptr(hulk_u32 a)
{
    return (T*)(hulk_uptr)a;
}

static hulk_u32 rd32(hulk_u32 a, hulk_u32 off)
{
    const unsigned char* p = ptr<const unsigned char>(a) + off;
    return p[0] | (p[1] << 8) | (p[2] << 16) | ((hulk_u32)p[3] << 24);
}

static hulk_u32 rd16(hulk_u32 a, hulk_u32 off)
{
    const unsigned char* p = ptr<const unsigned char>(a) + off;
    return p[0] | (p[1] << 8);
}

static float rdf(hulk_u32 a, hulk_u32 off)
{
    union {
        hulk_u32 u;
        float f;
    } v;
    v.u = rd32(a, off);
    return v.f;
}

static void wr32(hulk_u32 a, hulk_u32 v)
{
    if (a)
        *ptr<hulk_u32>(a) = v;
}

static HulkVoice* voice(hulk_u32 h)
{
    return ptr<HulkVoice>(h);
}

// mixbins = {u32 count, pairs*}; at most 16 pairs
static unsigned read_bins(hulk_u32 mixbins, HulkMixBin* out)
{
    if (!mixbins)
        return 0;
    hulk_u32 n = rd32(mixbins, 0), pairs = rd32(mixbins, 4);
    if (!pairs)
        return 0;
    if (n > HULK_AUDIO_MAX_BINS)
        n = HULK_AUDIO_MAX_BINS;
    for (hulk_u32 i = 0; i < n; i++) {
        out[i].bin = rd32(pairs, 8 * i) & 15;
        out[i].volume = (int)rd32(pairs, 8 * i + 4);
    }
    return n;
}

// backend log lines go to the image's trace (startup.cpp)
extern "C" void HULK_CDECL hulk_native_log(const char* line);
static void audio_log(const char* line)
{
    char buf[300] = "audio ";
    unsigned i = 6;
    while (*line && i < sizeof(buf) - 1)
        buf[i++] = *line++;
    buf[i] = 0;
    hulk_native_log(buf);
}

// the DirectSound object: one per DirectSoundCreate (the game makes one)
static struct {
    hulk_u32 refs;
} g_ds;

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_DirectSoundCreate(hulk_u32 guid, hulk_u32 out, hulk_u32 unk) {
    (void)guid; (void)unk;
    HULK_XDK_TRACE("DirectSoundCreate");
    hulk_audio_log_sink = audio_log;
    hulk_audio_init();
    g_ds.refs++;
    wr32(out, (hulk_u32)(hulk_uptr)&g_ds);
    return DS_OK;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_Release(hulk_u32 ds) {
    (void)ds;
    HULK_XDK_TRACE("IDirectSound_Release");
    if (g_ds.refs && --g_ds.refs == 0)
        hulk_audio_shutdown();
    return g_ds.refs;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_DirectSoundUseFullHRTF(void) {
    HULK_XDK_TRACE("DirectSoundUseFullHRTF");      // no HRTF: 3D positioning is the game's mix-bin panning
    return 0;
}

// img\dspimage.bin: the Xbox DSP's effect graph (I3DL2 reverb at index 0, crosstalk at 1). We have no DSP; the
// reverb is the mixer's own approximation. The image description out-pointer gets null (the game never reads it).
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_DownloadEffectsImage(hulk_u32 ds, hulk_u32 image, hulk_u32 size, hulk_u32 loc, hulk_u32 desc_out) {
    (void)ds; (void)image; (void)size; (void)loc;
    HULK_XDK_TRACE("IDirectSound_DownloadEffectsImage");
    wr32(desc_out, 0);
    return DS_OK;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_CreateSoundBuffer(hulk_u32 ds, hulk_u32 desc, hulk_u32 out, hulk_u32 unk) {
    (void)ds; (void)unk;
    HULK_XDK_TRACE("IDirectSound_CreateSoundBuffer");
    if (!desc || !out)
        return DSERR_INVALIDPARAM;
    hulk_u32 bytes = rd32(desc, 8), fmt = rd32(desc, 12), mixbins = rd32(desc, 16);
    HulkAudioFormat f;
    f.codec = HULK_CODEC_PCM;
    f.channels = 1;
    f.bits = 16;
    f.rate = HULK_AUDIO_RATE;
    if (fmt) {
        hulk_u32 tag = rd16(fmt, 0);
        f.channels = (int)rd16(fmt, 2);
        f.rate = rd32(fmt, 4);
        f.bits = (int)rd16(fmt, 14);
        if (tag == 0x69)
            f.codec = HULK_CODEC_XADPCM;
        else if (tag != 1)
            HULK_XDK_TRACE("DirectSound: unknown wave format tag (played as PCM)");
    }
    HulkMixBin bins[HULK_AUDIO_MAX_BINS];
    unsigned n = read_bins(mixbins, bins);
    HulkVoice* v = hulk_audio_voice_create(&f, mixbins ? bins : 0, n);
    if (!v)
        return DSERR_OUTOFMEMORY;
    (void)bytes;    // the game always hands its own memory over with SetBufferData (desc bytes = 0)
    wr32(out, (hulk_u32)(hulk_uptr)v);
    return DS_OK;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_Release(hulk_u32 buf) {
    HULK_XDK_TRACE("IDirectSoundBuffer_Release");
    hulk_audio_voice_release(voice(buf));
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetBufferData(hulk_u32 buf, hulk_u32 data, hulk_u32 bytes) {
    HULK_XDK_TRACE("IDirectSoundBuffer_SetBufferData");
    if (!buf)
        return DSERR_INVALIDPARAM;
    hulk_audio_voice_set_data(voice(buf), ptr<const void>(data), bytes);
    return DS_OK;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetHeadroom(hulk_u32 buf, hulk_u32 mb) {
    HULK_XDK_TRACE("IDirectSoundBuffer_SetHeadroom");
    if (buf)
        hulk_audio_voice_set_headroom(voice(buf), mb);
    return DS_OK;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetMixBinVolumes_8(hulk_u32 buf, hulk_u32 mixbins) {
    HULK_XDK_TRACE("IDirectSoundBuffer_SetMixBinVolumes_8");
    if (!buf)
        return DSERR_INVALIDPARAM;
    HulkMixBin bins[HULK_AUDIO_MAX_BINS];
    unsigned n = read_bins(mixbins, bins);
    hulk_audio_voice_set_bins(voice(buf), bins, n);
    return DS_OK;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_Play(hulk_u32 buf, hulk_u32 r1, hulk_u32 r2, hulk_u32 flags) {
    (void)r1; (void)r2;
    HULK_XDK_TRACE("IDirectSoundBuffer_Play");
    if (!buf)
        return DSERR_INVALIDPARAM;
    hulk_audio_voice_play(voice(buf), flags & 1);
    return DS_OK;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_Stop(hulk_u32 buf) {
    HULK_XDK_TRACE("IDirectSoundBuffer_Stop");
    if (buf)
        hulk_audio_voice_stop(voice(buf));
    return DS_OK;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_GetStatus(hulk_u32 buf, hulk_u32 out) {
    HULK_XDK_TRACE("IDirectSoundBuffer_GetStatus");
    wr32(out, buf ? hulk_audio_voice_status(voice(buf)) : 0);
    return DS_OK;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_GetCurrentPosition(hulk_u32 buf, hulk_u32 play_out, hulk_u32 write_out) {
    HULK_XDK_TRACE("IDirectSoundBuffer_GetCurrentPosition");
    hulk_u32 p = buf ? hulk_audio_voice_position(voice(buf)) : 0;
    wr32(play_out, p);
    wr32(write_out, p);
    return DS_OK;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetCurrentPosition(hulk_u32 buf, hulk_u32 bytes) {
    HULK_XDK_TRACE("IDirectSoundBuffer_SetCurrentPosition");
    if (buf)
        hulk_audio_voice_set_position(voice(buf), bytes);
    return DS_OK;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetFrequency(hulk_u32 buf, hulk_u32 hz) {
    HULK_XDK_TRACE("IDirectSoundBuffer_SetFrequency");
    if (buf)
        hulk_audio_voice_set_frequency(voice(buf), hz);
    return DS_OK;
}

// 12 words: room, room HF (mB), room rolloff, decay time, decay HF ratio (float), reflections (mB), reflections
// delay (float), reverb (mB), reverb delay, diffusion, density, HF reference (float). Applied at once (the game
// commits right after: CommitDeferredSettings is then a no-op).
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_SetI3DL2Listener(hulk_u32 ds, hulk_u32 params, hulk_u32 apply) {
    (void)ds; (void)apply;
    HULK_XDK_TRACE("IDirectSound_SetI3DL2Listener");
    if (!params)
        return DSERR_INVALIDPARAM;
    HulkI3DL2 l;
    l.room = (int)rd32(params, 0);
    l.room_hf = (int)rd32(params, 4);
    l.room_rolloff = rdf(params, 8);
    l.decay_time = rdf(params, 12);
    l.decay_hf_ratio = rdf(params, 16);
    l.reflections = (int)rd32(params, 20);
    l.reflections_delay = rdf(params, 24);
    l.reverb = (int)rd32(params, 28);
    l.reverb_delay = rdf(params, 32);
    l.diffusion = rdf(params, 36);
    l.density = rdf(params, 40);
    l.hf_reference = rdf(params, 44);
    hulk_audio_set_listener(&l);
    return DS_OK;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_CommitDeferredSettings(hulk_u32 ds) {
    (void)ds;
    HULK_XDK_TRACE("IDirectSound_CommitDeferredSettings");
    return DS_OK;
}

// once per sound update (0x240f50): the frame clock renders here (HULK_AUDIO_CLOCK=frame), and without a device
// the mixer advances by wall time
extern "C" hulk_u32 HULK_CDECL hulk_xdk_DirectSoundDoWork(void) {
    HULK_XDK_TRACE("DirectSoundDoWork");
    hulk_audio_do_work();
    return 0;
}

#else  // !HULK_NATIVE_SDL

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_Release(hulk_u32 a0) {
    (void)a0; HULK_XDK_TRACE("IDirectSound_Release");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_Release(hulk_u32 a0) {
    (void)a0; HULK_XDK_TRACE("IDirectSoundBuffer_Release");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_DirectSoundUseFullHRTF(void) {
    HULK_XDK_TRACE("DirectSoundUseFullHRTF");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_DownloadEffectsImage(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; HULK_XDK_TRACE("IDirectSound_DownloadEffectsImage");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetHeadroom(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1; HULK_XDK_TRACE("IDirectSoundBuffer_SetHeadroom");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetMixBinVolumes_8(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1; HULK_XDK_TRACE("IDirectSoundBuffer_SetMixBinVolumes_8");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_Play(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3; HULK_XDK_TRACE("IDirectSoundBuffer_Play");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_Stop(hulk_u32 a0) {
    (void)a0; HULK_XDK_TRACE("IDirectSoundBuffer_Stop");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_GetStatus(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1; HULK_XDK_TRACE("IDirectSoundBuffer_GetStatus");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_GetCurrentPosition(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2; HULK_XDK_TRACE("IDirectSoundBuffer_GetCurrentPosition");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetCurrentPosition(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1; HULK_XDK_TRACE("IDirectSoundBuffer_SetCurrentPosition");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_DirectSoundDoWork(void) {
    HULK_XDK_TRACE("DirectSoundDoWork");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetFrequency(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1; HULK_XDK_TRACE("IDirectSoundBuffer_SetFrequency");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetBufferData(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2; HULK_XDK_TRACE("IDirectSoundBuffer_SetBufferData");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_CommitDeferredSettings(hulk_u32 a0) {
    (void)a0; HULK_XDK_TRACE("IDirectSound_CommitDeferredSettings");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_CreateSoundBuffer(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3; HULK_XDK_TRACE("IDirectSound_CreateSoundBuffer");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_SetI3DL2Listener(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2; HULK_XDK_TRACE("IDirectSound_SetI3DL2Listener");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_DirectSoundCreate(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2; HULK_XDK_TRACE("DirectSoundCreate");
    return 0;
}

#endif
