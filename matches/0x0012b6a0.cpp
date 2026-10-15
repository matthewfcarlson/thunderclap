class Base {
  public:
    Base();
    virtual void f();
};
class Sub {
  public:
    Sub();
};
class ThreatDodgeTrack : public Base {
  public:
    ThreatDodgeTrack();
    virtual void f();
    char pad[8];
    int a;
    float b, c;
    char d;
    char pad2[7];
    Sub sub;
};
ThreatDodgeTrack::ThreatDodgeTrack() : Base(), a(0), b(-1.0f), c(1.0f), d(1), sub() {}