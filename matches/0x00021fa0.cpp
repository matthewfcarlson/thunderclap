extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21fa0[];
void operator delete(void*);
class Ref_21fa0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21fa0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_21fa0 : public Base_21fa0 {
  public:
    char pad[0x1c - 4];
    Ref_21fa0* m;
    Obj_21fa0* f2(unsigned char flags);
};
Obj_21fa0* Obj_21fa0::f2(unsigned char flags) {
    vptr = g_vftable_21fa0;
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
