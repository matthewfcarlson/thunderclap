class Base {
  public:
    virtual void B0();
    Base();
};

class Sub1 {
  public:
    void Init();
    char m[0xc];
};

class Sub2 {
  public:
    void Init();
    char m[0x100];
};

class CGrappleOpportunityTrack : public Base {
  public:
    virtual void Fn();
    char pad4[4];
    int m8;
    int m0c;
    float m10;
    float m14;
    Sub1 s1;
    int m24;
    Sub2 s2;
    CGrappleOpportunityTrack();
};

CGrappleOpportunityTrack::CGrappleOpportunityTrack() {
    m0c = 0;
    m10 = -1.0f;
    m14 = -1.0f;
    s1.Init();
    m24 = 0;
    s2.Init();
    m8 = 1;
}
