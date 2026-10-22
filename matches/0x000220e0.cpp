extern "C" void _ReadWriteBarrier();
extern void* g_vftable_220e0[];
void operator delete(void*);
class Ref_220e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_220e0 {
  public:
    void* vptr;
    void Fin();
};
class CInvincibleAction_220e0 : public CAction_220e0 {
  public:
    char pad[0x1c - 4];
    Ref_220e0* m;
    CInvincibleAction_220e0* f2(unsigned char flags);
};
CInvincibleAction_220e0* CInvincibleAction_220e0::f2(unsigned char flags) {
    vptr = g_vftable_220e0;
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
