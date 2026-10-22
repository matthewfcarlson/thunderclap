class Track_115c60 {
  public:
    Track_115c60();
    virtual void vf();
    char pad[8];
};
class MotionChaseTrack : public Track_115c60 {
  public:
    MotionChaseTrack();
    virtual void vf();
    int a;
    float b;
    int c, d, e, f;
    float h;
    int i;
};
MotionChaseTrack::MotionChaseTrack() : Track_115c60() {
    a = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    i = 0;
    b = -1.0f;
    h = 1.0f;
}