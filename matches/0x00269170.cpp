unsigned int GetTime();
class Pad_269170 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Ready();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void Update(unsigned int t);
    char pad[0x49e - 4];
    bool mActive;
    char pad2[1];
};
class ControllerSystemXBox {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void SetTime(unsigned int t);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void Tick();
    char pad[0xc];
    bool mFlag;
    char pad1[3];
    unsigned int mOffset;
    char pad2[8];
    Pad_269170 mPads[4];
    unsigned int mInterval;
    unsigned int mLast;
    void Poll();
};
void ControllerSystemXBox::Tick() {
    unsigned int now = GetTime();
    if (now - mLast >= mInterval) {
        mLast = now;
        Poll();
        for (int i = 0; i < 4; i++) {
            if (mPads[i].mActive && mPads[i].Ready())
                mPads[i].Update(mOffset + now);
        }
        if (!mFlag)
            SetTime(GetTime());
    }
}
