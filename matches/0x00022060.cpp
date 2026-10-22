extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22060[];
void operator delete(void*);
class Ref_22060 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22060 {
  public:
    void* vptr;
    void Fin();
};
class CSmartPropEventAction_22060 : public CAction_22060 {
  public:
    char pad[0x1c - 4];
    Ref_22060* m;
    CSmartPropEventAction_22060* f2(unsigned char flags);
};
CSmartPropEventAction_22060* CSmartPropEventAction_22060::f2(unsigned char flags) {
    vptr = g_vftable_22060;
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
