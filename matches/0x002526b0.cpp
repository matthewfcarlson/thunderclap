#include "gen/audio.h"

namespace audio {
struct Range {
    char pad[8];
    float a, b;
};
struct Target {
    char pad[20];
    float volume;
};
struct Context_2526b0 {
    char pad[4];
    Target* target;
};
class SeqAction_2526b0 {
  public:
    virtual void v0();
    virtual void v1(Context_2526b0*);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    int extra;
};
} // namespace audio
class Random {
  public:
    float Get(float, float);
};
extern Random* gRandom;
inline float keep(float x, volatile float& v) {
    v = x;
    return x;
}
void audio::SeqActionVarVolumeRand::vfunc_1(void* __p0) { Context_2526b0 * ctx = (Context_2526b0 *)__p0;

    volatile float a, b;
    Range* r = (*(Range * *)&this->f_08);
    float hi = r->b, lo = r->a;
    Target* tgt = ctx->target;
    tgt->volume = gRandom->Get(keep(lo, a), keep(hi, b));
    this->f_0c = 0;
}
