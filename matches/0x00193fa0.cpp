class Track_193fa0 {
  public:
    Track_193fa0();
    virtual void f();
};
class AccuracyLatencyTrack : public Track_193fa0 {
  public:
    AccuracyLatencyTrack();
    char pad[4];
    int a;
    int b;
    float c;
    int d;
    float e;
};
AccuracyLatencyTrack::AccuracyLatencyTrack() : b(0), c(-1.0f), d(0), e(1.0f) {
    a = 1;
}