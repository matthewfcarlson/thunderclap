class CTrack_6b170 {
  public:
    CTrack_6b170();
    virtual void vf();
    char pad[8];
};
class CWallSlideTrack : public CTrack_6b170 {
  public:
    CWallSlideTrack();
    int a;
    float b, c;
    int d;
    float e, ff;
    int g, h, i;
    virtual void vf();
};
CWallSlideTrack::CWallSlideTrack() : CTrack_6b170() {
    a = 0;
    b = -1.0f;
    c = 20.0f;
    d = 0;
    e = 20.0f;
    ff = 1.0f;
    g = 0;
    h = 0;
    i = 0;
}