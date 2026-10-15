class Base {
  public:
    Base();
    virtual void a();
    char pad[8];
};
class Sub {
  public:
    Sub();
    char pad[8];
};
struct Z {
    int v;
    Z() : v(0) {}
};
class ThreatBallTrack : public Base {
  public:
    ThreatBallTrack();
    virtual void a();
    int x;
    float y;
    int z;
    Sub s1;
    int p, q, r;
    Z t;
    Sub s2;
};
ThreatBallTrack::ThreatBallTrack() : Base(), x(0), y(-1.0f), z(-1), s1(), p(0), q(0), r(0), t(), s2() {
    *(int*)((char*)this + 8) = 1;
}