class CTrack_78080 {
  public:
    CTrack_78080();
    virtual void vf();
    char pad[4];
};
class CHeliDeathSpiralTrack : public CTrack_78080 {
  public:
    CHeliDeathSpiralTrack();
    virtual void vf();
    char p0[4];
    int a;
    float b, c;
    int d;
    float e;
    int f, g, h;
    int i, j;
    int k;
};
CHeliDeathSpiralTrack::CHeliDeathSpiralTrack()
    : a(0), b(-1.0f), c(0.5f), d(0), e(-0.017453292f), f(0), g(0), h(0), i(-5), j(0), k(0) {}