// Same code shape as 0x00062300 (propagated; names are from that function)
class CSweepTrack {
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
struct Helper_69bf0 {
    int f(CSweepTrack*, int);
};
extern "C" Helper_69bf0* __cdecl FUN_0008d690(int);
int CSweepTrack::vfunc_12(int a) {
    Helper_69bf0* p = FUN_0008d690(0x2c);
    if (p)
        return p->f(this, a);
    return 0;
}