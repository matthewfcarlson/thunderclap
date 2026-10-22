extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a1810[];
extern void* g_ref_2a1810[];
void operator delete(void*);
void operator delete[](void*);
class Ref_2a1810 {
  public:
    virtual void F0();
    virtual void Release();
};
class Mem_2a1810 {
  public:
    ~Mem_2a1810();
};
class DisplayTraversal_2a1810 {
  public:
    void* vptr;
    void Fin();
};
class ShadowTraversal_2a1810 : public DisplayTraversal_2a1810 {
  public:
    char pad[0x14];
    void* vptr2;
    char pad1[4];
    Mem_2a1810 m20;
    char pad2[0x0b];
    Ref_2a1810* m2c;
    char pad3[0x0c];
    void* m3c;
    ShadowTraversal_2a1810* f2(unsigned char flags);
};
ShadowTraversal_2a1810* ShadowTraversal_2a1810::f2(unsigned char flags) {
    vptr = g_vftable_2a1810;
    _ReadWriteBarrier();
    if (m2c) {
        m2c->Release();
        m2c = 0;
    }
    if (m3c)
        operator delete[](m3c);
    m20.~Mem_2a1810();
    vptr2 = g_ref_2a1810;
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
