extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22160[];
void operator delete(void*);
class Ref_22160 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_22160 {
  public:
    void* vptr;
    void Fin();
};
class Obj_22160 : public Base_22160 {
  public:
    char pad[0x1c - 4];
    Ref_22160* m;
    Obj_22160* f2(unsigned char flags);
};
Obj_22160* Obj_22160::f2(unsigned char flags) {
    vptr = g_vftable_22160;
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
