// Audio backend smoke test (docs/native-audio-input.md): tones and buffers through the DirectSound-shaped API, the
// mixer's output checked numerically (frequency, levels, pan, timing), never by ear; Xbox ADPCM against hand-made
// vectors. Host: the typed API (src/platform/sdl/audio/hulk_audio.h). HULK_TEST_XDK (i686 under Wine): the same
// cases through the hulk_xdk_* stand-ins with game-shaped structures (src/platform/sdl/xdk/audio_dsound.cpp).
// Output: HULK_TEST_OUT/audio_test.wav (the mixer's capture of the whole run), checked against what was rendered.
#include "audio/hulk_audio.h"
#include "test_common.h"

#ifdef HULK_TEST_XDK
#include "xdk/imports.h"
#endif

static const double kPi = 3.14159265358979323846;

// ---------------------------------------------------------------------------------------------
// the API under test
#ifdef HULK_TEST_XDK
typedef hulk_u32 V;
static hulk_u32 g_ds;
static void api_init()
{
    hulk_xdk_DirectSoundCreate(0, TEST_PTR(&g_ds), 0);
}
static void api_shutdown()
{
    hulk_xdk_IDirectSound_Release(g_ds);
}
static void fill_bins(hulk_u32* pairs, hulk_u32* mb, const HulkMixBin* bins, unsigned n)
{
    for (unsigned i = 0; i < n; i++) {
        pairs[2 * i] = bins[i].bin;
        pairs[2 * i + 1] = (hulk_u32)bins[i].volume;
    }
    mb[0] = n;
    mb[1] = TEST_PTR(pairs);
}
static V vcreate(const HulkAudioFormat& f, const HulkMixBin* bins, unsigned n)
{
    unsigned char wf[20];
    SDL_memset(wf, 0, sizeof(wf));
    unsigned short tag = f.codec == HULK_CODEC_XADPCM ? 0x69 : 1;
    unsigned short ch = (unsigned short)f.channels, bits = (unsigned short)f.bits;
    unsigned short align = f.codec == HULK_CODEC_XADPCM ? (unsigned short)(36 * ch) : (unsigned short)(ch * bits / 8);
    unsigned rate = f.rate, avg = f.rate * align;
    SDL_memcpy(wf + 0, &tag, 2);
    SDL_memcpy(wf + 2, &ch, 2);
    SDL_memcpy(wf + 4, &rate, 4);
    SDL_memcpy(wf + 8, &avg, 4);
    SDL_memcpy(wf + 12, &align, 2);
    SDL_memcpy(wf + 14, &bits, 2);
    hulk_u32 pairs[32], mb[2];
    fill_bins(pairs, mb, bins, n);
    // the game's descriptor (0x259610): size 24, flags 0x400a0, no bytes (SetBufferData follows), format, mix bins
    hulk_u32 desc[6] = {24, 0x400a0, 0, TEST_PTR(wf), n ? TEST_PTR(mb) : 0, 0};
    hulk_u32 out = 0;
    hulk_u32 hr = hulk_xdk_IDirectSound_CreateSoundBuffer(g_ds, TEST_PTR(desc), TEST_PTR(&out), 0);
    CHECK(hr == 0 && out != 0, "CreateSoundBuffer hr %x out %x", hr, out);
    hulk_xdk_IDirectSoundBuffer_SetHeadroom(out, 0);
    return out;
}
static void vdata(V v, const void* p, unsigned n) { hulk_xdk_IDirectSoundBuffer_SetBufferData(v, TEST_PTR(p), n); }
static void vplay(V v, int loop) { CHECK((int)hulk_xdk_IDirectSoundBuffer_Play(v, 0, 0, loop ? 1 : 0) >= 0, "Play"); }
static void vstop(V v) { hulk_xdk_IDirectSoundBuffer_Stop(v); }
static unsigned vstatus(V v)
{
    hulk_u32 s = 0xdead;
    hulk_xdk_IDirectSoundBuffer_GetStatus(v, TEST_PTR(&s));
    return s;
}
static unsigned vpos(V v)
{
    hulk_u32 p = 0xdead;
    hulk_xdk_IDirectSoundBuffer_GetCurrentPosition(v, TEST_PTR(&p), 0);
    return p;
}
static void vsetpos(V v, unsigned b) { hulk_xdk_IDirectSoundBuffer_SetCurrentPosition(v, b); }
static void vfreq(V v, unsigned hz) { hulk_xdk_IDirectSoundBuffer_SetFrequency(v, hz); }
static void vheadroom(V v, unsigned mb) { hulk_xdk_IDirectSoundBuffer_SetHeadroom(v, mb); }
static void vbins(V v, const HulkMixBin* bins, unsigned n)
{
    hulk_u32 pairs[32], mb[2];
    fill_bins(pairs, mb, bins, n);
    hulk_xdk_IDirectSoundBuffer_SetMixBinVolumes_8(v, TEST_PTR(mb));
}
static void vrelease(V v) { hulk_xdk_IDirectSoundBuffer_Release(v); }
static void listener(const HulkI3DL2& l)
{
    hulk_xdk_IDirectSound_SetI3DL2Listener(g_ds, TEST_PTR(&l), 1);   // HulkI3DL2 is the 12-word layout
    hulk_xdk_IDirectSound_CommitDeferredSettings(g_ds);
}
static void dowork() { hulk_xdk_DirectSoundDoWork(); }
#else
typedef HulkVoice* V;
static void api_init() { hulk_audio_init(); }
static void api_shutdown() { hulk_audio_shutdown(); }
static V vcreate(const HulkAudioFormat& f, const HulkMixBin* bins, unsigned n) { return hulk_audio_voice_create(&f, bins, n); }
static void vdata(V v, const void* p, unsigned n) { hulk_audio_voice_set_data(v, p, n); }
static void vplay(V v, int loop) { hulk_audio_voice_play(v, loop); }
static void vstop(V v) { hulk_audio_voice_stop(v); }
static unsigned vstatus(V v) { return hulk_audio_voice_status(v); }
static unsigned vpos(V v) { return hulk_audio_voice_position(v); }
static void vsetpos(V v, unsigned b) { hulk_audio_voice_set_position(v, b); }
static void vfreq(V v, unsigned hz) { hulk_audio_voice_set_frequency(v, hz); }
static void vheadroom(V v, unsigned mb) { hulk_audio_voice_set_headroom(v, mb); }
static void vbins(V v, const HulkMixBin* bins, unsigned n) { hulk_audio_voice_set_bins(v, bins, n); }
static void vrelease(V v) { hulk_audio_voice_release(v); }
static void listener(const HulkI3DL2& l) { hulk_audio_set_listener(&l); }
static void dowork() { hulk_audio_do_work(); }
#endif

// ---------------------------------------------------------------------------------------------
// signal analysis on rendered stereo float
static float g_out[2 * 48000 * 2];
static unsigned long long g_rendered;          // frames rendered by this test (the capture must have them all)
static short* g_all;                           // every rendered frame, quantized as the capture does
static unsigned long long g_all_cap;

static void render(unsigned frames)
{
    hulk_audio_render(g_out, frames);
    if (g_rendered + frames > g_all_cap) {
        g_all_cap = (g_rendered + frames) * 2 + 48000;
        g_all = (short*)SDL_realloc(g_all, (size_t)g_all_cap * 4);
    }
    for (unsigned i = 0; i < 2 * frames; i++) {
        float v = g_out[i] * 32767.0f;
        g_all[2 * g_rendered + i] = (short)(v > 32767.0f ? 32767 : v < -32768.0f ? -32768 : (int)SDL_lroundf(v));
    }
    g_rendered += frames;
}

static double rms(unsigned from, unsigned frames, int ch)
{
    double s = 0;
    for (unsigned i = from; i < from + frames; i++)
        s += (double)g_out[2 * i + ch] * g_out[2 * i + ch];
    return SDL_sqrt(s / frames);
}

// frequency from the positive-going zero crossings (interpolated)
static double freq(unsigned from, unsigned frames, int ch)
{
    double first = -1, last = -1;
    int n = 0;
    for (unsigned i = from + 1; i < from + frames; i++) {
        float a = g_out[2 * (i - 1) + ch], b = g_out[2 * i + ch];
        if (a < 0 && b >= 0) {
            double t = (i - 1) + (double)(-a) / (b - a);
            if (first < 0)
                first = t;
            last = t;
            n++;
        }
    }
    return n > 1 ? (n - 1) * (double)HULK_AUDIO_RATE / (last - first) : 0.0;
}

static short g_sine[48000 * 2];
static void make_sine(short* dst, unsigned frames, unsigned rate, double hz, double amp)
{
    for (unsigned i = 0; i < frames; i++)
        dst[i] = (short)SDL_lround(SDL_sin(2 * kPi * hz * i / rate) * amp * 32767.0);
}

static HulkAudioFormat pcm16(unsigned rate)
{
    HulkAudioFormat f = {HULK_CODEC_PCM, 1, 16, rate};
    return f;
}

static const HulkMixBin kStereo[2] = {{HULK_BIN_FRONT_LEFT, 0}, {HULK_BIN_FRONT_RIGHT, 0}};

// ---------------------------------------------------------------------------------------------
static void test_adpcm_vectors()
{
    // 1. predictor 0, index 0, every nibble 7: the IMA steps worked by hand (step 7 -> diff 0+1+3+7 = 11, index 8,
    //    step 16 -> 2+4+8+16 = 30, index 16, step 34 -> 63, step 73 -> 136, step 157 -> 293, step 337 -> 631,
    //    step 724 -> 1357, step 1552 -> 2910)
    unsigned char blk[36];
    SDL_memset(blk, 0x77, sizeof(blk));
    blk[0] = blk[1] = blk[2] = blk[3] = 0;
    short out[65 * 2];
    hulk_xadpcm_decode_block(blk, 1, out);
    static const short want1[9] = {0, 11, 41, 104, 240, 533, 1164, 2521, 5431};
    bool ok = true;
    for (int i = 0; i < 9; i++)
        ok = ok && out[i] == want1[i];
    CHECK(ok, "adpcm vector 1: %d %d %d %d %d %d %d %d %d", out[0], out[1], out[2], out[3], out[4], out[5], out[6],
          out[7], out[8]);
    CHECK(out[64] == 32767, "adpcm vector 1 saturates: %d", out[64]);

    // 2. clamping both ways: predictor 32000, index 88 (step 32767): nibble 7 -> +61436 -> 32767, then nibble 15
    //    -> 32767 - 61436 = -28669, then 15 again -> -32768; then nibble 0 -> -32768 + 4095 = -28673
    SDL_memset(blk, 0, sizeof(blk));
    blk[0] = 32000 & 0xff;
    blk[1] = 32000 >> 8;
    blk[2] = 88;
    blk[4] = 0xf7;
    blk[5] = 0x0f;
    hulk_xadpcm_decode_block(blk, 1, out);
    CHECK(out[0] == 32000 && out[1] == 32767 && out[2] == -28669 && out[3] == -32768 && out[4] == -28673,
          "adpcm vector 2: %d %d %d %d %d", out[0], out[1], out[2], out[3], out[4]);

    // 3. stereo layout: headers ch0 (100, index 0), ch1 (-100, index 0); then 4 bytes ch0, 4 bytes ch1, ...
    //    ch0 nibbles 1 (+ step>>2 + step>>3 = 1 at step 7, index stays 0), ch1 nibbles 9 (-1)
    unsigned char st[72];
    st[0] = 100; st[1] = 0; st[2] = 0; st[3] = 0;
    st[4] = (unsigned char)(-100 & 0xff); st[5] = 0xff; st[6] = 0; st[7] = 0;
    for (int r = 0; r < 8; r++)
        for (int b = 0; b < 4; b++) {
            st[8 + r * 8 + b] = 0x11;
            st[8 + r * 8 + 4 + b] = 0x99;
        }
    hulk_xadpcm_decode_block(st, 2, out);
    CHECK(out[0] == 100 && out[1] == -100 && out[2] == 101 && out[3] == -101 && out[128] == 164 && out[129] == -164,
          "adpcm stereo: %d %d %d %d .. %d %d", out[0], out[1], out[2], out[3], out[128], out[129]);

    // 4. a sine through the encoder and back: SNR
    short src[65 * 16], dec[65];
    make_sine(src, 65 * 16, 48000, 440.0, 0.5);
    double sig = 0, err = 0;
    for (int b = 0; b < 16; b++) {
        unsigned char enc[36];
        hulk_xadpcm_encode_block(src + 65 * b, 1, enc);
        hulk_xadpcm_decode_block(enc, 1, dec);
        for (int i = 0; i < 65; i++) {
            double s = src[65 * b + i], d = dec[i] - s;
            sig += s * s;
            err += d * d;
        }
    }
    double snr = 10 * SDL_log10(sig / (err > 0 ? err : 1));
    printf("adpcm: 440 Hz sine round trip SNR %.1f dB\n", snr);
    CHECK(snr > 25.0, "adpcm round trip SNR %.1f dB", snr);
}

static void test_tone_and_pan()
{
    make_sine(g_sine, 48000, 48000, 1000.0, 0.5);
    V v = vcreate(pcm16(48000), kStereo, 2);
    vdata(v, g_sine, 48000 * 2);
    vplay(v, 1);
    render(9600);
    double f = freq(0, 9600, 0), l = rms(0, 9600, 0), r = rms(0, 9600, 1);
    printf("tone: %.2f Hz, rms L %.4f R %.4f (want 1000, 0.3536)\n", f, l, r);
    CHECK(near(f, 1000.0, 1.0), "tone frequency %.2f", f);
    CHECK(near(l, 0.5 / SDL_sqrt(2.0), 0.002) && near(r, l, 0.0005), "tone levels %.4f %.4f", l, r);

    // pan: right bin at -600 mB -> 10^(-0.3) = 0.501 of the left
    HulkMixBin pan[2] = {{HULK_BIN_FRONT_LEFT, 0}, {HULK_BIN_FRONT_RIGHT, -600}};
    vbins(v, pan, 2);
    render(4800);
    l = rms(0, 4800, 0);
    r = rms(0, 4800, 1);
    printf("pan: R/L %.4f (want 0.5012)\n", r / l);
    CHECK(near(r / l, 0.50119, 0.002), "pan ratio %.4f", r / l);

    // headroom 600 mB on both bins at 0 dB
    vbins(v, kStereo, 2);
    vheadroom(v, 600);
    render(4800);
    l = rms(0, 4800, 0);
    printf("headroom 600: rms %.4f (want %.4f)\n", l, 0.5 / SDL_sqrt(2.0) * 0.50119);
    CHECK(near(l, 0.5 / SDL_sqrt(2.0) * 0.50119, 0.002), "headroom level %.4f", l);
    vheadroom(v, 0);

    // silence at -10000 mB
    HulkMixBin off[2] = {{HULK_BIN_FRONT_LEFT, -10000}, {HULK_BIN_FRONT_RIGHT, -10000}};
    vbins(v, off, 2);
    render(2400);
    CHECK(rms(0, 2400, 0) == 0.0 && rms(0, 2400, 1) == 0.0, "-10000 mB not silent");

    // the centre bin feeds both sides at -3 dB
    HulkMixBin centre[3] = {{HULK_BIN_FRONT_LEFT, -10000}, {HULK_BIN_FRONT_RIGHT, -10000}, {HULK_BIN_CENTER, 0}};
    vbins(v, centre, 3);
    render(4800);
    l = rms(0, 4800, 0);
    r = rms(0, 4800, 1);
    printf("centre: rms L %.4f R %.4f (want %.4f)\n", l, r, 0.5 / SDL_sqrt(2.0) * 0.70711);
    CHECK(near(l, 0.5 / SDL_sqrt(2.0) * 0.70711, 0.002) && near(l, r, 0.0005), "centre %.4f %.4f", l, r);

    // pitch: the same buffer at 24 kHz plays an octave down
    vbins(v, kStereo, 2);
    vfreq(v, 24000);
    render(9600);
    f = freq(0, 9600, 0);
    printf("pitch: SetFrequency 24000 -> %.2f Hz (want 500)\n", f);
    CHECK(near(f, 500.0, 1.0), "pitch %.2f", f);
    vstop(v);
    vrelease(v);
}

static void test_rate_and_pcm8()
{
    // a 22050 Hz buffer with 441 Hz in it, resampled to 48 kHz
    static short s22[22050];
    make_sine(s22, 22050, 22050, 441.0, 0.25);
    V v = vcreate(pcm16(22050), kStereo, 2);
    vdata(v, s22, sizeof(s22));
    vplay(v, 1);
    render(9600);
    double f = freq(0, 9600, 0), l = rms(0, 9600, 0);
    printf("22050 Hz buffer: %.2f Hz rms %.4f (want 441, 0.1768)\n", f, l);
    CHECK(near(f, 441.0, 0.5) && near(l, 0.25 / SDL_sqrt(2.0), 0.002), "resampled %.2f %.4f", f, l);
    vrelease(v);

    // unsigned 8-bit
    static unsigned char u8[48000];
    for (int i = 0; i < 48000; i++)
        u8[i] = (unsigned char)(128 + SDL_lround(SDL_sin(2 * kPi * 750.0 * i / 48000) * 100));
    HulkAudioFormat f8 = {HULK_CODEC_PCM, 1, 8, 48000};
    v = vcreate(f8, kStereo, 2);
    vdata(v, u8, sizeof(u8));
    vplay(v, 1);
    render(9600);
    f = freq(0, 9600, 0);
    l = rms(0, 9600, 0);
    printf("pcm8: %.2f Hz rms %.4f (want 750, %.4f)\n", f, l, 100.0 / 128 / SDL_sqrt(2.0));
    CHECK(near(f, 750.0, 1.0) && near(l, 100.0 / 128 / SDL_sqrt(2.0), 0.003), "pcm8 %.2f %.4f", f, l);
    vrelease(v);
}

static void test_positions()
{
    // a 0.1 s one-shot: playing until its end, then stopped with its position back at 0 (status and position
    // read consistently)
    static short shot[4800];
    make_sine(shot, 4800, 48000, 1000.0, 0.5);
    V v = vcreate(pcm16(48000), kStereo, 2);
    vdata(v, shot, sizeof(shot));
    CHECK(vstatus(v) == 0 && vpos(v) == 0, "fresh buffer status %u pos %u", vstatus(v), vpos(v));
    vplay(v, 0);
    render(2400);
    CHECK(vstatus(v) == HULK_STATUS_PLAYING && vpos(v) == 4800, "half way: status %u pos %u", vstatus(v), vpos(v));
    render(2400);
    CHECK(vstatus(v) == 0 && vpos(v) == 0, "at the end: status %u pos %u", vstatus(v), vpos(v));
    render(480);
    CHECK(rms(0, 480, 0) == 0.0, "a stopped one-shot is silent");

    // pause / resume as the HAL does it (0x258e50 Stop + GetCurrentPosition, 0x258ea0 SetCurrentPosition, Play)
    vplay(v, 0);
    render(1000);
    vstop(v);
    unsigned p = vpos(v);
    render(1000);
    CHECK(p == 2000 && vpos(v) == 2000 && vstatus(v) == 0, "paused at %u (now %u)", p, vpos(v));
    vsetpos(v, p);
    vplay(v, 0);
    render(1000);
    CHECK(vpos(v) == 4000, "resumed: %u", vpos(v));

    // looping wraps and keeps playing
    vstop(v);
    vsetpos(v, 0);
    vplay(v, 1);
    render(4800 + 1200);
    CHECK(vstatus(v) == (HULK_STATUS_PLAYING | HULK_STATUS_LOOPING) && vpos(v) == 2400, "loop: status %u pos %u",
          vstatus(v), vpos(v));
    vrelease(v);
}

static void test_adpcm_voice()
{
    // 500 Hz at 0.5 encoded as Xbox ADPCM (65 samples per 36-byte block), played through a voice
    enum { BLOCKS = 740 };                          // 48100 samples
    static short src[65 * BLOCKS];
    static unsigned char enc[36 * BLOCKS];
    make_sine(src, 65 * BLOCKS, 48000, 500.0, 0.5);
    for (int b = 0; b < BLOCKS; b++)
        hulk_xadpcm_encode_block(src + 65 * b, 1, enc + 36 * b);
    HulkAudioFormat fa = {HULK_CODEC_XADPCM, 1, 4, 48000};
    V v = vcreate(fa, kStereo, 2);
    vdata(v, enc, sizeof(enc));
    vplay(v, 0);
    render(9600);
    double f = freq(0, 9600, 0), l = rms(0, 9600, 0);
    printf("xadpcm voice: %.2f Hz rms %.4f (want 500, 0.3536), position %u (want %u)\n", f, l, vpos(v),
           (9600 / 65) * 36 + (9600 % 65) * 36 / 65);
    CHECK(near(f, 500.0, 1.0) && near(l, 0.5 / SDL_sqrt(2.0), 0.01), "adpcm voice %.2f %.4f", f, l);
    CHECK(vpos(v) == (9600 / 65) * 36 + (9600 % 65) * 36 / 65, "adpcm position %u", vpos(v));
    vsetpos(v, 36 * 100);                           // block 100 = sample 6500
    render(1);
    CHECK(vpos(v) == 36 * 100, "adpcm set position %u", vpos(v));
    vrelease(v);
}

static void test_reverb()
{
    // a click into bin 10 only: no output with the listener off (the game's start state), a decaying tail with a
    // room (I3DL2 levels 0 mB, 1 s decay)
    static short click[480];
    SDL_memset(click, 0, sizeof(click));
    click[0] = 30000;
    HulkMixBin send[3] = {{HULK_BIN_FRONT_LEFT, -10000}, {HULK_BIN_FRONT_RIGHT, -10000}, {HULK_BIN_I3DL2, 0}};
    HulkI3DL2 off = {-10000, -10000, 0.0f, 1.0f, 1.0f, -10000, 0.0f, -10000, 0.0f, 0.0f, 0.0f, 5000.0f};
    listener(off);
    V v = vcreate(pcm16(48000), send, 3);
    vdata(v, click, sizeof(click));
    vplay(v, 0);
    render(9600);
    CHECK(rms(0, 9600, 0) == 0.0, "reverb off: %.6f", rms(0, 9600, 0));
    HulkI3DL2 room = {0, 0, 0.0f, 1.0f, 0.83f, 0, 0.007f, 0, 0.011f, 100.0f, 100.0f, 5000.0f};
    listener(room);
    vsetpos(v, 0);
    vplay(v, 0);
    render(48000);
    double early = rms(0, 4800, 0), late = rms(24000, 4800, 0), tail = rms(43200, 4800, 0);
    printf("reverb: rms 0-0.1 s %.5f, 0.5-0.6 s %.5f, 0.9-1.0 s %.5f\n", early, late, tail);
    CHECK(early > 0.0005 && late < early && tail < late && tail > 0.0, "reverb tail %.5f %.5f %.5f", early, late, tail);
    // 1 s decay time: -60 dB per second, so 0.4 s from 0.55 to 0.95 is about -24 dB (a loose window)
    double db = 20 * SDL_log10(tail / late);
    CHECK(db < -12.0 && db > -36.0, "reverb decay %.1f dB over 0.4 s", db);
    listener(off);
    vrelease(v);
}

static void test_clocks()
{
    // the frame clock (HULK_AUDIO_CLOCK=frame): each DoWork renders exactly 800 frames
    api_shutdown();
    hulk_audio_set_clock(HULK_CLOCK_FRAME, 800);
    hulk_audio_set_capture(0);
    api_init();
    static short loop[48000];
    make_sine(loop, 48000, 48000, 1000.0, 0.25);
    V v = vcreate(pcm16(48000), kStereo, 2);
    vdata(v, loop, sizeof(loop));
    vplay(v, 1);
    unsigned long long f0, f1;
    hulk_audio_stats(0, 0, &f0);
    for (int i = 0; i < 10; i++)
        dowork();
    hulk_audio_stats(0, 0, &f1);
    printf("frame clock: 10 DoWork -> %llu frames, position %u bytes\n", f1 - f0, vpos(v));
    CHECK(f1 - f0 == 8000 && vpos(v) == 16000, "frame clock %llu / %u", f1 - f0, vpos(v));
    vrelease(v);

    // the device clock: SDL's device (the dummy driver in the tests) pulls in real time
    api_shutdown();
    hulk_audio_set_clock(HULK_CLOCK_DEVICE, 0);
    hulk_audio_set_capture(0);
    api_init();
    v = vcreate(pcm16(48000), kStereo, 2);
    vdata(v, loop, sizeof(loop));
    vplay(v, 1);
    Uint64 t0 = SDL_GetTicksNS();
    hulk_audio_stats(0, 0, &f0);
    SDL_Delay(500);
    for (int i = 0; i < 4; i++)
        dowork();
    hulk_audio_stats(0, 0, &f1);
    double secs = (SDL_GetTicksNS() - t0) / 1e9;
    printf("device clock (%s): %llu frames in %.3f s (%.0f frames/s), device %s\n",
           SDL_GetCurrentAudioDriver() ? SDL_GetCurrentAudioDriver() : "none", f1 - f0, secs, (f1 - f0) / secs,
           hulk_audio_has_device() ? "open" : "none (wall clock)");
    CHECK((f1 - f0) / secs > 48000 * 0.5 && (f1 - f0) / secs < 48000 * 1.6, "device clock rate %.0f", (f1 - f0) / secs);
    CHECK(vstatus(v) & HULK_STATUS_PLAYING, "device clock: still playing");
    vrelease(v);
    api_shutdown();
}

#ifdef HULK_TEST_XDK
// The radsound HAL's own order and structures: 0x2411b0 (effects image, HRTF), 0x241280 (the listener words at
// 0x3d5e68), 0x259610 (a channel whose mix-bin descriptor points into the channel itself: {count, bindings} then
// the bindings {bin id, volume}), 0x258f90 (volumes written through the channel's mapping, SetMixBinVolumes on the
// same descriptor, SetFrequency), 0x259be0 (Play), 0x258f40 (GetStatus until the one-shot ends), 0x240f50 (Commit,
// DoWork each update), 0x259b40 (Release).
static void test_game_sequence()
{
    unsigned char image[64];
    SDL_memset(image, 0x5a, sizeof(image));
    hulk_u32 loc[2] = {0, 1}, desc_out = 0xdead;
    CHECK(hulk_xdk_IDirectSound_DownloadEffectsImage(g_ds, TEST_PTR(image), sizeof(image), TEST_PTR(loc), TEST_PTR(&desc_out)) == 0 &&
              desc_out == 0,
          "effects image: desc out %x", desc_out);
    hulk_xdk_DirectSoundUseFullHRTF();
    // the XBE's listener words at 0x3d5e68 (room, room HF, rolloff, decay, HF ratio, reflections, delay, reverb,
    // delay, diffusion, density, HF reference)
    hulk_u32 l3d5e68[12] = {0xffffd8f0, 0xffffd8f0, 0, 0x3f800000, 0x3f800000, 0xffffd8f0, 0, 0xffffd8f0, 0, 0, 0,
                            0x459c4000};
    hulk_xdk_IDirectSound_SetI3DL2Listener(g_ds, TEST_PTR(l3d5e68), 1);

    struct Channel {
        hulk_u32 types[4];
        float volumes[4];
        float volume;
        hulk_u32 count;          // +0x24: the mix-bin descriptor starts here
        hulk_u32 bindings;       // +0x28
        hulk_u32 entries[6][2];  // {bin, volume}
    } ch;
    SDL_memset(&ch, 0, sizeof(ch));
    ch.count = 2;
    ch.bindings = TEST_PTR(ch.entries);
    ch.entries[0][0] = 0;        // type 1 -> bin 0
    ch.entries[1][0] = 1;        // type 2 -> bin 1
    struct Fmt {
        unsigned short tag, channels;
        hulk_u32 rate, avg;
        unsigned short align, bits, extra, unknown;
    } fmt = {1, 1, 24000, 48000, 2, 16, 0, 0};
    hulk_u32 desc[6] = {24, 0x400a0, 0, TEST_PTR(&fmt), TEST_PTR(&ch.count), 0};
    hulk_u32 buf = 0;
    hulk_xdk_IDirectSound_CreateSoundBuffer(g_ds, TEST_PTR(desc), TEST_PTR(&buf), 0);
    static short pcm[2400];       // 0.1 s at 24 kHz
    make_sine(pcm, 2400, 24000, 600.0, 0.5);
    hulk_xdk_IDirectSoundBuffer_SetBufferData(buf, TEST_PTR(pcm), sizeof(pcm));
    hulk_xdk_IDirectSoundBuffer_SetHeadroom(buf, 0);
    hulk_xdk_IDirectSoundBuffer_SetCurrentPosition(buf, 0);
    ch.entries[1][1] = (hulk_u32)-1200;                       // right at -12 dB, written in place as 0x258f90 does
    hulk_xdk_IDirectSoundBuffer_SetMixBinVolumes_8(buf, TEST_PTR(&ch.count));
    hulk_xdk_IDirectSoundBuffer_SetFrequency(buf, 48000);     // pitch x2: 0.05 s, 1200 Hz
    CHECK((int)hulk_xdk_IDirectSoundBuffer_Play(buf, 0, 0, 0) >= 0, "play");
    unsigned updates = 0;
    hulk_u32 status = 1;
    while (status & 1) {
        render(800);
        hulk_xdk_IDirectSound_CommitDeferredSettings(g_ds);
        hulk_xdk_DirectSoundDoWork();
        hulk_xdk_IDirectSoundBuffer_GetStatus(buf, TEST_PTR(&status));
        if (updates == 0) {
            double f = freq(0, 800, 0), l = rms(0, 800, 0), r = rms(0, 800, 1);
            printf("game sequence: %.1f Hz, R/L %.4f (want 1200, 0.2512)\n", f, r / l);
            CHECK(near(f, 1200.0, 3.0) && near(r / l, 0.25119, 0.002), "game sequence tone %.1f %.4f", f, r / l);
        }
        if (++updates > 100)
            break;
    }
    CHECK(updates == 3, "a 0.05 s one-shot ends in the 3rd 1/60 s update: %u", updates);   // 2400 frames
    hulk_xdk_IDirectSoundBuffer_Release(buf);
}
#endif

static const char* out_dir()
{
    const char* d = SDL_getenv("HULK_TEST_OUT");
    return d && *d ? d : ".";
}

static void check_capture(const char* path)
{
    size_t size = 0;
    unsigned char* w = (unsigned char*)SDL_LoadFile(path, &size);
    CHECK(w && size >= 44, "capture %s not written", path);
    if (!w || size < 44)
        return;
    unsigned data, rate;
    unsigned short ch, bits;
    SDL_memcpy(&ch, w + 22, 2);
    SDL_memcpy(&rate, w + 24, 4);
    SDL_memcpy(&bits, w + 34, 2);
    SDL_memcpy(&data, w + 40, 4);
    unsigned long long frames = data / 4;
    printf("capture: %s, %u Hz, %u ch, %u bit, %llu frames (rendered %llu)\n", path, rate, ch, bits, frames, g_rendered);
    CHECK(SDL_memcmp(w, "RIFF", 4) == 0 && SDL_memcmp(w + 8, "WAVE", 4) == 0 && rate == 48000 && ch == 2 && bits == 16,
          "capture header");
    CHECK(frames == g_rendered && size == 44 + (size_t)data, "capture length %llu vs %llu", frames, g_rendered);
    CHECK(frames == g_rendered && SDL_memcmp(w + 44, g_all, (size_t)data) == 0, "capture differs from what was rendered");
    SDL_free(w);
}

int test_main(void)
{
    char wav[512];
    SDL_snprintf(wav, sizeof(wav), "%s/audio_test.wav", out_dir());
    hulk_audio_set_clock(HULK_CLOCK_MANUAL, 0);
    hulk_audio_set_capture(wav);
    api_init();
    test_adpcm_vectors();
    test_tone_and_pan();
    test_rate_and_pcm8();
    test_positions();
    test_adpcm_voice();
    test_reverb();
#ifdef HULK_TEST_XDK
    test_game_sequence();
#endif
    hulk_audio_set_capture(0);         // closes the WAV (header final)
    check_capture(wav);
    test_clocks();
    SDL_free(g_all);
#ifdef HULK_TEST_XDK
    return test_done("native_audio (xdk, i686)");
#else
    return test_done("native_audio (host)");
#endif
}
