extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21b40[];
void operator delete(void*);
class Ref_21b40 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21b40 {
  public:
    void* vptr;
    void Fin();
};
class Obj_21b40 : public Base_21b40 {
  public:
    char pad[0x1c - 4];
    Ref_21b40* m;
    Obj_21b40* f2(unsigned char flags);
};
Obj_21b40* Obj_21b40::f2(unsigned char flags) {
    vptr = g_vftable_21b40;
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
