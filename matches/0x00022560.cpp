extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22560[];
void operator delete(void*);
class Ref_22560 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_22560 {
  public:
    void* vptr;
    void Fin();
};
class Obj_22560 : public Base_22560 {
  public:
    char pad[0x1c - 4];
    Ref_22560* m;
    Obj_22560* f2(unsigned char flags);
};
Obj_22560* Obj_22560::f2(unsigned char flags) {
    vptr = g_vftable_22560;
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
