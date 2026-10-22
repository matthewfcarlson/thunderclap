class Track_5ad00 {
  public:
    virtual void B0();
    Track_5ad00();
};

class Sub1_5ad00 {
  public:
    void Init();
    char m[0xc];
};

class Sub2_5ad00 {
  public:
    void Init();
    char m[0x100];
};

class CGrappleOpportunityTrack : public Track_5ad00 {
  public:
    virtual void Fn();
    char pad4[4];
    int m8;
    int m0c;
    float m10;
    float m14;
    Sub1_5ad00 s1;
    int m24;
    Sub2_5ad00 s2;
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
