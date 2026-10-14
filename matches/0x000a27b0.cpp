extern "C" void _ReadWriteBarrier();
extern void* g_vftable_a27b0[];
void operator delete(void*);
class Ref_a27b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Obj_a27b0 {
  public:
    void* vptr;
    char pad[0x34c];
    Ref_a27b0* m350;
    void Cam29();
    void Fin();
    Obj_a27b0* f2(unsigned char flags);
};
Obj_a27b0* Obj_a27b0::f2(unsigned char flags) {
    vptr = g_vftable_a27b0;
    _ReadWriteBarrier();
    if (m350) {
        m350->Release();
        m350 = 0;
    }
    Cam29();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
