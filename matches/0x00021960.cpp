extern "C" void _ReadWriteBarrier();
extern void* g_vftable_003f3574[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_21960 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21960 {
  public:
    void* vptr;
    void Fin();
};
class Obj_21960 : public Base_21960 {
  public:
    char pad[0x18];
    Ref_21960* m2;
    char pad2[0x4];
    Ref_21960* m1;
    Obj_21960* f2(unsigned char flags);
};
Obj_21960* Obj_21960::f2(unsigned char flags) {
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
