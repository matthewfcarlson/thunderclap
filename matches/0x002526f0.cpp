inline void* operator new(unsigned int, void* p) {
    return p;
}
namespace audio {
class SeqEventVarVolumeRand;
class SeqActionVarVolumeRand {
  public:
    virtual void v0();
    virtual void v1();
    int unused;
    SeqEventVarVolumeRand* owner;
    int value;
    SeqActionVarVolumeRand(SeqEventVarVolumeRand* p) : owner(p), value(0) {}
};
class Receiver {
  public:
    void Set(SeqActionVarVolumeRand*);
};
class SeqEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(Receiver*);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
class SeqEventVarVolumeRand : public SeqEvent {
  public:
    virtual void vfunc_2(Receiver*);
};
} // namespace audio
extern char bss;
extern "C" void* __cdecl FUN_00247530(void*);
void audio::SeqEventVarVolumeRand::vfunc_2(Receiver* r) {
    void* p = FUN_00247530(&bss);
    SeqActionVarVolumeRand* a = p ? new (p) SeqActionVarVolumeRand(this) : 0;
    r->Set(a);
}