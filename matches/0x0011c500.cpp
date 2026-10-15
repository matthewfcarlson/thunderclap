namespace hulkfight {
namespace ai {
class TrackBase {
  public:
    TrackBase();
    virtual void f();
    char pad[8];
};
class StrafeRunTrack : public TrackBase {
  public:
    StrafeRunTrack();
    virtual void f();
    int a;
    float b;
    int c, d, e, f1;
    float g, h;
    char i, j;
    char pad2[2];
    int k;
    float l;
};
StrafeRunTrack::StrafeRunTrack() : a(0), c(0), d(0), e(0), f1(0), i(0), j(0), k(0) {
    b = -1.0f;
    g = 40.0f;
    h = 1.5f;
    l = 1.0f;
}
} // namespace ai
} // namespace hulkfight