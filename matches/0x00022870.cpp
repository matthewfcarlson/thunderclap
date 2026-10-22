extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22870[];
void operator delete(void*);
class Ref_22870 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22870 {
  public:
    void* vptr;
    void Fin();
};
class CExplosionAction_22870 : public CAction_22870 {
  public:
    char pad[24];
    Ref_22870* m;
    CExplosionAction_22870* f2(unsigned char flags);
};
CExplosionAction_22870* CExplosionAction_22870::f2(unsigned char flags) {
    vptr = g_vftable_22870;
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
