extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1de20[];
class Ref_1de20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1de20 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1de20 : public Base_1de20 {
  public:
    char pad[0x18];
    Ref_1de20* m1c;
    ~CAction_1de20();
};
CAction_1de20::~CAction_1de20() {
    vptr = g_vftable_1de20;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
