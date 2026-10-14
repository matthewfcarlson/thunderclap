extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1573f0[];
void operator delete(void*);
class Ref_1573f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1573f0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1573f0 : public Base_1573f0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1573f0* m20;
    Ref_1573f0* m24;
    Ref_1573f0* m28;
    Obj_1573f0* f2(unsigned char flags);
};
Obj_1573f0* Obj_1573f0::f2(unsigned char flags) {
    vptr = g_vftable_1573f0;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
