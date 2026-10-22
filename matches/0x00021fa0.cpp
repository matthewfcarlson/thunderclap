extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21fa0[];
void operator delete(void*);
class Ref_21fa0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21fa0 {
  public:
    void* vptr;
    void Fin();
};
class CSmartPropThrowAction_21fa0 : public CAction_21fa0 {
  public:
    char pad[0x1c - 4];
    Ref_21fa0* m;
    CSmartPropThrowAction_21fa0* f2(unsigned char flags);
};
CSmartPropThrowAction_21fa0* CSmartPropThrowAction_21fa0::f2(unsigned char flags) {
    vptr = g_vftable_21fa0;
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
