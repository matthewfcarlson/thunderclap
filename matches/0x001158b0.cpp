class Base {
  public:
    Base();
    virtual void f();
    int a, b;
};
class MotionFleeTrack : public Base {
  public:
    MotionFleeTrack();
    int x;
    float y, z;
    virtual void f();
};
MotionFleeTrack::MotionFleeTrack() : Base(), x(0), y(-1.0f), z(1.0f) {}