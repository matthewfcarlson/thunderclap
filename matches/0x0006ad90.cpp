class Base {
  public:
    Base();
    virtual void B();
};

class CAlertStatusTrack : public Base {
  public:
    CAlertStatusTrack();
    virtual void Dummy();
    int pad4;
    int mCount;
    int mX;
    int mY;
};

CAlertStatusTrack::CAlertStatusTrack() {
    mX = 0;
    mY = 0;
    mCount = 1;
}
