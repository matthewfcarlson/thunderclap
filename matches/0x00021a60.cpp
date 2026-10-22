extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21a60[];
void operator delete(void*);
class Ref_21a60 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21a60 {
  public:
    void* vptr;
    void Fin();
};
class CComboMessageAction_21a60 : public CAction_21a60 {
  public:
    char pad[24];
    Ref_21a60* m;
    CComboMessageAction_21a60* f2(unsigned char flags);
};
CComboMessageAction_21a60* CComboMessageAction_21a60::f2(unsigned char flags) {
    vptr = g_vftable_21a60;
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
