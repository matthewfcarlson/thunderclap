class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class SuckTrack : public Base {
  public:
    SuckTrack();
    virtual void f();
    int a;
    int b;
    float c;
    int d, e, f1, g;
};
SuckTrack::SuckTrack() : b(0), d(0), e(0), f1(0), g(0) {
    c = -1.0f;
    a = 1;
}