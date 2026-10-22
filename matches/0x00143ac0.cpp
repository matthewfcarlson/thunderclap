class Track_143ac0 {
  public:
    Track_143ac0();
    virtual void f();
    char pad[4];
};
class MotionTrailStopTrack : public Track_143ac0 {
  public:
    MotionTrailStopTrack();
    int a;
    int b;
    int c;
};
MotionTrailStopTrack::MotionTrailStopTrack() : Track_143ac0() {
    b = 0;
    c = 0;
    a = 1;
}