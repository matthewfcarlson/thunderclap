class Base {
  public:
    virtual void B0();
    Base();
};

class CComboMessageTrack : public Base {
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
