namespace audio {
struct Range {
    char pad[8];
    float a, b;
};
struct Target {
    char pad[20];
    float volume;
};
struct Context {
    char pad[4];
    Target* target;
};
class SeqAction {
  public:
    virtual void v0();
    virtual void v1(Context*);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    int extra;
};
class SeqActionVarVolumeRand : public SeqAction {
  public:
    Range* range;
    int flag;
    virtual void v1(Context*);
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
void audio::SeqActionVarVolumeRand::v1(Context* ctx) {
    volatile float a, b;
    Range* r = range;
    float hi = r->b, lo = r->a;
    Target* tgt = ctx->target;
    tgt->volume = gRandom->Get(keep(lo, a), keep(hi, b));
    flag = 0;
}