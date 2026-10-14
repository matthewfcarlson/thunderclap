extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22300[];
void operator delete(void*);
class Ref_22300 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_22300 {
  public:
    void* vptr;
    void Fin();
};
class Obj_22300 : public Base_22300 {
  public:
    char pad[0x1c - 4];
    Ref_22300* m;
    Obj_22300* f2(unsigned char flags);
};
Obj_22300* Obj_22300::f2(unsigned char flags) {
    vptr = g_vftable_22300;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
