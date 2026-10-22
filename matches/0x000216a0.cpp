extern "C" void _ReadWriteBarrier();
extern void* g_vftable_216a0[];
void operator delete(void*);
class Ref_216a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_216a0 {
  public:
    void* vptr;
    void Fin();
};
class CAction_216a0 : public Action_216a0 {
  public:
    char pad[24];
    Ref_216a0* m;
    CAction_216a0* f2(unsigned char flags);
};
CAction_216a0* CAction_216a0::f2(unsigned char flags) {
    vptr = g_vftable_216a0;
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
