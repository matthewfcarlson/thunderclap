typedef unsigned int size_t;
inline void* operator new(size_t, void* p) {
    return p;
}
namespace audio {
class SeqEvent;
class SeqActionVarPitchRand {
  public:
    virtual void v0();
    char pad[4];
    SeqEvent* ev;
    int n;
    SeqActionVarPitchRand(SeqEvent* e) : ev(e), n(0) {}
};
class Ctx {
  public:
    void Add(SeqActionVarPitchRand*);
};
class SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(Ctx*);
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventVarPitchRand : public SeqEvent {
  public:
    virtual void v2(Ctx*);
};
} // namespace audio
extern char bss[];
extern "C" void* alloc(void*);
void audio::SeqEventVarPitchRand::v2(Ctx* ctx) {
    void* p = alloc(bss);
    ctx->Add(p ? new (p) SeqActionVarPitchRand(this) : 0);
}