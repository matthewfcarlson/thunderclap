class CJumpTrack {
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
class Alloc {
  public:
    int call(CJumpTrack*, int);
};
extern int __cdecl FUN_0008d690(int);
int CJumpTrack::vfunc_12(int param) {
    int x = FUN_0008d690(0x3c);
    if (x)
        return ((Alloc*)x)->call(this, param);
    return 0;
}