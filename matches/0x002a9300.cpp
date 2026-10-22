extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a9300[];
void operator delete(void*);
class Ref_2a9300 {
  public:
    virtual void F0();
    virtual void Release();
};
class BlendFrameController_2a9300 {
  public:
    void* vptr;
    void Fin();
};
class LightAnimationController_2a9300 : public BlendFrameController_2a9300 {
  public:
    char pad[0x114 - 4];
    Ref_2a9300* m;
    LightAnimationController_2a9300* f2(unsigned char flags);
};
LightAnimationController_2a9300* LightAnimationController_2a9300::f2(unsigned char flags) {
    vptr = g_vftable_2a9300;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
