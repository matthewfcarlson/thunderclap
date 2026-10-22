extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2e1470[];
void operator delete(void*);
class Ref_2e1470 {
  public:
    virtual void F0();
    virtual void Release();
};
class DrawablePrimitive_2e1470 {
  public:
    void* vptr;
    void Fin();
};
class PrimGroup_2e1470 : public DrawablePrimitive_2e1470 {
  public:
    char pad[60];
    Ref_2e1470* m;
    PrimGroup_2e1470* f2(unsigned char flags);
};
PrimGroup_2e1470* PrimGroup_2e1470::f2(unsigned char flags) {
    vptr = g_vftable_2e1470;
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
