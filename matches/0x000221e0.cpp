extern "C" void _ReadWriteBarrier();
extern void* g_vftable_221e0[];
extern void* g_base_vftable[];
void operator delete(void*);
class Ref_221e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_221e0 {
  public:
    void* vptr;
    void Fin();
};
class CEffectAction_221e0 : public CAction_221e0 {
  public:
    char pad[0x18];
    Ref_221e0* m1c;
    char pad2[4];
    Ref_221e0* m24;
    CEffectAction_221e0* f2(unsigned char flags);
};
CEffectAction_221e0* CEffectAction_221e0::f2(unsigned char flags) {
    vptr = g_vftable_221e0;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = g_base_vftable;
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
