extern "C" void _ReadWriteBarrier();
extern void* g_vt_2e15b0[];
void operator delete(void*);
class Ref_2e15b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2e15b0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2e15b0 : public Base_2e15b0 {
  public:
    char pad[104 - 4];
    Ref_2e15b0* m;
    Obj_2e15b0* f2(unsigned char flags);
};
Obj_2e15b0* Obj_2e15b0::f2(unsigned char flags) {
    vptr = g_vt_2e15b0;
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
