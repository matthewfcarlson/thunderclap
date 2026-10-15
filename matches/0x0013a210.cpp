class Base {
  public:
    virtual void fn();
    char pad[8];
    Base();
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class AnimationChargeTrack : public Base {
  public:
    int a;
    float b;
    int c;
    Sub one;
    int d;
    float e;
    Sub two;
    int f;
    float g, h;
    AnimationChargeTrack();
    virtual void fn();
};
AnimationChargeTrack::AnimationChargeTrack()
    : a(0), b(-1.0f), one(), d(0), e(-1.0f), two(), f(0), g(0.1f), h(0.1f) {}