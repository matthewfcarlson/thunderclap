extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a98c0[];
class Ref_2a98c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a98c0 {
  public:
    void* vptr;
    void Fin();
};
class BillboardQuadGroupAnimationController_2a98c0 : public SimpleFrameController_2a98c0 {
  public:
    char pad[60];
    Ref_2a98c0* m;
    ~BillboardQuadGroupAnimationController_2a98c0();
};
BillboardQuadGroupAnimationController_2a98c0::~BillboardQuadGroupAnimationController_2a98c0() {
    vptr = g_vftable_2a98c0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
