class Track_14de00 {
  public:
    virtual void f();
    char pad[4];
    int kind;
    Track_14de00();
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class HitReactionTrack : public Track_14de00 {
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
    : Track_14de00(), a(0), b(0), c(0), sub(), x(0), p(0), q(0), r(0), s(0), t(0), u(0), flag(false) {
    value = -1.0f;
    enabled = true;
    kind = 3;
}