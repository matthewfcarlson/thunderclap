extern "C" void _ReadWriteBarrier();
extern void* g_vftable_175020[];
class Ref_175020 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_175020 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_175020 {
    char c;
};
void __fastcall SubFini(Sub_175020*) throw();
void __fastcall SubFini2(Sub_175020*) throw();
class DriftToPositionAction_175020 : public Action_175020 {
  public:
    char p1c[24];
    void* m1c;
    Ref_175020* m20;
    char p38[20];
    Sub_175020 s38;
    ~DriftToPositionAction_175020() throw();
};
DriftToPositionAction_175020::~DriftToPositionAction_175020() throw() {
    vptr = g_vftable_175020;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    SubFini(&s38);
    Fin();
}
