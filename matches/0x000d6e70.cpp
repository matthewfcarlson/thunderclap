extern "C" void _ReadWriteBarrier();
extern void* g_vftable_d6e70[];
class Ref_d6e70 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class COverlayManager_d6e70 {
  public:
    void* vptr;
    Ref_d6e70* m4;
    char p8[0x24];
    Ref_d6e70* m2c;
    COverlayManager_d6e70* f2(unsigned char flags);
};
void operator delete(void*);
COverlayManager_d6e70* COverlayManager_d6e70::f2(unsigned char flags) {
    vptr = g_vftable_d6e70;
    _ReadWriteBarrier();
    if (m4) {
        m4->f1();
        m4 = 0;
    }
    if (m2c) {
        m2c->f1();
        m2c = 0;
    }
    if (flags & 1)
        operator delete(this);
    return this;
}
