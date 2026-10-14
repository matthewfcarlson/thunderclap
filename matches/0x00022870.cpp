extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22870[];
void operator delete(void*);
class Ref_22870 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_22870 {
  public:
    void* vptr;
    void Fin();
};
class Obj_22870 : public Base_22870 {
  public:
    char pad[24];
    Ref_22870* m;
    Obj_22870* f2(unsigned char flags);
};
Obj_22870* Obj_22870::f2(unsigned char flags) {
    vptr = g_vftable_22870;
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
