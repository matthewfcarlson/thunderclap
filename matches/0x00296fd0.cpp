extern "C" void _ReadWriteBarrier();
extern int vt1, vt2;
extern void Free(void*);
class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
class Root {
  public:
    void* vptr;
    void Fini();
};
class D : public Root {
  public:
    char p[0x14];
    Ref* a18;
    D* vfunc2(unsigned char f);
};
D* D::vfunc2(unsigned char f) {
    vptr = &vt1;
    _ReadWriteBarrier();
    if (a18) {
        a18->Release();
        a18 = 0;
    }
    vptr = &vt2;
    Fini();
    if (f & 1)
        Free(this);
    return this;
}
