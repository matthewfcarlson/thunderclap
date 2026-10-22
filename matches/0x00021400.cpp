extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21400[];
class Ref_21400 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_21400 {
  public:
    void* vptr;
    void Fin();
};
class CAction_21400 : public Action_21400 {
  public:
    char pad[24];
    Ref_21400* m;
    ~CAction_21400();
};
CAction_21400::~CAction_21400() {
    vptr = g_vftable_21400;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
