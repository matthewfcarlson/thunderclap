extern "C" void _ReadWriteBarrier();
extern void* g_vftable_227d0[];
void operator delete(void*);
class Ref_227d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_227d0 {
  public:
    void* vptr;
    void Fin();
};
class CTargetAction_227d0 : public CAction_227d0 {
  public:
    char pad[0x1c - 4];
    Ref_227d0* m;
    CTargetAction_227d0* f2(unsigned char flags);
};
CTargetAction_227d0* CTargetAction_227d0::f2(unsigned char flags) {
    vptr = g_vftable_227d0;
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
