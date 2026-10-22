extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22650[];
void operator delete(void*);
class Ref_22650 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22650 {
  public:
    void* vptr;
    void Fin();
};
class CDeathAction_22650 : public CAction_22650 {
  public:
    char pad[0x1c - 4];
    Ref_22650* m;
    CDeathAction_22650* f2(unsigned char flags);
};
CDeathAction_22650* CDeathAction_22650::f2(unsigned char flags) {
    vptr = g_vftable_22650;
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
