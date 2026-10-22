extern "C" void _ReadWriteBarrier();
extern void* g_vftable_220a0[];
void operator delete(void*);
class Ref_220a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_220a0 {
  public:
    void* vptr;
    void Fin();
};
class CSmartPropRemoveInstanceAction_220a0 : public CAction_220a0 {
  public:
    char pad[0x1c - 4];
    Ref_220a0* m;
    CSmartPropRemoveInstanceAction_220a0* f2(unsigned char flags);
};
CSmartPropRemoveInstanceAction_220a0* CSmartPropRemoveInstanceAction_220a0::f2(unsigned char flags) {
    vptr = g_vftable_220a0;
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
