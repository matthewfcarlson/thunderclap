class Base {
  public:
    Base();
    virtual void f();
};
class SimulationTrack : public Base {
  public:
    SimulationTrack();
    char pad[8];
    int x;
    float y;
};
SimulationTrack::SimulationTrack() {
    x = 0;
    y = -1.0f;
}