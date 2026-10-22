extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22610[];
void operator delete(void*);
class Ref_22610 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22610 {
  public:
    void* vptr;
    void Fin();
};
class CAlertStatusAction_22610 : public CAction_22610 {
  public:
    char pad[24];
    Ref_22610* m;
    CAlertStatusAction_22610* f2(unsigned char flags);
};
CAlertStatusAction_22610* CAlertStatusAction_22610::f2(unsigned char flags) {
    vptr = g_vftable_22610;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
