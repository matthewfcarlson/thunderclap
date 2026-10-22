extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21f20[];
void operator delete(void*);
class Ref_21f20 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21f20 {
  public:
    void* vptr;
    void Fin();
};
class CSmartPropSetStateAction_21f20 : public CAction_21f20 {
  public:
    char pad[24];
    Ref_21f20* m;
    CSmartPropSetStateAction_21f20* f2(unsigned char flags);
};
CSmartPropSetStateAction_21f20* CSmartPropSetStateAction_21f20::f2(unsigned char flags) {
    vptr = g_vftable_21f20;
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
