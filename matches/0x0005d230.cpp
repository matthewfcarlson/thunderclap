class CTrack_5d230 {
  public:
    CTrack_5d230();
    virtual void Fn();
};

class CHapticTrack : public CTrack_5d230 {
  public:
    CHapticTrack();
    virtual void Fn0();
    virtual void Fn1();
    virtual void Fn2();
    virtual void Fn3();

  private:
    char pad[4];
    int m0x8;
    int m0xc;
    float m0x10;
    int m0x14;
    int m0x18;
    char m0x1c;
};

CHapticTrack::CHapticTrack() {
    m0xc = 0;
    m0x14 = 0;
    m0x18 = 0;
    m0x1c = 0;
    m0x10 = -1.0f;
    m0x8 = 1;
}
