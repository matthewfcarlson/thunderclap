class Helper {
  public:
    int run(int, int);
};
extern Helper* __cdecl FUN_0008d690(int);
class CSmartPropRemoveInstanceTrack {
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
    virtual void f13();
    int pad[2];
    int member;
};
int CSmartPropRemoveInstanceTrack::vfunc_12(int arg) {
    Helper* p = FUN_0008d690(0x24);
    if (p)
        return p->run(arg, member);
    return 0;
}