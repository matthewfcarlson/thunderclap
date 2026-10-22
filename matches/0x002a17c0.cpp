extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a17c0[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_2a17c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class DisplayTraversal_2a17c0 {
  public:
    void* vptr;
    void Fin();
};
struct Sub_2a17c0 {
    char c;
    void Fini();
};
class ShadowTraversal_2a17c0 : public DisplayTraversal_2a17c0 {
  public:
    char pad[0x18 - 4];
    void* m18;
    int m1c;
    Sub_2a17c0 sub;
    char pad2[0x2c - 0x21];
    Ref_2a17c0* m2c;
    char pad3[0x3c - 0x30];
    void* m3c;
    ~ShadowTraversal_2a17c0();
};
ShadowTraversal_2a17c0::~ShadowTraversal_2a17c0() {
    vptr = g_vftable_2a17c0;
    _ReadWriteBarrier();
    if (m2c) {
        m2c->Release();
        m2c = 0;
    }
    if (m3c)
        operator delete(m3c);
    sub.Fini();
    m18 = g_vftable2;
    Fin();
}
