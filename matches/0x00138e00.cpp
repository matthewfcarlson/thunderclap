extern "C" void _ReadWriteBarrier();
extern void* g_vftable_00411dc4[];
extern void* g_vftable2[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    void Fin();
};

void operator delete(void*);
class Obj : public Base {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref* m20;
    Ref* m24;
    Ref* m28;
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
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
