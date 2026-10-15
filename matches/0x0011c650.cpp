class Base {
  public:
    Base();
    virtual void vf();
    char pad[8];
};
class StrafeCircleHBTrack : public Base {
  public:
    StrafeCircleHBTrack();
    int a;
    float b;
    int c, d, e, h;
    float g;
    virtual void vf();
};
StrafeCircleHBTrack::StrafeCircleHBTrack() : Base(), a(0), b(-1.0f), c(0), d(0), e(0), h(0), g(1.0f) {}