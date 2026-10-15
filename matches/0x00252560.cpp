namespace audio {
class Base {
  public:
    Base();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    int unk;
};
class SeqEventVarVolumeRand : public Base {
  public:
    float x;
    float y;
    SeqEventVarVolumeRand() : Base(), x(0.5f), y(1.0f) {}
};
class SeqEventVarVolumeRandType {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual SeqEventVarVolumeRand* vfunc_3();
};
} // namespace audio
extern char bss;
extern "C" void* __cdecl alloc(void*);
audio::SeqEventVarVolumeRand* audio::SeqEventVarVolumeRandType::vfunc_3() {
    audio::SeqEventVarVolumeRand* p = (audio::SeqEventVarVolumeRand*)alloc(&bss);
    if (p) {
        p->audio::SeqEventVarVolumeRand::SeqEventVarVolumeRand();
        return p;
    }
    return 0;
}