extern "C" void _ReadWriteBarrier();
extern void* g_vftable_220a0[];
void operator delete(void*);
class Ref_220a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_220a0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_220a0 : public Base_220a0 {
  public:
    char pad[0x1c - 4];
    Ref_220a0* m;
    Obj_220a0* f2(unsigned char flags);
};
Obj_220a0* Obj_220a0::f2(unsigned char flags) {
    vptr = g_vftable_220a0;
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
