extern "C" char DAT_0040ed2c[];
struct Ref_117350 {
    virtual void Add();
    virtual void Release();
};
void Init();
class MotionLocatorAction {
  public:
    char pad[0x1c];
    volatile unsigned int mArg;
    Ref_117350* mOld;
    unsigned int mZero;
    unsigned int mMin1;
    unsigned int mMin2;
    MotionLocatorAction* Build(unsigned int a, Ref_117350* r);
};
MotionLocatorAction* MotionLocatorAction::Build(unsigned int a, Ref_117350* r) {
    Init();
    mMin1 = 0x7f7fffff;
    mMin2 = 0x7f7fffff;
    *(volatile unsigned int*)this = ((int)DAT_0040ed2c);
    mArg = 0;
    mOld = 0;
    mZero = 0;
    mArg = a;
    if (r)
        r->Add();
    if (mOld)
        mOld->Release();
    mOld = r;
    return this;
}