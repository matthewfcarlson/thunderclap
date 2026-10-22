extern "C" void _ReadWriteBarrier();
extern void* g_vftable_173c50[];
class Ref_173c50 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_173c50 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_173c50 {
    char c;
};
void __fastcall SubFini(Sub_173c50*) throw();
void __fastcall SubFini2(Sub_173c50*) throw();
class JointPivotTrackerAction_173c50 : public Action_173c50 {
  public:
    char p1c[24];
    void* m1c;
    Ref_173c50* m20;
    Ref_173c50* m24;
    char p80[88];
    Ref_173c50* m80;
    ~JointPivotTrackerAction_173c50() throw();
};
JointPivotTrackerAction_173c50::~JointPivotTrackerAction_173c50() throw() {
    vptr = g_vftable_173c50;
    _ReadWriteBarrier();
    if (m80) {
        m80->Release();
        m80 = 0;
    }
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
