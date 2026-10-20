extern "C" void _ReadWriteBarrier();
extern void* g_vftable_152710[];
class Ref_152710 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_152710 {
  public:
    void* vptr;
    void Fin();
};
class ClearFightParamsHitRecordAction_152710 : public Base_152710 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_152710* m20;
    ~ClearFightParamsHitRecordAction_152710();
};
ClearFightParamsHitRecordAction_152710::~ClearFightParamsHitRecordAction_152710() {
    vptr = g_vftable_152710;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
