extern "C" void _ReadWriteBarrier();
extern void* g_vftable_134e90[];
class Ref_134e90 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_134e90 {
  public:
    void* vptr;
    void Fin();
};
class FallAction_134e90 : public Base_134e90 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_134e90* m20;
    Ref_134e90* m24;
    ~FallAction_134e90();
};
FallAction_134e90::~FallAction_134e90() {
    vptr = g_vftable_134e90;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
