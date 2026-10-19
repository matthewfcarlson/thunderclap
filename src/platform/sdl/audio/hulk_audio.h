// The native audio backend (docs/native-audio-input.md): our own mixer on SDL3 audio. Typed and pointer-sized, so
// the host tests and, later, the radsound HAL seam call it directly; src/platform/sdl/xdk/audio_dsound.cpp
// translates the game's DirectSound-shaped calls (32-bit handles and pointers) into these.
//
// Model: a voice is one sound buffer. It plays memory the caller owns (never copied: the game streams into the
// buffers it handed over), PCM8 / PCM16 / Xbox ADPCM, 1 or 2 channels, at a frequency the caller sets, into up to
// 16 mix bins with a volume each (hundredths of a decibel, mB). The mixer folds the speaker bins to stereo at
// 48 kHz and sends bin 10 through a software reverb set by the I3DL2 listener. One lock guards all state; every
// value a caller reads (status, position) is consistent with what the mixer has rendered.
#ifndef HULK_PLATFORM_SDL_AUDIO_H
#define HULK_PLATFORM_SDL_AUDIO_H

#ifdef __cplusplus
extern "C" {
#endif

#define HULK_AUDIO_RATE 48000            // the mixer's output rate (the Xbox APU's)
#define HULK_AUDIO_MAX_BINS 16
#define HULK_AUDIO_MIN_MB (-10000)       // silence

// mix bins (the speaker bins the game uses, 0x259610: 0 FL, 1 FR, 2 C, 3 LFE, 4 BL, 5 BR, 10 the I3DL2 send)
enum {
    HULK_BIN_FRONT_LEFT = 0, HULK_BIN_FRONT_RIGHT = 1, HULK_BIN_CENTER = 2, HULK_BIN_LFE = 3,
    HULK_BIN_BACK_LEFT = 4, HULK_BIN_BACK_RIGHT = 5, HULK_BIN_I3DL2 = 10
};

enum { HULK_CODEC_PCM = 0, HULK_CODEC_XADPCM = 1 };

typedef struct HulkAudioFormat {
    int codec;                  // HULK_CODEC_*
    int channels;               // 1 or 2
    int bits;                   // PCM: 8 (unsigned) or 16 (signed); Xbox ADPCM: 4
    unsigned rate;              // the base frequency (Hz) until hulk_audio_voice_set_frequency
} HulkAudioFormat;

typedef struct HulkMixBin {
    unsigned bin;               // 0..15
    int volume;                 // mB, <= 0
} HulkMixBin;

// The I3DL2 listener (the 12 words the game passes to SetI3DL2Listener, in that order)
typedef struct HulkI3DL2 {
    int room, room_hf;
    float room_rolloff, decay_time, decay_hf_ratio;
    int reflections;
    float reflections_delay;
    int reverb;
    float reverb_delay, diffusion, density, hf_reference;
} HulkI3DL2;

typedef struct HulkVoice HulkVoice;

enum { HULK_STATUS_PLAYING = 1, HULK_STATUS_LOOPING = 4 };   // GetStatus bits (the game tests bit 0, 0x258f40)

// Clock modes (HULK_AUDIO_CLOCK): device = SDL's device pulls in real time; frame[:N] = each do_work renders N
// frames (default 800) and queues them (deterministic); manual = only hulk_audio_render advances (tests).
enum { HULK_CLOCK_DEVICE = 0, HULK_CLOCK_FRAME = 1, HULK_CLOCK_MANUAL = 2 };

// Starts the mixer (idempotent). Reads HULK_AUDIO_CLOCK and HULK_AUDIO_CAPTURE unless set_clock/set_capture ran
// first. Opens SDL's default playback device except in manual mode; without a device the mixer still runs and
// do_work advances it by wall time. Returns 1.
int hulk_audio_init(void);
void hulk_audio_shutdown(void);
void hulk_audio_set_clock(int mode, unsigned frames_per_work);
int hulk_audio_set_capture(const char* wav_path);   // 16-bit stereo 48 kHz WAV of everything rendered; 0 closes
int hulk_audio_has_device(void);

HulkVoice* hulk_audio_voice_create(const HulkAudioFormat* format, const HulkMixBin* bins, unsigned count);
void hulk_audio_voice_release(HulkVoice* v);
void hulk_audio_voice_set_data(HulkVoice* v, const void* data, unsigned bytes);
int hulk_audio_voice_play(HulkVoice* v, int loop);
void hulk_audio_voice_stop(HulkVoice* v);
unsigned hulk_audio_voice_status(HulkVoice* v);
unsigned hulk_audio_voice_position(HulkVoice* v);              // bytes into the buffer (block-granular for ADPCM)
void hulk_audio_voice_set_position(HulkVoice* v, unsigned bytes);
void hulk_audio_voice_set_frequency(HulkVoice* v, unsigned hz);  // 0: the format's rate
void hulk_audio_voice_set_headroom(HulkVoice* v, unsigned mb);
void hulk_audio_voice_set_volume(HulkVoice* v, int mb);
// Volumes of the listed bins; a bin the voice wasn't created with is added.
void hulk_audio_voice_set_bins(HulkVoice* v, const HulkMixBin* bins, unsigned count);

void hulk_audio_set_listener(const HulkI3DL2* l);
void hulk_audio_do_work(void);

// Mixes `frames` stereo frames (float, interleaved) and advances every voice: the device callback's body, and the
// tests' manual clock. Also written to the capture file.
void hulk_audio_render(float* out, unsigned frames);

// Diagnostics: voices alive / playing, frames rendered so far.
void hulk_audio_stats(unsigned* voices, unsigned* playing, unsigned long long* frames);

// Log sink (default: SDL_Log).
typedef void (*hulk_audio_log_fn)(const char* line);
extern hulk_audio_log_fn hulk_audio_log_sink;

// Xbox ADPCM (xadpcm.cpp): a block is 36 bytes per channel and decodes to 65 samples per channel.
#define HULK_XADPCM_BLOCK 36
#define HULK_XADPCM_SAMPLES 65
// Decodes one block of `channels` channels (36 * channels bytes) into 65 * channels interleaved samples.
void hulk_xadpcm_decode_block(const unsigned char* in, int channels, short* out);
// Encoder for the tests (same algorithm run forward): 65 * channels samples -> 36 * channels bytes.
void hulk_xadpcm_encode_block(const short* in, int channels, unsigned char* out);

#ifdef __cplusplus
}
#endif

#endif
