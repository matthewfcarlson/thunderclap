extern "C" void _ReadWriteBarrier();
extern void* g_vftable_12c040[];
class Ref_12c040 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_12c040 {
  public:
    void* vptr;
    void Fin();
};
class ThreatBallAction_12c040 : public Action_12c040 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_12c040* m20;
    ~ThreatBallAction_12c040();
};
ThreatBallAction_12c040::~ThreatBallAction_12c040() {
    vptr = g_vftable_12c040;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
