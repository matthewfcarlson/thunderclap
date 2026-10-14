class CBase_69fa0 {
  public:
    CBase_69fa0();
    virtual ~CBase_69fa0();
};

class CComboTimerTrack : public CBase_69fa0 {
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
