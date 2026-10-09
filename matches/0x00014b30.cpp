class CKeyPoseAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual unsigned char vfunc_8(float dt);
    char pad[0x20];
    int mActive;
    int mIndex;
    float mTime;
    bool Advance(int i);
};
unsigned char CKeyPoseAction::vfunc_8(float dt) {
    if (mActive) {
        mTime -= dt;
        if (mTime <= 0.0f) {
            do {
                if (!Advance(mIndex + 1))
                    return 0;
            } while (mTime <= 0.0f);
        }
        return 1;
    }
    return 0;
}
