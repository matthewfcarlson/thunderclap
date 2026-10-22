class Track_12b6a0 {
  public:
    Track_12b6a0();
    virtual void f();
};
class Sub {
  public:
    Sub();
};
class ThreatDodgeTrack : public Track_12b6a0 {
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
ThreatDodgeTrack::ThreatDodgeTrack() : Track_12b6a0(), a(0), b(-1.0f), c(1.0f), d(1), sub() {}