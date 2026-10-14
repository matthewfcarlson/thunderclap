extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21860[];
void operator delete(void*);
class Ref_21860 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21860 {
  public:
    void* vptr;
    void Fin();
};
class Obj_21860 : public Base_21860 {
  public:
    char pad[0x1c - 4];
    Ref_21860* m;
    Obj_21860* f2(unsigned char flags);
};
Obj_21860* Obj_21860::f2(unsigned char flags) {
    vptr = g_vftable_21860;
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
