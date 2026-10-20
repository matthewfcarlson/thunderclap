extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f430[];
class Ref_1f430 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1f430 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1f430 : public Base_1f430 {
  public:
    char pad1c[0x18];
    Ref_1f430* m1c;
    ~CAction_1f430();
};
CAction_1f430::~CAction_1f430() {
    vptr = g_vftable_1f430;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
