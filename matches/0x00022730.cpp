extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22730[];
void operator delete(void*);
class Ref_22730 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_22730 {
  public:
    void* vptr;
    void Fin();
};
class Obj_22730 : public Base_22730 {
  public:
    char pad[0x1c - 4];
    Ref_22730* m;
    Obj_22730* f2(unsigned char flags);
};
Obj_22730* Obj_22730::f2(unsigned char flags) {
    vptr = g_vftable_22730;
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
