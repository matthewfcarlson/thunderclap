extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2c2570[];
void operator delete(void*);
class Ref_2c2570 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2c2570 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2c2570 : public Base_2c2570 {
  public:
    char pad[0x10 - 4];
    Ref_2c2570* m;
    Obj_2c2570* f2(unsigned char flags);
};
Obj_2c2570* Obj_2c2570::f2(unsigned char flags) {
    vptr = g_vftable_2c2570;
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
