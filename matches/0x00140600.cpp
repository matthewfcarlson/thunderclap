extern "C" void _ReadWriteBarrier();
extern void* g_vftable_140600[];
class Ref_140600 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_140600 {
  public:
    void* vptr;
    void Fin();
};
class WallJumpAction_140600 : public Base_140600 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_140600* m20;
    Ref_140600* m24;
    ~WallJumpAction_140600();
};
WallJumpAction_140600::~WallJumpAction_140600() {
    vptr = g_vftable_140600;
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
