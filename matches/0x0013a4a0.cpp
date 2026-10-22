class Track_13a4a0 {
  public:
    virtual void f();
    Track_13a4a0();
    char pad[8];
};
class Part_13a4a0 {
  public:
    Part_13a4a0();
    char pad[8];
};
class AnimationVelocityScaledTrack : public Track_13a4a0 {
  public:
    AnimationVelocityScaledTrack();
    int a;
    float b;
    char gap[4];
    Part_13a4a0 p;
    int c;
    float d;
    int e;
    float f0;
    int g;
    int h;
    float i;
    int j;
    Part_13a4a0 q;
    int k;
    float l;
    float m;
};
AnimationVelocityScaledTrack::AnimationVelocityScaledTrack()
    : a(0), b(-1.0f), c(0), d(1.0f), e(0), f0(-1.0f), g(0), h(0), i(-1.0f), j(0), k(0), l(0.1f), m(0.1f) {}