class CEffectTrack {
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
    virtual int vfunc_10(int, int, int);
    virtual void f11();
};
class Helper_60810 {
  public:
    int Run(CEffectTrack*, int, int);
};
extern void* Get(int);
int CEffectTrack::vfunc_10(int a, int b, int c) {
    void* p = Get(0x2c);
    if (p)
        return ((Helper_60810*)p)->Run(this, c, a);
    return 0;
}
