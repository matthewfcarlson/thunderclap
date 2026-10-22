extern void* g_vftable_1302c0[];
extern "C" void _ReadWriteBarrier();
class Ref_1302c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1302c0 {
  public:
    void* vptr;
    void Fin();
};
class DebugPrintAction_1302c0 : public Action_1302c0 {
  public:
    char pad[0x1c];
    Ref_1302c0* m20;
    ~DebugPrintAction_1302c0();
};
DebugPrintAction_1302c0::~DebugPrintAction_1302c0() {
    vptr = g_vftable_1302c0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    Fin();
}
