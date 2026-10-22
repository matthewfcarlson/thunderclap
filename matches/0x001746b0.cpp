extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1746b0[];
class Ref_1746b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1746b0 {
  public:
    void* vptr;
    void Fin();
};
class JointRelativeAction_1746b0 : public Action_1746b0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1746b0* m20;
    Ref_1746b0* m24;
    ~JointRelativeAction_1746b0();
};
JointRelativeAction_1746b0::~JointRelativeAction_1746b0() {
    vptr = g_vftable_1746b0;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
