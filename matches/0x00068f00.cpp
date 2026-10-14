class Base_68f00 {
  public:
    virtual void b0();
    virtual void b1();
    Base_68f00();
};

class CClimbingTrack : public Base_68f00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    CClimbingTrack();
    char pad[4]; // offset 4
    int m8;      // offset 8
    int m_c;     // offset 0xc
    float m10;   // offset 0x10
};

CClimbingTrack::CClimbingTrack() {
    m_c = 0;
    m10 = -1.0f;
    m8 = 1;
}
