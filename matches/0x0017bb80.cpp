extern "C" void _ReadWriteBarrier();
extern void* g_vftable_17bb80[];
void operator delete(void*);
class Ref_17bb80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_17bb80 {
  public:
    void* vptr;
    void Fin();
};
class Obj_17bb80 : public Base_17bb80 {
  public:
    char pad[0x18];
    Ref_17bb80* m;
    Obj_17bb80* f2(unsigned char flags);
};
Obj_17bb80* Obj_17bb80::f2(unsigned char flags) {
    vptr = g_vftable_17bb80;
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
