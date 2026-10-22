extern "C" void _ReadWriteBarrier();
extern void* g_vftable_224e0[];
void operator delete(void*);
class Ref_224e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_224e0 {
  public:
    void* vptr;
    void Fin();
};
class CInvulnerableAction_224e0 : public CAction_224e0 {
  public:
    char pad[0x1c - 4];
    Ref_224e0* m;
    CInvulnerableAction_224e0* f2(unsigned char flags);
};
CInvulnerableAction_224e0* CInvulnerableAction_224e0::f2(unsigned char flags) {
    vptr = g_vftable_224e0;
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
