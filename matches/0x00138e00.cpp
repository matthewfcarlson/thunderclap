extern "C" void _ReadWriteBarrier();
extern void* g_vftable_00411dc4[];
extern void* g_vftable2[];
class Ref_138e00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_138e00 {
  public:
    void* vptr;
    void Fin();
};

void operator delete(void*);
class Obj_138e00 : public Base_138e00 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_138e00* m20;
    Ref_138e00* m24;
    Ref_138e00* m28;
    Obj_138e00* f2(unsigned char flags);
};
Obj_138e00* Obj_138e00::f2(unsigned char flags) {
    vptr = g_vftable_00411dc4;
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
