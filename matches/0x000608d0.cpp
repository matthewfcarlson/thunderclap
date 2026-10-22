class CTrack_608d0 {
  public:
    CTrack_608d0();
    virtual void A();
    virtual void B();
    int m4;
};

class CEffectStopTrack_608d0 : public CTrack_608d0 {
  public:
    CEffectStopTrack_608d0();
    virtual void C();
    int m8;
    int mC;
    int m10;
    int m14;
};

CEffectStopTrack_608d0::CEffectStopTrack_608d0() : CTrack_608d0() {
    mC = 0;
    m10 = 0;
    m14 = -1;
    m8 = 1;
}
