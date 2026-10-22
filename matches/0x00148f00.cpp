extern "C" void _ReadWriteBarrier();
extern void* g_vftable_148f00[];
class Ref_148f00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_148f00 {
  public:
    void* vptr;
    void Fin();
};
class CivilianThrowAction_148f00 : public Action_148f00 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_148f00* m20;
    ~CivilianThrowAction_148f00();
};
CivilianThrowAction_148f00::~CivilianThrowAction_148f00() {
    vptr = g_vftable_148f00;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
