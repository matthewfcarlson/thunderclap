class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class RestPoseTrack : public Base {
  public:
    RestPoseTrack();
    virtual void f();
    int a;
    float b;
    char pad2[4];
    Sub sub;
    int c, d, e;
};
RestPoseTrack::RestPoseTrack() : Base(), a(0), b(-1.0f), sub(), c(-5), d(0), e(0) {}