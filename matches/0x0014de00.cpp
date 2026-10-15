class Base {
  public:
    virtual void f();
    char pad[4];
    int kind;
    Base();
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class HitReactionTrack : public Base {
  public:
    int a, b, c;
    Sub sub;
    float value;
    int x;
    bool enabled;
    int p, q, r, s, t, u;
    bool flag;
    HitReactionTrack();
    virtual void f();
};
HitReactionTrack::HitReactionTrack()
    : Base(), a(0), b(0), c(0), sub(), x(0), p(0), q(0), r(0), s(0), t(0), u(0), flag(false) {
    value = -1.0f;
    enabled = true;
    kind = 3;
}