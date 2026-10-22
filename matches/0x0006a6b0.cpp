class CTrack_6a6b0 {
  public:
    CTrack_6a6b0();
    virtual void B();
};
class COrientTrack : public CTrack_6a6b0 {
  public:
    COrientTrack();
    virtual ~COrientTrack() throw();
    virtual void F();
    char pad4[4];
    int m8;
    int m0c;
    float m10;
    float m14;
    int m18;
    char m1c;
    int m20;
    int m24;
    int m28;
};

COrientTrack::COrientTrack() {
    m0c = 0;
    m18 = 0;
    m1c = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m10 = -1.0f;
    m14 = -0.0174532925f;
    m8 = 1;
}
