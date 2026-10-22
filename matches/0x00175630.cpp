extern "C" void _ReadWriteBarrier();
extern void* g_vftable_175630[];
class Ref_175630 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_175630 {
  public:
    void* vptr;
    void Fin();
};
class DriftToHulkAction_175630 : public Action_175630 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_175630* m20;
    ~DriftToHulkAction_175630();
};
DriftToHulkAction_175630::~DriftToHulkAction_175630() {
    vptr = g_vftable_175630;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
