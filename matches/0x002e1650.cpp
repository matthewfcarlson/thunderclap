extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2e1650[];
void operator delete(void*);
class Ref_2e1650 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2e1650 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2e1650 : public Base_2e1650 {
  public:
    char pad[4];
    Ref_2e1650* m;
    Obj_2e1650* f2(unsigned char flags);
};
Obj_2e1650* Obj_2e1650::f2(unsigned char flags) {
    vptr = g_vftable_2e1650;
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
