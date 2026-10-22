extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a8a70[];
class Ref_2a8a70 {
  public:
    virtual void F0();
    virtual void Release();
};
class BlendFrameController_2a8a70 {
  public:
    void* vptr;
    void Fin();
};
class LightAnimationController_2a8a70 : public BlendFrameController_2a8a70 {
  public:
    char pad[272];
    Ref_2a8a70* m;
    ~LightAnimationController_2a8a70();
};
LightAnimationController_2a8a70::~LightAnimationController_2a8a70() {
    vptr = g_vftable_2a8a70;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
