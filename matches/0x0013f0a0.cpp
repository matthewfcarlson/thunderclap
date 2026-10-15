class Base {
  public:
    Base();
    virtual void vf();
    char pad[8];
};
class WallExitTrack : public Base {
  public:
    WallExitTrack();
    virtual void vf();
    int a;
    float b;
    int c;
    int d;
    float e;
    int f;
    float g;
    float h;
    int i;
    int j;
    int k;
};
WallExitTrack::WallExitTrack()
    : a(0), b(-1.0f), c(0), d(0), e(20.0f), f(0), g(0.785398185f), h(0.52359879f), i(-5), j(0), k(0) {}