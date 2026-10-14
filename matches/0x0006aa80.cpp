class Base {
  public:
    virtual void f0();
    virtual void f1();
    Base();
};
class CRageModeTrack : public Base {
  public:
    virtual void g0();
    virtual void g1();
    CRageModeTrack();
    char pad[4];
    int mFlag;
    int mC;
    int mD;
};
CRageModeTrack::CRageModeTrack() {
    mFlag = 1;
    mC = 0;
    mD = 0;
}
