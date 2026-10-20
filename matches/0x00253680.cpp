#include "gen/audio.h"

namespace audio {
struct Data {
    char pad[8];
    float lo, hi;
};
struct Sound {
    char pad[0x24];
    float pitch;
};
struct Context_253680 {
    char pad[4];
    Sound* snd;
};
struct Rand {
    float between(float, float);
};
extern Rand* gRand;

} // namespace audio
void audio::SeqActionVarPitchRand::vfunc_1(void* __p0) { Context_253680 * ctx = (Context_253680 *)__p0;

    float hi = (*(Data * *)&this->f_08)->hi;
    float lo = (*(Data * *)&this->f_08)->lo;
    Sound* snd = ctx->snd;
    snd->pitch = gRand->between(lo, hi);
    this->f_0c = 0;
}
