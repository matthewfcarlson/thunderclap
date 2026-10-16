namespace hulkfight {
class Base {
  public:
    virtual void f();
    char pad[8];
    Base();
};
class StatEndTrialTrack : public Base {
  public:
    int a, b;
    StatEndTrialTrack();
    virtual void f();
};
StatEndTrialTrack::StatEndTrialTrack() : Base(), a(0), b(0) {}
} // namespace hulkfight