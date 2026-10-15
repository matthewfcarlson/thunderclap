class Base {
  public:
    virtual void v();
    Base();
    char pad[8];
};
class Part {
  public:
    Part();
    char pad[8];
};
class AnimationLinkedTrack : public Base {
  public:
    virtual void v();
    AnimationLinkedTrack();
    int a;
    float b;
    char gap[4];
    Part p;
    float x, y, z;
    char gap2[4];
    Part q;
    float r, s, t;
};
AnimationLinkedTrack::AnimationLinkedTrack()
    : Base(), a(0), b(-1.0f), p(), x(1.0f), y(0.0f), z(-1.0f), q(), r(0.0f), s(0.1f), t(0.1f) {}