// Xbox ADPCM (WAVE_FORMAT 0x69), written from the format's public description: it is IMA ADPCM (the IMA Digital
// Audio Focus and Technical Working Groups' 1992 recommended practice: the 89-entry step table and the 8-entry
// index table below) packed in 36-byte blocks per channel:
//
//   header, per channel: int16 first sample, uint8 step index, uint8 reserved          (4 bytes x channels)
//   then 8 rounds of 4 bytes per channel, channel after channel: 8 nibbles each, low nibble first (32 bytes x ch)
//
// The header sample is the block's first output sample and the predictor for the 64 nibbles: 65 samples per
// channel per block. (The game's own wave format for it, 0x259610, says 36-byte blocks, 4 bits, mono.)
#include "hulk_audio.h"

static const short kStep[89] = {
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 25, 28, 31, 34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88, 97,
    107, 118, 130, 143, 157, 173, 190, 209, 230, 253, 279, 307, 337, 371, 408, 449, 494, 544, 598, 658, 724, 796,
    876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066, 2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428,
    4871, 5358, 5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899, 15289, 16818, 18500, 20350,
    22385, 24623, 27086, 29794, 32767};
static const signed char kIndex[8] = {-1, -1, -1, -1, 2, 4, 6, 8};

struct ImaState {
    int pred;
    int index;
};

static int clamp16(int v)
{
    return v < -32768 ? -32768 : v > 32767 ? 32767 : v;
}

static short ima_step(ImaState* s, int nibble)
{
    int step = kStep[s->index];
    int diff = step >> 3;
    if (nibble & 1)
        diff += step >> 2;
    if (nibble & 2)
        diff += step >> 1;
    if (nibble & 4)
        diff += step;
    s->pred = clamp16(nibble & 8 ? s->pred - diff : s->pred + diff);
    s->index += kIndex[nibble & 7];
    s->index = s->index < 0 ? 0 : s->index > 88 ? 88 : s->index;
    return (short)s->pred;
}

extern "C" void hulk_xadpcm_decode_block(const unsigned char* in, int channels, short* out)
{
    if (channels < 1)
        channels = 1;
    if (channels > 2)
        channels = 2;
    ImaState st[2];
    for (int c = 0; c < channels; c++) {
        const unsigned char* h = in + 4 * c;
        st[c].pred = (short)(h[0] | (h[1] << 8));
        st[c].index = h[2] > 88 ? 88 : h[2];
        out[c] = (short)st[c].pred;
    }
    const unsigned char* p = in + 4 * channels;
    for (int round = 0; round < 8; round++) {
        for (int c = 0; c < channels; c++) {
            for (int b = 0; b < 4; b++) {
                unsigned char byte = *p++;
                int n = 1 + round * 8 + b * 2;      // sample number within the block (0 is the header's)
                out[n * channels + c] = ima_step(&st[c], byte & 15);
                out[(n + 1) * channels + c] = ima_step(&st[c], byte >> 4);
            }
        }
    }
}

// The forward direction, for the tests: per sample, the nibble whose reconstruction (through ima_step, so encoder
// and decoder can't drift) lands nearest the input.
static int encode_one(ImaState* s, int sample)
{
    int best = 0, best_err = 0x7fffffff;
    for (int n = 0; n < 16; n++) {
        ImaState t = *s;
        int err = ima_step(&t, n) - sample;
        err = err < 0 ? -err : err;
        if (err < best_err) {
            best_err = err;
            best = n;
        }
    }
    ima_step(s, best);
    return best;
}

extern "C" void hulk_xadpcm_encode_block(const short* in, int channels, unsigned char* out)
{
    if (channels < 1)
        channels = 1;
    if (channels > 2)
        channels = 2;
    ImaState st[2];
    for (int c = 0; c < channels; c++) {
        int first = in[c];
        // a start index that suits the block's first step
        int d = in[channels + c] - first;
        d = d < 0 ? -d : d;
        int idx = 0;
        while (idx < 88 && kStep[idx] * 2 < d)
            idx++;
        st[c].pred = first;
        st[c].index = idx;
        unsigned char* h = out + 4 * c;
        h[0] = (unsigned char)(first & 0xff);
        h[1] = (unsigned char)((first >> 8) & 0xff);
        h[2] = (unsigned char)idx;
        h[3] = 0;
    }
    unsigned char* p = out + 4 * channels;
    for (int round = 0; round < 8; round++) {
        for (int c = 0; c < channels; c++) {
            for (int b = 0; b < 4; b++) {
                int n = 1 + round * 8 + b * 2;
                int lo = encode_one(&st[c], in[n * channels + c]);
                int hi = encode_one(&st[c], in[(n + 1) * channels + c]);
                *p++ = (unsigned char)(lo | (hi << 4));
            }
        }
    }
}
