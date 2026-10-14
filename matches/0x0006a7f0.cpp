class CDriftTrackBase {
  public:
    CDriftTrackBase();
    virtual ~CDriftTrackBase();
};
class CDriftTrack : public CDriftTrackBase {
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
