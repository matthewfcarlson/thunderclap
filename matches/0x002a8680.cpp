extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a8680[];
void operator delete(void*);
class Ref_2a8680 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2a8680 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2a8680 : public Base_2a8680 {
  public:
    char pad[0x40 - 4];
    Ref_2a8680* m;
    Obj_2a8680* f2(unsigned char flags);
};
Obj_2a8680* Obj_2a8680::f2(unsigned char flags) {
    vptr = g_vftable_2a8680;
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
