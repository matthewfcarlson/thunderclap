extern "C" void _ReadWriteBarrier();
extern void* g_vftable_d7ab0[];
void operator delete(void*);
class Ref_d7ab0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_d7ab0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_d7ab0 : public Base_d7ab0 {
  public:
    char pad[332];
    Ref_d7ab0* m;
    Obj_d7ab0* f2(unsigned char flags);
};
Obj_d7ab0* Obj_d7ab0::f2(unsigned char flags) {
    vptr = g_vftable_d7ab0;
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
