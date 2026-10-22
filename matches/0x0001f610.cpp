extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f610[];
class Ref_1f610 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f610 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1f610 : public Action_1f610 {
  public:
    char pad1c[0x18];
    Ref_1f610* m1c;
    ~CAction_1f610();
};
CAction_1f610::~CAction_1f610() {
    vptr = g_vftable_1f610;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
