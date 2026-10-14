extern "C" void _ReadWriteBarrier();
extern void* g_vftable_224e0[];
void operator delete(void*);
class Ref_224e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_224e0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_224e0 : public Base_224e0 {
  public:
    char pad[0x1c - 4];
    Ref_224e0* m;
    Obj_224e0* f2(unsigned char flags);
};
Obj_224e0* Obj_224e0::f2(unsigned char flags) {
    vptr = g_vftable_224e0;
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
