class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class MotionTrailStopTrack : public Base {
  public:
    MotionTrailStopTrack();
    int a;
    int b;
    int c;
};
MotionTrailStopTrack::MotionTrailStopTrack() : Base() {
    b = 0;
    c = 0;
    a = 1;
}