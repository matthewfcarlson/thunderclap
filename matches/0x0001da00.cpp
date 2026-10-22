extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1da00[];
class Ref_1da00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1da00 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1da00 : public Action_1da00 {
  public:
    char pad[0x18];
    Ref_1da00* m1c;
    ~CAction_1da00();
};
CAction_1da00::~CAction_1da00() {
    vptr = g_vftable_1da00;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
