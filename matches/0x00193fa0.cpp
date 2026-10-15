class Base {
  public:
    Base();
    virtual void f();
};
class AccuracyLatencyTrack : public Base {
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