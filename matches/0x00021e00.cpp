extern "C" void _ReadWriteBarrier();
extern void* g_vftable_003f381c[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_21e00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21e00 {
  public:
    void* vptr;
    void Fin();
};
class Obj_21e00 : public Base_21e00 {
  public:
    char pad[0x18];
    Ref_21e00* m2;
    char pad2[0x4];
    Ref_21e00* m1;
    Obj_21e00* f2(unsigned char flags);
};
Obj_21e00* Obj_21e00::f2(unsigned char flags) {
    vptr = g_vftable_003f381c;
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
