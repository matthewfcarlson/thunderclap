struct Iface {
    virtual void s0();
    virtual void Release();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual int Get15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void Call21();
    virtual int Get22();
    virtual bool Ok23();
};
struct W {
    int v;
    W(const W& o) { v = o.v; }
};
void __cdecl Init(Iface** pp, W w, int a, int b, int c, int d, int e, int f);
class MyFileStream {
  public:
    virtual void vfunc_0();
    virtual bool vfunc_1(W x);
    Iface* mIface;
    int mA;
    int mB;
};
bool MyFileStream::vfunc_1(W x) {
    Iface** pp = &mIface;
    Init(pp, x, 0, 0, 1, 0, 1, 1);
    (*pp)->Call21();
    if ((*pp)->Ok23() && (*pp)->Get15() && (*pp)->Get22() == 0) {
        mB = (*pp)->Get15();
        mA = 0;
        return true;
    }
    (*pp)->Release();
    *pp = 0;
    return false;
}
