class CTrack_6a7f0 {
  public:
    CTrack_6a7f0();
    virtual ~CTrack_6a7f0();
};
class CDriftTrack : public CTrack_6a7f0 {
  public:
    CDriftTrack();
    virtual ~CDriftTrack();
    char pad4[4];
    int m8;
    int mC;
    float m10;
    int m14;
    float m18;
};
CDriftTrack::CDriftTrack() {
    mC = 0;
    m14 = 0;
    m10 = -1.0f;
    m18 = 1.0f;
    m8 = 1;
}
