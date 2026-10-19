// The I3DL2 reverb approximation (audio_internal.h). Our own small Schroeder network; the I3DL2 parameter meanings
// are the public Interactive 3D Audio Level 2 guideline's.
#include "audio_internal.h"

#include <SDL3/SDL_stdinc.h>

static const unsigned kComb[4] = {1557, 1617, 1491, 1422};   // frames at 48 kHz; the right side adds 23
static const unsigned kSpread = 23;

void hulk_reverb_reset(HulkReverb* r)
{
    SDL_memset(r, 0, sizeof(*r));
    for (int s = 0; s < 2; s++)
        for (int i = 0; i < HulkReverb::NCOMB; i++)
            r->comb_len[s][i] = kComb[i] + (s ? kSpread : 0);
    r->ap_g = 0.5f;
}

void hulk_reverb_set(HulkReverb* r, const HulkI3DL2* l)
{
    float room = hulk_audio_mb_gain(l->room);
    r->early_gain = room * hulk_audio_mb_gain(l->reflections);
    // the four combs sum: scale the late part down to about unity
    r->late_gain = room * hulk_audio_mb_gain(l->reverb) * 0.25f;
    r->active = r->early_gain > 0.0f || r->late_gain > 0.0f;
    float decay = l->decay_time < 0.1f ? 0.1f : l->decay_time > 20.0f ? 20.0f : l->decay_time;
    for (int s = 0; s < 2; s++)
        for (int i = 0; i < HulkReverb::NCOMB; i++) {
            // a comb of length d decays by 60 dB in `decay` seconds: g^(T*rate/d) = 10^-3
            float d = (float)r->comb_len[s][i];
            r->feedback[s][i] = SDL_powf(10.0f, -3.0f * d / (decay * HULK_AUDIO_RATE));
        }
    float hf = l->decay_hf_ratio < 0.1f ? 0.1f : l->decay_hf_ratio > 2.0f ? 2.0f : l->decay_hf_ratio;
    r->damp = hf >= 1.0f ? 0.0f : (1.0f - hf) * 0.8f;
    float diff = l->diffusion < 0.0f ? 0.0f : l->diffusion > 100.0f ? 100.0f : l->diffusion;
    r->ap_g = 0.3f + 0.4f * diff / 100.0f;
    float rd = l->reflections_delay < 0.0f ? 0.0f : l->reflections_delay > 0.3f ? 0.3f : l->reflections_delay;
    float ld = l->reverb_delay < 0.0f ? 0.0f : l->reverb_delay > 0.1f ? 0.1f : l->reverb_delay;
    r->pre_reflect = (unsigned)(rd * HULK_AUDIO_RATE);
    r->pre_late = (unsigned)((rd + ld) * HULK_AUDIO_RATE);
    if (r->pre_late >= HulkReverb::PRE)
        r->pre_late = HulkReverb::PRE - 1;
}

void hulk_reverb_process(HulkReverb* r, const float* in, float* out, unsigned n)
{
    if (!r->active)
        return;
    for (unsigned f = 0; f < n; f++) {
        r->pre[r->pre_pos] = in[f];
        float early = r->pre[(r->pre_pos + HulkReverb::PRE - r->pre_reflect) % HulkReverb::PRE];
        float late_in = r->pre[(r->pre_pos + HulkReverb::PRE - r->pre_late) % HulkReverb::PRE];
        r->pre_pos = (r->pre_pos + 1) % HulkReverb::PRE;
        for (int s = 0; s < 2; s++) {
            float acc = 0.0f;
            for (int i = 0; i < HulkReverb::NCOMB; i++) {
                float* buf = r->comb[s][i];
                unsigned p = r->comb_pos[s][i];
                float y = buf[p];
                r->comb_lp[s][i] = y * (1.0f - r->damp) + r->comb_lp[s][i] * r->damp;
                buf[p] = late_in + r->comb_lp[s][i] * r->feedback[s][i];
                r->comb_pos[s][i] = (p + 1) % r->comb_len[s][i];
                acc += y;
            }
            // two allpasses (diffusion)
            float* a1 = r->ap1[s];
            unsigned p1 = r->ap1_pos[s];
            float b1 = a1[p1];
            float o1 = -acc * r->ap_g + b1;
            a1[p1] = acc + b1 * r->ap_g;
            r->ap1_pos[s] = (p1 + 1) % HulkReverb::AP1;
            float* a2 = r->ap2[s];
            unsigned p2 = r->ap2_pos[s];
            float b2 = a2[p2];
            float o2 = -o1 * r->ap_g + b2;
            a2[p2] = o1 + b2 * r->ap_g;
            r->ap2_pos[s] = (p2 + 1) % HulkReverb::AP2;
            out[2 * f + s] += early * r->early_gain + o2 * r->late_gain;
        }
    }
}
