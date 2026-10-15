class Base {
  public:
    Base();
    virtual void f();
    char data[8];
};
class StrafeCircleTrack : public Base {
  public:
    StrafeCircleTrack();
    virtual void f();
    int a;
    float b;
    int c, d, e, f1;
    float g, h;
    char i;
    char pad2[3];
    float j;
    char k;
};
StrafeCircleTrack::StrafeCircleTrack()
    : Base(), a(0), b(-1.0f), c(0), d(0), e(0), f1(0), g(40.0f), h(1.5f), i(0), j(1.0f), k(0) {}