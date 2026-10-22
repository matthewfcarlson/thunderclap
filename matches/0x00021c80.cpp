extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21c80[];
void operator delete(void*);
class Ref_21c80 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21c80 {
  public:
    void* vptr;
    void Fin();
};
class CComboTimerAction_21c80 : public CAction_21c80 {
  public:
    char pad[24];
    Ref_21c80* m;
    CComboTimerAction_21c80* f2(unsigned char flags);
};
CComboTimerAction_21c80* CComboTimerAction_21c80::f2(unsigned char flags) {
    vptr = g_vftable_21c80;
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
