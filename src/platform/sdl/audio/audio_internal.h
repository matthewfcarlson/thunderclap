// Internal pieces of the audio backend (hulk_audio.cpp, reverb.cpp).
#ifndef HULK_PLATFORM_SDL_AUDIO_INTERNAL_H
#define HULK_PLATFORM_SDL_AUDIO_INTERNAL_H

#include "hulk_audio.h"

// mB (hundredths of a decibel) -> linear amplitude; <= -10000 is silence
float hulk_audio_mb_gain(int mb);

// The I3DL2 approximation: a pre-delay line with one early-reflection tap and a Schroeder network (four damped
// feedback combs per side, two allpasses) on the bin-10 send. Not the Xbox's DSP image: our own, documented as an
// approximation (docs/native-audio-input.md). Parameters per I3DL2: room / reflections / reverb levels (mB),
// decay time (s), HF ratio, delays (s), diffusion (%).
struct HulkReverb {
    enum { PRE = 16384, NCOMB = 4, CMAX = 2048, AP1 = 556, AP2 = 441 };
    float pre[PRE];
    unsigned pre_pos;
    unsigned pre_reflect, pre_late;                 // tap distances (frames)
    float comb[2][NCOMB][CMAX];
    unsigned comb_len[2][NCOMB];
    unsigned comb_pos[2][NCOMB];
    float comb_lp[2][NCOMB];
    float feedback[2][NCOMB];
    float damp;
    float ap1[2][AP1], ap2[2][AP2];
    unsigned ap1_pos[2], ap2_pos[2];
    float ap_g;
    float early_gain, late_gain;
    int active;                                     // 0 when every level is at the floor: process() is skipped
};

void hulk_reverb_reset(HulkReverb* r);
void hulk_reverb_set(HulkReverb* r, const HulkI3DL2* l);
// in: n mono frames of the send; out: n stereo frames, added to
void hulk_reverb_process(HulkReverb* r, const float* in, float* out, unsigned n);

#endif
