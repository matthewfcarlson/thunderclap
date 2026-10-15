class Base {
  public:
    Base();
    virtual void vf();
    char pad[8];
};
class CWallSlideTrack : public Base {
  public:
    CWallSlideTrack();
    int a;
    float b, c;
    int d;
    float e, ff;
    int g, h, i;
    virtual void vf();
};
CWallSlideTrack::CWallSlideTrack() : Base() {
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