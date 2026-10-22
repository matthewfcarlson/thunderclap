class Track_1158b0 {
  public:
    Track_1158b0();
    virtual void f();
    int a, b;
};
class MotionFleeTrack : public Track_1158b0 {
  public:
    MotionFleeTrack();
    int x;
    float y, z;
    virtual void f();
};
MotionFleeTrack::MotionFleeTrack() : Track_1158b0(), x(0), y(-1.0f), z(1.0f) {}