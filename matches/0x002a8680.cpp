extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a8680[];
void operator delete(void*);
class Ref_2a8680 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a8680 {
  public:
    void* vptr;
    void Fin();
};
class ShaderAnimationController_2a8680 : public SimpleFrameController_2a8680 {
  public:
    char pad[0x40 - 4];
    Ref_2a8680* m;
    ShaderAnimationController_2a8680* f2(unsigned char flags);
};
ShaderAnimationController_2a8680* ShaderAnimationController_2a8680::f2(unsigned char flags) {
    vptr = g_vftable_2a8680;
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
