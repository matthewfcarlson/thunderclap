class Track_18f220 {
  public:
    Track_18f220();
    virtual void f();
};
class SimulationTrack : public Track_18f220 {
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