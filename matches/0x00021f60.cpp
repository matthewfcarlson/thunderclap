extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21f60[];
void operator delete(void*);
class Ref_21f60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21f60 {
  public:
    void* vptr;
    void Fin();
};
class Obj_21f60 : public Base_21f60 {
  public:
    char pad[0x1c - 4];
    Ref_21f60* m;
    Obj_21f60* f2(unsigned char flags);
};
Obj_21f60* Obj_21f60::f2(unsigned char flags) {
    vptr = g_vftable_21f60;
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
