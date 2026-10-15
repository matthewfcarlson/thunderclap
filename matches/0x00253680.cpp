namespace audio {
struct Data {
    char pad[8];
    float lo, hi;
};
struct Sound {
    char pad[0x24];
    float pitch;
};
struct Context {
    char pad[4];
    Sound* snd;
};
struct Rand {
    float between(float, float);
};
extern Rand* gRand;
class SeqActionVarPitchRand {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(Context*);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad[4];
    Data* data;
    int active;
};
void SeqActionVarPitchRand::vfunc_1(Context* ctx) {
    float hi = data->hi;
    float lo = data->lo;
    Sound* snd = ctx->snd;
    snd->pitch = gRand->between(lo, hi);
    active = 0;
}
} // namespace audio