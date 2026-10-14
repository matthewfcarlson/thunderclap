extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21da0[];
void operator delete(void*);
class Ref_21da0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21da0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_21da0 : public Base_21da0 {
  public:
    char pad[24];
    Ref_21da0* m;
    Obj_21da0* f2(unsigned char flags);
};
Obj_21da0* Obj_21da0::f2(unsigned char flags) {
    vptr = g_vftable_21da0;
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
