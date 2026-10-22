class Track_11c650 {
  public:
    Track_11c650();
    virtual void vf();
    char pad[8];
};
class StrafeCircleHBTrack : public Track_11c650 {
  public:
    StrafeCircleHBTrack();
    int a;
    float b;
    int c, d, e, h;
    float g;
    virtual void vf();
};
StrafeCircleHBTrack::StrafeCircleHBTrack() : Track_11c650(), a(0), b(-1.0f), c(0), d(0), e(0), h(0), g(1.0f) {}