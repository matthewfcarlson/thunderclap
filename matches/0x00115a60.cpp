class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class MotionBoostTrack : public Base {
  public:
    MotionBoostTrack();
    virtual void f();
    int a;
    float b;
    int c, d, e, f0;
    float g;
    int h;
};
MotionBoostTrack::MotionBoostTrack() : a(0), c(0), d(0), e(0), f0(0), h(0) {
    b = -1.0f;
    g = 1.0f;
}