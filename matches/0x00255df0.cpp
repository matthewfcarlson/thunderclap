class SeqAction {
  public:
    virtual void x();
    char pad[0x10];
};
class SeqActionClip : public SeqAction {
  public:
    int mObj;
    int mState;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4(int);
    virtual void v5();
    virtual void v6();
};
int Check(int);
void Do(int);
void SeqActionClip::vfunc_4(int) {
    if (mObj != 0) {
        if (Check(mObj) == 1)
            Do(mObj);
    }
    mState = 5;
}