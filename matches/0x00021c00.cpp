extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21c00[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_21c00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21c00 {
  public:
    void* vptr;
    void Fin();
};
class Obj_21c00 : public Base_21c00 {
  public:
    char pad[0x1c - 4];
    Ref_21c00* m1c;
    Obj_21c00* f2(unsigned char flags);
};
Obj_21c00* Obj_21c00::f2(unsigned char flags) {
    vptr = g_vftable_21c00;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
