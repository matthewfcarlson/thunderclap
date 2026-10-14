extern "C" void _ReadWriteBarrier();
extern void* g_vftable_23e390[];
void operator delete(void*);
class Ref_23e390 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_23e390 {
  public:
    void* vptr;
    void Fin();
};
class Obj_23e390 : public Base_23e390 {
  public:
    char pad[28];
    Ref_23e390* m;
    Obj_23e390* f2(unsigned char flags);
};
Obj_23e390* Obj_23e390::f2(unsigned char flags) {
    vptr = g_vftable_23e390;
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
