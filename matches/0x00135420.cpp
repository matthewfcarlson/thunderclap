extern "C" void _ReadWriteBarrier();
extern void* g_vftable_135420[];
class Ref_135420 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_135420 {
  public:
    void* vptr;
    void Fin();
};
class FlyingBrakeAction_135420 : public Base_135420 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_135420* m20;
    Ref_135420* m24;
    ~FlyingBrakeAction_135420();
};
FlyingBrakeAction_135420::~FlyingBrakeAction_135420() {
    vptr = g_vftable_135420;
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
