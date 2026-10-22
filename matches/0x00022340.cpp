extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22340[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_22340 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22340 {
  public:
    void* vptr;
    void Fin();
};
class CJumpAttackAction_22340 : public CAction_22340 {
  public:
    char pad[0x18];
    Ref_22340* m2;
    char pad2[0x4];
    Ref_22340* m1;
    CJumpAttackAction_22340* f2(unsigned char flags);
};
CJumpAttackAction_22340* CJumpAttackAction_22340::f2(unsigned char flags) {
    vptr = g_vftable_22340;
    _ReadWriteBarrier();
    if (m1) {
        m1->Release();
        m1 = 0;
    }
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (m2) {
        m2->Release();
        m2 = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
