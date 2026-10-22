extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21780[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_21780 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21780 {
  public:
    void* vptr;
    void Fin();
};
class CJumpAction_21780 : public CAction_21780 {
  public:
    char pad[0x1c - 4];
    Ref_21780* m1c;
    char pad2[4];
    Ref_21780* m24;
    CJumpAction_21780* f2(unsigned char flags);
};
CJumpAction_21780* CJumpAction_21780::f2(unsigned char flags) {
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = g_vftable_21780;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
