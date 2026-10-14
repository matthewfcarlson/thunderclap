extern "C" void _ReadWriteBarrier();
extern void* g_vftable_b3d50[];
void operator delete(void*);
class Ref_b3d50 {
  public:
    virtual void F0();
    virtual void Release();
};
class Obj_b3d50 {
  public:
    void* vptr;
    Ref_b3d50* m4;
    Obj_b3d50* f2(unsigned char flags);
};
Obj_b3d50* Obj_b3d50::f2(unsigned char flags) {
    vptr = g_vftable_b3d50;
    _ReadWriteBarrier();
    m4->Release();
    if (flags & 1)
        operator delete(this);
    return this;
}
