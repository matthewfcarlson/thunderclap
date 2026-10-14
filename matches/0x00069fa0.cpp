class CBase {
  public:
    CBase();
    virtual ~CBase();
};

class CComboTimerTrack : public CBase {
  public:
    virtual ~CComboTimerTrack();
    CComboTimerTrack();
    char pad4[4];
    int m8;
    int mC;
    float m10;
    int m14;
};

CComboTimerTrack::CComboTimerTrack() {
    mC = 0;
    m14 = 0;
    m10 = -1.0f;
    m8 = 1;
}
