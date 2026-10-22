class Track_12b5d0 {
  public:
    Track_12b5d0();
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
class ThreatBallTrack : public Track_12b5d0 {
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
ThreatBallTrack::ThreatBallTrack() : Track_12b5d0(), x(0), y(-1.0f), z(-1), s1(), p(0), q(0), r(0), t(), s2() {
    *(int*)((char*)this + 8) = 1;
}