extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f530[];
class Ref_1f530 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1f530 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1f530 : public Base_1f530 {
  public:
    char pad[0x18];
    Ref_1f530* m1c;
    ~CAction_1f530();
};
CAction_1f530::~CAction_1f530() {
    vptr = g_vftable_1f530;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
