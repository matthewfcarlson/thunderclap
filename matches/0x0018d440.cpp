extern "C" void _ReadWriteBarrier();
extern void* g_vftable_18d440[];
class Ref_18d440 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_18d440 {
  public:
    void* vptr;
    void Fin();
};
class VarAssignAction_18d440 : public Action_18d440 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_18d440* m20;
    ~VarAssignAction_18d440();
};
VarAssignAction_18d440::~VarAssignAction_18d440() {
    vptr = g_vftable_18d440;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
