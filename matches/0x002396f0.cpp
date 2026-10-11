class Action {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5(unsigned int, int);
    int pad4[2];
    unsigned int flags;
    char pad10[0x28];
};
class Sub {
  public:
    void Init(unsigned int, int);
    void Run(unsigned int);
    bool Check(int);
    void Finish();
};
namespace fight {
class ExecuteAction : public Action {
  public:
    Sub sub;
    char pad39[0x27];
    unsigned int mCount;
    unsigned char mFlag;
    void V5(unsigned int, int);
};
} // namespace fight
void fight::ExecuteAction::V5(unsigned int index, int arg) {
    if (index == 0 && !mFlag)
        sub.Init(mCount, arg);
    mFlag = 0;
    sub.Run(index);
    if (index == mCount - 1) {
        if (sub.Check(0)) {
            flags &= 0xfffffffc;
            sub.Finish();
            return;
        }
        flags = (flags & 0xfffffffd) | 1;
    }
    sub.Finish();
}
