class CTrack_629a0 {
  public:
    CTrack_629a0();
    virtual void baseMethod();
    char pad[4];
};

class CSmartPropThrowingTrack_629a0 : public CTrack_629a0 {
  public:
    virtual void method1();
    int m8;
    int mC;
    float m10;
    CSmartPropThrowingTrack_629a0();
};

CSmartPropThrowingTrack_629a0::CSmartPropThrowingTrack_629a0() {
    mC = 0;
    m10 = -1.0f;
    m8 = 1;
}
