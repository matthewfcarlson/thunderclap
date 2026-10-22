extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21d60[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_21d60 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21d60 {
  public:
    void* vptr;
    void Fin();
};
class CGrappleSwapAction_21d60 : public CAction_21d60 {
  public:
    char pad[0x1c - 4];
    Ref_21d60* m1c;
    CGrappleSwapAction_21d60* f2(unsigned char flags);
};
CGrappleSwapAction_21d60* CGrappleSwapAction_21d60::f2(unsigned char flags) {
    vptr = g_vftable_21d60;
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
