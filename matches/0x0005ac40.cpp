class CGrappleDetachTrackBase {
  public:
    virtual ~CGrappleDetachTrackBase();
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    CGrappleDetachTrackBase();
    char pad[8];
};
class CGrappleDetachTrack : public CGrappleDetachTrackBase {
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
