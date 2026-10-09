class ClimbLocomotion4Track {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int vfunc_10(int, int, int);
};
class Helper {
  public:
    int f(ClimbLocomotion4Track*, int);
};
extern "C" Helper* FUN_0008d690(int);
int ClimbLocomotion4Track::vfunc_10(int a, int b, int c) {
    Helper* p = FUN_0008d690(0x4c);
    if (p)
        return p->f(this, c);
    return 0;
}