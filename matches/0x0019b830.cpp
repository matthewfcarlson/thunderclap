extern "C" void _ReadWriteBarrier();
extern void* g_vftable_19b830[];
void operator delete(void*);
class Ref_19b830 {
  public:
    virtual void F0();
    virtual void Release();
};
class Obj_19b830 {
  public:
    void* vptr;
    void* m4;
    char pad[0xc];
    Ref_19b830* m14;
    Obj_19b830* f2(unsigned char flags);
};
Obj_19b830* Obj_19b830::f2(unsigned char flags) {
    vptr = g_vftable_19b830;
    _ReadWriteBarrier();
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    if (m4)
        m4 = 0;
    if (flags & 1)
        operator delete(this);
    return this;
}
