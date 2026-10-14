class Base {
  public:
    virtual void f();
    Base();
    char pad[8];
};
class Part {
  public:
    Part();
    char pad[8];
};
class AnimationVelocityScaledTrack : public Base {
  public:
    AnimationVelocityScaledTrack();
    int a;
    float b;
    char gap[4];
    Part p;
    int c;
    float d;
    int e;
    float f0;
    int g;
    int h;
    float i;
    int j;
    Part q;
    int k;
    float l;
    float m;
};
AnimationVelocityScaledTrack::AnimationVelocityScaledTrack()
    : a(0), b(-1.0f), c(0), d(1.0f), e(0), f0(-1.0f), g(0), h(0), i(-1.0f), j(0), k(0), l(0.1f), m(0.1f) {}