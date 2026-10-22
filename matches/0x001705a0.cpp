class Track_1705a0 {
  public:
    virtual void f();
    Track_1705a0();
    char pad[4];
};
class MotionStateTrack : public Track_1705a0 {
  public:
    virtual void f();
    MotionStateTrack();
    int a;
    int b;
    float c;
    int d;
};
MotionStateTrack::MotionStateTrack() {
    b = 0;
    d = 0;
    c = -1.0f;
    a = 1;
}