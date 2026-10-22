class Track_12e870 {
  public:
    Track_12e870();
    virtual void f();
    char pad[4];
};
class StatBeginTrialTrack : public Track_12e870 {
  public:
    StatBeginTrialTrack();
    char pad2[4];
    int a, b;
    virtual void f();
};
StatBeginTrialTrack::StatBeginTrialTrack() {
    a = 0;
    b = 0;
}