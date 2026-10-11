extern "C" void _ReadWriteBarrier();
extern int vt1, vt2;
extern void Free(void*);
class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
class D {
  public:
    void* vptr;
    char p[0x18];
    Ref* a1c;
    Ref* a20;
    D* vfunc2(unsigned char f);
};
D* D::vfunc2(unsigned char f) {
    vptr = &vt1;
    _ReadWriteBarrier();
    if (a1c) {
        a1c->Release();
        a1c = 0;
    }
    if (a20) {
        a20->Release();
        a20 = 0;
    }
    vptr = &vt2;
    if (f & 1)
        Free(this);
    return this;
}
