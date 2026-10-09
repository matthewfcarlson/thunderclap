// Same code shape as 0x00062300 (propagated; names are from that function)
class CSmartPropAttachTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual int vfunc_12(int);
};
struct Helper {
    int f(CSmartPropAttachTrack*, int);
};
extern "C" Helper* __cdecl FUN_0008d690(int);
int CSmartPropAttachTrack::vfunc_12(int a) {
    Helper* p = FUN_0008d690(0x2c);
    if (p)
        return p->f(this, a);
    return 0;
}