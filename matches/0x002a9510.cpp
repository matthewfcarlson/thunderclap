extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a9510[];
class Ref_2a9510 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a9510 {
  public:
    void* vptr;
    void Fin();
};
class TextureAnimationController_2a9510 : public SimpleFrameController_2a9510 {
  public:
    char pad[60];
    Ref_2a9510* m;
    ~TextureAnimationController_2a9510();
};
TextureAnimationController_2a9510::~TextureAnimationController_2a9510() {
    vptr = g_vftable_2a9510;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
