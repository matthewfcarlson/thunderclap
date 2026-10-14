extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22610[];
void operator delete(void*);
class Ref_22610 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_22610 {
  public:
    void* vptr;
    void Fin();
};
class Obj_22610 : public Base_22610 {
  public:
    char pad[24];
    Ref_22610* m;
    Obj_22610* f2(unsigned char flags);
};
Obj_22610* Obj_22610::f2(unsigned char flags) {
    vptr = g_vftable_22610;
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
