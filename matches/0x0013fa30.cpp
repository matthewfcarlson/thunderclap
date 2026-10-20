extern "C" void _ReadWriteBarrier();
extern void* g_vftable_13fa30[];
class Ref_13fa30 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_13fa30 {
  public:
    void* vptr;
    void Fin();
};
class WallRunAction_13fa30 : public Base_13fa30 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_13fa30* m20;
    Ref_13fa30* m24;
    Ref_13fa30* m28;
    ~WallRunAction_13fa30();
};
WallRunAction_13fa30::~WallRunAction_13fa30() {
    vptr = g_vftable_13fa30;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
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
