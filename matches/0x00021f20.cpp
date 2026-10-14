extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21f20[];
void operator delete(void*);
class Ref_21f20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21f20 {
  public:
    void* vptr;
    void Fin();
};
class Obj_21f20 : public Base_21f20 {
  public:
    char pad[24];
    Ref_21f20* m;
    Obj_21f20* f2(unsigned char flags);
};
Obj_21f20* Obj_21f20::f2(unsigned char flags) {
    vptr = g_vftable_21f20;
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
