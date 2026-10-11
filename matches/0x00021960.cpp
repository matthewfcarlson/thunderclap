extern "C" void _ReadWriteBarrier();
extern void* g_vftable_003f3574[];
extern void* g_vftable2[];
void operator delete(void*);
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
class Obj : public Base {
  public:
    char pad[0x18];
    Ref* m2;
    char pad2[0x4];
    Ref* m1;
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_vftable_003f3574;
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
