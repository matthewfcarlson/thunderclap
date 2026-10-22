extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22520[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_22520 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22520 {
  public:
    void* vptr;
    void Fin();
};
class CRageModeAction_22520 : public CAction_22520 {
  public:
    char pad[0x18];
    Ref_22520* m;
    CRageModeAction_22520* f2(unsigned char flags);
};
CRageModeAction_22520* CRageModeAction_22520::f2(unsigned char flags) {
    vptr = g_vftable_22520;
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
