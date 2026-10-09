struct Params {
    int p0, p1, p2, p3, p4, p5, p6, p7;
};
void* Alloc(unsigned n);
inline void* operator new(unsigned, void* p) {
    return p;
}
class Impl {
  public:
    Impl(int ctx);
    void Setup(int a, int b, int c, int d, int e, int f);
    virtual void v0();
    virtual void v1();
    virtual int v2();
    virtual void v3(int del);
};
class d3dDevice {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual Impl* vfunc_10(Params* p);
    int pad;
    int mRes;
    int mCtx;
};
Impl* d3dDevice::vfunc_10(Params* p) {
    void* m = Alloc(0x40);
    Impl* o;
    if (m)
        o = new (m) Impl(mCtx);
    else
        o = 0;
    o->Setup(p->p0, p->p1, 0, p->p4, p->p5, p->p7);
    mRes = o->v2();
    if (mRes != 1) {
        o->v3(1);
        return 0;
    }
    return o;
}
