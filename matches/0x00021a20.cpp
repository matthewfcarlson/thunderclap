extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21a20[];
void operator delete(void*);
class Ref_21a20 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21a20 {
  public:
    void* vptr;
    void Fin();
};
class CSoundAction_21a20 : public CAction_21a20 {
  public:
    char pad[24];
    Ref_21a20* m;
    CSoundAction_21a20* f2(unsigned char flags);
};
CSoundAction_21a20* CSoundAction_21a20::f2(unsigned char flags) {
    vptr = g_vftable_21a20;
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
