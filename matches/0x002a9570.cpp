extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a9570[];
void operator delete(void*);
class Ref_2a9570 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a9570 {
  public:
    void* vptr;
    void Fin();
};
class TextureAnimationController_2a9570 : public SimpleFrameController_2a9570 {
  public:
    char pad[0x40 - 4];
    Ref_2a9570* m;
    TextureAnimationController_2a9570* f2(unsigned char flags);
};
TextureAnimationController_2a9570* TextureAnimationController_2a9570::f2(unsigned char flags) {
    vptr = g_vftable_2a9570;
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
