class CTrack_6a150 {
  public:
    virtual void f0();
    virtual void f1();
    CTrack_6a150();
};

class CIntangibleTrack : public CTrack_6a150 {
  public:
    virtual void f0();
    char pad4[4];
    int m8;
    float mC;
    float m10;
    CIntangibleTrack();
};

CIntangibleTrack::CIntangibleTrack() {
    mC = 0.0f;
    m10 = -1.0f;
    m8 = 1;
}
