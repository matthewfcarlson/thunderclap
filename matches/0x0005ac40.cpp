class CTrack_5ac40 {
  public:
    virtual ~CTrack_5ac40();
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    CTrack_5ac40();
    char pad[8];
};
class CGrappleDetachTrack : public CTrack_5ac40 {
  public:
    virtual ~CGrappleDetachTrack();
    int m0xc;
    int m0x10;
    CGrappleDetachTrack();
};
CGrappleDetachTrack::CGrappleDetachTrack() {
    m0xc = 0;
    m0x10 = 0;
}
