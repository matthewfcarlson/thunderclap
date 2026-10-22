extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a9b80[];
void operator delete(void*);
class Ref_2a9b80 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a9b80 {
  public:
    void* vptr;
    void Fin();
};
class BillboardQuadGroupAnimationController_2a9b80 : public SimpleFrameController_2a9b80 {
  public:
    char pad[0x40 - 4];
    Ref_2a9b80* m;
    BillboardQuadGroupAnimationController_2a9b80* f2(unsigned char flags);
};
BillboardQuadGroupAnimationController_2a9b80* BillboardQuadGroupAnimationController_2a9b80::f2(unsigned char flags) {
    vptr = g_vftable_2a9b80;
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
