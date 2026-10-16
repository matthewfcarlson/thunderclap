class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class StatBeginTrialTrack : public Base {
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