class Track_16fe80 {
  public:
    Track_16fe80();
    virtual void f();
    char pad[8];
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class RestPoseTrack : public Track_16fe80 {
  public:
    RestPoseTrack();
    virtual void f();
    int a;
    float b;
    char pad2[4];
    Sub sub;
    int c, d, e;
};
RestPoseTrack::RestPoseTrack() : Track_16fe80(), a(0), b(-1.0f), sub(), c(-5), d(0), e(0) {}