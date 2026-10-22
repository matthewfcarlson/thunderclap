extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22690[];
void operator delete(void*);
class Ref_22690 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22690 {
  public:
    void* vptr;
    void Fin();
};
class CAIHintAction_22690 : public CAction_22690 {
  public:
    char pad[0x1c - 4];
    Ref_22690* m;
    CAIHintAction_22690* f2(unsigned char flags);
};
CAIHintAction_22690* CAIHintAction_22690::f2(unsigned char flags) {
    vptr = g_vftable_22690;
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
