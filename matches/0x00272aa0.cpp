class Inner_272aa0 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_272aa0 {
  public:
    char pad0[0x0c];
    Inner_272aa0 mInner;
    char pad10[0x44 - 0x10];
    int mValue;
    char pad48[0x54 - 0x48];
    unsigned char mFlag;
    char pad55[3];
    int mArg;
    void Run(int);
};
void __cdecl Helper(int);
void Obj_272aa0::Run(int arg) {
    mInner.A();
    mArg = arg;
    mFlag = 1;
    if (mValue != 0) {
        mInner.B();
        Helper(mValue);
    } else {
        mInner.B();
    }
}
