class Track_115d00 {
  public:
    Track_115d00();
    virtual void vf();
    char pad[8];
};
class MotionClosestWaypointTrack : public Track_115d00 {
  public:
    MotionClosestWaypointTrack();
    int a;
    float b, c;
    int d, e, f0, g;
    char h, i;
    char pad2[2];
    float j, k;
    virtual void vf();
};
MotionClosestWaypointTrack::MotionClosestWaypointTrack()
    : Track_115d00(), a(0), b(-1.0f), c(1.0f), d(0), e(0), f0(0), g(0), h(0), i(0), j(0.2f), k(3.0f) {}