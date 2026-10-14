class Base_697c0 {
  public:
    virtual void B0();
    Base_697c0();
};

class CComboMessageTrack : public Base_697c0 {
  public:
    virtual void Fn0();
    int m4;
    int m8;
    int mC;
    char m10;
    char pad[0x3F];
    int m50;
    CComboMessageTrack();
};

CComboMessageTrack::CComboMessageTrack() {
    mC = 0;
    m50 = 0;
    m10 = 0;
    m8 = 1;
}
