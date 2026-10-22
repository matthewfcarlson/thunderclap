class Track_11c5b0 {
  public:
    Track_11c5b0();
    virtual void f();
    char pad[8];
};
class StrafeLateralHBTrack : public Track_11c5b0 {
  public:
    StrafeLateralHBTrack();
    virtual void f();
    int a;
    float b;
    int c, d, e, g;
    float h;
};
StrafeLateralHBTrack::StrafeLateralHBTrack() : Track_11c5b0(), a(0), c(0), d(0), e(0), g(0) {
    b = -1.0f;
    h = 1.0f;
}