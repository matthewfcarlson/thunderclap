class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class StrafeLateralHBTrack : public Base {
  public:
    StrafeLateralHBTrack();
    virtual void f();
    int a;
    float b;
    int c, d, e, g;
    float h;
};
StrafeLateralHBTrack::StrafeLateralHBTrack() : Base(), a(0), c(0), d(0), e(0), g(0) {
    b = -1.0f;
    h = 1.0f;
}